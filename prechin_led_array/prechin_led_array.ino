static int val;

void setup()
{
  int i;
  
  // seteamos las columnas como salidas y las ponemos en bajo
  for (i = 8 ; i < 14; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }
  
  val = 8;
}

void loop()
{
  int i = 0;
  // actualizar los leds
  for (i = 8; i < 14; i++){
    if ( i >= val) {
      digitalWrite(i, HIGH); // logica negativa
    } else {
      digitalWrite(i, LOW);
    }
  }  
  
  val++;
  if (val > 0xf)
    val = 8;
    
  delay(100);
}
