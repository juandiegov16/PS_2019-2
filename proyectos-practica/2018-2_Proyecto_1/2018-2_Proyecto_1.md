# Comando de conteo de palabras

Crear una aplicación que implemente una versión simplificada del comando [wc](https://linuxconfig.org/wc-1-manual-page),
(a continuación el mensaje de ayuda del comando):

```
wc [option] FILE
wc, o "word count," muestra en consola el número de saltos de línea, palabras, y caracteres del archivo de entrada.
-h: ayuda, muestra este mensaje
-l: muestra el total de saltos de línea
-w: muestra el total de palabras
-c: muestra el total de caracteres
```

Ejemplo de uso, asumiendo que el archivo miarchivo.txt existe en el sistema:

```bash
$ wc miarchivo.txt
5 13 57 miarchivo.txt
```
donde 5 es el número de saltos de línea en el archivo, 13 el número de palabras y 57 el número de caracteres. Otro ejemplo:
```bash
$ wc -w miarchivo.txt
13
```

## Funcionamiento

* El programa debe poder implementar la lectura de opciones e implementarlas tal como se especifica arriba.
* El programa debe aceptar un argumento e interpretarlo como el archivo de texto que se va a analizar.
* El programa debe mostrar mensajes de errores apropiados (archivo no encontrado, opciones invalidas, etc.) en STDERR.
* El programa mostrará el mensaje de ayuda arriba mostrado en los siguientes casos:
  * Se usa la opción –h
  * El número de argumentos proporcionados es erróneo.
  * Se especifica una opción no existente.

## Evaluación
* El código fuente debe estar en una carpeta *src*, cabeceras en una carpeta *include*, archivos .o en una carpeta *obj* y ejecutable(s) en una carpeta *bin*.

## Rúbrica
![](https://i.imgur.com/6INzGMq.png)
