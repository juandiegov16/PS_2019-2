# Lectura 05

 Libro Computer Systems, Bryant y O’Hallaron
 Secciones 1.1 – 1.4, 3.1 – 3.3 y 7.1 – 7.4

 > Autor apuntes: Juan Diego Vallejo

## 1.1. La información es bits + contexto
* Un programa/archivo fuente consiste de una secuencia de bits
(con valor de 1 o 0), organizados en fragmentos de 8 bits llamados **bytes**.
* Cada byte tiene un valor entero que corresponde a un caracter.
* Archivos como un `.c` que consisten exclusivamente de caracteres ASCII se
llaman *text files*.

## 1.2. Los programas son traducidos a diferentes formas

![](https://i.imgur.com/6XChFYJ.png)

### Preprocesamiento
* El programa original es modificado de acuerdo a directivas con el `#`.
El resultado es un archivo `.i`.

### Compilación
* El archivo `.i` es traducido a `.s`, lenguaje ensamblador.

### Ensamble
* El ensamblador traduce el `.s` a instrucciones en lenguaje de máquina, y las
empaqueta en un archivo objeto (`.o`).
  * Un archivo `.o` no es legible para un humano.

### Enlace
* Programa es enlazado con librerías utilizadas, y el resultado es un ejecutable.

## 1.3. Sirve entender cómo funcionan los sistemas de compilación
Por qué? Para:
* Optimizar rendimiento de programas
* Entender errores en tiempo de enlace
* Evitar huecos de seguridad

## 1.4. Procesadores leen e interpretan instrucciones guardadas en memoria
(Material cubierto en los videos de Playposit)

## 3.1. (Representación a nivel máquina) Perspectiva histórica
* x86 es la línea de procesadores de Intel.
* *Ley de Moore:* Poder computacional se duplica cada 18 meses.

## 3.2. Codificación de programas
* Comando **gcc** invoca al compilador de C. (Argumento **-01** indica al compilador aplicar optimizaciones de nivel 1)
	* *Preprocesador* expande código con declaraciones de **#include** y **#define**
	* *Compilador* genera código de ensamblador del código fuente en archivos **.s**
	* *Ensamblador* convierte assembly code a binarios object-code **.o**
	* *Linker* une los object-codes con código que implementa funciones de librería y genera el ejecutable final.

### 3.2.1 Código a nivel de máquina
* Formato y comportamiento de un programa a nivel de máquina está definido por *instruction set architecture*
	* Instrucciones son ejecutadas en secuencia
	* Direcciones de memoria utilizadas son direcciones virtuales, con modelo de memoria asemejándose a un arreglo de bytes.

### 3.2.2 Ejemplos de código
* Opción **-S** ocasiona que GCC corra el compilador, genere un **.s** y no vaya más allá.
* Opción **-c** compila y ensambla el código. Esto genera un **code.o** en formato binario.
	* Dentro del **.o** existe una secuencia de 17 bytes en hex (es el object-code de las instrucciones de máquina)
* **objdump -d** sirve para inspeccionar contenido de archivos **.o**


## 3.3. Formatos de datos
![](https://i.imgur.com/Btm4eb5.png)

*Declaración / Tamaño en bytes*
* char / 1
* short / 2
* int / 4
* char * / 4
* float / 4
* double / 8
* long double / 10

## 7.1. Drivers de compilador
* Mayoría de sistemas de compilación proveen un driver que invoca el preprocesador, compilador, ensamblador y linker, a medida que vayan siendo necesitados por el usuario.
	* Driver corre el **preproc**, que traduce *main.c* en un archivo intermedio ASCII *main.i*
	* Luego corre el **compilador**, que traduce *main.i* a un archivo ASCII en lenguaje ensamblador *main.s*
	* Después, corre el **ensamblador**, que traduce *main.s* a un archivo de objeto *main.o*
	* Por último, corre el **linker**, que combina los **.o** especificados, junto con los archivos objeto de sistema necesarios para crear el **ejecutable**

## 7.2. Linking estático
* Para construir el ejecutable, el linker debe hacer dos cosas:
	* Resolución de símbolos: Archivos objeto definen y refieren a *símbolos*, con el propósito de asociar una referencia de símbolo con exactamente una definición.
	* Re-localización: Compiladores y ensambladores generan secciones de datos y código que comienzan en dirección 0. El linker reubica estas secciones asociando un lugar en memoria con cada definición de símbolo. y luego modificando las referencias para que apunten a este lugar en memoria

## 7.3. Archivos objeto
Viene en tres tipos:
* Relocatable: Contiene código binario y datos de manera que se puede combinar con otros relocatable en tiempo de compilación para crear un ejecutable.
* Ejecutable: Contiene código binario y datos en forma que se puede copiar directamente en memoria y ejecutar
* Shared: Tipo especial de relocatable que puede ser cargado en memoria y enlazado dinámicamente, ya sea en tiempo de carga o de ejecución.


## 7.4. Archivos objeto relocatable
* .text: Código de máquina
* .rodata: Datos de sólo lectura (format strings, tablas de switch)
* .data: Variables globales INICIALIZADAS
* .bss: Variables globales NO INICIALIZADAS
* .symtab: Tabla de símbolos
* .rel .text: Texto a modificar cuando el linker combine el presente **.o** con otros.
