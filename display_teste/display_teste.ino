// Programa : Display LCD 16x2 e modulo I2C
// Autor : Arduino e Cia

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x3F,2,1,0,4,5,6,7,3, POSITIVE);
 
void setup()
{
 lcd.begin (16,2);

}
 
void loop()
{ lcd.clear();
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
}
