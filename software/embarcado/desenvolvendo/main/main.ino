
//inclusão das bibliotecas utilizadas:
#include "Sensor.hpp"
#include "ldr.hpp"
#include "rtc.hpp"
#include "SDCard.hpp"

//declaração dos objetos 
SDCard datalog;
Sensor TH_interno;
Sensor TH_externo;
ldr LDR_sul;
ldr LDR_leste;
ldr LDR_oeste;
ldr LDR_interno;
rtc relogio;

//variavel auxiliar para somar strings de maniera mais visivel
String registro , data_registro, horario_registro;

//configuração iniciais

void setup() {
  
  Serial.begin(115200); //UART para debugar
  //configuração dos sensores e SD
  
  datalog.setCSPin(2);
  TH_externo.setConfig(4,dht_11);
  TH_interno.setConfig(aht_20);
  LDR_sul.LDR_Config(27, 4096, 3.3, 10000);
  LDR_oeste.LDR_Config(26, 4096, 3.3, 10000);
  LDR_leste.LDR_Config(25, 4096, 3.3, 10000);
  LDR_interno.LDR_Config(14, 4096, 3.3, 10000);

  //Cabeçalho rodar somente uma vez
  //datalog.writeFile("/datalog.txt","Data,Horario,Temp_int,Hum_int,Temp_ext,Hum_ext,Lux_int,Lux_oest,Lux_leste,Lux_sul\r\n");

}

void loop() {

  //a cada 5 segundos le todos os sensores e grava no cartão SD em arquivo de texto separado por ','
  
  delay(5000);
  data_registro = (String)relogio.getDay() + "/" + (String)relogio.getMonth() + "/" + (String)relogio.getYear();
  horario_registro = (String)relogio.getHour() + ":" + (String)relogio.getMinute() + ":" + relogio.getSecond();
  
  Serial.println(registro);
  
  registro = (String)data_registro + "," + (String)horario_registro + "," + (String)TH_interno.getTemperature() + ","
  + (String)TH_interno.getHumidity() + "," + (String)TH_externo.getTemperature() + ","
  + (String)TH_externo.getHumidity() + "," + (String)LDR_interno.getLuxValue() + "," + (String)LDR_oeste.getLuxValue() + "," 
  + (String)LDR_leste.getLuxValue() + "," + (String)LDR_sul.getLuxValue() + "\r\n";

  datalog.writeFile("datalog.csv", registro);
}
