#include "musico.h"

void hardCodeMusicians(eMusician listMusicians[], int sizeMusician)
{
  int i;
  int id[M]={10,11,12,13,14};
  char name[M][51]={"Leon","Tomas","Ezequiel ","Joaquin ","Sofia"};
  char lastName[M][51]={"Tellechea","Saalcedo","Vasquez","Moreira","Boubeta"};
  int age[M]={19,20,33,22,40};
  int idOrchestra[M]= {2,2,1,2,2};;
  int idInstrument[M]= {1000,1001,1002,1003,1004};;

  for(i=0; i<sizeMusician; i++)
  {
      listMusicians[i].id = id[i];
      strcpy(listMusicians[i].nameMusician, name[i]);
      strcpy(listMusicians[i].lastName, lastName[i]);
      listMusicians[i].age = age[i];
      listMusicians[i].idInstrument = idInstrument[i];
      listMusicians[i].orchestraId = idOrchestra[i];
      listMusicians[i].isEmptyMusician = FULL;
  }
}

void initMusicians(eMusician listMusicians[], int sizeMusician)
{
  int i;

  for(i=0; i<sizeMusician; i++)
  {
      listMusicians[i].isEmptyMusician = EMPTY;
  }
}

int searchEmptyMusician(eMusician listMusicians[], int sizeMusician)
{
  int i;
  int index = -1;

  for(i=0; i<sizeMusician; i++)
  {
      if(listMusicians[i].isEmptyMusician==EMPTY)
      {
          index =  i;
          break;
      }
  }
  return index;
}

int findMusicianById(eMusician listMusicians[] , int sizeMusician)
{
    int i, searchId;
    int flag=0;

    searchId = getInt("\nEnter the Musicians id: ", "\nError enter a valid id: ", 10, sizeMusician+10);

    for(i=0; i<sizeMusician;i++)
    {
        if(searchId == listMusicians[i].id)
        {
            return i;
            flag=1;
        }
    }

    if(flag==0)
    {
        return -1;
    }

}

void deleteMusician(eMusician listMusicians[])
{
    int findReturn;
    char answer;

    findReturn=findMusicianById(listMusicians, M);

    if(findReturn != -1)
    {
    answer = getChar("\nAre you are shure you want to delete this Musician? (ENTER=Yes/N=No): ", "\nError, enter (ENTER=Yes/n=No): \n", '\n', 'n');
    if(answer=='\n')
    {
    listMusicians[findReturn].isEmptyMusician=EMPTY;
    printf("\nMusician deleted\n");
    }else{
    printf("\nAction canceled\n");
    }
    }else{
    printf("\nError musician id not found\n");
    }
}

void showOneMusician(eMusician myMusician)
{
  printf ("\n%8d %15s %10s\t%8.d\t%8.d\t%8.d\n", myMusician.id,
                                                 myMusician.nameMusician,
                                                 myMusician.lastName,
                                                 myMusician.age,
                                                 myMusician.orchestraId,
                                                 myMusician.idInstrument);
}

