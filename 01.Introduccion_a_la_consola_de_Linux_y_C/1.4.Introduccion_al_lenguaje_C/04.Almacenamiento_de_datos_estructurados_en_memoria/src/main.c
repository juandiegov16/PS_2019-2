#include "validar.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
  Usuario_t user;

  printf("Introduce tu primer nombre: \n");
  scanf("%s",user.nombre);

	printf("Introduce tu primer apellido: \n");
	scanf("%s",user.apellido);

  // Guarda apellido en minúscula para uso en username sin alterar el original
  char apellido_minusculas[MAXSTR];
  memset(apellido_minusculas, '\0', MAXSTR);
  for(int i = 0; i<strlen(user.apellido);i++)
  {
    apellido_minusculas[i] = tolower(user.apellido[i]);
  }

  //Imprime la inicial del nombre + apellido en minúsculas en la variable username
  //memset(user.username, '\0', MAXSTR);
  snprintf(user.username, MAXSTR, "%c%s", tolower(user.nombre[0]), apellido_minusculas);
  // printf("%s",user.username);
  printf("Tu nombre de usuario es: %s\n", user.username);


  printf("Introduce una contraseña. (Sugerencia: Mínimo 10 caracteres; incluye al menos una letra y un número)\n");
  scanf("%s",user.password);

  //Generar user ID
  user.userid = rand();

  validar(user);

}
