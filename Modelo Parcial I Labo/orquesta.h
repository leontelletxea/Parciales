#include <stdio.h>
#include <string.h>
#define EMPTY 0
#define FULL 1
#define O 5

typedef struct
{
  int idOrchestra;
  char nameOrchestra[51];
  char place[51];
  int typeOrchestra;
  int isEmptyOrchestra;
}eOrchestra;

void hardCodeOrchestras(eOrchestra listOrchestras[], int sizeOrchestra);

eOrchestra addOrchestra();

void initOrchestra(eOrchestra listOrchestras[], int sizeOrchestra);

int searchEmptyOrchestra(eOrchestra listOrchestras[], int sizeOrchestra);

void chargeOneOrchestra(eOrchestra listOrchestras[], int sizeOrchestra);

static int createOrchestraId(void);

int findOrchestraById(eOrchestra listOrchestras[] , int sizeOrchestra);

void deleteOrchestra(eOrchestra listOrchestras[]);

void showAllOrchestras(eOrchestra listOrchestras[], int sizeOrchestra);

void showOneOrchestra (eOrchestra myOrchestra);

