#include <Ultrasonic.h>
#define trigger 5                   // pino trigger ligado na porta 5
#define echo 6                      // pino echo ligado na porta 6
Ultrasonic ultrasonic(trigger,echo);// função que ler o sensor ultrasonico



void setup() {
  Serial.begin(9600);
  Serial.println("lendo sensor");
 

}

void loop() {
   float cmsec;
  long microsec = ultrasonic.timing();
  cmsec = ultrasonic.convert(microsec,Ultrasonic::CM);
  Serial.print(cmsec);
  delay(500);
    if (cmsec > 80){
      //codigo caça alguem 
      }else if (cmsec < 80){
      // codigo manda pra fora
      } 
     

}
