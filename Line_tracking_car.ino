
#define lineTracking1 11
#define lineTracking2 4
#define lineTracking3 2

int in1=9;
int in2=8;
int in3=7;
int in4=6;
int ENA=10;
int ENB=5;
int ABS=115;

bool num1, num2, num3;
bool flag;
 
 void _mForward(){
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
  Serial.println("go forward!");
}

void _mBack(){
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW);
  Serial.println("go back!");
}

void _mleft(){
  analogWrite(ENA,ABS);
  analogWrite(ENB,ABS);
  digitalWrite(in1,HIGH);
  digitalWrite(in2,LOW);
  digitalWrite(in3,HIGH);
  digitalWrite(in4,LOW); 
  Serial.println("go left!");
}

void _mright(){
   analogWrite(ENA,ABS);
   analogWrite(ENB,ABS);
  digitalWrite(in1,LOW);
  digitalWrite(in2,HIGH);
  digitalWrite(in3,LOW);
  digitalWrite(in4,HIGH);
   //Serial.println("go right!");
} 

void _mStop(){
   digitalWrite(ENA,LOW);
   digitalWrite(ENB,LOW);
   Serial.println("Stop!");
} 

void setup(){
  Serial.begin(9600);
}

void loop() {
  num1 = digitalRead(lineTracking1);    
  num2 = digitalRead(lineTracking2);
  num3 = digitalRead(lineTracking3); 

  if(num2){
    _mForward();
  }
  else if(num1) { 
    while(1) {
      num1 = digitalRead(lineTracking1);        
      if(num1) {  
        _mleft();
      }
      else{
        break; 
      }                
    }                                       
  }   
  else if(num3) {
    while(1) {
      num3 = digitalRead(lineTracking3);        
      if(num3) {  
        _mright();
      }
      else{
        break; 
      }                
    }                                       
  }
  else{
    num1 = digitalRead(lineTracking1);    
    num3 = digitalRead(lineTracking3); 
    if(num1 && !num3){
      _mleft();
      while(1){
         num3 = digitalRead(lineTracking1);
         if(num3) {
          break; 
         }
      }
    }
    else if(num3 && !num1){
      _mright();
      while(1){
         num1 = digitalRead(lineTracking1);
         if(num1) {
          break; 
         }
      }      
    } 
  }
}

