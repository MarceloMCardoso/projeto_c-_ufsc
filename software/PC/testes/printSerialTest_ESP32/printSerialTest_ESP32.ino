//TESTES COM TX ESP32 E RX ADAPTADOR

int i = 0;

void setup() {
  Serial.begin(9600); //CONFIGURA BAUD RATE DA UART
}

void loop() {
    Serial.print("TESTE"); //ESCREVE A EMNSAGEM
    Serial.println(i);     //IMPRIME O VALOR DO CONTADOR
     i++;

     if(i==10)i=0;


  delay(500);
}
