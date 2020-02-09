#include <Event.h>
#include <Timer.h>
#include <FrequencyTimer2.h>
#include <LedControl.h>

#define CAR { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 0, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0}\
  }


#define SPACE { \
    {0, 0, 0, 0, 0,0,0,0}, \
    {0, 0, 0, 0, 0,0,0,0}, \
    {0, 0, 0, 0, 0,0,0,0}, \
    {0, 0, 0, 0, 0,0,0,0}, \
    {0, 0, 0, 0, 0,0,0,0}, \
    {0, 0, 0, 0, 0,0,0,0}, \
    {0, 0, 0, 0, 0,0,0,0}\
  }

#define G { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 1, 1, 1, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}\
  }

#define THREE { \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 1, 0, 0}, \
    {0, 0, 1, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 0, 1, 1, 1, 0}, \
    {0, 0, 1, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 1, 1, 1, 0, 0}, \
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
    {0, 0, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 0, 0}, \
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
    {0, 0, 1, 1, 1, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 1, 1, 1, 0, 0}, \
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
    {0, 0, 1, 1, 1, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 1, 1, 1, 0, 0}, \
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
    {0, 0, 1, 1, 1, 1, 0, 0}, \
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
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}\
  }

int columnas[8] = {0, 21, 2, 3, 4, 5, 6, 7};
int filas[8] = {15, 14, 13, 12, 11, 10, 9, 8};

int matriz[16][8];

const int caracteres = 22;
byte oracion[caracteres][8][8] = { G , THREE, GUION , S , E , C , C , I , O , N , A , GUION , P , R , A , C , T , I , C , A , UNO , SPACE};
//----------------------------------------- DESPLAZAMIENTO ---------------------------------------------------
int letraActual = 0;
int lineaActual = 0;
/**
 * 0: Abajo -> Arriba
 * 1: Arriba->Abajo
 */
int flagDesplazamiento = 0; 
int oldDesplazamiento = 0; // Almacenara el anterior estado


//para los enemigos
long randompos;

// para el boton
unsigned long time_init; //tiempo desde que el arduino comienza a iniciar /current
unsigned long time_last; // ultimo tiempo de la lectura
const int intervalo_button = 50;
int estado_prev = LOW;    //estado previo stateprevius
unsigned long time_press; //longopress
unsigned long duracion;
bool estate_button = false;
unsigned long min_time = 1500;  // 3 segundos

LedControl lc = LedControl(16, 18, 17, 1);

//--------------------------------------------------- HILOS ---------------------
Timer timer1;
Timer timer2;


void setup() {
  Serial.begin(9600);
  //---------------------------------------- SETEAMOS LOS PINES
  for (int i = 0; i  < 16; i++) pinMode(i, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(19, INPUT);

  pinMode(A0,INPUT); //-------------- SWITCH PARA CAMBIAR ORIENTACION

  clearLeds(); //------------------------- Si se inicia de nuevo entonces limpiaremos la matriz de leds


  lc.shutdown(0, false);
  //Intensidad de los les de la matriz con modulo
  lc.setIntensity(0, 8);
  //Limpiamos la matriz con modulo
  lc.clearDisplay(0);
  //hasta aqui


  timer2.every(150, tipoDesplazamiento, 0); //------------------------- Este tiempo dictara la velocidad en la que se mostraran las figuras/letras
  timer1.every(5, game, 0); //--------------------------------------- Hilo para el resto del juego

  //Inicializamos la comunicación serial
   //Serial.begin(#numero);
  //randomEnemigo();
  //Establecemos la semilla en un pin analogico (Cada vez que se juegue las posiciones de los enemigos seran diferentes para cada inicio)
  //randomSeed(analogRead(A0));
}

void loop() {
  time_init = millis();
  timer1.update();
  timer2.update();
}


/**
   METODO PRINCIPAL DEL JUEGO
*/
void game() {
  verificarOrientacion();
  Estado_Boton();
  showMatrizModulo();
  showMatrizSinModulo();
  
}


/**
 * METODO QUE OBTENDRA EL VALOR
 * DEL SWITCH QUE DIRIGIRA
 * LA ORIENTACION
 */
void verificarOrientacion(){
  int estado = digitalRead(A0);
  if(estado == 1){
    flagDesplazamiento = 1;
    if(flagDesplazamiento != oldDesplazamiento){
      lineaActual = 7;
      oldDesplazamiento = 1;
    }
  }else{
    flagDesplazamiento = 0;
    if(flagDesplazamiento != oldDesplazamiento){
      lineaActual = 0;
      oldDesplazamiento = 0;
    }
  }
}


/**
 * METODO QUE SE ENCARGARA DE VERIFICAR LA FLAG
 * 
 */
void tipoDesplazamiento(){
  if(flagDesplazamiento == 0) desplazarLetra();
  else desplazarLetraInversa();
}
/**
   METODO QUE PONDRA LA MATRIZ EN 0'S
*/
void clearLeds()
{
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 8; j++) {
      matriz[i][j] = 0;
    }

  }

}

/**
   METODO QUE SE ENCARGARA
   DE IR A LA SIGUIENTE LETRA
   ABAJO -> ARRIBA
*/
void desplazarLetra()
{

  //------ A la matriz actual, movemos los datos ya en ella 1 posicion
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 8; j++) {
      if (i + 1 > 15) matriz[i][j] = matriz[0][j];
      else matriz[i][j] = matriz[i + 1][j];
    }

  }

  for (int i = 0; i < 8; i++) {
    matriz[15][i] = oracion[letraActual][lineaActual][i];

  }

  lineaActual++;
  if (lineaActual > 7) {
    lineaActual = 0;
    letraActual = (letraActual + 1 >= caracteres) ? 0 : letraActual + 1;
  }
}



/**
   METODO QUE SE ENCARGARA
   DE IR A LA SIGUIENTE LETRA
   ARRIBA -> ABAJO
*/
void desplazarLetraInversa()
{

  //------ A la matriz actual, movemos los datos ya en ella 1 posicion
  for (int i = 15; i > -1; i--) {
    for (int j = 0; j < 8; j++) {
      if (i - 1 < 0) matriz[i][j] = matriz[15][j];
      else matriz[i][j] = matriz[i - 1][j];
    }

  }

  for (int i = 0; i < 8; i++) {
    matriz[0][i] = oracion[letraActual][lineaActual][i];

  }

  lineaActual--;
  if (lineaActual < 0) {
    lineaActual = 7;
    letraActual = (letraActual + 1 >= caracteres) ? 0 : letraActual + 1;
  }
}

/**
   METODO QUE MOSTRARA LO QUE ESTE DENTRO DE LA MATRIZ ACTUAL
   DESDE LAS POSICIONES 8-15
   ABAJO -> ARRIBA
*/
void showMatrizModulo() {
  for (int j = 0; j < 8; j++) {

    for (int i = 0; i < 8; i++) {
      //------------------- MATRIZ INFERIOR
      if (matriz[i+8][j] == 1) lc.setLed(0, j, i, true);
      else lc.setLed(0, j, i, false);
      
    }
  
  }
}




/**
   METODO QUE MOSTRARA LO QUE ESTE DENTRO DE LA MATRIZ ACTUAL
   DESDE LAS POSICIONES 0-7
*/
void showMatrizSinModulo() {

  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++){
      if(matriz[i+1][j] == 1) digitalWrite(filas[j],LOW);
      else digitalWrite(filas[j],HIGH);
    }
    digitalWrite(columnas[i], HIGH);
    delay(1);
    digitalWrite(columnas[i], LOW);
  }
  
}



/*
   metodo para ver cuando se presiona el boton 3 seg y cuando se presiona rapidamente
*/
void Estado_Boton() {
  if (time_init - time_last > intervalo_button) {
    int estado = digitalRead(19);

    if (estado == HIGH && estado_prev == LOW && !estate_button) {
      time_press = time_init;
      estado_prev = HIGH;
    }
    duracion = time_init - time_press;

    if (estado == HIGH && !estate_button && duracion >= min_time) {
      estate_button = true;
      digitalWrite(20, HIGH); // enciende la led cuando se presiona durante 3 seg
    }
    if (estado == LOW && estado_prev == HIGH) {
      estado_prev = LOW;
      estate_button = false;
      digitalWrite(20, LOW); // apaga la led cuando se deja de presionar el boton
      if (!estate_button && duracion < min_time) {
        //---aqui iria para pausar ya que este requiere una solo push corto del boton
      }
    }
    time_last = time_init;
  }

}

// Metodo para generar enemigos random 0=izquierda, 1=centro y 2=derecha !*Se tiene que probar*!
void randomEnemigo(){
  //Genera un numero aleatorio entre 0 y 2
  randompos = random(0,2);
  
  //Escribe el numero aleatorio por el puerto serie
  Serial.print("El numero aleatorio es = ");
  Serial.println(randompos);
 
  //Esperamos 1 segundo para repetir
  delay(1000);
  }
