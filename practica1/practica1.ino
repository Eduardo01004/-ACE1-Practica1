#include <FrequencyTimer2.h>
#include <LedControl.h>
#define SPACE { \
    {0, 0, 0, 0, 0,0,0,0}, \
    {0, 0, 0, 0, 0,0,0,0}, \
    {0, 0, 0, 0, 0,0,0,0}, \
    {0, 0, 0, 0, 0,0,0,0}, \
    {0, 0, 0, 0, 0,0,0,0}, \
    {0, 0, 0, 0, 0,0,0,0}, \
    {0, 0, 0, 0, 0,0,0,0}\
  }

#define H { \
    {0, 0, 0, 0, 0,0,0,0}, \
    {1, 1, 0, 0, 0,0,1,1}, \
    {1, 1, 0, 0, 0,0,1,1}, \
    {1, 1, 0, 1, 1,1,1,1}, \
    {1, 1, 0, 1, 1,1,1,1}, \
    {1, 1, 0, 0, 0,0,1,1}, \
    {1, 1, 0, 0, 0,0,1,1}, \
    {1, 0, 0, 0, 0,0,0,0}\
  }


#define O { \
    {1, 1, 1, 1, 1,1,1,1}, \
    {1, 1, 1, 1, 1,1,1,1}, \
    {1, 1, 0, 0, 0, 0, 1, 1}, \
    {1, 1, 0, 0, 0, 0, 1, 1}, \
    {1, 1, 0, 0, 0, 0, 1, 1}, \
    {1, 1, 0, 0, 0, 0, 1, 1}, \
    {1, 1, 1, 1, 1, 1, 1, 1}, \
    {1, 1, 1, 1, 1, 1, 1, 1}\
  }



int columnas[8] = {0, 1, 2, 3, 4, 5, 6, 7};
int filas[8] = {15, 14, 13, 12, 11, 10, 9, 8};
int col = 0;
int led[8][8];


const int caracteres = 4;
byte oracion[caracteres][8][8] = { SPACE, H , O, SPACE};
int letraActual = 0;

LedControl lc = LedControl(16, 18, 17, 1);
void setup() {
  for (int i = 0; i  < 16; i++) pinMode(i, OUTPUT);
  for (int i = 0; i  < 16; i++) digitalWrite(columnas[i], LOW);

  clearLeds(); //------------------------- Si se inicia de nuevo entonces limpiaremos la matriz de leds
  FrequencyTimer2::disable(); //-------------------------------------- Si hay alguno ya iniciado lo quitamos
  FrequencyTimer2::setPeriod(3500); //-------------------------------- Intervalor en la que se refrescara la letra
  FrequencyTimer2::setOnOverflow(display); //---------------------- Metodo que se encargara de mostrar la letra

  setLetra(letraActual);
  lc.shutdown(0, false);

  //Set a medium brightness for the LEDs
  lc.setIntensity(0, 8);

  //Clear the display
  lc.clearDisplay(0);

}

void loop() {
  letraActual = ++letraActual % 3; //------------------- Por cada vez que se repita iremos a la siguiente letra, uso modular para regresar a 0 cuando termine las letras
  desplazarLetra();

}

/**
   METODO QUE PONDRA LA MATRIZ EN 0'S
*/
void clearLeds()
{
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      led[i][j] = 0;
    }

  }

}

/**
   METODO QUE SE ENCARGARA
   DE IR A LA SIGUIENTE LETRA
*/
void desplazarLetra()
{

  //------ A la matriz actual, movemos los datos ya en ella 1 posicion

  for (int n = 0; n < 8; n++) {
    // Clear display array
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        led[i][j] = led[i][j + 1];
      }

    }

    //---------------------- LLenamos en la ultima posicion de la matriz la siguiente fila de la letra actual
    for (int i = 0; i < 8; i++) {
      led[i][7] = oracion[letraActual][n][i];
      delay(5); // Este tiempo es el que se cambiara dependiendo la velocidad que se quiera la palabra
    }
  }
}

/**
   METODO QUE MOSTRARA LO QUE ESTE DENTRO DE LA MATRIZ ACTUAL
*/
void display() {
  digitalWrite(columnas[col], LOW);
  col++;
  
  if (col == 8) col = 0;
  for (int i = 0; i < 8; i++) {
  
    if (led[col][i] == 1) {
      lc.setLed(0, col, i, true);
      digitalWrite(filas[i], LOW);

    }
    else {
      digitalWrite(filas[i], HIGH);
      lc.setLed(0, col, i, false);
      
    }
   

  }
  digitalWrite(columnas[col], HIGH);
  delay(5);
}


/**
   METODO QUE SE ENCARGARA DE MANEJAR
   QUE LETRA ES LA ACTUAL
   @param x, indice de la letra a asignar
*/
void setLetra(int x) {
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      led[i][j] = oracion[x][j][i];
    }
  }
}
