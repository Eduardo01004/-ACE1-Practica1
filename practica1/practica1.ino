#include <Event.h>
#include <Timer.h>
#include <FrequencyTimer2.h>
#include <LedControl.h>

#define CERO                      \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
        {0, 0, 1, 1, 1, 1, 0, 0}, \
        {0, 1, 1, 0, 0, 0, 1, 0}, \
        {0, 1, 0, 1, 0, 0, 1, 0}, \
        {0, 1, 0, 0, 1, 0, 1, 0}, \
        {0, 1, 0, 0, 0, 1, 1, 0}, \
        {0, 0, 1, 1, 1, 1, 0, 0}, \
    {                             \
      0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

#define DOS                       \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
        {0, 0, 0, 1, 1, 1, 1, 0}, \
        {0, 0, 1, 0, 0, 0, 0, 0}, \
        {0, 0, 1, 1, 1, 1, 0, 0}, \
        {0, 0, 0, 0, 0, 0, 1, 0}, \
        {0, 0, 0, 0, 0, 0, 1, 0}, \
    {                             \
      0, 0, 1, 1, 1, 1, 1, 0      \
    }                             \
  }

#define NINE                      \
  {                               \
    {0, 0, 0, 1, 1, 1, 0, 0},     \
        {0, 0, 1, 0, 0, 0, 1, 0}, \
        {0, 0, 1, 0, 0, 0, 1, 0}, \
        {0, 0, 1, 1, 1, 1, 0, 0}, \
        {0, 0, 1, 0, 0, 0, 0, 0}, \
        {0, 0, 1, 0, 0, 0, 1, 0}, \
    {                             \
      0, 0, 0, 1, 1, 1, 0, 0      \
    }                             \
  }

#define OCHO                      \
  {                               \
    {0, 0, 0, 1, 1, 1, 0, 0},     \
        {0, 0, 1, 0, 0, 0, 1, 0}, \
        {0, 0, 1, 0, 0, 0, 1, 0}, \
        {0, 0, 0, 1, 1, 1, 0, 0}, \
        {0, 0, 1, 0, 0, 0, 1, 0}, \
        {0, 0, 1, 0, 0, 0, 1, 0}, \
    {                             \
      0, 0, 0, 1, 1, 1, 0, 0      \
    }                             \
  }

#define SEVEN                     \
  {                               \
    {0, 0, 1, 1, 1, 1, 1, 0},     \
        {0, 0, 1, 0, 0, 0, 0, 0}, \
        {0, 0, 1, 0, 0, 0, 0, 0}, \
        {0, 0, 0, 1, 0, 0, 0, 0}, \
        {0, 0, 0, 0, 1, 0, 0, 0}, \
        {0, 0, 0, 0, 1, 0, 0, 0}, \
    {                             \
      0, 0, 0, 0, 1, 0, 0, 0      \
    }                             \
  }

#define SIX                       \
  {                               \
    {0, 0, 0, 1, 1, 1, 1, 0},     \
        {0, 0, 0, 0, 0, 0, 1, 0}, \
        {0, 0, 0, 0, 0, 0, 1, 0}, \
        {0, 0, 1, 1, 1, 1, 1, 0}, \
        {0, 0, 1, 0, 0, 0, 1, 0}, \
        {0, 0, 1, 0, 0, 0, 1, 0}, \
    {                             \
      0, 0, 1, 1, 1, 1, 1, 0      \
    }                             \
  }

#define FIVE                      \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
        {0, 0, 1, 1, 1, 1, 1, 0}, \
        {0, 0, 0, 0, 0, 0, 1, 0}, \
        {0, 0, 1, 1, 1, 1, 1, 0}, \
        {0, 0, 1, 0, 0, 0, 0, 0}, \
        {0, 0, 1, 0, 0, 0, 0, 0}, \
    {                             \
      0, 0, 1, 1, 1, 1, 1, 0      \
    }                             \
  }

#define FOUR                      \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
        {0, 0, 1, 0, 0, 0, 1, 0}, \
        {0, 0, 1, 0, 0, 0, 1, 0}, \
        {0, 0, 1, 1, 1, 1, 1, 0}, \
        {0, 0, 1, 0, 0, 0, 0, 0}, \
        {0, 0, 1, 0, 0, 0, 0, 0}, \
    {                             \
      0, 0, 1, 0, 0, 0, 0, 0      \
    }                             \
  }

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
        {0, 0, 0, 0, 0, 0, 1, 0}, \
        {0, 1, 1, 1, 1, 0, 1, 0}, \
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
        {0, 0, 0, 1, 1, 1, 0, 0}, \
        {0, 0, 1, 0, 0, 0, 1, 0}, \
        {0, 0, 1, 0, 0, 0, 0, 0}, \
        {0, 0, 1, 1, 1, 0, 0, 0}, \
        {0, 0, 1, 0, 0, 0, 1, 0}, \
        {0, 0, 0, 1, 1, 1, 0, 0}, \
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
        {0, 1, 1, 1, 1, 1, 0, 0}, \
        {0, 0, 0, 0, 0, 0, 1, 0}, \
        {0, 0, 1, 1, 1, 1, 0, 0}, \
        {0, 1, 0, 0, 0, 0, 0, 0}, \
        {0, 1, 0, 0, 0, 0, 0, 0}, \
        {0, 0, 1, 1, 1, 1, 0, 0}, \
    {                             \
      0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

#define E                         \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
        {0, 1, 1, 1, 1, 1, 1, 0}, \
        {0, 0, 0, 0, 0, 0, 1, 0}, \
        {0, 0, 1, 1, 1, 1, 1, 0}, \
        {0, 0, 1, 1, 1, 1, 1, 0}, \
        {0, 0, 0, 0, 0, 0, 1, 0}, \
        {0, 1, 1, 1, 1, 1, 1, 0}, \
    {                             \
      0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

#define C                         \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
        {0, 0, 1, 1, 1, 1, 0, 0}, \
        {0, 1, 0, 0, 0, 0, 1, 0}, \
        {0, 0, 0, 0, 0, 0, 1, 0}, \
        {0, 0, 0, 0, 0, 0, 1, 0}, \
        {0, 1, 0, 0, 0, 0, 1, 0}, \
        {0, 0, 1, 1, 1, 1, 0, 0}, \
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
        {0, 1, 0, 0, 0, 1, 1, 0}, \
        {0, 1, 0, 0, 1, 0, 1, 0}, \
        {0, 1, 0, 1, 0, 0, 1, 0}, \
        {0, 1, 1, 0, 0, 0, 1, 0}, \
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
        {0, 0, 0, 0, 0, 0, 1, 0}, \
        {0, 0, 0, 0, 0, 0, 1, 0}, \
    {                             \
      0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

#define R                         \
  {                               \
    {0, 0, 0, 0, 0, 0, 0, 0},     \
        {0, 0, 1, 1, 1, 1, 1, 0}, \
        {0, 1, 0, 0, 0, 0, 1, 0}, \
        {0, 1, 0, 0, 0, 0, 1, 0}, \
        {0, 0, 1, 1, 1, 1, 1, 0}, \
        {0, 0, 1, 0, 0, 0, 1, 0}, \
        {0, 1, 0, 0, 0, 0, 1, 0}, \
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
        {0, 0, 0, 1, 1, 1, 0, 0}, \
        {0, 0, 0, 1, 1, 1, 1, 0}, \
        {0, 0, 0, 1, 1, 0, 0, 0}, \
        {0, 0, 0, 1, 1, 0, 0, 0}, \
        {0, 1, 1, 1, 1, 1, 1, 0}, \
    {                             \
      0, 0, 0, 0, 0, 0, 0, 0      \
    }                             \
  }

/**
 * -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 *  ---------------------------------------------------------- ESTRUCTURAS PARA ENEMIGOS    --------------------------------------------------------------------------
 *  -------------------------------------------------------------------------------------------------------------------------------------------------------------------
 * 
 */
int right[5][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}};

int left[5][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}};

int center[5][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}};

int enemigo_vacio[5][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0,0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}};

//----------------------Contador Aescendente
int contador_0[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}};

int contador_1[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 0, 0, 1, 1, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}};

int contador_2[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 1, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 1, 0}};

int contador_3[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 1, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 1, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0}};

int contador_4[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 1, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0}};

int contador_5[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 1, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 1, 1, 1, 1, 0}};

int contador_6[8][8] = {
    {0, 0, 0, 1, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 1, 0},
    {0, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 1, 1, 1, 1, 1, 0}};
int contador_7[8][8] = {
    {0, 0, 1, 1, 1, 1, 1, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0}};
int contador_8[8][8] = {
    {0, 0, 0, 1, 1, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 1, 1, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 1, 0, 0, 0, 1, 0},
    {0, 0, 0, 1, 1, 1, 0, 0}};

int contador_9[8][8] =
    {
        {0, 0, 0, 1, 1, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 1, 1, 1, 1, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 1, 0},
        {0, 0, 0, 1, 1, 1, 0, 0}};

int fase_inicial = 3; // variable para el switch de control
unsigned long tiempoini;
unsigned long time_ultimo;
unsigned long time_past;
unsigned long duration;

unsigned long tiempo_cronometro = 0;
unsigned long tiempo_cronometro2 = 0;
bool flag_cronometro = true;

/*-------------------------------------------------------------TIEMPO DE VELOCIDAD PARA LETRAS-------------------------------*/
unsigned long tiempo_despla = 0;
unsigned long tiempo_despla2 = 0;
int segundos = 0;
int velocidad = 400;

int columnas[8] = {0, 21, 2, 3, 4, 5, 6, 7};
int filas[8] = {15, 14, 13, 12, 11, 10, 9, 8};
int matriz[16][8];

const int caracteres = 22;
byte oracion[caracteres][8][8] = {G, THREE, GUION, S, E, C, C, I, O, N, A, GUION, P, R, A, C, T, I, C, A, UNO, SPACE};
//----------------------------------------- DESPLAZAMIENTO ---------------------------------------------------
int letraActual = 0;
int lineaActual = 0;

//-------------------------------------------- ENEMIGOS -------------------------------------------------------------------------------------
int probabilidad = 4;
int enemigos[25][5][8];

/**
 * 0: Abajo -> Arriba
 * 1: Arriba->Abajo
 */
int flagDesplazamiento = 0;
int oldDesplazamiento = 0; // Almacenara el anterior estado

int num = 0;  //variable enemigos
int num1 = 0; //variable de n y n-100

//--------------------------------- para el boton
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

void setup()
{
  tiempo_cronometro = millis();
  tiempo_despla = millis();

  Serial.begin(9600);
  //---------------------------------------- SETEAMOS LOS PINES
  for (int i = 0; i < 16; i++)
  pinMode(i, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(20, OUTPUT);
  pinMode(A1, INPUT); //----------------boton

  pinMode(A0, INPUT); //-------------- SWITCH PARA CAMBIAR ORIENTACION

  pinMode(A2, INPUT); // -------------

  clearLeds(); //------------------------- Si se inicia de nuevo entonces limpiaremos la matriz de leds

  lc.shutdown(0, false);
  //Intensidad de los les de la matriz con modulo
  lc.setIntensity(0, 8);
  //Limpiamos la matriz con modulo
  lc.clearDisplay(0);
  //hasta aqui

  timer2.every(5, tipoDesplazamiento, 0); //------------------------- Este tiempo dictara la velocidad en la que se mostraran las figuras/letras
  timer1.every(5, game, 0);               //--------------------------------------- Hilo para el resto del juego

  randomSeed(analogRead(A13)); // Semilla para los numeros aleatorios

  generarEnemigos();
}

void loop()
{
  time_init = millis();
  timer1.update();
  timer2.update();
  // int resultado = map(analogRead(A2),0,1023,0,100);
  
  
  
}

/*
 * METODO QUE SE ENCARGARA DE LLENAR EL ARREGLO ENEMIGOS
 * YA SEA DE ENEMIGOS O DE ESPACIOS EN BLANCO 
 */
void generarEnemigos()
{
  for (int i = 0; i < 25; i++)
  {
    /*
     * Si el numero random es menor a la probabilidad entonces es un enemigo
     * de lo contrario se tomara como espacio vacio
     *  
     */
    long numero = random(0, 10);
    if (numero <= probabilidad)
    {
      /*NUMERO:
       * 0 -> Enemigo izquierdo
       * 1 -> Enemigo derecho
       * 2 -> Enemigo centro
       */
      long lado = random(0, 2);
      if (lado == 0)
        guardarEnemigo(i,left);
      else if (lado == 1)
        guardarEnemigo(i,right);
      else
        guardarEnemigo(i,center);
    }
    else
      guardarEnemigo(i,enemigo_vacio);
  }
}

/*
 *METODO QUE SE ENCARGARA DE GUARDAR UN 
 ENEMIGO/ESPACIO EN CIERTA POSICION 
 */
void guardarEnemigo(int index,int objeto[5][8]){
  for(int i = 0; i < 5; i++){
    for(int j = 0; j < 8; j++){
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
  Temporizador();
}

/**
 * METODO QUE SE ENCARGARA DE VERIFICAR LA FLAG
 * 
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
  }
}

/*
 * METODO ENCARGADO DE
 * MOVER LOS ENEMIGOS 
 * 
 * 
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


int regla_Tres(int x)
{
  return (x * 500) / 100;
}

/**
 * METODO QUE OBTENDRA EL VALOR
 * DEL SWITCH QUE DIRIGIRA
 * LA ORIENTACION
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
    letraActual = (letraActual + 1 >= caracteres) ? 0 : letraActual + 1;
  }
}

/*
 * Metodo que se usa para contar del 0 al 3
 */
void Contador()
{
  duration = duracion; //------si se quita el 1000 hay un pequeño retraso al iniciar
  if ((duration / 1000) >= 2)
    Llenar_Matriz(contador_0, contador_1);

  if ((duration / 1000) >= 3.2)
    Llenar_Matriz(contador_0, contador_2);

  if ((duration / 1000) >= 4.5)
    Llenar_Matriz(contador_0, contador_3);

  if ((duration / 1000) >= 6)
  {
    clearLeds();
    letraActual = 0;
    fase_inicial = 0; //aqui iria que empieze el juego
    lineaActual = (flagDesplazamiento == 1) ? 7 : 0;
  }
}
/*
 * Metodo que se encarga de llenar la matariz con los numeros
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
 * Metodo que se encarga de contar hasta 99
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
    
    if (segundos >= 99){
      Clonar(matriz_temp3,contador_9);
      Clonar(matriz_temp4,contador_9);
      Llenar_Matriz(matriz_temp4, matriz_temp3);
    }else{
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
 * Metodo Que se encarga de clonar una matriz 
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
 * Metodo que se Encarga de contar los segundos 
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
    letraActual = (letraActual + 1 >= caracteres) ? 0 : letraActual + 1;
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
        lc.setLed(0, j, i, true);
      else
        lc.setLed(0, j, i, false);
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
      if (matriz[i + 1][j] == 1)
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
      fase_inicial = 1; // estado contador
      //digitalWrite(20, HIGH); // enciende la led cuando se presiona durante 3 seg
      if (fase_inicial == 0)
        fase_inicial = 1;
      else if (fase_inicial == 1)
      {
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
        if (fase_inicial == 0){
          //clearLeds();
          fase_inicial = 2;
          flag_cronometro = false;
        }
         else if (fase_inicial == 2){ // aqui iria el juego
          clearLeds();
          fase_inicial = 0;
          flag_cronometro = true;
        }
        
      }
    }
    time_last = time_init;
  }
}
