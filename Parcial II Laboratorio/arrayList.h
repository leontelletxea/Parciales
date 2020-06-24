#include "LinkedList.h"

typedef struct{
  int ID_MENSAJE;
  int ID_USUARIO;
  int POPULARIDAD;
  char MENSAJE[2000];
}ePost;

typedef struct{
  int ID_USUARIO;
  char NICK[51];
  int POPULARIDAD;
}eUsuario;

ePost* constructorPorDefectoPost();

ePost* constructorParametrizadoPost(char* ID_MENSAJE, char* ID_USUARIO, char* POPULARIDAD, char* MENSAJE);

void leerPost(LinkedList* listaDePosts);

