/*
  Libreria LiquidCrystal - Hola mundo
 
 Demuestra el uso de un display LCD de 16x2. La libreria funciona con
 todos los display LCD compatibles con Hitachi HD44780. Hay muchos 
 disponibles y normalmente los reconoces porque tienen una interfaz
 de 16 pines.
 
 Este sketch imprime "Hola mundo!" en la pantalla y muestra el tiempo
 desde el ultimo reinicio.
 
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

#if defined(ARDUINO) && ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#define BITS_FOUR

#ifdef BITS_EIGHT
// definir un par de macros para que sea mas sencillo modificar en el futuro
#define LCD_RS 9
#define LCD_RW 10
#define LCD_EN 8

#define LCD_D0 0
#define LCD_D1 1
#define LCD_D2 2
#define LCD_D3 3
#define LCD_D4 4
#define LCD_D5 5
#define LCD_D6 6
#define LCD_D7 7

LiquidCrystal lcd(LCD_RS, LCD_RW, LCD_EN, 
  LCD_D0, LCD_D1, LCD_D2, LCD_D3, LCD_D4, LCD_D5, LCD_D6, LCD_D7); 

#elif defined BITS_FOUR
#define LCD_RS 7
#define LCD_EN 6

#define LCD_D4 5
#define LCD_D5 4
#define LCD_D6 3
#define LCD_D7 2

LiquidCrystal lcd(LCD_RS, LCD_EN, LCD_D4, LCD_D5, LCD_D6, LCD_D7); 

#endif

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
}

void updateDisplay() {
  lcd.clear();
  lcd.setCursor(col, 0);
  lcd.print(texto);
  //lcd.print(col, DEC);
  //lcd.setCursor(10, 0);
  //lcd.print(order, DEC);
    
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
   delay(200);
   count++;
   if (count % 2 == 0)
     updateDisplay();
   lcd.setCursor(0, 1);
   //lcd.print(millis(), HEX);
   lcd.print(analogRead(0)*5000.0/1024);
   lcd.setCursor(6, 1);
   lcd.print("mV");
}
  
  // setar el cursor a la segunda linea, columna 0
  //lcd.setCursor(0, 1);
  // imprimir cantidad de segundos desde el inicio
  //lcd.print(millis()/1000);
  
//}

