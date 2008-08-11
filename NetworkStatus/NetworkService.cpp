#include "NetworkService.h"

#include <NetworkManager/NetworkManager.h>

#include <QHostAddress> //IP to String
#include <QDBusConnection>
#include <QDBusInterface>
#include <QDBusReply>
#include <QtCore/qendian.h> //Endian conversion

NetworkService::NetworkService(QObject* parent)
  : LaunchpadService()
{
  setName("net");
}

void
NetworkService::start()
{
  m_dbus = new QDBusInterface( NM_DBUS_SERVICE, NM_DBUS_PATH, NM_DBUS_INTERFACE, QDBusConnection::systemBus(), this);
  if (!m_dbus->isValid())
    return stop();
  connect(m_dbus,SIGNAL(StateChanged(uint)), this, SLOT(stateChanged(uint)));
  updateDevices();
  setRunning(true);
}

void
NetworkService::stop()
{
  m_dbus->deleteLater();
  setRunning(false);
}

void
NetworkService::stateChanged(uint state)
{
  switch(state) {
    case NM_STATE_UNKNOWN:
      setData("State", "Unknown");
      break;
    case NM_STATE_ASLEEP:
      setData("State", "Asleep");
      break;
    case NM_STATE_CONNECTING:
      setData("State", "Connecting");
      break;
    case NM_STATE_CONNECTED:
      setData("State", "Connected");
      break;
    case NM_STATE_DISCONNECTED:
      setData("State", "Disconnected");
      break;
  }
  updateDevices();
}

void
NetworkService::updateDevices() {
  QMap<QString, QVariant> deviceList;
  QDBusReply<QList<QDBusObjectPath> > reply = m_dbus->call("GetDevices");
  foreach(const QDBusObjectPath device, reply.value()) {
    //TODO: Wireless information
    QString path = device.path();
    QDBusInterface dev( NM_DBUS_SERVICE, path, NM_DBUS_INTERFACE_DEVICE, QDBusConnection::systemBus());
    QMap<QString, QVariant> devInfo;
#if Q_BYTE_ORDER == Q_LITTLE_ENDIAN
    uint tmp;
    tmp = qToBigEndian<uint>(dev.property("Ip4Address").toUInt());
    devInfo.insert("Address", QHostAddress(tmp).toString());
#else
    devInfo.insert("Address", QHostAddress(dev.property("Ip4Address").toUInt()).toString());
#endif
    devInfo.insert("Device", dev.property("Interface").toString());
    QString state;
    
    switch(dev.property("State").toInt()) {
      case NM_DEVICE_STATE_UNKNOWN:
        state = "Unknown";
        break;
      case NM_DEVICE_STATE_UNMANAGED:
        state = "Unmanaged";
        break;
      case NM_DEVICE_STATE_UNAVAILABLE:
        state = "Unavailable";
        break;
      case NM_DEVICE_STATE_DISCONNECTED:
        state = "Disconnected";
        break;
      case NM_DEVICE_STATE_PREPARE:
        state = "Preparing";
        break;
      case NM_DEVICE_STATE_CONFIG:
        state = "Configuring";
        break;
      case NM_DEVICE_STATE_NEED_AUTH:
        state = "Need Credentials";
        break;
      case NM_DEVICE_STATE_IP_CONFIG:
        state = "IP Configure";
        break;
      case NM_DEVICE_STATE_ACTIVATED:
        state = "Active";
        break;
      case NM_DEVICE_STATE_FAILED:
        state = "Failed";
        break;
    }
    devInfo.insert("State", state);
    
    deviceList.insert(dev.property("Interface").toString(), QVariant(devInfo));
  }
  
  setData("Devices", QVariant(deviceList));
}

Q_EXPORT_PLUGIN2(networkservice, NetworkService)

#include "NetworkService.moc"
