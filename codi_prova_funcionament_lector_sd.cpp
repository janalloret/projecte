// no necessita cap llibreria
// alimentat a 5v, amb pins que posa abaix
// targeta formatejada amb 32fat
#include <SPI.h>
#include <SD.h>
// Prueba con estos pines alternativos:
#define CS_PIN 5 // Opciones comunes: 5, 13, 21
#define SCK_PIN 13
#define MISO_PIN 11
#define MOSI_PIN 12

SPIClass spi = SPIClass(FSPI); // Usa SPI1 (FSPI)
File fitxerdit1,fitxerdit2,fitxerdit3,fitxerdit4,fitxerdit5,fitxerprova;

void setup() {
Serial.begin(115200);
delay(2000);

// Configura SPI con los pines
spi.begin(SCK_PIN, MISO_PIN, MOSI_PIN, CS_PIN);

Serial.print("Iniciando SD... ");

// Intenta inicializar con velocidad reducida (1 MHz)
  if (!SD.begin(CS_PIN, spi )) { // <- ¡Velocidad reducida!
    Serial.println("Fallo. Verifica:");
    Serial.println("- Pines y conexiones");
    Serial.println("- Formato FAT32");
    Serial.println("- Resistencia pull-up");
    while (1);
  }
  Serial.println("Correcto");

// Leer archivo...
  fitxerprova = SD.open("/prova.html");
  fitxerdit1=SD.open("/ma1.html");
  fitxerdit2=SD.open("/ma2.html");
  fitxerdit3=SD.open("/ma3.html");
  fitxerdit4=SD.open("/ma4.html");
  fitxerdit5=SD.open("/ma5.html");

  if (fitxerprova) {
    Serial.println("Contenido:");
    while (fitxerprova.available()) {
    Serial.write(fitxerprova.read());
    }
    fitxerprova.close();
  } 

  else {
  Serial.println("Error abriendo archivo");
  }
}

void loop() {}
