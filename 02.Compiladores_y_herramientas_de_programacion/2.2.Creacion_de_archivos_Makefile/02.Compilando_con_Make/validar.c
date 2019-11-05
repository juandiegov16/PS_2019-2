//
// Created by Carlos David Cunalata Chang on 10/31/19.
//

#include "validar.h"
#include<stdio.h>
#include <ctype.h>

int validar(Usuario_t *user)
{

    //minuscula se resta 32
    //mayucula se suma 32
    //rango 65-90 97-122
    int firstDigit;
    firstDigit = user ->nombre[0];
    if((firstDigit >=65 && firstDigit <= 90) || (firstDigit >= 97 && firstDigit <= 122))
    {
        if(firstDigit >= 97)//minuscula
        {
            firstDigit = firstDigit - 32;
        }
        user -> nombre[0] = firstDigit;
    }

    //PARA VALIDAR EL APELLIDO
    firstDigit = user ->apellido[0];
    if((firstDigit >=65 && firstDigit <= 90) || (firstDigit >= 97 && firstDigit <= 122))
    {
        if(firstDigit >= 97)//minuscula
        {
            firstDigit = firstDigit - 32;
        }
        user -> apellido[0] = firstDigit;
    }


    //generar username
    char userName_tmp[ARRAY_L];
    userName_tmp[0] = tolower(user->nombre[0]);
    int seq;
    for(seq = 1; seq < ARRAY_L ; seq++)
    {
        userName_tmp[seq] = tolower(user->apellido[seq-1]);
    }
    //Lo inserta en el Struct
    for(seq = 0 ; seq < ARRAY_L ; seq++)
    {
        user -> username[seq] = userName_tmp[seq];
    }

    //1 letra, mínimo un digito y mínimo 10 caracteres en total
    int flag_counter;
    int flag_letra = 0;
    int flag_digito = 0;
    int flag_caracteres=0;
    // isdigit isalpha
    for(flag_counter=0;flag_counter<ARRAY_L && user ->password[flag_counter]!=EOF && user ->password[flag_counter] != '\0' ;flag_counter++)
    {
        if(isdigit(user ->password[flag_counter]))
        {

            flag_digito++;
        }
        if (isalpha(user ->password[flag_counter]))
        {
            flag_letra++;
        }
        flag_caracteres++;
    }
    if(flag_digito>=1 && flag_letra>=1 && flag_caracteres >=10)
    {
        printf("Proceso finalizado exitosamente\n\n");
        return 0;
    }
    else
    {
        if(flag_caracteres <=10)
        {
            fprintf(stderr,"La contraseña debe de contener mínimo 10 caracteres");
            return 3;
        }
        else if(flag_letra==0)
        {
            fprintf(stderr,"La contraseña no contiene letras");
            return  4;
        }
        else
        {
            fprintf(stderr,"La contraseña no contiene digitos");
            return  5;//no contiene digitos
        }

    }
}
