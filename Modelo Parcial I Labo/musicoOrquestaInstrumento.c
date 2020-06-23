#include "musicoOrquestaInstrumento.h"

void getWord(char wordValue[], char message[])
{
    int len;

    printf("%s", message);
    fflush(stdin);
    fgets(wordValue, 51, stdin);

    len=strlen(wordValue);
    wordValue[len-1]='\0';
}

int getInt(char message[],char messageError[], int min, int max)
{

    int integerValue;

    printf("%s", message);
    scanf("%d", &integerValue);

    while(integerValue <  min || integerValue > max)
    {
        printf("%s", messageError);
        scanf("%d", &integerValue);
    }
    return integerValue;
}

char getChar(char message[],char messageError[], char answer, char answer2)
{
    char letterValue;

    printf("%s", message);
    fflush(stdin);
    scanf("%c", &letterValue);
    fflush(stdin);

    while(letterValue!=answer && letterValue!=answer2)
    {
        printf("%s", messageError);
        fflush(stdin);
        scanf("%c", &letterValue);
    }
    return letterValue;
}

int optionMenu(void)
{
    int option;

        printf("\n### MAIN MENU ###");
        printf("\n1.ADD ORCHESTRA\n");
        printf("2.DELETE ORCHESTRA\n");
        printf("3.LIST ORCHESTRAS\n");
        printf("4.ADD MUSICIAN\n");
        printf("5.EDIT MUSICIAN\n");
        printf("6.DELETE MUSICIAN\n");
        printf("7.PRINT MUSICIANS\n");
        printf("8.ADD INSTRUMENT\n");
        printf("9.PRINT INSTRUMENTS\n");
        printf("10.INFORMS MENU\n");
        printf("11.EXIT MENU\n");
        option = getInt("CHOOSE AN OPTION: ", "\nERROR SELECT AN EXISTING OPTION: ", 1, 11);
        system("cls");

        return option;
}

void actionMenu(eOrchestra listOrchestras[],eMusician listMusicians[], eInstrument listInstruments[], eInstrumentType listInstrumentType[], int sizeOrchestra , int sizeMusician, int sizeInstrument, int sizeType,  int option, int flag, int flag2, int flag3)
{
            switch(option)
            {
            case 1:
                 printf("### ADD ORCHESTRA ###\n");
                 chargeOneOrchestra(listOrchestras, O);
                break;
            case 2:
                 if(flag==1)
                 {
                 printf("### DELETE ORCHESTRA ###\n");
                 showAllOrchestras(listOrchestras, sizeOrchestra);
                 deleteOrchestra(listOrchestras);
                 }else{
                     printf("Error, please enter at least one Orchestra before delete someone\n");
                 }
                break;
            case 3:
                 if(flag==1)
                 {
                 printf("### LIST ORCHESTRAS ###\n");
                 showAllOrchestras(listOrchestras, O);
                 }else{
                     printf("Error, please enter at least one Orchestra before list\n");
                 }
                break;
            case 4:
                 printf("### ADD MUSICIAN ###\n");
                chargeOneMusician(listMusicians, listOrchestras, listInstruments, M, O, I);
                break;
            case 5:
                if(flag2==1)
                {
                printf("### EDIT MENU ###\n");
                showAllMusicians(listMusicians, M, listOrchestras, O);
                editMusician(listMusicians, listOrchestras, M, O);
                }else{
                     printf("Error, please enter at least one Musician before edit\n");
                 }
                break;
            case 6:
                if(flag2==1)
                {
                printf("### DELETE MUSICIAN ###\n");
                showAllMusicians(listMusicians, M, listOrchestras, O);
                deleteMusician(listMusicians);
                }else{
                     printf("Error, please enter at least one Musician before delete\n");
                 }
                break;
            case 7:
                if(flag2==1)
                {
                printf("### PRINT MUSICIANS ###\n");
                showAllMusicians(listMusicians, M, listOrchestras, O);
                }else{
                     printf("Error, please enter at least one Instrument before list\n");
                 }
                 break;
            case 8:
                if(flag3==1)
                {
                printf("### ADD INSTRUMENT ###\n");
                chargeOneInstrument(listInstruments, I);
                }else{
                     printf("Error, please enter at least one Instrument before list\n");
                 }
                break;
            case 9:
                if(flag3==1)
                {
                printf("### PRINT INSTRUMENTS ###\n");
                showAllInstruments(listInstruments, listInstrumentType, I, T);
                }else{
                     printf("Error, please enter at least one Instrument before list\n");
                 }
                 break;
            case 10:
                informsMenu(listOrchestras, listMusicians, listInstruments, listInstrumentType, O, M, I, T);
            case 11:
                break;
            }

}

eMusician addMusician(eOrchestra listOrchestras[], eMusician listMusicians[], eInstrument listInstruments[], int sizeOrchestra, int sizeMusician, int sizeInstrument)
{
    eMusician auxMusician;

    auxMusician.id=createMusicianId();

    getWord(auxMusician.nameMusician, "\nEnter the Musician name: ");
    getWord(auxMusician.lastName, "\nEnter the Musician last name: ");
    auxMusician.age = getInt("\nEnter the musicians age: ", "\nError, enter an valid musician age: ", 14, 100);

    printf("\nEnter the orchestras id: ");
    auxMusician.orchestraId = findOrchestrasId(listOrchestras, listMusicians, sizeOrchestra, sizeMusician);
    while(auxMusician.orchestraId == -1)
    {
    printf("\nError, enter an existing Orchestras id: ");
        auxMusician.orchestraId = findOrchestrasId(listOrchestras, listMusicians, sizeOrchestra, sizeMusician);
    }

    printf("\nEnter the Instrument id: ");
    auxMusician.idInstrument = findInstrumentsId(listInstruments, listMusicians, sizeInstrument, sizeMusician);
    while(auxMusician.idInstrument == -1)
    {
    printf("\nError, enter an existing Instrument id: ");
        auxMusician.idInstrument = findInstrumentsId(listInstruments, listMusicians, sizeInstrument, sizeMusician);
    }

    auxMusician.isEmptyMusician = FULL;

    return auxMusician;
}

static int createMusicianId(void)
{
    static int id=9;
    id++;
    return id;
}

int findOrchestrasId(eOrchestra listOrchestra[], eMusician listMusicians[], int sizeOrchestra,  int sizeMusician)
{
    int i;
    int flag=0;
    int auxMusicianId;

    scanf("%d", &auxMusicianId);

        for(i=0; i<sizeOrchestra; i++)
        {
            if(auxMusicianId == listOrchestra[i].idOrchestra && auxMusicianId!=0)
            {
                return auxMusicianId;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            return -1;
        }
}

int findInstrumentsId(eInstrument listInstruments[], eMusician listMusicians[], int sizeInstrument,  int sizeMusician)
{
    int i;
    int flag=0;
    int auxMusicianInstrument;

    scanf("%d", &auxMusicianInstrument);

        for(i=0; i<sizeInstrument; i++)
        {
            if(auxMusicianInstrument == listInstruments[i].idInstrument && auxMusicianInstrument!=0)
            {
                return auxMusicianInstrument;
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            return -1;
        }
}

void chargeOneMusician(eMusician listMusicians[], eOrchestra listOrchestras[], eInstrument listInstruments[], int sizeMusician, int sizeOrchestra, int sizeInstrument)
{
  int index;

  index = searchEmptyMusician(listMusicians, sizeMusician);

  if(index!=-1)
  {
      listMusicians[index] = addMusician(listOrchestras, listMusicians, listInstruments, sizeOrchestra, sizeMusician, sizeInstrument);
  }
}

void editMusician(eMusician listMusicians[], eOrchestra listOrchestras[], int sizeMusician, int sizeOrchestra)
{
    int findReturn, answer;
    int flag=0;
    char enter;
    eMusician auxMusician;

    findReturn=findMusicianById(listMusicians, M);
    auxMusician=listMusicians[findReturn];

    if(findReturn!=-1)
    {
    do
    {
    printf("\n1.AGE\n");
    printf("2.ORCHEST ID\n");
    printf("3.SAVE CHANGES\n");
    printf("4.EXIT EDIT\n");
    answer = getInt("CHOOSE AN OPTION: ", "\nError, enter an existing option: ", 1, 4);
    system("cls");

    switch(answer)
    {
        case 1:
           auxMusician.age = getInt("\nReenter age: ", "\nError enter a valid age: ", 14, 100);
           printf("\nMusician precharged succesfully\n");
           break;
        case 2:
            printf("\nEnter the orchestras id: ");
            auxMusician.orchestraId = findOrchestrasId(listOrchestras, listMusicians, sizeOrchestra, sizeMusician);
            while(auxMusician.orchestraId == -1)
            {
            printf("\nError, enter an existing Orchestras id: ");
                auxMusician.orchestraId = findOrchestrasId(listOrchestras, listMusicians, sizeOrchestra, sizeMusician);
            }
            printf("\nId precharged succesfully\n");

           break;
        case 3:
        enter = getChar("\nAre you shure you want to save changes? (ENTER=Yes)\n", "\nError, enter (ENTER=Yes/n=No): ", '\n', 'n');
        if(enter=='\n')
        {
            listMusicians[findReturn].orchestraId=auxMusician.orchestraId;
            listMusicians[findReturn]=auxMusician;
            listMusicians[findReturn].isEmptyMusician=FULL;

            printf("\nChanges saved succefully\n");

        }else{
            printf("\nChanges saves canceled\n");
        }
        flag=1;
           break;
        case 4:
            break;
        default:
           break;
    }
    }while(answer!=4);
    printf("\nExit edit menu\n");
    }else{
    printf("\nError, musicians id not found\n");
    }
}

void showAllMusicians(eMusician listMusicians[], int sizeMusician, eOrchestra listOrchestras[], int sizeOrchestra)
{
   int i, j;

    printf("\n# MUSICIAN ID ##### NAME # LAST NAME ######## AGE ###### ORCHESTRA ID # INSTRUMENT ID\n");
    for(i=0; i<sizeMusician; i++)
    {
        for(j=0; j<sizeOrchestra; j++)
        {
            if(listOrchestras[j].idOrchestra == listMusicians[i].orchestraId)
            {
                if(listOrchestras[j].isEmptyOrchestra == FULL && listMusicians[i].isEmptyMusician==FULL)
                {
                    showOneMusician(listMusicians[i]);
                }
            }
        }
    }
}

void informsMenu(eOrchestra listOrchestras[], eMusician listMusicians[], eInstrument listInstruments[], eInstrumentType listInstrumentType[], int sizeOrchestra, int sizeMusician, int sizeInstrument, int sizeType)
{
    char option;

    do
    {
        printf("\n### INFORMS MENU ###");
        printf("\na)ORCHESTRAS WITH MORE THAN FIVE MUSICIANS\n");
        printf("b)MUSICIANS WHITH MORE THIRTY YEARS OLD\n");
        printf("c)ORCHESTRAS SEARCHED BY NAME\n");
        printf("d)FULL ORCHESTRAS\n");
        printf("e)SHOW ALL MUSICIANS FOR ONE ORCHESTRA SEARCHED BY ID\n");
        printf("f)ORCHESTRA WITH MORE MUSICIANS\n");
        printf("g)MUSICIANS PLAYING WIND INSTRUMENTS\n");
        printf("h)ORCHESTRAS MUSICIAN PROMEDY\n");
        printf("i)EXIT MENU\n");
        printf("CHOOSE AN OPTION: ");
        fflush(stdin);
        scanf("%c", &option);
        system("cls");

        switch(option)
        {
        case 'a':
            showOrchestrasWhitMoreFiveMusicians(listOrchestras, listMusicians, O, M);
            break;
        case 'b':
            showMusiciansWithMoreThirtyYears(listMusicians, listInstruments, listOrchestras, listInstrumentType, M, I, O, T);
            break;
        case 'c':
            showOrchestrasByName(listOrchestras, O);
            break;
        case 'd':
            fullOrchestras(listOrchestras, listMusicians, listInstruments, O, M, I);
            break;
        case 'e':
            showAllMusicianOfOneOrchestraById(listOrchestras, listMusicians, listInstruments, listInstrumentType, O, M, I, T);
            break;
        case 'f':
            orchestraWithMoreMusicians(listOrchestras, listMusicians, O, M);
            break;
        case 'g':
            musiciansInstrumentWind(listMusicians, listInstruments, listInstrumentType, M, I, T);
            break;
        case 'h':
            orchestrasMusiciansPromedy(listOrchestras, listMusicians, O, M);
            break;
        }
    }while(option!='i');
    printf("\nExit informs menu...\n");
}

void showOrchestrasWhitMoreFiveMusicians(eOrchestra listOrchestras[], eMusician listMusicians[], int sizeOrchestra, int sizeMusician)
{
    int i, j;
    int flag=0;

    for(i=0; i<sizeOrchestra; i++)
    {
        int musicianCounter=0;
        for(j=0; j<sizeMusician; j++)
        {
            if(listOrchestras[i].isEmptyOrchestra ==  FULL && listMusicians[j].isEmptyMusician == FULL)
            {
                if(listOrchestras[i].idOrchestra == listMusicians[j].orchestraId)
                {
                    musicianCounter++;
                }
            }
        }
        if(musicianCounter>=5)
        {
            printf("\nOrchestras with more than five Musicians: \n");
            printf("\n# ORCHESTRA ID ############ NAME ######## PLACE ############ TIPE #\n");
            showOneOrchestra(listOrchestras[i]);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nError, not found\n");
    }
}

void showMusiciansWithMoreThirtyYears(eMusician listMusicians[], eInstrument listInstruments[], eOrchestra listOrchestras[], eInstrument listInstrumentType[],  int sizeMusician, int sizeInstrument, int sizeOrchesta, int sizeType)
{
    int i;
    int flag=0;

        for(i=0; i<sizeMusician; i++)
        {
            int orchestraPosition=0;
            int instrumentPosition=0;
            if(listMusicians[i].isEmptyMusician == FULL)
            {
                if(listMusicians[i].age >= 30)
                {
                    orchestraPosition=listMusicians[i].orchestraId-1;
                    instrumentPosition=listMusicians[i].idInstrument-1000;
                    if(flag==0)
                    {
                        printf("\nMusicians with more thirty years old: \n");
                        printf("\n# MUSICIAN ID ##### NAME # LAST NAME ######## AGE ############## ORCHESTRA ############ INSTRUMENT #\n");
                    }
                    printf ("\n%8d %15s %10s\t%8.d\t%8s\t%8s\n", listMusicians[i].id,
                                                                   listMusicians[i].nameMusician,
                                                                   listMusicians[i].lastName,
                                                                   listMusicians[i].age,
                                                                   listOrchestras[orchestraPosition].nameOrchestra,
                                                                   listInstruments[instrumentPosition].instrumentName);
                    flag=1;
                }
            }
        }
        if(flag==0)
        {
            printf("\nError, not found\n");
        }
}

void showOrchestrasByName(eOrchestra listOrchestras[], int sizeOrchestra)
{
    int i;
    int flag=0;
    char orchestrasPlace[51];

    getWord(orchestrasPlace, "\nEnter a Orchestras place to search: ");

        for(i=0; i<sizeOrchestra; i++)
        {
            if(strcmp(orchestrasPlace, listOrchestras[i].place)==0 && listOrchestras[i].isEmptyOrchestra == FULL)
            {
                    if(flag==0)
                    {
                        printf("\n# ORCHESTRA ID ############ NAME ######## PLACE ############ TIPE #\n");
                    }
                    showOneOrchestra(listOrchestras[i]);
                    flag=1;
                }
        }
        if(flag==0)
        {
            printf("\nError, place not found\n");
        }
}

void fullOrchestras(eOrchestra listOrchestras[], eMusician listMusicians[], eInstrument listInstruments[], int sizeOrchestra, int sizeMusician, int sizeInstrument)
{
    int i, j, e;
    int flag=0;

    for(i=0; i<sizeOrchestra; i++)
    {
        int chords=0;
        int wind=0;
        int percussion=0;
        for(j=0; j<sizeMusician; j++)
        {
            if(listOrchestras[i].isEmptyOrchestra == FULL && listMusicians[j].isEmptyMusician == FULL)
            {
                if(listOrchestras[i].idOrchestra == listMusicians[j].orchestraId)
                {
                    for(e=0; e<sizeInstrument; e++)
                    {
                        if(listMusicians[j].idInstrument == listInstruments[e].idInstrument)
                        {
                            if(listInstruments[e].typeInstrument==1)
                            {
                                chords++;
                            }
                            if(listInstruments[e].typeInstrument==2 || listInstruments[e].typeInstrument==3 )
                            {
                                wind++;
                            }
                            if(listInstruments[e].typeInstrument==4)
                            {
                                percussion++;
                            }
                        }
                    }
                }

            }
        }
        if(chords>=5 /*&& wind>=3 && percussion>=2*/)
        {
            if(flag==0)
            {
                printf("\nFull Orchestras: \n");
                printf("\n# ORCHESTRA ID ############ NAME ######## PLACE ############ TIPE #\n");
            }
            showOneOrchestra(listOrchestras[i]);
            flag=1;
        }
    }
    if(flag==0)
    {
        printf("\nError, not found\n");
    }
}

void showAllMusicianOfOneOrchestraById(eOrchestra listOrchestras[],eMusician listMusicians[],eInstrument listInstruments[], eInstrumentType listType[], int sizeOrchestra, int sizeMusician, int sizeInstrument, int sizeType)
{
    int i, j;
    int flag=0;
    int orchestrasId;

    orchestrasId = getInt("\nEnter a Orchestras id to search: ", "\nError enter a valid id to search: ", 1, sizeOrchestra);

        for(i=0; i<sizeOrchestra; i++)
        {
            int instrumentPosition;
            int typePosition;
            if(orchestrasId == listOrchestras[i].idOrchestra)
            {
                for(j=0; j<sizeMusician; j++)
                {
                    if(orchestrasId == listMusicians[j].orchestraId && listOrchestras[i].isEmptyOrchestra == FULL && listMusicians[j].isEmptyMusician == FULL)
                    {
                            if(flag==0)
                            {
                                printf("\nOrchestra Musicians: \n");
                                printf("\n# NAME ############ LAST NAME ### AGE ############ INSTRUMENT ##### TYPE\n");
                            }
                            instrumentPosition=listMusicians[j].idInstrument-1000;
                            typePosition=listMusicians[j].idInstrument-1000;
                            printf ("\n%15s %10s\t%8.d\t%8s\t%8s\n", listMusicians[j].nameMusician,
                                                                     listMusicians[j].lastName,
                                                                     listMusicians[j].age,
                                                                     listInstruments[instrumentPosition].instrumentName,
                                                                     listType[typePosition].instrumentType);
                            flag=1;
                    }
                }
            }
        }
}

void orchestraWithMoreMusicians(eOrchestra listOrchestras[], eMusician listMusicians[], int sizeOrchestra, int sizeMusician)
{
    int i, j;
    int flag=0;
    int maximum=0;
    int position=0;

    for(i=0; i<sizeOrchestra; i++)
    {
        int musiciansCounter=0;
        for(j=0; j<sizeMusician; j++)
        {

            if(listOrchestras[i].idOrchestra == listMusicians[j].orchestraId && listOrchestras[i].isEmptyOrchestra == FULL && listMusicians[j].isEmptyMusician == FULL)
            {
                musiciansCounter++;
            }
        }
            if(i==0 || musiciansCounter>maximum)
            {
                maximum=musiciansCounter;
                position=listOrchestras[i].idOrchestra-1;
            }
            if(i==sizeOrchestra-1)
            {
                if(flag==0)
                {
                    printf("\nOrchestra with more Musicians: \n");
                    printf("\n# ORCHESTRA ID ############ NAME ######## PLACE ############ TIPE ###### MUSICIANS #\n");
                }
                printf ("\n%8d %30s %8s\t%8.d\t%8.d\n", listOrchestras[position].idOrchestra,
                                                        listOrchestras[position].nameOrchestra,
                                                        listOrchestras[position].place,
                                                        listOrchestras[position].typeOrchestra,
                                                        maximum);
                flag=1;
            }
    }
}

void musiciansInstrumentWind(eMusician listMusicians[], eInstrument listInstruments[], eInstrumentType listType[], int sizeMusician, int sizeInstruments, int sizeType)
{
    int i, j, a, b;
    int flag=0;
    eMusician auxMusician;

    for(i=0; i<sizeMusician; i++)
    {
        int instrumentPosition;
        int typePosition;
        if(listMusicians[i].isEmptyMusician == FULL)
        {
            for(j=0; j<sizeInstruments; j++)
            {
                if(listMusicians[i].idInstrument==listInstruments[j].idInstrument)
                {
                    if(listInstruments[j].typeInstrument==2 || listInstruments[j].typeInstrument==3)
                    {
                            instrumentPosition=listMusicians[i].idInstrument-1000;
                            typePosition=listMusicians[i].idInstrument-1000;
                            if(flag==0)
                            {
                                printf("\nOrchestra wind instruments Musicians: \n");
                                printf("\n# NAME ############ LAST NAME ### AGE ############ INSTRUMENT ##### TYPE\n");
                            }

                                /**for(a=0; a<sizeMusician-1; a++)
                                {
                                    for(b=a+1; b<sizeMusician; b++)
                                    {
                                        if(strcmp(listMusicians[a].lastName, listMusicians[b].lastName)>0)
                                        {
                                                    auxMusician = listMusicians[a];
                                                    listMusicians[a] = listMusicians[b];
                                                    listMusicians[b] = auxMusician;
                                        }

                                    }
                                }**/

                            printf ("\n%15s %10s\t%8.d\t%8s\t%8s\n", listMusicians[i].nameMusician,
                                                                     listMusicians[i].lastName,
                                                                     listMusicians[i].age
                                                                     /*listInstruments[instrumentPosition].instrumentName,
                                                                     listType[typePosition].instrumentType*/);
                           flag=1;
                    }
                }
            }
        }
    }
}

void orchestrasMusiciansPromedy(eOrchestra listOrchestras[], eMusician listMusicians[], int sizeOrchestra, int sizeMusician)
{
    int i, j, a;
    int orchestrasCounter=0;

    for (i=0; i<sizeOrchestra; i++)
    {
        if(listOrchestras[i].isEmptyOrchestra == FULL)
        {
            orchestrasCounter++;
        }
    }

    for (j=0; j<sizeOrchestra; j++)
    {
        int musiciansCounter=0;
        float promedy=0;
        for (a=0; a<sizeMusician; a++)
        {

            if(listOrchestras[j].idOrchestra == listMusicians[a].orchestraId && listMusicians[a].isEmptyMusician == FULL && listOrchestras[j].isEmptyOrchestra == FULL)
            {
                musiciansCounter++;
            }
        }
        promedy = (float)musiciansCounter/orchestrasCounter;
        printf("\nOrchestras promedy of Orchestra with id %d: %.1f\n", listOrchestras[j].idOrchestra, promedy);
    }
}
