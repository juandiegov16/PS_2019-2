# Compilando con Make

Crear un programa en C que cumpla todos los requisitos de la práctica 3: **Almacenamiento de datos estructurados en memoria** y que contenga la siguiente funcionalidad extra (puede reusar el código de la práctica anterior):

* Los mensajes de error enviarlos a STDERR en lugar de STDOUT, es decir, no usar printf para mostrar mensajes de error, usar por ejemplo [fprintf](https://stackoverflow.com/questions/39002052/how-i-can-print-to-stderr-in-c/39002243)
* Ingresar más de un usuario, es decir, implementar un menú donde se pregunte si desea ingresar otro usuario o terminar.
* Guardar la información generada en un archivo con nombre usuario.txt y con el contenido ingresado en el siguientes formato:
    * ```
    <nombre><tab><apellido><tab><username><tab><password><tab><userid>
    ```
      * Ejemplo: Jose  Perez  jperez  miclave12345  112

    * Un usuario por línea, guardar al terminar
* Para guardar, crear una función llamada guardar() en un archivo guardar.c y con una cabecera guardar.h
* La función debe tener la siguiente declaración:
```c
void guardar(Usuario_t *); /* Usuario_t * es el puntero al arreglo de usuarios */
```


## Creación del Makefile

El programa debe contener un archivo *Makefile* que compile todo el proyecto y genere un ejecutable con el nombre *usuarios*. El archivo *Makefile* debe tener las siguientes características:

1. Ser sensible a la modificación de todos los archivos, incluso las cabeceras. Compilar solamente los archivos modificados (es decir, generar .o intermedios)
2. Tener un target llamado *clean* el cual borra todos los archivos .o y el ejecutable usuarios.

### Entregable

El entregable es un archivo zip (o tar.gz) con los siguientes archivos:

1. Makefile
2. main.c (código principal con función main)
3. validar.c
4. validar.h
5. guardar.c
6. guardar.h

#### TIPS:
* Revisar este enlace sobre como usar fprintf, fopen y fclose para escribir texto en un archivo: [https://www.zentut.com/c-tutorial/c-write-text-file/](https://www.zentut.com/c-tutorial/c-write-text-file/)
