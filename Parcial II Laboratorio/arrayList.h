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

eUsuario* constructorPorDefectoUsuario();

eUsuario* constructorParametrizadoUsuario(char* ID_USUARIO, char* NICK, char* POPULARIDAD);

void cargarDesdePost(LinkedList* listaDePosts);

void cargarDesdeUsuarios(LinkedList* listaDeUsuarios);

void cargarFeed(LinkedList* listaDePosts, LinkedList* listaDeUsuarios);

void cargarDesdeFeed();

