#ifndef MENU_HPP
#define MENU_HPP

#include "SerialToDevice.hpp"


class menu{
private:
  SerialToDevice teste1;
public:
  void menuInitialize();
  void options();
};


void menu::menuInitialize(){
  teste1.setConfig(1,"teste1"); //bluetooth
  teste1.msgWrite("Bem vindo ao menu bluettoth! ");
}



void menu::options(){
  char opt;
  teste1.msgWrite("Selecione uma das opcoes abaixo: ");
  teste1.msgWrite("(1) Exibir leituras atuais.");
  teste1.msgWrite("(2) Exibir previsao.");
  teste1.msgWrite("(3) Exibir numero de dados coletados.");
  teste1.msgWrite("(4) Sair.");
  do {
    opt = teste1.msgRead_char();
    switch (opt){
      case 1:
        break;
      case 2: 
        break;
      default:
        break;
      
    }
  }while(opt!=4);
}

#endif
