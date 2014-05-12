const byte fils = 4; 
const byte cols = 4;

#if 0
byte filsPins[fils] = {0, 1, 2, 3}; // conecta los pines de las filas
byte colsPins[cols] = {4, 5, 6, 7}; // conecta las columnas
#else
byte colsPins[fils] = {0, 1, 2, 3}; // conecta los pines de las filas
byte filsPins[cols] = {4, 5, 6, 7}; // conecta las columnas
#endif

#define D1 1
#define D2 2
#define D3 4
#define D4 8
#define D5 16
#define D6 32

byte keymap[fils][cols] = {
  {D1,          D1|D2,       D1|D3,       D1|D2|D3 },
  {D1|D4,       D1|D4|D2,    D1|D4|D3,    D1|D4|D2|D3},
  {D1|D5,       D1|D5|D2,    D1|D5|D3,    D1|D5|D2|D3},
  {D1|D5|D4,    D1|D5|D4|D2, D1|D5|D4|D3, D1|D5|D4|D3|D2},
};

void setup()
{
  int i;
  
  // usar algunos pines para mostrar la salida en binario
  for (i = 8 ; i < 14; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
  
}

int escanearTeclas() {
  byte f, c, v;
  int out = 0;
  
  // reinicializar pines de las filas, permitir multiplexar entradas
  for ( f = 0 ; f < fils ; f++ ) {
    pinMode(filsPins[f], INPUT_PULLUP);
  }
    
  for ( c = 0 ; c < cols ; c++ ) {
    pinMode(colsPins[c], OUTPUT);
    digitalWrite(colsPins[c], LOW); // iniciar pulso de columa
    for ( f = 0 ; f < fils ; f++ ) {
      v = digitalRead(filsPins[f]);
      if ( v == 0)
        out = keymap[f][c];
    }
    // poner en alta impedancia
    digitalWrite(colsPins[c], HIGH);
    pinMode(colsPins[c], INPUT);
  }
  
  return out;
}

void loop()
{
  int i, j;
  int status = escanearTeclas();
  
  digitalWrite(8, (status & D1) == 0);
  digitalWrite(9, (status & D2) == 0);
  digitalWrite(10,(status & D3) == 0);
  digitalWrite(11,(status & D4) == 0);
  digitalWrite(12,(status & D5) == 0);
  digitalWrite(13,(status & D6) == 0);

}

