#include "csapp.h"

enum Estado {EXIT = 0, ESPERANDO_NOMBRE, ARCHIVO_INVALIDO, ENVIANDO_ARCHIVO} estado; //Estados para la FSM

void responder_cliente(int connfd);

int main(int argc, char **argv)
{
	int listenfd, connfd;
	unsigned int clientlen;
	struct sockaddr_in clientaddr;
	struct hostent *hp;
	char *haddrp, *port;

	if (argc != 2) {
		fprintf(stderr, "usage: %s <port>\n", argv[0]);
		exit(0);
	}
	port = argv[1];

	listenfd = Open_listenfd(port);
	while (1) {
		clientlen = sizeof(clientaddr);
		connfd = Accept(listenfd, (SA *)&clientaddr, &clientlen);

		/* Determine the domain name and IP address of the client */
		hp = Gethostbyaddr((const char *)&clientaddr.sin_addr.s_addr,
					sizeof(clientaddr.sin_addr.s_addr), AF_INET);
		haddrp = inet_ntoa(clientaddr.sin_addr);
		printf("server connected to %s (%s)\n", hp->h_name, haddrp);

		responder_cliente(connfd);
		Close(connfd);
	}
	exit(0);
}

void responder_cliente(int connfd)
{
	char buf[MAXLINE];
	char filename[MAXLINE];
	char *filebuf;
	rio_t rio;
	size_t n;
	struct stat sbuf;
	FILE * fp;

	estado = ESPERANDO_NOMBRE;
	Rio_readinitb(&rio, connfd);
	while(estado) {
		switch(estado)
		{
			case ESPERANDO_NOMBRE:
				n = Rio_readlineb(&rio, buf, MAXLINE);
				printf("Petición recibida para archivo %s", buf);
				strcpy(filename,buf); //Guardar nombre archivo en filename
				filename[n-1] = '\0'; //remueve el \n al final del nombre de archivo
				if(stat(filename,&sbuf) < 0) //Verificar si el archivo existe
					estado = ARCHIVO_INVALIDO;
				else {
					if(sbuf.st_size > 0) {
						n = sprintf(buf, "%lu\n", sbuf.st_size); //Convierte el tamaño en cadena de caracteres
						Rio_writen(connfd, buf, n); //Envia el tamaño al cliente
						estado = ENVIANDO_ARCHIVO; //Cambio de estado
					}else
						estado = ARCHIVO_INVALIDO;
				}

				break;
			case ARCHIVO_INVALIDO:
				Rio_writen(connfd, "0\n", 2); //Si el archivo no ha sido encontrado o esta vacío, envia 0 al cliente
				estado = EXIT;
				break;
			case ENVIANDO_ARCHIVO:
				n = Rio_readlineb(&rio, buf, MAXLINE); //Espera el OK del cliente
				if(n!=3)
					estado = EXIT; //En este caso se asume que por alguna razón, el cliente no envió OK
				else {
					printf("Enviando archivo...\n");
					fp = Fopen(filename,"r");
					filebuf = Malloc(sbuf.st_size);
					n = Fread(filebuf, 1, sbuf.st_size, fp); //Se lee el archivo y se guarda en un buffer
					if (n > 0)
						Rio_writen(connfd, filebuf, n);	//Se envia el contenido del archivo al cliente
					Free(filebuf);
					Fclose(fp);

					estado = EXIT;
				}
				break;
			default:
				estado = EXIT;
		}
	}
}
