//carregar  a biblioteca do sensor utrasonico
#include <Ultrasonic.h>

//define os pino para o trigger e echo
#define pino_trigger 5
#define pino_echo 4


//inicializar o senso nos pinos definidos acima
Ultrasonic ultrasonic(pino_trigger,pino_echo);

void setup() {
  Serial.begin(9600);
  Serial.println("Lendo dados do sensor...");
  pinMode(6,OUTPUT);
  

}

void loop() {


  float cmMsec, InMsec;

  long microsec = ultrasonic.timing();
  cmMsec = ultrasonic.convert(microsec, Ultrasonic::CM);
  InMsec = ultrasonic.convert(microsec, Ultrasonic::IN);


  Serial. print(" Distancia em CM");
  Serial.print(cmMsec);
  Serial.print("- Distancia em polegadas");
  Serial.println(InMsec);
   
if (cmMsec < 130){
  digitalWrite(6,HIGH);
  delay(1000);
  digitalWrite(6,LOW);
  delay(1000);
  if(cmMsec<40){
  for  (int i=0;i < 15;i++){
  digitalWrite(6,HIGH);
  delay(100);
  digitalWrite(6,LOW);
  delay(100);}
  }
  
}else{digitalWrite(6,LOW);}
  
  

}
