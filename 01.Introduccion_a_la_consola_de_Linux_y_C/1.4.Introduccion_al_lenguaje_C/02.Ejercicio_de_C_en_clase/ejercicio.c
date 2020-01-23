/* Integrantes:
Carlos Cunalata
Juan Diego Vallejo */

#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (){
  char entrada[30];
  // char *inicial;
  int i = 0;

  //Pide entrada de texto (nombre)
  printf("Ingrese su primer nombre y su primer apellido: ");
  fgets(entrada, 30, stdin);

  char inicial;
  inicial = tolower(entrada[0]);
  for(int i = 0; i<strlen(entrada);i++)
  {
    entrada[i] = tolower(entrada[i]);
  }

  char *p = strtok(entrada, " ");
  char *nom_ape[2];

  while(p)
  {
    nom_ape[i++] = p;
    p = strtok(NULL, " ");
  }

  printf("Usuario sugerido: %c%s", inicial, nom_ape[1]);
  return 0;
}
