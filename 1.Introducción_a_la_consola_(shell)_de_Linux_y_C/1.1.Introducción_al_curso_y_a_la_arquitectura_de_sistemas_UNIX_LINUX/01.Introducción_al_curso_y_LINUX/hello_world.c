/*Hello World Program*/

#include <stdio.h>
void show_squares();


int main()
{
  printf("Hello World\n");
  show_squares();
}

/*Arreglos para obtener los resultados correctos se encuentran comentados.*/
void show_squares()
{
  int x;
  // long x;
  for (x = 5; x <= 5000000; x = x*10)
  {
    printf("x=%d x² = %d\n", x, x*x);
    // printf("x=%ld x² = %ld\n", x, x*x);
  }
}
