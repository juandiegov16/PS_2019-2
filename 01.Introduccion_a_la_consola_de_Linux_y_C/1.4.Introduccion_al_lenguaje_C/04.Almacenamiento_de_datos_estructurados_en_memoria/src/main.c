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
	// printf("Nombre: %s\n",user.nombre);

	printf("Introduce tu primer apellido: \n");
	scanf("%s",user.apellido);
  // printf("Apellido: %s\n",user.apellido);

  // Guarda apellido en minúscula para uso en username sin alterar el original
  char apellido_minusculas[MAXSTR];

  for(int i = 0; i<strlen(user.apellido);i++)
  {
    apellido_minusculas[i] = tolower(user.apellido[i]);
  }

  //Imprime la inicial del nombre + apellido en minúsculas en la variable username
  snprintf(user.username, MAXSTR, "%c%s", tolower(user.nombre[0]), apellido_minusculas);
  printf("Tu nombre de usuario es: %s\n", user.username);


  printf("Introduce una contraseña. (Sugerencia: Mínimo 10 caracteres; incluye al menos una letra y un número)\n");
  scanf("%s",user.password);

  //Generar user ID
  user.userid = rand();

  validar(user);

}
