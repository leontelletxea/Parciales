#include "orquesta.h"

void hardCodeOrchestras(eOrchestra listOrchestras[], int sizeOrchestra)
{
  int i;
  int id[O]={1,2,3,4,5};
  char name[O][51]={"Berliner Philharmoniker","Boston Symphony Orchestra","Chicago Symphony Orchestra","London Symphony Orchestra","Staatskapelle Dresden"};
  char place[O][51]={"Germany","Boston","Chicago","London","Germany"};
  int type[O]= {101,100,100,100,102};;

  for(i=0; i<sizeOrchestra; i++)
  {
      listOrchestras[i].idOrchestra = id[i];
      strcpy(listOrchestras[i].nameOrchestra, name[i]);
      strcpy(listOrchestras[i].place, place[i]);
      listOrchestras[i].typeOrchestra = type[i];
      listOrchestras[i].isEmptyOrchestra = FULL;
  }
}

eOrchestra addOrchestra()
{
    eOrchestra auxOrchestra;
    int len;

    auxOrchestra.idOrchestra = createOrchestraId();

    getWord(auxOrchestra.nameOrchestra, "\nEnter the orchestras name: ");
    getWord(auxOrchestra.place, "\nEnter the Orchestras place: ");
    auxOrchestra.typeOrchestra = getInt("\n1.Sinfonic\n2.Filarmonic\n3.Camera\nEnter the Orchestras type: ", "\nError, please enter an existing type: ", 1, 3);
    auxOrchestra.isEmptyOrchestra = FULL;

    printf("\nOrchestras charged succefully, Orchestras id: %d\n", auxOrchestra.idOrchestra);

    return auxOrchestra;
}

void initOrchestra(eOrchestra listOrchestras[], int sizeOrchestra)
{
  int i;

  for(i=0; i<sizeOrchestra; i++)
  {
      listOrchestras[i].isEmptyOrchestra = EMPTY;
  }
}

int searchEmptyOrchestra(eOrchestra listOrchestras[], int sizeOrchestra)
{
  int i;
  int index = -1;

  for(i=0; i<sizeOrchestra; i++)
  {
      if(listOrchestras[i].isEmptyOrchestra==EMPTY)
      {
          index =  i;
          break;
      }
  }
  return index;
}

void chargeOneOrchestra(eOrchestra listOrchestras[], int sizeOrchestra)
{
  int index;

  index = searchEmptyOrchestra(listOrchestras, sizeOrchestra);

  if(index!=-1)
  {
      listOrchestras[index] = addOrchestra();
  }
}

static int createOrchestraId(void)
{
    static int id=0;
    id++;
    return id;
}

int findOrchestraById(eOrchestra listOrchestras[] , int sizeOrchestra)
{
    int i, searchId;
    int flag=0;

    searchId = getInt("\nEnter the Orchestras id: ", "\nError enter a valid id: ", 1, sizeOrchestra);

    for(i=0; i<sizeOrchestra;i++)
    {
        if(searchId == listOrchestras[i].idOrchestra)
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

void deleteOrchestra(eOrchestra listOrchestras[])
{
    int findReturn;
    char answer;

    findReturn = findOrchestraById(listOrchestras, O);

    if(findReturn != -1)
    {
    answer = getChar("\nAre you are shure you want to delete this Orchestra? (ENTER=Yes/n=No): ", "\nError, enter (ENTER=Yes/n=No): ", '\n', 'n');
    if(answer=='\n')
    {
    listOrchestras[findReturn].isEmptyOrchestra=EMPTY;
    printf("\nOrchestras deleted\n");
    }else{
    printf("\nAction canceled\n");
    }
    }else{
    printf("\nError Orchestras id not found\n");
    }
    system("cls");
}

void showAllOrchestras(eOrchestra listOrchestras[], int sizeOrchestra)
{
   int i;

   printf("\n# ORCHESTRA ID ############ NAME ######## PLACE ############ TIPE #\n");
   for(i=0; i<sizeOrchestra; i++)
   {
       if(listOrchestras[i].isEmptyOrchestra==FULL)
       {
           showOneOrchestra(listOrchestras[i]);
       }

   }

}

void showOneOrchestra (eOrchestra myOrchestra)
{
  printf ("\n%8d %30s %8s\t%8.d\n", myOrchestra.idOrchestra,
                                    myOrchestra.nameOrchestra,
                                    myOrchestra.place,
                                    myOrchestra.typeOrchestra);
}
