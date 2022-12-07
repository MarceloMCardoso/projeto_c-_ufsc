#ifndef SERIALTODEVICE_HPP
#define SERIALTODEVICE_HPP

#include "BluetoothSerial.h"

#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

#if !defined(CONFIG_BT_SPP_ENABLED)
#error Serial Bluetooth not available or not enabled. It is only available for the ESP32 chip.
#endif

BluetoothSerial SerialBT;

class SerialToDevice{
private:
  uint8_t type;
  String name;
public:
  void setConfig(uint8_t _type, String _name);
  void msgWrite(String _msg);
  char msgRead_char();
};


void SerialToDevice::setConfig(uint8_t _type, String _name){
  type = _type;
  switch (type){
    case 1:
      //type bluetooth
        SerialBT.begin(_name); //Bluetooth device name
      break;
    case 2:
      //type uart wire connection
        Serial2.begin(115200);
      break;
  }
}

void SerialToDevice::msgWrite(String _msg){
  switch (type){
    case 1:
      //type bluetooth
        SerialBT.println(_msg);
      break;
    case 2:
      //type uart wire connection
        Serial2.println(_msg);
      break;
  }
}

char SerialToDevice::msgRead_char(){
  char x;
    switch (type){
    case 1:
      //type bluetooth
          while (SerialBT.available()) {
            x = (char)SerialBT.read();}
          return x;
      break;
    case 2:
      //type uart wire connection
        return (char)Serial2.read();
      break;
  }
  
}

#endif
