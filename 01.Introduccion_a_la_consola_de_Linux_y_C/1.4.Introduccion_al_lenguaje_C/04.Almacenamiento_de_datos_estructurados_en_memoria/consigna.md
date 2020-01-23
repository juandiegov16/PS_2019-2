Crear un programa en C con la siguiente funcionalidad:

* Mantener en una estructura con nombre Usuario los siguientes datos:
  * Nombre
  * Apellido
  * username
  * password
  * userid
* Ingresar todos los datos desde la consola, generar aleatoriamente el userid.
* Validar los datos usando una función con nombre validar:
  * Nombre y Apellido deben de empezar con mayúscula, **cambiar esto automáticamente en la función, no retornar error en este caso**
  * username debe ser generado automáticamente a partir del nombre y apellido usando la primera letra del nombre y el apellido completo, todo en minúsculas.
  * password debe de tener mínimo 1 letra, mínimo un digito y mínimo 10 caracteres en total
* La función validar() debe de retornar:
  * 0 si no hubo ningún error
  * 3 si password < 10
  * 4 si password no contiene letras
  * 5 si password no contiene dígitos

Usar un archivo de cabecera .h: El tipo de datos Usuario y la función validar() deben de estar en una cabecera. Implementar validar() en un archivo diferente de main.

En la función main después de la validación, se debe mostrar un mensaje de error apropiado al código devuelto.

**TIP:** Usar switch para mostrar el mensaje de error.

Entregable:

* Archivo completado: validar.h
* validar.c (Implementación de función)
* main.c
