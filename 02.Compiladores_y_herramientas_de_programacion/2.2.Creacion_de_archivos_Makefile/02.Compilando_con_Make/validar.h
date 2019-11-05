//
// Created by Carlos David Cunalata Chang on 10/31/19.
//

#ifndef PROGSIS2019_HEADERF_H
#define PROGSIS2019_HEADERF_H
#define ARRAY_L 50

typedef struct Usuario
{
    char nombre[ARRAY_L];
    char apellido[ARRAY_L];
    char username [ARRAY_L];
    char password[ARRAY_L];
    int userid;
}Usuario_t;

int validar(Usuario_t *user);
#endif //PROGSIS2019_HEADERF_H
