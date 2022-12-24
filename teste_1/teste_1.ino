int buzzer = 8;// variavel do buzzer do arduino
int cotd = 0;// contador 
int ledr = 2,ledy = 3,ledg = 4,ledpr = 5,ledpg = 6;//variaveis pros ledes do semaforo
int botton = 7; 

void setup() {
  pinMode(ledr,OUTPUT);
  pinMode(ledy,OUTPUT);
  pinMode(ledg,OUTPUT);
  pinMode(ledpr,OUTPUT);
  pinMode(ledpg,OUTPUT);
  pinMode(botton,INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
}


void loop() {
  
                  
}
void alerta(){
  digitalWrite(LED_BUILTIN,HIGH);
  if (cotd<16){
  digitalWrite(buzzer, HIGH);   
  delay(150);                       
  digitalWrite(buzzer, LOW);    
  delay(150); 
  cotd = cotd + 1;}  
  else if(cotd<64){
   digitalWrite(buzzer, HIGH);   
  delay(110);                       
  digitalWrite(buzzer, LOW);    
  delay(110);
  cotd = cotd + 1;
  }else if(cotd<96){
   digitalWrite(buzzer, HIGH);   
  delay(75);                       
  digitalWrite(buzzer, LOW);    
  delay(75);
  cotd = cotd + 1;
  }else{
    digitalWrite(buzzer,LOW);
    digitalWrite(LED_BUILTIN,LOW);
    delay(5000);
    digitalWrite(LED_BUILTIN,HIGH);
    delay(500);
    cotd = 0 ;}
  }

void inicial(){
  digitalWrite(ledg,HIGH);
  digitalWrite(ledpr,HIGH);
  digitalWrite(ledr,LOW);
  digitalWrite(ledpg,LOW);
  }

void checa (int x){
   int aux = x;
   if(aux = 1){
    fechar();
    }    
}

void fechar(){
  digitalWrite(ledy,HIGH);
  digitalWrite(ledg,LOW);
  delay(2000);
  digitalWrite(ledr,HIGH);
  digitalWrite(ledpg,HIGH);
  digitalWrite(ledpr,LOW);
  digitalWrite(ledy,LOW);
  delay(10000);
  alerta();
  }
