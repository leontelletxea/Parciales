#include <stdio.h>
#include <string.h>
#define EMPTY 0
#define FULL 1
#define I 5
#define T 4

typedef struct
{
  int idInstrument;
  char instrumentName[51];
  int typeInstrument;
  int isEmptyInstrument;
}eInstrument;

typedef struct
{
  int numericType;
  char instrumentType[51];
}eInstrumentType;

void hardCodeInstruments(eInstrument listInstruments[], int sizeInstrument);

eInstrument addInstrument();

void initInstruments(eInstrument listInstruments[], int sizeInstrument);

int searchEmptyInstrument(eInstrument listInstruments[], int sizeInstrument);

void chargeOneInstrument(eInstrument listInstruments[], int sizeInstrument);

static int createInstrumentId(void);

void showAllInstruments(eInstrument listInstruments[], eInstrumentType listInstrumentType[], int sizeInstrument, int sizeType);

void showOneInstrument(eInstrument myInstrument);

void showInstrumentType(eInstrumentType myInstrumentType);
