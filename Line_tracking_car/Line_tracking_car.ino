
#define lineTracking1 11
#define lineTracking2 4
#define lineTracking3 2

int in1=9;
int in2=8;
int in3=7;
int in4=6;
int ENA=10;
int ENB=5;
int ABS=130;

bool num1, num2, num3;
bool flag;
 
 void re(){
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println("go forward!");
}

void frente(){
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("go back!");
}

void esquerda(){
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);

  digitalWrite(in2,HIGH);
 
  Serial.println("go left!");
}

void direita(){
   analogWrite(ENA,ABS);
   analogWrite(ENB,ABS);
 
  digitalWrite(in4,HIGH);
   //Serial.println("go right!");
} 

void para(){
   digitalWrite(ENA,LOW);
   digitalWrite(ENB,LOW);
     digitalWrite(in1,HIGH);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,HIGH);
   Serial.println("Stop!");
} 

void segue(){
  frente();delay(500);para();delay(500);
  }

void leve(){
  direita();delay(200);para();delay(50);
  }  

void setup(){
  Serial.begin(9600);
}

void loop() {
  num1 = digitalRead(lineTracking1);    
  num2 = digitalRead(lineTracking2);
  num3 = digitalRead(lineTracking3); 
  /*
   if(num1 == 0 && num2 == 0 && num3 == 0){
    frente();delay(200);
    para();delay(100);
    }else if(num1 == 0 && num2 == 0 && num3 == 1){
    direita(); delay(50);
    para();delay(100);
    }else if(num1 == 0 && num2 == 1 && num3 == 0){
      while(num2 == 1){
        segue();
    frente();delay(10);esquerda();delay(10);frente();delay(10);direita();delay(10);}  
    }else if(num1 == 0 && num2 == 1 && num3 == 1){
  
    }else if(num1 == 1 && num2 == 0 && num3 == 0){
  
    }else if(num1 == 1 && num2 == 0 && num3 == 1){
  
    }else if(num1 == 1 && num2 == 1 && num3 == 0){
   
    }else if(num1 == 1 && num2 == 1 && num3 == 1){
   
    }*/
   frente();
   delay(1500);
   para();
   delay(150);
 
}
