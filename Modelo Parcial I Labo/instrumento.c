#include "instrumento.h"

void hardCodeInstruments(eInstrument listInstruments[], int sizeInstrument)
{
  int i;
  int id[I]={1000,1001,1002,1003,1004};
  char name[I][51]={"Guitar","Piano","Bajo ","Ukelele ","Battery"};
  int type[I]= {2,3,1,1,1};;

  for(i=0; i<sizeInstrument; i++)
  {
      listInstruments[i].idInstrument = id[i];
      strcpy(listInstruments[i].instrumentName, name[i]);
      listInstruments[i].typeInstrument = type[i];
      listInstruments[i].isEmptyInstrument = FULL;
  }
}

eInstrument addInstrument()
{
    eInstrument auxInstrument;
    int len;

    auxInstrument.idInstrument=createInstrumentId();

    getWord(auxInstrument.instrumentName, "\nEnter the Instruments name: ");
    auxInstrument.typeInstrument = getInt("\n\n1.Chords\n2.Wind-Wood\n3.Wind-Metal\n4.PercussionEnter the Instrument type: ", "\nError, please enter an existing type: ", 1, 4);
    auxInstrument.isEmptyInstrument = FULL;

    printf("\nInstrument charged succefully, Instrument id: %d\n", auxInstrument.idInstrument);

    return auxInstrument;
}

void initInstruments(eInstrument listInstruments[], int sizeInstrument)
{
  int i;

  for(i=0; i<sizeInstrument; i++)
  {
      listInstruments[i].isEmptyInstrument = EMPTY;
  }
}

int searchEmptyInstrument(eInstrument listInstruments[], int sizeInstrument)
{
  int i;
  int index = -1;

  for(i=0; i<sizeInstrument; i++)
  {
      if(listInstruments[i].isEmptyInstrument==EMPTY)
      {
          index =  i;
          break;
      }
  }
  return index;
}

void chargeOneInstrument(eInstrument listInstruments[], int sizeInstrument)
{
  int index;

  index = searchEmptyInstrument(listInstruments, sizeInstrument);

  if(index!=-1)
  {
      listInstruments[index] = addInstrument();
  }
}

static int createInstrumentId(void)
{
    static int id=999;
    id++;
    return id;
}

void showAllInstruments(eInstrument listInstruments[], eInstrumentType listInstrumentType[], int sizeInstrument, int sizeType)
{
   int i, j;

   printf("\n# INSTRUMENT ID ### NAME ######### TYPE #\n");
   for(i=0; i<sizeInstrument; i++)
   {
        for(j=0; j<sizeType; j++)
        {
            if(listInstruments[i].isEmptyInstrument==FULL)
            {
               if(listInstruments[i].typeInstrument==listInstrumentType[j].numericType)
               {
                   showOneInstrument(listInstruments[i]);
                   showInstrumentType(listInstrumentType[j]);
               }
            }
        }
   }
}

void showOneInstrument(eInstrument myInstrument)
{
  printf ("\n%10d %14s", myInstrument.idInstrument,
                         myInstrument.instrumentName);
}

void showInstrumentType(eInstrumentType myInstrumentType)
{
  printf ("%15s\n", myInstrumentType.instrumentType);
}

