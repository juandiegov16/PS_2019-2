# Lectura_10_CSAPP
> Computer Systems, Secciones 7.6.2-3, 7.9-7.11
Autor apuntes: Juan Diego Vallejo

## 7.6.2. Enlazando con Librerías Estáticas
* En la práctica, todos los sistemas de compilación proveen un mecanismo para
empaquetar módulos objetos similares en un solo archivo llamado *librería estática*,
el cual se puede mandar como entrada al linker.
* Cuando un ejecutable se enlaza con una lib stat, cada instancia del mismo
contiene una copia de TODAS las funciones implementadas en la librería.
  * Cualquier cambio pequeñito requeriría recompilar todo.
* `.a` significa *archive*.

## 7.6.3. Cómo los linkers usan librerías estáticas para resolver referencias
* El orden en la terminal y los Makefiles IMPORTA.
* Regla general: Poner librerías al final de la línea.

## 7.9. Cargando archivos objeto ejecutables
* Un programa se ejecuta para nosotros llamando al *loader*.
  * Cualquier programa en Unix puede llamar al loader mediante la función `execve`.
* Punto de entrada = primera instrucción
* **Loading**: Copiar un programa a memoria y ejecutarlo.
## 7.10. Linking dinámico con librerías compartidas

## 7.11. Cargando y enlazando librerías compartidas desde aplicaciones
