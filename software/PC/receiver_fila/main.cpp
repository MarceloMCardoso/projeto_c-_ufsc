#include <stdio.h>		
#include <string.h>
#include <iostream>
#include "Serial.h"
#include <list>

using namespace std;

unsigned i = 0;

int main() {
	Serial Serial1;

  	list <string> test;
  	int tam;
  	tam=10;

  	for(int i=0;i<tam;i++){
  	cout << i << endl;
  		Serial1.SerialIsOn();
    	test.push_front(Serial1.SerialRead());
    	cout << Serial1.SerialRead() << endl;
  	}

  	cout << "Tamanho da lista: " << test.size() << endl;

  	tam = test.size();
  
  	for(int i=0;i<tam;i++){
      	cout << test.front() << endl;
      	test.pop_front();

  	}

  	cout << "fim" << endl;

    return 0;
}
