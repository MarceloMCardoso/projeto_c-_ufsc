#ifndef LOGGER_HPP
#define LOGGER_HPP


//inclusão das bibliotecas utilizadas:
#include "Sensor.hpp"
#include "ldr.hpp"
#include "rtc.hpp"
#include "SDCard.hpp"
#include <cstring>
using namespace std; 

 
class logger{
private:
  //declaração dos objetos 
  SDCard datalog;
  Sensor TH_interno;
  Sensor TH_externo;
  ldr LDR_sul;
  ldr LDR_leste;
  ldr LDR_oeste;
  ldr LDR_interno;
  rtc relogio;
  //variavel auxiliar para somar strings de maneira mais visivel
  String registro , data_registro, horario_registro;
public:
 void setConfig();
 void saveData();
  //String consultaData(uint8_t _ano, uint8_t _mes, uint32_t _dia, uint8_t _hora);
 uint32_t consultaNumData();
};

void logger::setConfig(){
  datalog.setCSPin(2);
  TH_externo.setConfig(4,dht_11);
  TH_interno.setConfig(aht_20);
  LDR_sul.LDR_Config(27, 4096, 3.3, 10000);
  LDR_oeste.LDR_Config(26, 4096, 3.3, 10000);
  LDR_leste.LDR_Config(25, 4096, 3.3, 10000);
  LDR_interno.LDR_Config(14, 4096, 3.3, 10000);
}


void logger::saveData(){
  //Cabeçalho rodar somente uma vez
  //datalog.writeFile("/datalog.txt","Data,Horario,Temp_int,Hum_int,Temp_ext,Hum_ext,Lux_int,Lux_oest,Lux_leste,Lux_sul\r\n");
  String mes = (String)relogio.getMonth();
  if(relogio.getMonth()<=9) mes = (String)"0"+relogio.getMonth();
  String dia = (String)relogio.getDay();
  if(relogio.getDay()<=9) dia = (String)"0"+relogio.getDay();
  String hora = (String)relogio.getHour();
  if(relogio.getHour()<=9) hora = (String)"0"+relogio.getHour();
  String ano = (String)relogio.getYear();
  if(relogio.getYear()<=9) ano = (String)"0"+relogio.getYear();
  String minuto = (String)relogio.getMinute();
  if(relogio.getMinute()<=9) minuto = (String)"0"+relogio.getMinute();
  String segundo = (String)relogio.getSecond();
  if(relogio.getSecond()<=9) segundo = (String)"0"+relogio.getSecond();
  data_registro = (String)(ano) + "," +(String)mes + "," + (String)dia;
  horario_registro = (String)hora + "," + (String)minuto + "," + segundo;
  
  registro = (String)data_registro + "," + (String)horario_registro + "," + (String)TH_interno.getTemperature() + ","
  + (String)TH_interno.getHumidity() + "," + (String)TH_externo.getTemperature() + ","
  + (String)TH_externo.getHumidity() + "," + (String)LDR_interno.getLuxValue() + "," + (String)LDR_oeste.getLuxValue() + "," 
  + (String)LDR_leste.getLuxValue() + "," + (String)LDR_sul.getLuxValue() + "\r\n";
  datalog.writeFile("datalog.txt", registro);
  delay(100);
  
}
/*
String logger::consultaData(uint8_t _ano, uint8_t _mes, uint32_t _dia, uint8_t _hora){
  uint32_t max_lines = datalog.getNumLinhas("datalog.txt");
  uint32_t i = 0;
  uint8_t ano = 0;
  String s = datalog.getOneLine("datalog.txt",max_lines);
  int n = s.length();
  char char_array[n + 1];
  //strcpy(char_array, s.c_str());
  
  ano = (int)char_array[0]*10+(int)char_array[0]*1;
  while(ano!=_ano){
      i++;
      s = datalog.getOneLine("datalog.txt",i);
      n = s.length();
      char_array[n + 1];
      strcpy(char_array, s.c_str());
      ano = (int)(char_array[0]-48)*10+(int)(char_array[0]-48)*1;
  }
  
  //datalog.getOneLine("datalog.txt",430)
  /*
  while(i<=max_lines){
    i++;
    while(_ano!=ano){};
    
  };
    Serial.println(datalog.getOneLine("datalog.txt",max_lines));
      /*Serial.println(char_array[0]);
      Serial.println(char_array[1]);


  return (String)char_array[1];
}

*/


uint32_t logger::consultaNumData(){
  return datalog.getNumLinhas("datalog.txt");
}


#endif
