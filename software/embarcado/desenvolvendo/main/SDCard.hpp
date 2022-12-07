#ifndef SDCARD_HPP
#define SDCARD_HPP

#include "FS.h"
#include "SD.h"
#include "SPI.h"


class SDCard{
private:
  uint8_t CSPin;
  bool state;
public:
  void setCSPin(uint8_t _CSPin);
  void writeFile(String _name, String _msg);
  String readFile(String _name);
  bool getState();
  uint32_t getNumLinhas(String _name);
  String getOneLine(String _name, uint32_t _numLine);

};


void SDCard::setCSPin(uint8_t _CSPin){
  CSPin = _CSPin;
  if(!SD.begin(CSPin))state=0;
  else state=1;
}


void SDCard::writeFile(String _name, String _msg){
    if(!SD.begin(CSPin))state=0;
    else state=1;
    _name = "/" + (String)_name;
    File file = SD.open(_name, FILE_APPEND);
    file.print(_msg);
    file.close();
}

String SDCard::readFile(String _name){
    File file = SD.open(_name);
    while(file.available()){
        return (String)file.read();
    }
    file.close();
}

String SDCard::getOneLine(String _name, uint32_t _numLine){
  _name = "/" + (String)_name; 
  String line;
  File file = SD.open(_name);
  file.seek(0);
  char cr;
  
  for(unsigned int i = 0; i < (_numLine -1);){
    cr = file.read();
    if(cr == '\n'){
      i++;
    }
  }
  
  //Now we are at the right line
  while(true){
    cr = file.read();
    line = line + cr;
    if(cr == '\n'){
      break;
    }
  }
  //a for loop with a read limit might be a good idea
  return line;
}



uint32_t SDCard::getNumLinhas(String _name){
  uint32_t total_linhas = 0;
    if(!SD.begin(CSPin))state=0;
    else state=1;
    _name = "/" + (String)_name;
    File file = SD.open(_name);
    while(file.available()){
      if(file.read()=='\n'){
        total_linhas++;
      }
    }
    file.close();
    return total_linhas;
}

bool SDCard::getState(){
  return state;
}









#endif
