#include "validar.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

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


  int letras, digitos, total = 0;

  //Contadores
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
    printf("ERROR (3) Contraseña tiene menos de 10 caracteres.\n");
  }
  else if (letras == 0)
  {
    printf("ERROR (4) Contraseña no tiene letras.\n");
  }
  else if (digitos == 0)
  {
    printf("ERROR (4) Contraseña no tiene números.\n");
  }
  else
  {
    printf("OK (0) Todo en orden.\n");
  }


  //Comprobación datos
  printf("\nSus datos son:\n");
  printf("Nombre:\t %s\n", user.nombre);
  printf("Apellido:\t %s\n", user.apellido);
  printf("Nombre de usuario:\t %s\n", user.username);
  printf("Contraseña:\t %s\n", user.password);
  printf("User ID:\t %d\n", user.userid);

}
