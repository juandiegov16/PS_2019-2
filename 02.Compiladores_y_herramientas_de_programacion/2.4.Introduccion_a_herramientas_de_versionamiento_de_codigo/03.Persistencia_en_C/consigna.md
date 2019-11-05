# Práctica Uso de persistencia en C
Práctica sobre uso de persistencia en C para la materia Programación de Sistemas (CCPG1008) de la ESPOL.

El programa *usuarios*, el cual se genera al compilar el código fuente en este repositorio, permite ingresar el nombre, apellido y contraseña de usuarios de un sistema Linux desde consola. El programa valida la contraseña, genera un userid aleatorio para cada usuario y finalmente graba los usuarios, un usuario por línea, en un archivo de texto con nombre *usuarios.txt*.

## Instrucciones
La práctica consiste en modificar el código fuente en este repositorio para que el programa *usuarios* pueda también **leer** el archivo generado *usuarios.txt*, mostrar su contenido en consola y agregar nuevos usuarios al archivo.

El archivo, si existe, debe ser leído al iniciar la ejecución y su contenido debe ser mostrado. Luego el progama debe ingresar usuarios nuevos y agregarlos al final del archivo. Por ejemplo, asumiendo que *usuarios.txt* existe y contiene 3 usuarios, una posible ejecución del programa sería:

```
$ ./usuarios
Archivo usuarios.txt existe y contiene 3 usuarios:
1) Juan Pueblo con username: jpueblo, contraseña: alpha12345 y userid 702.
2) Jose Perez con username: jperez, contraseña: beta123456 y userid 735.
3) Alfaro Moreno con username: amoreno, contraseña: barcelona435 y userid 481.

Ingrese el nombre y apellido del usuario (ej. Jose Perez): Pablo Garcia
Ingrese la contraseña (min. 10 caracteres con letras y números): espol12345
Usuario Pablo Garcia con contraseña espol12345
Nombre de usuario sugerido pgarcia
¿Desea ingresar otro usuario? (S/N)
n

Usuarios ingresados almacenados en usuarios.txt
```

El nuevo usuario ingresado aparecerá al final del archivo:
```
$ cat usuarios.txt
Juan	Pueblo	jpueblo	alpha12345	702
Jose	Perez	jperez	beta123456	735
Alfaro	Moreno	amoreno	barcelona435	481
Pablo	Garcia	pgarcia	espol12345	586
```

Para implementar está funcionalidad, se requiere:
1. Cambiar los nombres de *guardar.c* y *guardar.h* a *persistencia.c* y *persistencia.h* (1 commit)
2. Agregar una nueva función para leer el archivo con el siguiente prototipo en *persistencia.h*: (1 commit)
```C
/*
* Lee el archivo usuarios.txt asumiendo que contiene una lista de usuarios, un usuario por línea,
* con el siguiente formato:
* <nombre><tab><apellido><tab><username><tab><password><tab><userid>
* Almacena lo leido en "usuarios" y retorna el número de usuarios encontrados.
*/
int leer(Usuario_t *usuarios);
```
3. Implementar la función *leer* (TIP: usar *fscanf*) en *persistencia.c* y usarla en *main.c* para obtener la funcionalidad requerida. (1 commit)
4. Modificar el *Makefile* y cualquier otro archivo que sea necesario para obtener la funcionalidad requerida. (1 commit o más)
