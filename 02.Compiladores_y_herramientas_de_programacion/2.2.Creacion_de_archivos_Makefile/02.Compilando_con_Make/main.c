#include<stdio.h>
#include<stdlib.h>
#include <ctype.h>
#include "validar.h"
#include "guardar.h"
#include <time.h>
#define MAX_USUARIOS 50
#define TRUE 1
#define FALSE 0


int main()
{
    struct Usuario usuarios[MAX_USUARIOS];
    int contador_guardadas = 0;
    int llave_main = TRUE;
    while(llave_main)
    {

        struct Usuario user;
	srand(time(NULL));
        //Generacion de numero aleatorio
        user.userid = rand();
        //Inicializamos los arreglos de los campos nombres, apellido , password y username
        int j = 0;
        for(j=0;j<ARRAY_L;j++)
        {
            user.username[j] = '\0';
            user.nombre[j] = '\0';
            user.apellido[j] = '\0';
            user.password[j] = '\0';
        }
        printf("Ingrese su nombre: \n");
        scanf("%s",user.nombre);
        printf("Ingrese su apellido: \n");
        scanf("%s",user.apellido);
        printf("Ingrese su password, *debe de tener mínimo 1 letra, mínimo un digito y mínimo 10 caracteres en total\nPassword: ");
        scanf("%s",user.password);

        int analisis = validar(&user);


        if(analisis == 0)
        {
            printf("\nNombre: %s\n",user.nombre);
            printf("Apellido: %s\n",user.apellido);
            printf("Nombre de usuario: %s\n",user.username);
            printf("Contraseña: %s\n",user.password);
            printf("Id Usuario: %d\n",user.userid);
            contador_guardadas = contador_guardadas + 1;
            usuarios[contador_guardadas-1] = user;
        }

        //Preguntamos si desea ingresar otro usuario, caso contrario termina el programa
        printf("\nDesea ingresar otro usuario?[Y/N]:\n");


        int llave_pregunta = TRUE;
        while(llave_pregunta)
        {
            char pregunta = getchar();


            //buclear
            if((pregunta == 'Y')|| (pregunta == 'y'))
            {
                llave_pregunta = FALSE;
            }
            else if((pregunta == 'N')|| pregunta == 'n')
            {
                llave_pregunta = FALSE;
                llave_main = FALSE;
            }
            else
            {
                printf("Ingresa [Y/N] para ingresar otro usuario:\n");
            }
        }

    }
    if(contador_guardadas>0)
    {
        guardar(usuarios,contador_guardadas);
    }
    else
    {
        fprintf(stderr,"No se guardo ningun usuario en el sistema\n");
    }
    printf("\n\nPrograma finalizado!\n");
}
