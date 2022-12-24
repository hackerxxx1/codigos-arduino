#include <Wire.h>


int myAddress[127];
byte error, address;
int nDevices;
bool echo = false;
void showMenu() {
  Serial.println(F("\nI2C Scanner v.7"));
  Serial.println(F(" s - Escanear por dispositivos I2C"));
  Serial.println(F(" l - Listar todos dispositivos encotrados no último escaneamento"));
  Serial.println(F(" o - Requisitar dados de um dispositivo (limitado a conexão entre Arduinos)"));
  Serial.println(F(" e - Habilitar ou desabilitar função echo"));
  Serial.println(F(" h - Mostra esse menu novamente\n"));
}
void setup()
{
  Wire.begin();
  Serial.begin(9600);
  while (!Serial);             // Leonardo: wait for serial monitor
  showMenu();
}
void loop()
{
  if (Serial.available() > 0) {
    char c = Serial.read();
    if (echo) {
      Serial.print("[I2CS] Recebido: ");
      Serial.println(c);
    }
    switch (c) {
      case 'e':
        echo = !echo;
        Serial.println(echo ? "[I2CS] Echo habilitado" : "[I2CS] Echo desabilitado");
        break;
      case 'h':
        showMenu();
        break;
      case 'o':
        if (nDevices <= 0) {
          Serial.println(F("\n[IC2S] Primeiro você deve realizar um escaneamento."));
        } else {
          Serial.println(F("\n[IC2S] Digite com qual dispositivo deseja conectar: "));
          for (int i =  0; i < nDevices; i++ ) {
            Serial.print(F("[IC2S] ")); Serial.print(i + 1); Serial.print(F(") ")); Serial.print(F("0x")); if (myAddress[i] < 16)Serial.print(F("0")); Serial.println(myAddress[i], HEX);
          }
          while (Serial.available() < 1);
          int val = Serial.parseInt();
          Serial.print(F("[IC2S] Abrindo conexão no endereço")); Serial.print(F(" 0x")); if (myAddress[val - 1] < 16)Serial.print(F("0")); Serial.println(myAddress[val - 1], HEX);
          delay(100);
          if (myAddress[val - 1] != 0) {
            Wire.requestFrom(myAddress[val - 1], 6); // request 6 bytes from slave device #8
            Serial.print(F("[IC2S] Recebido de 0x")); if (myAddress[val - 1] < 16)Serial.print(F("0")); Serial.print(myAddress[val - 1], HEX); Serial.print(F(": "));
            while (Wire.available()) {
              char c = Wire.read();
              Serial.print(c);
            } Serial.println(F("\n"));
          } else {
            Serial.println(F("Invalido\n"));
          }
        }
        break;
      case 'l':
        if (nDevices <= 0) {
          Serial.println(F("\n[I2CS] Nenhum dispositivo para exibir\n"));
        } else {
          Serial.println(F("\n[IC2S] Dispositivos encontrados no último escaneamento"));
          for (int i =  0; i < nDevices; i++ ) {
            Serial.print(F("[IC2S] ")); Serial.print(i + 1); Serial.print(F(") ")); Serial.print(F("0x")); if (myAddress[i] < 16)Serial.print(F("0")); Serial.println(myAddress[i], HEX);
          } Serial.println(F("[I2CS] Fim\n"));
        }

        break;
      case 's':
        Serial.println(F("[I2CS] Escaneando..."));
        nDevices = 0;
        for (address = 1; address < 127; address++ )
        {
          Wire.beginTransmission(address);
          error = Wire.endTransmission();

          if (error == 0)
          {
            Serial.print(F("[I2CS] Dispositivo I2C encontrado no endereço 0x"));
            if (address < 16)Serial.print(F("0"));
            Serial.print(address, HEX);
            Serial.println(F("!"));
            myAddress[nDevices] = address;
            nDevices++;
          }
          else if (error == 4)
          {
            Serial.print(F("[I2CS] Erro desconhecido encontrado no endereço 0x"));
            if (address < 16)Serial.print(F("0"));
            Serial.println(address, HEX);
          }
        }
        if (nDevices == 0) {
          Serial.println(F("[I2CS] Nenhum dispositivo detectado\n"));
        } else {
          Serial.println(F("[I2CS] Escaneamento encerrado\n"));
        }
        break;
      default:
       Serial.println(F("[I2CS] Comando não reconhecido, em caso de duvidas digite 'h'.\n"));
        break;
    }
  }
}
