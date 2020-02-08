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
    {0, 1, 1, 0, 0,1,1,0}, \
    {0, 1, 1, 0, 0,1,1,0}, \
    {0, 1, 1, 1, 1,1,1,0}, \
    {0, 1, 1, 1, 1,1,1,0}, \
    {0, 1, 1, 0, 0,1,1,0}, \
    {0, 1, 1, 0, 0,1,1,0}, \
    {0, 0, 0, 0, 0,0,0,0}\
  }
  
  #define G { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}\
  }

  #define THREE { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 0, 0, 0, 0, 1, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 0, 0, 0, 0, 1, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}\
  }

  #define GUION { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}\
  }
  #define S { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}\
  }

  #define E{ \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}\
  }

  #define C { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}\
  }

  #define I { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}\
  }

  #define O { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 1, 0, 0, 1, 1, 0}, \
    {0, 1, 1, 0, 0, 1, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}\
  }
  
  #define N { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 1, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 1, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}\
  }

  #define A { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}\
  }

  #define P { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}\
  }

  #define R { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}\
  }

  #define T { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}\
  }

  #define UNO { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 0, 0, 0}, \
    {0, 1, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}\
  }

int columnas[8] = {0, 1, 2, 3, 4, 5, 6, 7};
int filas[8] = {15, 14, 13, 12, 11, 10, 9, 8};
int col = 0;

int matriz[8][16];

const int caracteres = 23;
byte oracion[caracteres][8][8] = { SPACE, G , THREE, GUION , S , E , C , C , I , O , N , A , GUION , P , R , A , C , T , I , C , A , UNO , SPACE};
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
  //Intensidad de los les de la matriz con modulo
  lc.setIntensity(0, 8);
  //Limpiamos la matriz con modulo
  lc.clearDisplay(0);

}

void loop() {
  letraActual = (letraActual + 1 >= caracteres) ? 0 : letraActual + 1; //------------------- Ciclo segun la cantidad de letras que haya -------------------------------
  desplazarLetra();

}

/**
   METODO QUE PONDRA LA MATRIZ EN 0'S
*/
void clearLeds()
{
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 16; j++) {
      matriz[i][j] = 0;
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
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 16; j++) {
        matriz[i][j] = matriz[i][j + 1];
      }

    }

    //---------------------- LLenamos en la ultima posicion de la matriz la siguiente fila de la letra actual
    int y = 0;
    for (int i = 0; i < 8; i++) {
      matriz[y][15] = oracion[letraActual][n][i];
      y = (y + 1 > 7) ? 0 : y + 1; //--------- Si es mayor a 8 se regresa a 0 ya que cada figura es de 8x8
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

  //--------------- MATRIZ SUPERIOR -----------------------------------
    if (matriz[col][i] == 1) digitalWrite(filas[i], LOW);
    else digitalWrite(filas[i], HIGH);
    
  //------------------- MATRIZ INFERIOR
   if (matriz[col][i+8] == 1) lc.setLed(0,col,i,true);
   else lc.setLed(0,col,i,false);

   

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
      matriz[i][j] = oracion[x][j][i];
    }
  }
}
