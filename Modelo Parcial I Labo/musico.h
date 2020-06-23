#include <stdio.h>
#include <string.h>
#define EMPTY 0
#define FULL 1
#define M 5

typedef struct
{
  int id;
  char nameMusician[51];
  char lastName[51];
  int age;
  int orchestraId;
  int idInstrument;
  int isEmptyMusician;
}eMusician;

void hardCodeMusicians(eMusician listMusicians[], int sizeMusician);

void initMusicians(eMusician listMusicians[], int sizeMusician);

int searchEmptyMusician(eMusician listMusicians[], int sizeMusician);

int findMusicianById(eMusician lisM[] , int sizeMusician);

void deleteMusician(eMusician listMusicians[]);

void showOneMusician(eMusician myMusician);

