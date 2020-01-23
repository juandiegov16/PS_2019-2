//
// Created by Carlos David Cunalata Chang on 11/3/19.
//
#include "validar.h"
#include "guardar.h"
#include<stdio.h>

void guardar(Usuario_t *usuarios, int n_registros)
{
    printf("GUARDANDO CAMBIOS!\n");
    FILE * registro;
    registro = fopen("usuarios.txt","a");


    int i;

    for(i=0;i<n_registros ;i++)
    {
        fprintf(registro,"%s %s %s %s %d\n", usuarios ->nombre, usuarios ->apellido, usuarios ->username, usuarios ->password, usuarios ->userid);
        printf("%s %s\n",usuarios->nombre,usuarios->apellido);
        usuarios++;
    }
    fclose(registro);
}