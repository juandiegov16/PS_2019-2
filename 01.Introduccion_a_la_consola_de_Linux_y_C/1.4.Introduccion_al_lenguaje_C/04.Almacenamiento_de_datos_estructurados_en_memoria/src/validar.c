#include "validar.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void validar (Usuario_t user)
{
  //Mayúscula inicial de nombre y apellido
  for (int i= 0; i<1; i++)
  {
    user.nombre[i] = toupper(user.nombre[i]);
  }
  for (int i= 0; i<1; i++)
  {
    user.apellido[i] = toupper(user.apellido[i]);
  }

  //Declaración contadores
  int letras, digitos, total = 0;

  //Funcionamiento contadores
  for (int i=0; i<strlen(user.password);i++)
  {
    if(isalpha(user.password[i]))
    {
      ++letras;
    }
    if(isdigit(user.password[i]))
    {
      ++digitos;
    }
    ++total;
  }

  //Para mensajes de error
  if (total < 10)
  {
    printf("\nERROR (3) -> Contraseña tiene menos de 10 caracteres.\n");
  }
  else if (letras == 0)
  {
    printf("\nERROR (4) -> Contraseña no tiene letras.\n");
  }
  else if (digitos == 0)
  {
    printf("\nERROR (5) -> Contraseña no tiene números.\n");
  }
  else
  {
    printf("\nOK (0) -> Todo en orden.\n");
  }


  //Comprobación datos (Comentar todo el bloque de considerarlo pertinente)
  printf("\nSus datos son:\n");
  printf("Nombre:\t %s\n", user.nombre);
  printf("Apellido:\t %s\n", user.apellido);
  printf("Nombre de usuario:\t %s\n", user.username);
  printf("Contraseña:\t %s\n", user.password);
  printf("User ID:\t %d\n", user.userid);

}
