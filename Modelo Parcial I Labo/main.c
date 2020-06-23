#include <stdio.h>
#include <stdlib.h>
#include "musicoOrquestaInstrumento.h"
#define O 5
#define M 5
#define I 5
#define T 4


int main()
{
    int option;
    int flag=1;
    int flag2=1;
    int flag3=1;

    eOrchestra listOrchestras[O];
    eMusician listMusicians[M];
    eInstrument listInstruments[I];
    eInstrumentType listInstrumentType[T] = {{1,"Chords"},{2,"Wind-Woood"},{3,"Wind-Metal"},{4,"Percussion"}};

    //initOrchestra(listOrchestras, O);
    //initMusicians(listMusicians, M);
    //initInstruments(listInstruments, I);

    hardCodeOrchestras(listOrchestras, O);
    hardCodeMusicians(listMusicians, M);
    hardCodeInstruments(listInstruments, I);

    do
    {
        option = optionMenu();
        switch(option)
        {
        case 1:
            flag=1;
            break;
        case 4:
            flag2=1;
            break;
        case 8:
            flag3=1;
            break;
        }
        actionMenu(listOrchestras, listMusicians, listInstruments, listInstrumentType, O, M, I, T, option, flag, flag2, flag3);
    }while(option!=11);
    printf("Exit Console...\n");
    return 0;
}
