//TESTES COM TX ESP32 E RX ADAPTADOR

int i = 0;

void setup() {
  Serial.begin(9600); //CONFIGURA BAUD RATE DA UART
}

void loop() {
  if(i<10)i++;
  else i=0;
  Serial.print(i);
  Serial.println("TESTE"); //ESCREVE A EMNSAGEM
  delay(500);
}
