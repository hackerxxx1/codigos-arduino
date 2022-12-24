#include<Wire.h>
#include<LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3,POSITIVE);


int dados[100],vetor[16];
int ctd=0,ti = 3, ctd2=0;
void setup() {

  lcd.begin(16,2);
  //Pinos ligados aos pinos 1, 2, 3 e 4 do teclado - Linhasi
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  
  //Pinos ligados aos pinos 5, 6, 7 e 8 do teclado - Colunas
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(10, INPUT);
  pinMode(11, INPUT);
  // seta porta led rgb
  pinMode(7,OUTPUT);//vermelho
  pinMode(2,OUTPUT);//verde
  pinMode(12,OUTPUT);// azul
  
  
  Serial.begin(9600);
  Serial.println("Aguardando acionamento das teclas...");
  Serial.println();

}

void loop() {
 inicializar();
 digitalWrite(7,HIGH);
 delay(500);
 digitalWrite(7,LOW);
 delay(500);
 digitalWrite(2,HIGH);
 delay(500);
 digitalWrite(2,LOW);
 delay(500);
 digitalWrite(12,HIGH);
 delay(500);
 digitalWrite(12,LOW);
 

 while(ti-2!= 4&& digitalRead(10)!=HIGH){
  if(ctd == 0){    lcd.clear();
lcd.home();}


  
    for (ti = 3; ti<7; ti++)
    {
    //Alterna o estado dos pinos das linhas
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(ti, HIGH);
    //Verifica se alguma tecla da coluna 1 foi pressionada
    if (digitalRead(8) == HIGH)
    {
 
        
      imprime_linha_coluna(ti-2, 1);
      while(digitalRead(8) == HIGH){ if(ti-2==1){
        vetor[1]=1;
        lcd.print("1");
        lcd.setCursor(ctd,0);
          ctd++;
          break;
      }else if(ti-2==2){
        vetor[4]=1;
         lcd.print("4");
         lcd.setCursor(ctd,0);
           ctd++;
           break;
      }else if(ti-2==3){
        vetor[7]=1;
         lcd.print("7");
         lcd.setCursor(ctd,0);
           ctd++;
          break;
      }else if (ti-2==4){
        vetor[14]=1;
         lcd.print("*");
         lcd.setCursor(ctd,0);
           ctd++;
         break;
      }
     }
    }

    //Verifica se alguma tecla da coluna 2 foi pressionada    
    if (digitalRead(9) == HIGH)
    {
     
      
      imprime_linha_coluna(ti-2, 2);
      while(digitalRead(9) == HIGH){  if(ti-2==1){
        vetor[2]=1;
         lcd.print("2");
         lcd.setCursor(ctd,0);
           ctd++;
           break;
      }else if(ti-2==2){
        vetor[5]=1;
         lcd.print("5");
         lcd.setCursor(ctd,0);
           ctd++;
           break;
      }else if(ti-2==3){
        vetor[8]=1;
         lcd.print("8");
         lcd.setCursor(ctd,0);
           ctd++;
           break;
      }else if (ti-2==4){
        vetor[0]=1;
         lcd.print("0");
         lcd.setCursor(ctd,0);
           ctd++;
           break;
      }};
      
    }
    
    //Verifica se alguma tecla da coluna 3 foi pressionada
    if (digitalRead(10) == HIGH)
    {
      
      
      imprime_linha_coluna(ti-2, 3);
      while(digitalRead(10) == HIGH){  if(ti-2==1){
        vetor[3]=1;
         lcd.print("3");
         lcd.setCursor(ctd,0);
           ctd++;
           break;
      }else if(ti-2==2){
        vetor[6]=1;
         lcd.print("6");
         lcd.setCursor(ctd,0);
           ctd++;
           break;
      }else if(ti-2==3){
        vetor[9]=1;
         lcd.print("9");
         lcd.setCursor(ctd,0);
           ctd++;
           break;
      }else if (ti-2==4){
        vetor[15]=1;
         lcd.print("=");
         lcd.setCursor(ctd,0);
           ctd++;
           break;
      }}
    }
    
    //Verifica se alguma tecla da coluna 4 foi pressionada
    if (digitalRead(11) == HIGH)
    {
      
      imprime_linha_coluna(ti-2, 4);
      while(digitalRead(11) == HIGH){  if(ti-2==1){
        vetor[10]=1;
         lcd.print("+");
         lcd.setCursor(ctd,0);
           ctd++;
           break;
      }else if(ti-2==2){
        vetor[11]=1;
         lcd.print("-");
         lcd.setCursor(ctd,0);
           ctd++;
           break;
      }else if(ti-2==3){
        vetor[12]=1;
         lcd.print("x");
         lcd.setCursor(ctd,0);
           ctd++;
           break;
      }else if (ti-2==4){
        vetor[13]=1;
         lcd.print("/");
         lcd.setCursor(ctd,0);
           ctd++;
           break;
      }} 
    }
    for(int i=0;i<16;i++){
     if (vetor[i] == 1){
      dados[ctd2]= i;
      ctd2++;}
     }
   }
   delay(100);
  
 }

}

void imprime_linha_coluna(int x, int y)
{
       Serial.print("Linha : ");
       Serial.print(x);
       Serial.print(" x Coluna : ");
       Serial.print(y);
       delay(10);
       Serial.println();

 }

void inicializar(){
   lcd.setBacklight(HIGH);
lcd.setCursor(0,0);

  lcd.clear();
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("                tudo bom?");
  delay(500);
  lcd.clear();
  lcd.print("               tudo bom?");
  delay(500);
  lcd.clear();
  lcd.print("              tudo bom?");
  delay(500);
  lcd.clear();
  lcd.print("             tudo bom?");
  delay(500);
  lcd.clear();
  lcd.print("            tudo bom?");
  delay(500);
  lcd.clear();
  lcd.print("           tudo bom?");
  delay(500);
  lcd.clear();
  lcd.print("          tudo bom?");
  delay(500);
  lcd.clear();
  lcd.print("         tudo bom?");
  delay(500);
  lcd.clear();
  lcd.print("        tudo bom?");
  delay(500);
  lcd.clear();
  lcd.print("       tudo bom?");
  delay(500);
  lcd.clear();
  lcd.print("      tudo bom?");
  delay(500);
  lcd.clear();
  lcd.print("     tudo bom?");
  delay(500);
  lcd.clear();
  lcd.print("    tudo bom?");
  delay(500);
  lcd.clear();
  lcd.print("   tudo bom?");
  delay(500);
  lcd.clear();
  lcd.print("  tudo bom?");
  delay(500);
  lcd.clear();
  lcd.print(" tudo bom?");
  delay(500);
  lcd.clear();
  lcd.print("tudo bom?");
  delay(500);
  lcd.clear();
  lcd.print("udo bom?");
  delay(500);
  lcd.clear();
  lcd.print("do bom?");
  delay(500);
  lcd.clear();
  lcd.print("o bom?");
  delay(500);
  lcd.clear();
  lcd.print(" bom?");
  delay(500);
  lcd.clear();
  lcd.print("bom?");
  delay(500);
  lcd.clear();
  lcd.print("om?");
  delay(500);
  lcd.clear();
  lcd.print("m?");
  delay(500);
  lcd.clear();
  lcd.print("?");
  delay(500);
  lcd.clear();

  lcd.print("operacao please!");
  }


