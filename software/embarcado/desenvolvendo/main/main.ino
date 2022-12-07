#include "menu.hpp"
#include "logger.hpp"

menu teste;
logger LOG;
hw_timer_t *My_timer = NULL;
bool flag = 0;
  
void IRAM_ATTR rotina(){
  flag = !flag;
}

void setup() {
  Serial.begin(115200); //UART para debugar
  LOG.setConfig();
  teste.menuInitialize();


  My_timer = timerBegin(2, 80, true);
  timerAttachInterrupt(My_timer, &rotina, true);
  timerAlarmWrite(My_timer, 5*1000000, true);
  timerAlarmEnable(My_timer); //Just Enable


}

void loop() {
  if(flag == 1){
    LOG.saveData();
    flag = 0;
  }
  
  //teste.menuInitialize();
  //teste.options();

}
