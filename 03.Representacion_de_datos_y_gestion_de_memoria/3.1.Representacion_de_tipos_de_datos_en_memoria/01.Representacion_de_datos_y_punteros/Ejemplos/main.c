#include <stdio.h>

void viewMemory(int*);

int main () {

   int  var = 2000000;   /* variable entero de 4 bytes */
   unsigned char  *ip;        /* declaración de puntero */

   ip = &var;  /* el puntero ip ahora contiene la dirección de memoria de var */

   printf("Dirección de memoria de la variable var: %p\n", &var);

   printf("Valor de puntero ip: %p\n", ip);

   printf("ip + 1: %p\n",ip+1);

   /* Acceder al valor al que apunta ip */
   printf("Valor de *ip: %d\n", *ip );

   viewMemory(&var);

   return 0;
}

void viewMemory(int *x){
	unsigned char *p = x;

	printf("Valor int: %x\n", (unsigned int) *x);
	printf("Pos 0: %x\n",*p);
	printf("Pos 1: %x\n", *(p+1));
	printf("Pos 2: %x\n", *(p+2));
	printf("Pos 3: %x\n", *(p+3));
}
