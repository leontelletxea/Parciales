#include "orquesta.h"
#include "musico.h"
#include "instrumento.h"

void getWord(char wordValue[], char message[]);

int getInt(char message[],char messageError[], int min, int max);

char getChar(char message[],char messageError[], char answer, char answer2);

int optionMenu(void);

void actionMenu(eOrchestra listOrchestras[],eMusician listMusicians[], eInstrument listInstruments[], eInstrumentType listInstrumentType[], int sizeOrchestra , int sizeMusician, int sizeInstrument, int sizeType,  int option, int flag, int flag2, int flag3);

void showAllMusicians(eMusician listMusicians[], int sizeMusician, eOrchestra listOrchestras[], int sizeOrchestra);

eMusician addMusician(eOrchestra listOrchestras[], eMusician listMusicians[], eInstrument listInstruments[], int sizeOrchestra, int sizeMusician, int sizeInstrument);

static int createMusicianId(void);

int findOrchestrasId(eOrchestra listOrchestra[], eMusician listMusicians[], int sizeOrchestra,  int sizeMusician);

int findInstrumentsId(eInstrument listInstruments[], eMusician listMusicians[], int sizeInstrument,  int sizeMusician);

void chargeOneMusician(eMusician listMusicians[], eOrchestra listOrchestras[], eInstrument listInstruments[], int sizeMusician, int sizeOrchestra, int sizeInstrument);

void editMusician(eMusician listMusicians[], eOrchestra listOrchestras[], int sizeMusician, int sizeOrchestra);

void informsMenu(eOrchestra listOrchestras[], eMusician listMusicians[], eInstrument listInstruments[], eInstrumentType listInstrumentType[], int sizeOrchestra, int sizeMusician, int sizeInstrument, int sizeType);

void showOrchestrasWhitMoreFiveMusicians(eOrchestra listOrchestras[], eMusician listMusicians[], int sizeOrchestra, int sizeMusician);

void showMusiciansWithMoreThirtyYears(eMusician listMusicians[], eInstrument listInstruments[], eOrchestra listOrchestras[], eInstrument listInstrumentType[],  int sizeMusician, int sizeInstrument, int sizeOrchesta, int sizeType);

void showOrchestrasByName(eOrchestra listOrchestras[], int sizeOrchestra);

void fullOrchestras(eOrchestra listOrchestras[], eMusician listMusicians[], eInstrument listInstruments[], int sizeOrchestras, int sizeMusician, int sizeInstrument);

void showAllMusicianOfOneOrchestraById(eOrchestra listOrchestras[],eMusician listMusicians[],eInstrument listInstruments[], eInstrumentType listType[], int sizeOrchestra, int sizeMusician, int sizeInstrument, int sizeType);

void orchestraWithMoreMusicians(eOrchestra listOrchestras[], eMusician listMusicians[], int sizeOrchestra, int sizeMusician);

void musiciansInstrumentWind(eMusician listMusicians[], eInstrument listInstruments[], eInstrumentType listType[], int sizeMusician, int sizeInstruments, int sizeType);

void orchestrasMusiciansPromedy(eOrchestra listOrchestras[], eMusician listMusicians[], int sizeOrchestra, int sizeMusician);
