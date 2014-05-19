/*
  Libreria LiquidCrystal - Hola mundo
 
 Demuestra el uso de un display LCD de 16x2. La libreria funciona con
 todos los display LCD compatibles con Hitachi HD44780. Hay muchos 
 disponibles y normalmente los reconoces porque tienen una interfaz
 de 16 pines.
 
 Este sketch imprime "Hola mundo!" en la pantalla y muestra el valor 
 de la entrada analogica en milli volts
 
 Basado en el codigo:
 Library originally added 18 Apr 2008
 by David A. Mellis
 library modified 5 Jul 2009
 by Limor Fried (http://www.ladyada.net)
 example added 9 Jul 2009
 by Tom Igoe
 modified 22 Nov 2010
 by Tom Igoe
 
 This example code is in the public domain.
 
 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */

// incluir libreria:
#include <LiquidCrystal.h>

#define BITS_FOUR

#define LCD_RS 7
#define LCD_EN 6

#define LCD_D4 5
#define LCD_D5 4
#define LCD_D6 3
#define LCD_D7 2

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7); 

#define LCD_COLS  16
#define LCD_ROWS  2


static unsigned char col = 0;
static unsigned int count = 0;
static bool order = 0;
String texto = "Hola mundo!!";
int longTexto = texto.length();

void setup() {
  // Setear cantidad de caracteres y lineas
  lcd.begin(LCD_COLS, LCD_ROWS);
  lcd.noAutoscroll();
  lcd.noCursor(); 
  
  //inicializar puerto serie
  Serial.begin(115200);
}

void updateDisplay() {
  lcd.clear();
  lcd.setCursor(col, 0);
  lcd.print(texto);
    
  if (order == 0) {
    col++;
    if (col == LCD_COLS-longTexto) {
      order = 1;
    }
  } else {
    col--;
    if (col == 0) {
      order = 0;
    }
  }
}

void loop() {
   int sensor;
   delay(200);
   count++;
   if (count % 2 == 0)
     updateDisplay();
   lcd.setCursor(0, 1);
   sensor = analogRead(5);
   Serial.println(sensor);
   lcd.print(sensor*5000.0/1024);
   lcd.setCursor(6, 1);
   lcd.print("mV");
}

