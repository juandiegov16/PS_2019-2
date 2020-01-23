# Monitor remoto de rendimiento
El proyecto final consiste en la creación de una aplicación cliente – servidor para monitorear remotamente el estado de una computadora.

## Servidor
El programa servidor debe poder mantener varias conexiones de clientes simultáneamente y tener el siguiente uso, el cuál debe mostrarse al usar la opción –h (mostrar ayuda en inglés):

```
./monitord –h
monitord broadcasts the host's usage and performance data to all connected clients.

Usage:
  monitord [-c] [<port>]
  monitord [-l <log_file>] [<port>]
  monitord -h

Options:
  -h             Help, show this screen.
  -c             Console mode.
  -l <log_file>  Log file to use [default: log.txt].
```


Al establecerse una conexión, *monitord* debe enviar al cliente la siguiente información, cada segundo:

* Versión del sistema operativo
* Uptime
* Promedio carga en 1 minuto, 5 minutos y 15 minutos
* Número de procesadores
* Porcentaje de uso de cada procesador
* Memoria total
* Memoria libre
* Número de procesos
* Número de procesos en ejecución

## Cliente
El programa cliente tendrá el siguiente uso:
```
./monitorc –h
monitorc connects to a remote monitord service and displays the server’s usage and performance data.

Usage:
  monitorc [<ip>] [<port>]
  monitorc -h

Options:
  -h             Help, show this screen.
```

La comunicación cliente-servidor debe usar [Protocol Buffers](https://developers.google.com/protocol-buffers/) de Google. Más detalles sobre la implementación del proyecto en **Proyecto final Programacion de Sistemas.pdf**.

El archivo .proto de definición de mensajes a usar: **monitor.proto**

La forma de comunicación entre cliente y servidor se aprecia a continuación:
![](https://i.imgur.com/mAzpkWc.png)

## Evaluación
* El código fuente debe estar en una carpeta *src*, cabeceras en una carpeta *include* y librerías en una carpeta *lib*.
* Debido al uso de un protocolo común con Protocol Buffers, el servidor deberá poder comunicarse con clientes de terceros (por ejemplo un cliente desarrollado por el profesor o por otros compañeros).
