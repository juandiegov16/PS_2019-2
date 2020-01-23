# Tarea: The Linux Command Line, Leer capítulos 12, 24
> Autor apuntes: Juan Diego Vallejo

## 12. Una Gentil Introducción a vi
(En vez de apuntes, adjuntaré tutoriales.)
* [Vim Tutorial - Tutorialspoint](https://www.tutorialspoint.com/vim/index.htm)
* [Learn vim for the Last Time: A Tutorial and Primer | Daniel Miessler](https://danielmiessler.com/study/vim/)
* [Vim Crash Course](https://gist.github.com/dmsul/8bb08c686b70d5a68da0e2cb81cd857f)
* [Interactive Vim Tutorial](https://www.openvim.com/)

## 24. Escribiendo Nuestro Primer Script

### ¿Qué es un script de shell?
Un archivo conteniendo una serie de comandos, los cuales son leídos por el shell y ejecutados en el orden especificado.
### Cómo escribir un script de shell
1. Poner todos los comandos que queremos
2. Hacer que el script sea ejecutable (usar `chmod`)
3. Poner el script en alguna parte donde el shell lo pueda encontrar

### Formato de un script

* La notación para comentarios: poner # en inicio de línea
* La secuencia `#!` - llamada *shebang* - le dice al sistema el nombre del interpretador que debe ser utilizado para ejecutar el script. **Poner en la primera línea.**
  * Suele ser `#!/bin/bash`
