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












## Referencias
[1. Difference between help, info and man command - Stack Exchange](https://unix.stackexchange.com/questions/19451/difference-between-help-info-and-man-command)
