/* Implemente un programa en C usando tuberías similar a los existentes en los ficheros
pipe.c y pipe2.c, pero en este caso que un proceso genere dos números aleatorios flotantes 
y envie la suma de ellos al otro proceso para que éste muestre su resultado.
*/

#include <stdio.h>
#include <stdlib.h>   //exit, rand, srand
#include <unistd.h>   //pipe, close, fork, usleep, read, write, getpid, getppid
#include <sys/wait.h> //wait
#include <errno.h>    //Control de errores
#include <string.h>   //strerror
#include <time.h>     //Para la semilla del generador de aleatorios

//CUIDADO -lrt HAY QUE PONERLO PARA COMPILAR

int main()
{
    pid_t flag;                     // Bandera para la espera de los hijos
    int status, status_1, status_2; // Enteros para la espera de los hijos, y las tuberias(Comprobación de la creación de las tuberias)
    float num, num2;                // Flotantes que van guardar los números aleatorios
    int fildes_1[2], fildes_2[2];   // Vectores para las funciones de las tuberias
    const int BSIZE = 100;          // Valor para el tamaño del buffer
    char buf[BSIZE], suma[20];      //
    ssize_t nbytes;                 // Para comprobar el número de bites cuando leemos

    status_1 = pipe(fildes_1); //Tuberia 1
    status_2 = pipe(fildes_2); //Tuberia 2

    //Comprobación de creación de las tuberías
    if (status_1 == -1) //Si da error el primer pipe
    {
        perror("Error en pipe 1");
        exit(EXIT_FAILURE);
    }
    else if (status_2 == -1) //Si da error el segundo pipe
    {
        perror("Error en pipe 2");
        exit(EXIT_FAILURE);
    }

    //creamos el proceso padre con los hijos
    switch (fork())
    {

    case -1: // Ocurrió un error al hacer fork()
        perror("No se ha podido crear el proceso hijo...");
        exit(EXIT_FAILURE);

    case 0:
        if (close(fildes_1[1]) == -1) // En esta tubería solo va a leer por lo que cerramos la escritura
        {
            perror("Error en close");
            exit(EXIT_FAILURE);
        }
        if (close(fildes_2[0]) == -1) // En esta tubería solo va a escribir por lo que cerramos la lectura
        {
            perror("Error en close");
            exit(EXIT_FAILURE);
        }

        // Leer usando READ
        nbytes = read(fildes_1[0], buf, BSIZE); //Guardamos en nbytes la lectura de la tubería 1

        if (nbytes == -1)
        {
            perror("Error en read");
            exit(EXIT_FAILURE);
        }
        else if (nbytes == 0) //read() no ha leido nada -> Se ha llegado a EOF -> El padre ha cerrado la tuberia
            printf("[HIJO]: Detecto que mi padre ha cerrado la tuberia 1...\n");

        else
        {
            //printf("[HIJO]: Leido %s de la tuberia 1.\n", buf);
            int cont = 0;
            char *token;
            char *token_2;
            token = strtok(buf, ";");    //Leo el primer número
            token_2 = strtok(NULL, ";"); //Leo el segundo número

            float a, b;

            a = atof(token);
            b = atof(token_2);

            printf("[HIJO]: Leido %f y %f\n", a, b);

            printf("[HIJO]: sumamos ambos...\n");

            float x = a + b;

            sprintf(suma, "%f", x);
        }

        if (close(fildes_1[0]) == -1) //Se termina de leer -> Cerramos filfes[0]
        {
            perror("Error en close");
            exit(EXIT_FAILURE);
        }
        else
            printf("[HIJO]: Tuberia 1 cerrada.\n");

        if (write(fildes_2[1], suma, 20) == -1)
        {
            perror("Error en write");
            exit(EXIT_FAILURE);
        }
        printf("[HIJO]: He escrito en la tuberia 2.\n");

        if (close(fildes_2[1]) == -1) //Se termina de leer -> Cerramos filfes[0]
        {
            perror("Error en close");
            exit(EXIT_FAILURE);
        }
        else
            printf("[HIJO]: Tuberia 2 cerrada.\n");

        exit(EXIT_SUCCESS);

    default:

        if (close(fildes_1[0]) == -1) // En esta tuberia se va a escribir por lo que cerramos la lectura
        {
            perror("Error en close");
            exit(EXIT_FAILURE);
        }

        if (close(fildes_2[1]) == -1) // En esta tuberia se va a leer por lo que cerramos la escritura
        {
            perror("Error en close");
            exit(EXIT_FAILURE);
        }

        printf("[PADRE]: Se van a generar dos numeros de forma aleatoria.\n");

        srand(time(NULL)); //Semilla para la generacion de numeros aleatorios
        // Número aleatorio entre 0 y 4999
        num = (float)rand() / (float)(RAND_MAX / 5000);  //Asiganmos los números FLOTANTES aleatorios a num 1
        num2 = (float)rand() / (float)(RAND_MAX / 5000); //Asiganmos los números FLOTANTES aleatorios a num 2

        printf("[PADRE]: Los numeros son %f y %f.\n", num, num2);

        sprintf(buf, "%f;%f", num, num2); //mete ambos numeros en el buffer buf

        // Escribimos datos en la tubería
        if (write(fildes_1[1], buf, 20) == -1)
        {
            perror("Error en write");
            exit(EXIT_FAILURE);
        }
        printf("[PADRE]: He escrito los dos números en la tuberia 1.\n");

        // El hijo verá FEOF (por hacer close)
        if (close(fildes_1[1]) == -1)
        {
            perror("Error en close");
            exit(EXIT_FAILURE);
        }
        else
            printf("[PADRE]: Tuberia 1 cerrada.\n");

        nbytes = read(fildes_2[0], suma, 20); //Se va a quedar aqui parado hasta que haya algo que leer en la fildes_2

        if (nbytes == -1)
        {
            perror("Error en read");
            exit(EXIT_FAILURE);
        }
        else if (nbytes == 0) //read() no ha leido nada -> Se ha llegado a EOF -> El padre ha cerrado la tuberia
            printf("[PADRE]: Detecto que mi hijo ha cerrado la tuberia 2...\n");
        else
            printf("[PADRE]: Leido %s de la tuberia 2.\n", suma);

        if (close(fildes_2[0]) == -1) //Se termina de leer -> Cerramos filfes[0]
        {
            perror("Error en close");
            exit(EXIT_FAILURE);
        }
        else
            printf("[PADRE]: Tuberia 2 cerrada.\n");

        //Control de errores

        while ((flag = wait(&status)) > 0)
        {
            if (WIFEXITED(status))
            {
                printf("Proceso Padre, Hijo con PID %ld finalizado, status = %d\n", (long int)flag, WEXITSTATUS(status));
            }
            else if (WIFSIGNALED(status))
            { //Para seniales como las de finalizar o matar
                printf("Proceso Padre, Hijo con PID %ld finalizado al recibir la señal %d\n", (long int)flag, WTERMSIG(status));
            }
        }
        if (flag == (pid_t)-1 && errno == ECHILD)
        {
            printf("Proceso Padre %d, no hay mas hijos que esperar. Valor de errno = %d, definido como: %s\n", getpid(), errno, strerror(errno));
        }
        else
        {
            printf("Error en la invocacion de wait o waitpid. Valor de errno = %d, definido como: %s\n", errno, strerror(errno));
            exit(EXIT_FAILURE);
        }

        exit(EXIT_SUCCESS);
    } //switch
}

/*
while ( (flag=waitpid(-1,&status,WUNTRACED | WCONTINUED)) > 0 ) 
{
    if (WIFEXITED(status)) 
    {
	    printf("Proceso Padre %d, hijo con PID %ld finalizado, status = %d\n", getpid(), (long int)flag, WEXITSTATUS(status));
    } 
    else if (WIFSIGNALED(status))  
    {
	    printf("Proceso Padre %d, hijo con PID %ld finalizado al recibir la señal %d\n", getpid(), (long int)flag, WTERMSIG(status));
    } 
    else if (WIFSTOPPED(status))  //Para cuando se para un proceso. Con wait() no nos serviria.
    {
	    printf("Proceso Padre %d, hijo con PID %ld parado al recibir la señal %d\n", getpid(), (long int)flag,WSTOPSIG(status));
    } 
    else if (WIFCONTINUED(status))  //Para cuando se reanuda un proceso parado. Con wait() no nos serviria.
    {
	    printf("Proceso Padre %d, hijo con PID %ld reanudado\n", getpid(), (long int) flag);		  
    }
}//while

if (flag==(pid_t)-1 && errno==ECHILD)
{
    printf("Proceso Padre %d, no hay mas hijos que esperar. Valor de errno = %d, definido como: %s\n", getpid(), errno, strerror(errno));
}
else
{
    printf("Error en la invocacion de wait o waitpid. Valor de errno = %d, definido como: %s\n", errno, strerror(errno));
    exit(EXIT_FAILURE);
}

*/