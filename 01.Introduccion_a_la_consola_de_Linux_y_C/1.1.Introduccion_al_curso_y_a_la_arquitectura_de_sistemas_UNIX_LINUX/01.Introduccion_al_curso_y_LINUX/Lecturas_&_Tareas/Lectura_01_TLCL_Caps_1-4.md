# Tarea: The Linux Command Line, Leer capítulos 1-4
> Autor apuntes: Juan Diego Vallejo

## 1. Qué es el shell?

* *Shell*: Programa que toma comandos del teclado y los pasa para ejecución
al sistema operativo.
* *Bash*: "Bourne Again SHell", referencia al hecho que *bash* es una mejora del
 *sh*, programa de shell Unix original escrito por Steve Bourne.

### Emuladores de terminal

Cuando usamos una GUI, necesitamos un programa llamado *emulador de terminal*.
En GNOME se llama *gnome-terminal*; en KDE se llama *konsole*.
Todos hacen lo mismo: Darnos acceso al shell.

### Primeros pasos

```bash
[me@linuxbox ~]$
```

Esto se llama el *shell prompt* y aparece cuando el shell está listo para
aceptar comandos. Usualmente será *usuario@máquina*, seguido del directorio de
trabajo.

Si el último caracter del prompt es un *#*, la sesión de terminal actual tiene
privilegios *superuser* (equivalente a Admin en Windows).

#### Historial de comandos
La mayoría de distros de Linux recuerdan los últimos 1000 comandos por defecto.
Se pueden navegar con las flechas arriba y abajo.

#### Movimiento de cursor
Es posible con las flechas izquierda y derecha.

#### Copiar y pegar
* Copiar: Ctrl+Shift+C
* Pegar: Ctrl+Shift+V

### Comandos simples
* ```date```: Muestra hora y fecha actual.
* ```cal```: Muestra un calendario del mes actual.
* ```df```: Muestra cantidad actual de espacio libre en discos duros.
* ```free```: Muestra cantidad de memoria libre.

### Terminar una sesión
Se puede cerrar la ventana o ingresar el comando ```exit```.

### Lectura adicional
* [Steve Bourne, padre del Bourne Shell](http://en.wikipedia.org/wiki/Steve_Bourne)
* [Concepto de Shell en computación](http://en.wikipedia.org/wiki/Shell_(computing))


## 2. Navegación
Se utilizarán los siguientes comandos:
* ```pwd```: Imprimir nombre de directorio de trabajo actual
* ```cd```: Cambiar directorio
* ```ls```: Listar contenidos directorio

### Entendiendo el árbol del sistema de archivos

Tal como Windows, un sistema como Linux organiza sus archivos en una
*estructura jerárquica de directorios*.
* El primer directorio en el sistema se llama *directorio raíz* (root).
* Linux tiene un solo árbol, independiente de cuántos dispositivos de
almacenamiento estén montados en la computadora.

### Directorio de trabajo actual

![Ejemplo](https://i.imgur.com/LmwBK8j.png)

> *El árbol mostrado por un explorador de archivos*

Podemos mostrar el directorio actual con el comando ```pwd```.

![](https://i.imgur.com/oGVatlh.png)

### Listar contenidos de un directorio

Usamos el comando ```ls```.

![](https://i.imgur.com/pwQYhRt.png)

### Cambiar directorio de trabajo actual

Utilizamos el comando ```cd``` seguido de la *ruta* del directorio deseado.
* Ruta: Camino que tomamos recorriendo las ramas del árbol para llegar a donde queremos.
* Rutas pueden ser **absolutas** o **relativas**.

#### Rutas absolutas

Comienza con root y sigue rama por rama hasta llegar al directorio requerido.
He aquí un ejemplo:

![](https://i.imgur.com/Fl2pdH8.png)

#### Rutas relativas

Comienza desde el directorio actual y utiliza notación especial.

* ```.```: Directorio actual
* ```..```: Directorio padre del actual

He aquí ejemplos para cada uno:

![](https://i.imgur.com/xmFC0sU.png)

![](https://i.imgur.com/mVwzehY.png)

En casi todos los casos, podemos omitir el ```./```. En general, si no especificamos una ruta, se asume el directorio de trabajo actual.

##### Atajos útiles

* ```cd```: Cambia directorio actual al directorio hogar (home).
* ```cd - ```: Cambia al directorio anterior.
* ```cd ~user_name```: Cambia al directorio home del usuario especificado.

#### Datos importantes sobre filenames

* Filenames que comienzan con un punto están escondidos. Esto quiere decir que sólos erán visibles utilizando ```ls -a```.
* Filenames y comandos son *case sensitive* (importa el uso de minúsculas y mayúsculas).
* En Linux no existe el concepto de "extensión". Archivos pueden tener el nombre que uno quiera.
* **No incluir espacios en filenames.** Es preferible utilizar guiones o subguiones.

## 3. Explorando el Sistema
Se utilizarán los siguientes comandos:
* ```ls```: Lista contenido directorio
* ```file```: Determina tipo de archivo
* ```less```: Ver contenido archivo

### ls
Argumentos comunes para ```ls```:
![](https://i.imgur.com/KiVJzJF.png)

#### Detalles sobre el formato largo
Así se ve una ejecución de ```ls -l```:

![](https://i.imgur.com/6z2VDhG.png)

Y aquí el significado de los campos:

![](https://i.imgur.com/xsASREk.png)

### Lecturas adicionales

* [Versión completa del *Linux Filesystem Hierarchy Standard*](http://www.pathname.com/fhs/)
* [Artículo sobre la estructura de directorios de Unix](http://en.wikipedia.org/wiki/Unix_directory_structure)
* [Descripción detallada del formato de texto ASCII](http://en.wikipedia.org/wiki/ASCII)

## 4. Manipulación de archivos y directorios
Se utilizarán los siguientes comandos:

* ```cp```: Copiar archivos y directorios
* ```mv```: Mover/renombrar archivos y directorios
* ```mkdir```: Crear directorios
* ```rm```: Remover archivos y directorios
* ```ln```: Crear enlaces hard y enlaces soft

### Wildcards
Caracteres especiales para especificar rápidamente grupos de filenames, basándose en patrones de caracteres.

#### Wildcards comunes
![](https://i.imgur.com/pAcAWB8.png)

#### Clases de caracteres comunes
![](https://i.imgur.com/OvoDsTM.png)

#### Ejemplos de wildcards
![](https://i.imgur.com/wV7NhY6.png)
![](https://i.imgur.com/H2bfDxT.png)

### mkdir
Funciona así:

`mkdir dir1`

*Crea un directorio llamado dir1*

`mkdir dir1 dir2 dir3`

*Crea los directorios dir1, dir2 y dir3*

### cp
Se puede utilizar de dos modos:
1.
`cp item1 item2` para copiar el archivo o directorio *item1* al archivo o directorio *item2*.
2.
`cp item... directory` para copiar múltiples items/directorios a un directorio.

#### Argumentos comunes de cp
![](https://i.imgur.com/k7cnDcL.png)

### mv
Utilizado prácticamente de la misma manera que `cp`.

#### Argumentos comunes de mv
![](https://i.imgur.com/emGN9Tr.png)

### rm
Funciona así:

`rm item...`

donde *item* es uno o más archivos/directorios.

#### Argumentos comunes de rm
![](https://i.imgur.com/7J9Nvv2.png)
![](https://i.imgur.com/VSXYZKq.png)

* **Tip útil**: Antes de borrar con `rm`, probar la wildcard a utilizar con `ls`.

### ln
Utilizado para crear *hard enlaces hard* o *enlaces soft*. Utilizado de dos maneras:

`ln file link`

para crear un *enlace hard*, y

`ln -s item link`

para crear un *enlace soft* donde *item* es un archivo o directorio.

#### Enlaces hard

* Por defecto, todo archivo tiene un *enlace hard* que le otorga su nombre. Cuando creamos un *enlace hard*, creamos una entrada de directorio adicional para un archivo.

* Tienen dos limitaciones importantes:
  1. Un *enlace hard* no puede referir a un archivo fuera de su propio sistema de archivos. (Ejemplo: Un archivo en otra partición del disco.)
  2. Un *enlace hard* no puede referir a un directorio.

* Un *enlace hard* no es distinguible del archivo mismo.
* Cuando se borra un *enlace hard*, se elimina el vínculo pero el contenido del archivo sigue existiendo hasta que se supriman todas las referencias al archivo.

#### Enlaces soft

* Funcionan como un atajo de Windows.
* Si se le escribe algo al link, se escribe sobre el archivo referido.
* Si se borra el link, el archivo referido no es afectado.
* Si se borra el archivo, el link sigue existiendo pero sin apuntar a nada. Se dice entonces que el link está roto.
