#include <Event.h>
#include <Timer.h>
#include <FrequencyTimer2.h>
#include <LedControl.h>
#define SPACE                     \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {                             \
                                  0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

#define G                         \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 0, 0}, \
    {                             \
                                  0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

#define THREE                     \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
    {0, 0, 1, 1, 1, 1, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 1, 1, 1, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 1, 1, 1, 1, 0}, \
    {                             \
                                  0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

#define GUION                     \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 0, 0}, \
    {                             \
                                  0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }
#define S                         \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
    {0, 0, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 1, 0, 0}, \
    {0, 0, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 0, 0}, \
    {                             \
                                  0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

#define E                         \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {                             \
                                  0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

#define C                         \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
    {0, 0, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 1, 1, 0}, \
    {                             \
                                  0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

#define I                         \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {                             \
                                  0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

#define O                         \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
    {0, 0, 1, 1, 1, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 0, 1, 1, 1, 1, 0, 0}, \
    {                             \
                                  0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

#define N                         \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 1, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 1, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {                             \
                                  0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

#define A                         \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
    {0, 0, 1, 1, 1, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {                             \
                                  0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

#define P                         \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 0, 0}, \
    {                             \
                                  0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

#define R                         \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
    {0, 1, 1, 1, 1, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 0, 0, 0, 0, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 1, 0, 0}, \
    {0, 1, 0, 0, 0, 1, 0, 0}, \
    {                             \
                                  0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

#define T                         \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {                             \
                                  0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

#define UNO                       \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 1, 1, 1, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 0, 0, 1, 1, 0, 0, 0}, \
    {0, 1, 1, 1, 1, 1, 1, 0}, \
    {                             \
                                  0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

/**
   -------------------------------------------------------------------------------------------------------------------------------------------------------------------
    ---------------------------------------------------------- ESTRUCTURAS PARA ENEMIGOS    --------------------------------------------------------------------------
    -------------------------------------------------------------------------------------------------------------------------------------------------------------------
*/



//----------------------Contador Aescendente
int contador_0[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 1, 1, 0, 0, 0, 1, 0},
  {0, 1, 0, 1, 0, 0, 1, 0},
  {0, 1, 0, 0, 1, 0, 1, 0},
  {0, 1, 0, 0, 0, 1, 1, 0},
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

int contador_1[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 1, 1, 1, 0, 0, 0},
  {0, 1, 1, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 0, 0, 1, 1, 0, 0, 0},
  {0, 1, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

int contador_2[8][8] = {
  {0, 0, 0, 1, 1, 1, 0, 0},
  {0, 0, 1, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 1, 1, 1, 1, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 1, 0}
};

int contador_3[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 0, 0}
};

int contador_4[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0}
};

int contador_5[8][8] = {
  {0, 0, 0, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 1, 0}
};

int contador_6[8][8] = {
  {0, 0, 1, 1, 1, 1, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0, 0, 0},
  {0, 0, 1, 1, 1, 1, 1, 0},
  {0, 0, 1, 0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0, 0, 1, 0},
  {0, 0, 1, 1, 1, 1, 1, 0}
};
int contador_7[8][8] = {
  {0, 0, 1, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0},
  {0, 0, 0, 0, 1, 0, 0, 0}
};
int contador_8[8][8] = {
  {0, 0, 0, 1, 1, 1, 0, 0},
  {0, 0, 1, 0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0, 0, 1, 0},
  {0, 0, 0, 1, 1, 1, 0, 0},
  {0, 0, 1, 0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0, 0, 1, 0},
  {0, 0, 0, 1, 1, 1, 0, 0}
};

int contador_9[8][8] =
{
  {0, 0, 0, 1, 1, 1, 0, 0},
  {0, 0, 1, 0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0, 0, 1, 0},
  {0, 0, 0, 1, 1, 1, 1, 0},
  {0, 0, 0, 0, 0, 0, 1, 0},
  {0, 0, 1, 0, 0, 0, 1, 0},
  {0, 0, 0, 1, 1, 1, 0, 0}
};

int fase_inicial = 0; // variable para el switch de control
unsigned long duration;

unsigned long tiempo_cronometro = 0;
unsigned long tiempo_cronometro2 = 0;
bool flag_cronometro = false;

/*-------------------------------------------------------------TIEMPO DE VELOCIDAD PARA LETRAS-------------------------------*/
unsigned long tiempo_despla = 0;
unsigned long tiempo_despla2 = 0;
int segundos = 0;
int velocidad = 150;

int columnas[8] = {22, 21, 2, 3, 4, 5, 6, 7};
int filas[8] = {15,14,23,12,11,10,9,8};
int matriz[16][8];
int backup[16][8];

byte oracion[22][8][8] = {G, THREE, GUION, S, E, C, C, I, O, N, A, GUION, P, R, A, C, T, I, C, A, UNO, SPACE};
//----------------------------------------- DESPLAZAMIENTO ---------------------------------------------------
int letraActual = 0;
int lineaActual = 0;

//-------------------------------------------- ENEMIGOS -------------------------------------------------------------------------------------
int enemigos[25][5][8];

//---------------------------------------------------------------------- JUGADOR ---------------------------------------------------------------
int posX = 4;

//-------------------------------------------- DIFICULTAD ------------------------------------------------------------------------------------
unsigned long tiempo_dificultad = 0;
unsigned long tiempo_dificultad2 = 0;

//---------------------------------------- ESTADOS ----------------------------------------------------------------------------------------
int flagEstado = 0; //---- 0 -> MENSAJE A JUEGO, 1-> JUEGO A MENSAJE

/**
   0: Abajo -> Arriba
   1: Arriba->Abajo
*/
int flagDesplazamiento = 0;
int oldDesplazamiento = 0; // Almacenara el anterior estado



//--------------------------------- VARIABLES PARA EL BOTON-------------------------------------------
unsigned long time_init; //tiempo desde que el arduino comienza a iniciar /current
unsigned long time_last; // ultimo tiempo de la lectura
const int intervalo_button = 50;
int estado_prev = LOW;    //estado previo stateprevius
unsigned long time_press; //longopress
unsigned long duracion;
bool estate_button = false;
unsigned long min_time = 1400; // 3 segundos

LedControl lc = LedControl(16, 18, 17, 1);

//--------------------------------------------------- HILOS ---------------------
Timer timer1;
Timer timer2;
Timer timer3;

void setup()
{
  tiempo_cronometro = millis();
  tiempo_despla = millis();

  Serial.begin(9600);
  //---------------------------------------- SETEAMOS LOS PINES
  for (int i = 0; i < 16; i++)
    pinMode(i, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(A1, INPUT); //----------------boton

  pinMode(A0, INPUT); //-------------- SWITCH PARA CAMBIAR ORIENTACION

  pinMode(A2, INPUT); // ------------- POTENCIOMETRO

  pinMode(A3,INPUT); //----------------- MOVER IZQUIERDA
  pinMode(A4,INPUT); //----------------- MOVER DERECHA

  

  clearLeds(); //------------------------- Si se inicia de nuevo entonces limpiaremos la matriz de leds

  lc.shutdown(0, false);
  //Intensidad de los les de la matriz con modulo
  lc.setIntensity(0, 8);
  //Limpiamos la matriz con modulo
  lc.clearDisplay(0);
  //hasta aqui

  timer2.every(5, tipoDesplazamiento, 0); //------------------------- Este tiempo dictara la velocidad en la que se mostraran las figuras/letras
  timer1.every(5, game, 0);               //--------------------------------------- Hilo para el resto del juego
  timer3.every(85,verificarPosicion,0);

  randomSeed(analogRead(A13)); // Semilla para los numeros aleatorios


}

void loop()
{
  time_init = millis();
  timer1.update();
  timer2.update();
  timer3.update();
  int resultado = map(analogRead(A2),0,1023,0,100);
  if(fase_inicial == 0) velocidad = 4.4 * resultado + 60;
  
  Serial.print(resultado);
  Serial.print("_");
  Serial.println(velocidad);
  



}

/*
   METODO QUE SE ENCARGARA DE LLENAR EL ARREGLO ENEMIGOS
   YA SEA DE ENEMIGOS O DE ESPACIOS EN BLANCO
*/
void generarEnemigos()
{
  int left[5][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
  };

  int center[5][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
  };

  int enemigo_vacio[5][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
  };

  int right[5][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}
  };

  for (int i = 0; i < 25; i++)
  {
    /*
       Si el numero random es menor a la probabilidad entonces es un enemigo
       de lo contrario se tomara como espacio vacio
    */
    long numero = random(0, 10);
    if (numero <= 8)
    {
      /*NUMERO:
         0 -> Enemigo izquierdo
         1 -> Enemigo derecho
         2 -> Enemigo centro
      */
      long lado = random(0, 2);
      if (lado == 0)
        guardarEnemigo(i, left);
      else if (lado == 1)
        guardarEnemigo(i, right);
      else
        guardarEnemigo(i, center);
    }
    else
      guardarEnemigo(i, enemigo_vacio);
  }
}

/*
  METODO QUE SE ENCARGARA DE GUARDAR UN
  ENEMIGO/ESPACIO EN CIERTA POSICION
*/
void guardarEnemigo(int index, int objeto[5][8]) {
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 8; j++) {
      enemigos[index][i][j] = objeto[i][j];
    }
  }
}


/**
   METODO PRINCIPAL DEL JUEGO
*/
void game()
{
  verificarOrientacion();
  Estado_Boton();
  showMatrizModulo();
  showMatrizSinModulo();
  if(fase_inicial == 3){
    lc.setLed(0, 7, posX, true);
  }
  Temporizador();
  controlarDificultad();
  if(fase_inicial == 3) colision();
}

/**
 * METODO QUE SIRVE PARA
 * MOVER AL JUGADOR
 */
void verificarPosicion(){
  int n = digitalRead(A3);
  int n2 = digitalRead(A4);
  if(n == 1) posX++;
  else if(n2 == 1) posX--;
}


/**
   METODO QUE SE ENCARGARA DE VERIFICAR LA FLAG
*/

void tipoDesplazamiento()
{
  switch (fase_inicial)
  {
    case 0:
      tiempo_despla2 = millis();
      if (tiempo_despla2 > (tiempo_despla + velocidad))
      {

        if (flagDesplazamiento == 0)
          desplazarLetra();
        else
          desplazarLetraInversa();

        tiempo_despla = millis();
      }
      break;
    case 1:
      Contador();
      break;

    case 2:
      Cronometro();
      break;

    case 3:
      tiempo_despla2 = millis();
      if (tiempo_despla2 > (tiempo_despla + velocidad))
      {
        desplazarEnemigo();
        tiempo_despla = millis();
      }
      break;

    case 4:
      Cronometro();
    break;
  }
}

/*
   METODO ENCARGADO DE
   MOVER LOS ENEMIGOS
*/
void desplazarEnemigo()
{

  for (int i = 15; i > -1; i--)
  {
    for (int j = 0; j < 8; j++)
    {
      if (i - 1 < 0)
        matriz[i][j] = matriz[15][j];
      else
        matriz[i][j] = matriz[i - 1][j];
    }
  }

  for (int i = 0; i < 8; i++)
  {
    matriz[0][i] = enemigos[letraActual][lineaActual][i];
  }

  lineaActual--;
  if (lineaActual < 0)
  {
    lineaActual = 4;
    letraActual = (letraActual + 1 >= 25) ? 0 : letraActual + 1;
  }
}



/**
   METODO QUE OBTENDRA EL VALOR
   DEL SWITCH QUE DIRIGIRA
   LA ORIENTACION
*/

void verificarOrientacion()
{
  int estado = digitalRead(A0);
  if (estado == 1)
  {
    flagDesplazamiento = 1;
    if (flagDesplazamiento != oldDesplazamiento)
    {
      lineaActual = 7;
      oldDesplazamiento = 1;
    }
  }
  else
  {
    flagDesplazamiento = 0;
    if (flagDesplazamiento != oldDesplazamiento)
    {
      lineaActual = 0;
      oldDesplazamiento = 0;
    }
  }
}

/**
   METODO QUE PONDRA LA MATRIZ EN 0'S
*/
void clearLeds()
{
  for (int i = 0; i < 16; i++)
  {
    for (int j = 0; j < 8; j++)
    {
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
  for (int i = 0; i < 16; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (i + 1 > 15)
        matriz[i][j] = matriz[0][j];
      else
        matriz[i][j] = matriz[i + 1][j];
    }
  }

  for (int i = 0; i < 8; i++)
  {
    matriz[15][i] = oracion[letraActual][lineaActual][i];
  }

  lineaActual++;
  if (lineaActual > 7)
  {
    lineaActual = 0;
    letraActual = (letraActual + 1 >= 22) ? 0 : letraActual + 1;
  }
}

/*
   Metodo que se usa para contar del 0 al 3
*/
void Contador()
{
  duration = duracion-150; //-- ese -150 sirve para quitar el pequeno retraso al iniciar
  if ((duration / 1000) >= 1)
    Llenar_Matriz(contador_3, contador_3);

  if ((duration / 1000) >= 2)
    Llenar_Matriz(contador_2, contador_2);

  if ((duration / 1000) >= 3)
    Llenar_Matriz(contador_1, contador_1);

  if ((duration / 1000) >= 4)
  {
    //------------------------------ JUEGO -> MENSAJE ----------------------------------
    if (flagEstado == 1) {
      fase_inicial = 0;
      clearLeds();
      letraActual = 0;
      velocidad = 150;
      lineaActual = (flagDesplazamiento == 1) ? 7 : 0;
      flag_cronometro = false; //dejamos de contar los segundos
      segundos = 0; // volvemos a setear nuestro contador de segundos
    }
    //----------------------------- MENSAJE -> JUEGO ---------------------------------
    else {
      clearLeds();
      generarEnemigos();
      letraActual = 0;
      fase_inicial = 3; //aqui iria que empieze el juego
      velocidad = 500;
      lineaActual = 4;
      flag_cronometro = true; //empezamos a contar desde que empezamos a jugar
    }

  }
}
/*
   Metodo que se encarga de llenar la matariz con los numeros
*/

void Llenar_Matriz(int decena[16][8], int unidad[8][8])
{
  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      matriz[i][j] = decena[i - 1][j]; // muestra el cero constante en la matriz sin modulo
    }
  }
  for (int a = 8; a < 16; a++)
  {
    for (int b = 0; b < 8; b++)
    {
      matriz[a][b] = unidad[a - 9][b]; // muestra los numeros 1-2-3 en la matriz con modulo estos 3 for de abajo
    }
  }
}

/*
   Metodo que se encarga de contar hasta 99
*/
void Cronometro()
{
  // if estado == 2 juego
  int matriz_temp1[8][8];
  int matriz_temp2[8][8];
  int matriz_temp3[8][8];
  int matriz_temp4[8][8];
  int decena = segundos / 10;
  int unidad = segundos % 10;

  if (segundos >= 99) {
    Clonar(matriz_temp3, contador_9);
    Clonar(matriz_temp4, contador_9);
    Llenar_Matriz(matriz_temp4, matriz_temp3);
  } else {
    if (decena == 0 ) Clonar(matriz_temp1 , contador_0);
    if (decena == 1) Clonar(matriz_temp1 , contador_1);
    if (decena == 2) Clonar(matriz_temp1 , contador_2);
    if (decena == 3) Clonar(matriz_temp1 , contador_3);
    if (decena == 4) Clonar(matriz_temp1 , contador_4);
    if (decena == 5) Clonar(matriz_temp1 , contador_5);
    if (decena == 6) Clonar(matriz_temp1 , contador_6);
    if (decena == 7) Clonar(matriz_temp1 , contador_7);
    if (decena == 8) Clonar(matriz_temp1 , contador_8);
    if (decena == 9) Clonar(matriz_temp1 , contador_9);
    if (unidad == 0) Clonar(matriz_temp2 , contador_0);
    if (unidad == 1) Clonar(matriz_temp2 , contador_1);
    if (unidad == 2) Clonar(matriz_temp2 , contador_2);
    if (unidad == 3) Clonar(matriz_temp2 , contador_3);
    if (unidad == 4) Clonar(matriz_temp2 , contador_4);
    if (unidad == 5) Clonar(matriz_temp2 , contador_5);
    if (unidad == 6) Clonar(matriz_temp2 , contador_6);
    if (unidad == 7) Clonar(matriz_temp2 , contador_7);
    if (unidad == 8) Clonar(matriz_temp2 , contador_8);
    if (unidad == 9) Clonar(matriz_temp2 , contador_9);
    Llenar_Matriz(matriz_temp1, matriz_temp2);
  }

}
/*
   Metodo Que se encarga de clonar una matriz
*/

void Clonar(int matriz1[8][8], int matriz2[8][8])
{

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      matriz1[i][j] = matriz2[i][j];
    }
  }
}

/*
   Metodo que se Encarga de contar los segundos
*/
void Temporizador()
{
  tiempo_cronometro2 = millis();
  if (tiempo_cronometro2 > (tiempo_cronometro + 1000) && flag_cronometro == true)
  {
    tiempo_cronometro = millis();
    segundos++;
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
  for (int i = 15; i > -1; i--)
  {
    for (int j = 0; j < 8; j++)
    {
      if (i - 1 < 0)
        matriz[i][j] = matriz[15][j];
      else
        matriz[i][j] = matriz[i - 1][j];
    }
  }

  for (int i = 0; i < 8; i++)
  {
    matriz[0][i] = oracion[letraActual][lineaActual][i];
  }

  lineaActual--;
  if (lineaActual < 0)
  {
    lineaActual = 7;
    letraActual = (letraActual + 1 >= 22) ? 0 : letraActual + 1;
  }
}

/**
   METODO QUE MOSTRARA LO QUE ESTE DENTRO DE LA MATRIZ ACTUAL
   DESDE LAS POSICIONES 8-15
   ABAJO -> ARRIBA
*/
void showMatrizModulo()
{
  for (int j = 0; j < 8; j++)
  {

    for (int i = 0; i < 8; i++)
    {
      //------------------- MATRIZ INFERIOR
      if (matriz[i + 8][j] == 1)
        lc.setLed(0, i, j, true);
      else
        lc.setLed(0, i, j, false);
    }
  }
}

/**
   METODO QUE MOSTRARA LO QUE ESTE DENTRO DE LA MATRIZ ACTUAL
   DESDE LAS POSICIONES 0-7
*/
void showMatrizSinModulo()
{

  for (int i = 0; i < 8; i++)
  {
    for (int j = 0; j < 8; j++)
    {
      if (matriz[i][j] == 1)
        digitalWrite(filas[j], LOW);
      else
        digitalWrite(filas[j], HIGH);
    }
    digitalWrite(columnas[i], HIGH);
    delay(1);
    digitalWrite(columnas[i], LOW);
  }
}

/*
   metodo para ver cuando se presiona el boton 3 seg y cuando se presiona rapidamente
*/
void Estado_Boton()
{
  if (time_init - time_last > intervalo_button)
  {
    int estado = digitalRead(A1);

    if (estado == HIGH && estado_prev == LOW && !estate_button)
    {
      time_press = time_init;
      estado_prev = HIGH;
    }
    duracion = time_init - time_press;
    if (estado == HIGH && !estate_button && duracion >= min_time)
    {
      estate_button = true;
      //digitalWrite(20, HIGH); // enciende la led cuando se presiona durante 3 seg
      //-------------------------- ESTAMOS EN EL MENSAJE Y QUEREMOS IR AL JUEGO
      if (fase_inicial == 0) {
        flagEstado = 0;
        fase_inicial = 1;
      }
      //-------------------------- ESTAMOS EN EL JUEGO Y QUEREMOS IR AL MENSAJE
      else if (fase_inicial == 3) {
        fase_inicial = 1;
        flagEstado = 1;
      }
    }
    if (estado == LOW && estado_prev == HIGH)
    {
      estado_prev = LOW;
      estate_button = false;
      // apaga la led cuando se deja de presionar el boton
      digitalWrite(20, HIGH);

      if (!estate_button && duracion < min_time)
      {
        //---aqui iria para pausar ya que este requiere una solo push corto del boton
        if (fase_inicial == 3) {
          makeBackup();
          clearLeds();
          fase_inicial = 2;
          flag_cronometro = false;
        }
        else if (fase_inicial == 2) { // aqui iria el juego
          clearLeds();
          restoreBackup();
          fase_inicial = 3;
          flag_cronometro = true;
        }else if(fase_inicial == 4){
          clearLeds();
          flagEstado = 0;
          fase_inicial = 1;
          segundos = 0;
          
        }

      }
    }
    time_last = time_init;
  }
}

/*
   METODO QUE HARA UN BACKUP DE LA MATRIZ
   CUANDO ESTE EN PAUSA
*/
void makeBackup() {
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 8; j++) {
      backup[i][j] = matriz[i][j];
    }
  }
}

/*
   RESTAURARA LA ULTIMA COPIA REALIZADA DE
   LA MATRIZ
*/
void restoreBackup() {
  for (int i = 0; i < 16; i++) {
    for (int j = 0; j < 8; j++) {
      matriz[i][j] = backup[i][j];
    }
  }
}

/**
   METODO QUE SE ENCARGARA DE IR AUMENTANDO LA DIFICULTAD CADA 10s
*/
void controlarDificultad()
{
  tiempo_dificultad2 = millis();
  if (tiempo_dificultad2 > (tiempo_dificultad + 10000) && flag_cronometro == true )
  {
    tiempo_dificultad = millis();
    velocidad = (velocidad - 60 > 90) ? velocidad - 60 : 90;
  }
}

/**
 * METODO QUE SE ENCARGARA
 * DE VERIFICAR QUE EL JUGADOR
 * NO TOCA LAS ORILLAS
 * O A  OTRA NAVE
 */
void colision(){
  if(posX > 7 || posX < 0){
    clearLeds();
    fase_inicial = 4;
    posX = 4;
    flag_cronometro = false;
  }else{
    for(int i = 0; i < 16; i++){
      for(int j = 0; j < 8; j++){
        if(matriz[i][j] == 1 && posX == j && i == 15 ){
          clearLeds();
          fase_inicial = 4;
          posX = 4;
          flag_cronometro = false;
        }
      }
    }
  }
}
