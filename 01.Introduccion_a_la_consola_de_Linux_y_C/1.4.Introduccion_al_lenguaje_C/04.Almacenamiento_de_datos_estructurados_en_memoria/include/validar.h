/* validar.h */
#define MAXSTR 50

typedef struct Usuario{
 char nombre[MAXSTR];
 char apellido[MAXSTR];
 char username[MAXSTR];
 char password[MAXSTR];
 int userid;
}Usuario_t;


/*TODO: Declaración validar() */
void validar(Usuario_t user);
