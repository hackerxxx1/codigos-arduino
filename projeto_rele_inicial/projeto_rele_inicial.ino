


int botton = 4, ctd = 0 ;
void setup() {
 
pinMode(2,OUTPUT);
pinMode(botton,INPUT);

}

void loop() {
  int x = digitalRead(4);
  if (x == 1){
       seta();
  } else { digitalWrite(2,LOW); } 
}

  

void seta(){
  digitalWrite(2,HIGH);
delay(300);
digitalWrite(2,LOW);
delay(300); }
