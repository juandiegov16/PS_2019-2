# Tarea: The Linux Command Line, Leer capítulos 5,6,9
> Autor apuntes: Juan Diego Vallejo

## 5. Trabajando con comandos
Se utilizarán los siguientes comandos:
* `type`: Indica cómo se interpreta un comando
* `which`: Muestra qué programa ejecutable se ejecutará
* `help`: Brinda ayuda con elementos del shell
* `man`: Muestra documentación de un comando
* `apropos`: Despliega una lista de comandos apropiados/pertinentes
* `info`: Documentación (con hipervínculos) de un comando
* `whatis`: Imprimir nombre de directorio de trabajo actual
* `alias`: Otorgarle un apodo a un comando

[¿Cuál es la diferencia entre help,man e info?](1)

### ¿Qué exactamente es un comando?
Puede ser una de cuatro cosas:
1. Un **programa ejecutable** como los archivos que se encuentran en `/usr/bin`. Puede ser un *binario compilado* o un programa escrito en *lenguajes de scripting*.
2. Un **comando incorporado en el shell**.
3. Una **función del shell**. Entiéndase, script en miniatura incluido en el entorno.
4. Un **alias**. Comando definido por el usuario, construido con otros comandos.

### Identificando comandos

#### `type` - Muestra el tipo de un comando
```bash
type command
```
* Por ejemplo, nos puede decir si un comando es un alias, es incorporado o si está en /bin.

#### `which` - Muestra ubicación de un ejecutable
```bash
which command
```
* Sólo funciona con programas ejecutables.

### Obteniendo documentación de un comando

#### `help` - Obtener ayuda para incorporados del shell
```bash
help command
```

#### `--help` - Mostrar información de uso
Muchos programas ejecutables tienen soporte para una opción `--help` que muestra una descripción de la sintaxis apropiada y posibles aditamentos.

```bash
command --help
```
#### `man` - Mostrar manual de un programa
> Documentación formal.

```bash
man program
```
#### `apropos` - Muestra comandos apropiados
```bash
apropos program
```

#### `whatis` - Muestra descripción muy breve de un comando
```bash
whatis program
```

#### `info` - Muestra entrada de información de un programa
Se considera una alternativa que provee GNU Project a las páginas man. Las páginas info son mostradas por un lector, y contienen hipervínculos.
```bash
info program
```

### Creando comandos con `alias`
1. Usar `type` para verificar que el nombre que le queremos asignar al comando esté disponible.
2. ```bash
alias name='string'
```
Donde *name* es el nombre de nuestro nuevo comando y *string* es la serie de instrucciones/comandos que queremos que contenga.

* Para remover un alias:
```bash
unalias command
```

## 6. Redirección
Se utilizarán los siguientes comandos:
* `cat`: Concatena archivos
* `sort`: Organiza líneas de texto
* `uniq`: Reporta u omite líneas repetidas
* `grep`: Imprime líneas coincidentes con un patrón dado
* `wc`: Imprime número de saltos de línea, palabras y caracteres de un archivo
* `head`: Muestra porción inicial de un archivo
* `tail`: Muestra porción final de un archivo
* `tee`: Lee desde entrada estándar y escribe a salida estándar y archivos

### Entrada estándar, Salida estándar & Error estándar
* Los programas que utilizamos producen salidas, las cuales usualmente pueden ser de dos tipos:
  * Los resultados del programa (*stdout*) y sus mensajes de estado (*stderr*). Por defecto, ambos están ligados a la pantalla y no se guardan en disco.

* Además, muchos programas reciben entrada de *stdin*, el cual está - por defecto - vinculado con el teclado.

### Redirigiendo la salida estándar
Para redirigir la salida estándar a un archivo en vez de la pantalla usamos el operador `>`.
  * Conviene hacer esto por si queremos guardar los resultados de un comando, por ejemplo.

> Redirección en acción

```bash
ls -l /usr/bin > ls-resultado.txt
```

Lo que hizo este comando fue crear un listado en formato largo del directorio `/usr/bin` y enviar los resultados al archivo `ls-resultado.txt`.
* Nota: Usar `>` redirige la salida hacia un archivo, **sobreescribiéndolo por completo**. Para *anexar* salida redirigida al final de un archivo, usamos `>>`.

### Redirigiendo error estándar
No tiene un operador dedicado así que debemos referirnos a su *descriptor de archivo*.
* El shell se refiere internamente a stdin, stdout y stderr como 0, 1 y 2 respectivamente.

> Ejemplo

```bash
ls -l /bin/usr 2> ls-error.txt
```
Esto redirige el error estándar a `ls-error.txt`.

### Redirigiendo salida y error estándar a un archivo

#### Método 1
```bash
ls -l /bin/usr > ls-salida.txt 2>&1
```
Esto redirige salida estándar a `ls-salida.txt` y redirige stderr a stdout con la notación `2>&1`.

#### Método 2

```bash
ls -l /bin/usr &> ls-salida.txt
```
### Desechar salida no deseada
```bash
ls -l /bin/usr 2> /dev/null
```

### Redirigir entrada estándar
El comando `cat` lee uno o más archivos y los copia a stdout:
```bash
cat [file...]
```

* Si escribimos solamente `cat`, se quedará esperando una entrada de teclado.
* Podemos leer archivos del siguiente modo:
```bash
cat < lazy_dog.txt
```

### Pipelines
Utilizando el operador `|` podemos enviar la salida estándar de un comando a la entrada estándar de otro:
```bash
command1 | command2
```
#### Filtros
> Ejemplo

```bash
ls -l /bin /usr/bin | sort | less
```
Entrega una lista por directorio, `sort` las junta y ordena todo.

> Para matar líneas repetidas del ejemplo anterior

```bash
ls -l /bin /usr/bin | sort | uniq | less
```

### `wc` - Contar palabras, líneas y bytes
```bash
wc file
```
Imprime tres números que respectivamente corresponden a líneas, palabras y bytes del archivo dado.
* Si se ejecuta sin argumentos, acepta entrada estándar.

### `grep`
Uso:
```bash
grep pattern [file...]
```

### `head/tail`
Por defecto, `head` imprime las 10 primeras líneas de un archivo mientras que `tail` imprime las 10 últimas. Número de líneas ajustable con la opción `-n`.
* Utilizables con pipelines.

### `tee`
Lee stdin, lo copia a stdout y a uno o más archivos. Esto es útil para capturar los contenidos de un *pipeline* en una etapa intermedia de procesamiento.

> Aplicando a un ejemplo anterior

```bash
ls -l /usr/bin | tee ls.txt | grep zip
```












## Referencias
[1. Difference between help, info and man command - Stack Exchange](https://unix.stackexchange.com/questions/19451/difference-between-help-info-and-man-command)
