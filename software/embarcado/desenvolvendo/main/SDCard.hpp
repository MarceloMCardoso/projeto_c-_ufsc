#ifndef SDCARD_HPP
#define SDCARD_HPP

#include "FS.h"
#include "SD.h"
#include "SPI.h"


class SDCard{
private:
  uint8_t CSPin;
public:
  void setCSPin(uint8_t _CSPin);
  void writeFile(String _name, String _msg);
  void readFile(String _name);
};


void SDCard::setCSPin(uint8_t _CSPin){
  CSPin = _CSPin;
  SD.begin(_CSPin);
}


void SDCard::writeFile(String _name, String _msg){
    SD.begin(CSPin);
    _name = "/" + (String)_name;
    File file = SD.open(_name, FILE_APPEND);
    file.print(_msg);
    file.close();
}

void SDCard::readFile(String _name){
    File file = SD.open(_name);
    Serial.print("Read from file: ");
    while(file.available()){
        Serial.write(file.read());
    }
    file.close();
}










#endif
