
int sensor = A0;    //sensor ldr
int led = LED_BUILTIN;      // led pra teste
int valor = 0;   // valor do sensor

void setup() {
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  pinMode(led,OUTPUT);
  
}

void loop() {

  valor = analogRead(sensor);
  Serial.println("valor= ");
  Serial.println(valor);
   delay(1000);
  if (valor > 100){
    digitalWrite(led,HIGH);
    } else{digitalWrite(led,LOW);}
  

}
