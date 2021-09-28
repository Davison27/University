#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <arpa/inet.h>

/* --------------------------------------------------------------------------------------
 
 El servidor envia un número al servidor que espera recibir para poder enviar algún DAYTIME

---------------------------------------------------------------------------------------- */
 
int main ( )
{
     
	/*---------------------------------------------------- 
		Parámetros para el descriptor del socket y 
        buffer para datos 
	-----------------------------------------------------*/
	int Socket_Cliente;
	char Datos[100];
   
   	/* -----------------------------------------------------
   		Parámetros para la información del servidor
   	-----------------------------------------------------*/
   	struct sockaddr_in Servidor;  
   	socklen_t Longitud_Servidor;
    
    /* -----------------------------------------------------
   		Parámetros para la función select
   	-----------------------------------------------------*/

    struct timeval timeout;
	fd_set lectura;
	int salida;
	char cadena[60];

	//Inicializar la estructua timeval
	timeout.tv_sec = 5;
	timeout.tv_usec = 0;
  
  






   	/* --------------------------------------------------
			Se abre el socket cliente
		---------------------------------------------------*/
		Socket_Cliente = socket (AF_INET, SOCK_DGRAM, 0);
		if (Socket_Cliente == -1)
		{
			printf ("No se puede abrir el socket cliente\n");
    			exit (-1);	
		}

 		/*---------------------------------------------------------------------
			Necesitamos una estructura con la informaci\ufffdn del Servidor
			para poder solicitarle un servicio.
   		----------------------------------------------------------------------*/
		Servidor.sin_family = AF_INET;
		Servidor.sin_port = htons(2000);
		Servidor.sin_addr.s_addr =  inet_addr("127.0.0.1");
  	 	Longitud_Servidor = sizeof(Servidor);

	    /*---------------------------------------------------------------------
			Aquí vamos a realizar un select para comprobar si el servidor 
            esta activo, en caso contrario saldrá del programa.
   		----------------------------------------------------------------------*/

        //Inicializar los conjuntos fd_set
        FD_ZERO(&lectura);
        FD_SET(0,&lectura);
        
        for(int i=0; i<3 ; i++){
        salida = select(1,&lectura,NULL,NULL,&timeout);
            if(salida != 0 && salida !=-1){
                i=3;
            }
        }
        
        if(salida == -1)
        {
            printf("Se ha producido un error en select\n");
        }
        else if(salida == 0)
        {
            printf("Se ha agotado el tiempo\n");

        }


        /*-----------------------------------------------------------------------
			Se env\ufffda mensaje al Servidor
		-----------------------------------------------------------------------*/

        printf("Inserte un valor de los siguientes:\n\n");
        printf("Inserte 'DAY' para recibir el día\n");
        printf("Inserte 'TIME' para recibir la hora\n");
        printf("Inserte 'DAYTIME' para recibir el día y la hora\n");
        scanf("%s", Datos);

		char enviado = sendto (Socket_Cliente, (char *) &Datos, sizeof(Datos), 0,
			(struct sockaddr *) &Servidor, Longitud_Servidor);
   
   	    /*if (enviado != 'DAY' || enviado != 'TIME' || enviado != 'DAYTIME')
    	{
			printf("Error al solicitar el servicio, el valor insertado no coincide\n");
		}*/
    	/*else
		{*/


        /*----------------------------------------------------------------------
			Esperamos la respuesta del Servidor
		----------------------------------------------------------------------- */ 
			char recibido = recvfrom (Socket_Cliente, (char *)&Datos, sizeof(Datos), 0,
			(struct sockaddr *) &Servidor, &Longitud_Servidor);
			
   		if(recibido == "DAY"){
            printf("%s", recibido);
        }
        if(recibido == "TIME"){
            printf("%s", recibido);
        }
        if(recibido == "DAYTIME"){
            printf("%s", recibido);
        }

   		else
      		printf ("Error al leer del servidor\n");
		
		//}
		
		close(Socket_Cliente);
        return 0;
}