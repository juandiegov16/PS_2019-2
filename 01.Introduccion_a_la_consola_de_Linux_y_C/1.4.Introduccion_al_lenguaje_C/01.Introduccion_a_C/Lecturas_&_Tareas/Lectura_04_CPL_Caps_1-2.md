# Tarea: The C Programming Language, leer capítulos 1 y 2
> Autor apuntes: Juan Diego Vallejo

## 1. Introducción
### 1.1. Empezando

> Programa "Hello World"

```c
#include <stdio.h>

main()
{
  printf("Hello world!\n");
}
```
* En un sistema Unix, el programa debe crearse en un archivo `.c` y luego
compilarse.
* Compilación por defecto entrega un archivo ejecutable llamado `a.out`.


* Un programa en C, consiste de *funciones* y *variables*.
* Una función contiene *enunciados* que especifican las operaciones que se
llevarán a cabo, y las variables almacenan valores a ser utilizados.
* Un programa empieza a ejecutarse en `main`, ergo, todo programa debe contenerlo
en alguna parte.

* Los paréntesis luego del nombre de la función rodean la lista de *argumentos*.

### 1.2. Variables y expresiones aritméticas

* *Comentarios* son líneas que explican funcionamiento del programa. Son rodeadas
por `*/` y `*/` para que sean ignoradas por el compilador.
* **En C, todas las variables deben ser declaradas antes de usarse!!**

### 1.3. El enunciado `for`
Consta de tres partes:
* Inicialización
* Condición de control
* Paso de incremento

La elección entre `while` y `for` es arbitraria.

### 1.4. Constantes simbólicas
* Una línea `#define` establece una *constante simbólica*  a ser utilizada.
De ahí en adelante, cualquier ocurrencia de la constante será evaluada en el
valor que hemos definido que la reemplace.
Explicado mejor:
```c
# define LOWER 0
```
> Cuando usemos la palabra "LOWER" en cualquier parte del programa, será
reemplazada por un 0 en compilación y ejecución.


### 1.5. Entrada y salida de caracteres
```c
c = getchar(c);
```
> Lee el siguiente caracter de la entrada cada vez que es llamado.

```c
putchar(c); //Imprime un caracter cada vez que es llamado
```
#### 1.5.1. Copia de archivos
Programa ejemplo. Copia entrada a salida un caracter a la vez.
```c
#include <stdio.h>

/*copia entrada a salida*/
main()
{
  int c;

  ;
  while ((c = getchar()) != EOF)
  {
    putchar(c);
  }
}
```
* `EOF` significa "end of file".

#### 1.5.2. Contar caracteres
```c
main()
{
  double nc;
  for (nc = 0; getchar != EOF; ++nc)
  {
    printf("%.0f\n", nc);
  }
}
```

#### 1.5.3. Contar líneas
```c
main()
{

  int c, nl;
  nl = 0;

  while ((c = getchar()) != EOF)
  {
    if (c == '\n')
    {
      ++nl;
    }
    printf("%d\n", nl);
  }
}
```

#### 1.5.4. Contar palabras
```c
#include <stdio.h>

#define IN 1
#define OUT 0

main()
{
  int c, nl, nw, nc, state;

  state = OUT;
  nl = nw = nc = 0;
  while ((c = getchar()) != EOF)
  {
    ++nc;
    if (c == '\n')
    {
      ++nl;
    }
    if (c == ' ' || c == '\n' || c == '\t')
    {
      state = OUT;
    }else if (state == OUT)
    {
      state = IN;
      ++nw;
    }
  }
  printf("%d %d %d\n", nl, nw, nc);
}
```

### 1.6. Arreglos
