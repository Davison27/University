/*Implemente un programa que obtenga e imprima información sobre usuarios del sistema(todoslos campos de la estructurapasswd) 
e información sobre grupos del sistema (GIDynombre del grupomediante la estructuragroup), según las opciones recibidas por la 
línea deargumentos.

La opción-u/--userse utilizará para indicar un usuario. Si le pasamos como argu-mento un número, lo 
interpretará como UID, en caso contrario como el nombre delusuario. Se mostrará la información correspondiente a su 
estructurapasswd.

La opción-g/--groupse utilizará para indicar un grupo. Si le pasamos como argu-mento un número, lo 
interpretará como GID, en caso contrario como el nombre delgrupo. Se mostrará la información correspondiente a su estructuragroup.

La opción-a/--activeserá equivalente a especificar--usercon el usuario actual.

La opción-m/--maingroupmodifica a--usero--activey hace que imprima lainformación de su grupo principal (mismo formato que--group).

Si se invoca al programa con la opción-so con--allgroups, se mostrarán todoslos grupos del sistema, junto con su identificador. 
Para ello recorra el fichero corres-pondiente (le permitirá recordar como gestionar y buscar en cadenas) y luego vayaextrayendo 
información como si se invocase la opción--group. No muestre directa-mente el contenido del fichero, recórralo y muestre la información 
por cada grupo quehaya.

Si se invoca al programa sin ninguna opción se mostrará la información del usuarioactual (con el mismo formato que que-u/--user) y 
del grupo al que pertenece (conel mismo formato que que-g/--group).

Se creará una opción de ayuda-h/--helppara mostrar información sobre cada unode  los  usos  del  programa.  Esa  información  también
se  mostrará  cuando  el  usuariocometacualquier error en la invocación del programa.
  
Tenga también en cuenta el siguiente control de errores:

Asegurar que se pasan nombres e identificadores de usuarios o grupos válidos queexistan en la máquina.Asegurar que no se puedan pasar 
por línea de comandos opciones que sean incompa-tibles. Las únicas combinaciones posibles son:

•--help, junto con cualquiera (se ignoran las demás)
•  vacío
•--user <usuario>
•--user <usuario> --maingroup
•--active
•--active --maingroup
•--group <grupo>
•--allgroups
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <getopt.h>
#include <stdbool.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <string.h>

void help()
{
    printf("Uso del programa: ejercicio1 [opciones]\n");
    printf("Opciones:\n");
    printf("-h, --help\n");
    printf("Imprimir esta ayuda\n");
    printf("-u, --user (<nombre>|<uid>) Información sobre el usuario\n");
    printf("-a, --active\n");
    printf("Información sobre el usuario activo actual\n");
    printf("-m, --maingroup\n");
    printf("Además de info de usuario, imprimir la info de su\n");
    printf("grupo principal\n");
    printf("-g, --group (<nombre>|<gid>) Información sobre el grupo\n");
    printf("-s, --allgroups\n");
    printf("Muestra info de todos los grupos del sistema\n");
}

void imprimirDatosUsuario(struct passwd *pw)
{
    printf("Nombre: %s\n", pw->pw_gecos);
    printf("Login: %s\n", pw->pw_name);
    printf("Password: %s\n", pw->pw_passwd);
    printf("UID: %d\n", pw->pw_uid);
    printf("Home: %s\n", pw->pw_dir);
    printf("Shell: %s\n", pw->pw_shell);
    printf("Número de grupo principal: %d\n", pw->pw_gid);
}

void imprimirDatosGrupo(struct group *gr)
{
    printf("Nombre del grupo: %s\n", gr->gr_name);
    printf("GID: %d\n", gr->gr_gid);
}

int main(int argc, char **argv)
{
    //DECLARO LAS BANDERAS, POR DEFECTO DESACTIVADAS
    bool hflag = false;
    char *uvalue = NULL;
    bool mflag = false;
    bool aflag = false;
    char *gvalue = NULL;
    bool sflag = false;

    //ESTRUCTURAS PARA CARGAR INFORMACION
    struct passwd *pw; //donde almaceno informacion de un usuario
    struct group *gr;  //aqui de un grupo

    //ESTRUCTURA DONDE ALMACENAMOS LA RELACION DE NOMBRES CORTOS Y LARGOS
    static struct option long_options[] = {
        //{<nombre largo>, <recibe/no recibe argumento>, NULL, <nombre corto>}
        {"help", no_argument, NULL, 'h'},
        {"user", required_argument, NULL, 'u'},
        {"maingroup", no_argument, NULL, 'm'},
        {"active", no_argument, NULL, 'a'},
        {"group", required_argument, NULL, 'g'},
        {"allgroups", no_argument, NULL, 's'},
        /* Necesario para indicar el final de las opciones */
        {0, 0, 0, 0}};

    //RECONOZCO LAS OPCIONES RECIBIDAS Y ACTIVO SUS RESPECTIVAS BANDERAS
    int c;
    while ((c = getopt_long(argc, argv, "hu:mag:s", long_options, NULL)) != -1)
    {
        switch (c)
        {
        case 'h':
            hflag = true;
            break;

        case 'u':
            uvalue = optarg;
            break;

        case 'm':
            mflag = true;
            break;

        case 'a':
            aflag = true;
            break;

        case 'g':
            gvalue = optarg;
            break;

        case 's':
            sflag = true;
            break;

        case '?':
            /*if (optopt == 'c')
                fprintf(stderr,
                        "La opción %c requiere un argumento. Valor de opterr = "
                        "%d\n",
                        optopt, opterr);
            else if (isprint(optopt))
                fprintf(stderr,
                        "Opción desconocida \"-%c\". Valor de opterr = %d\n",
                        optopt, opterr);
            else
                fprintf(stderr, "Caracter `\\x%x'. Valor de opterr = %d\n",
                        optopt, opterr);
            return 1;*/
            /*No hace falta realizar esta comprobación de errores*/
        default:
            abort();
        }
    }

    //CONTROL DE ERRORES
    if (uvalue != NULL && (aflag == true || gvalue != NULL || sflag == true))
    {
        printf("La opcion --user solo se puede acompañar de --maingroup.\n");
        help();
        return 1;
    }

    if (aflag == true && (uvalue != NULL || gvalue != NULL || sflag == true))
    {
        printf("La opcion --user solo se puede acompañar de --maingroup.\n");
        help();
        return 1;
    }

    if (gvalue != NULL && (uvalue != NULL || mflag == true || aflag == true || sflag == true))
    {
        printf("La opcion --group no se puede acompañar de ninguna otra opcion.\n");
        help();
        return 1;
    }

    if (sflag == true && (uvalue != NULL || mflag == true || gvalue != NULL || aflag == true))
    {
        printf("La opcion --allgroups no se puede acompañar de ninguna otra opcion.\n");
        help();
        return 1;
    }

    if (mflag == true && uvalue == NULL && aflag == false)
    {
        printf("La opcion --maingroup debe ir acompañada de --user o --active.\n");
        help();
        return 1;
    }

    //AÑADIR FUNCIONALIDAD SEGÚN LAS BANDERAS ACTIVAS
    if (hflag == true) /*Si la bandera relacionada con help esta activa accedemos e imprimimos la función help()*/
    {
        help();
        return 0; /*Devolvemos 0 para cerrar el programa*/
    }

    //Se ha activado la opcion --user
    if (uvalue != NULL)
    {
        /*
        Para cargar el struct passwd con los datos de un usuario, necesito o bien el nombre del usuario, 
        o bien el UID del usuario. 
        */

        //Lo primero es ver si uvalue contiene un nombre de usuario o un uid y cargar la informacion de dicho usuario
        char *endptr = NULL;
        long uid = strtol(uvalue, &endptr, 10);         /*La función strtol convierte el uvalue en un long itn que se guarda en endptr*/
        if (((*uvalue) != '\0') && ((*endptr) == '\0')) /*Si el valor captado por la bandera u es distinto de 0*/
        {
            //strtol tiene éxito, la cadena contiene un número
            if ((pw = getpwuid(uid)) == NULL)
            {
                printf("El UID de usuario no existe en el sistema.\n");
                return 1;
            }
        }
        else
        {
            //strtol ha encontrado un error, la cadena NO contiene un número
            if ((pw = getpwnam(uvalue)) == NULL)
            {
                printf("El nombre de usuario no existe en el sistema.\n");
                return 1;
            }
        }

        //Imprimo la informacion del usuario
        imprimirDatosUsuario(pw);

        //Miro si la bandera mflag esta activa
        if (mflag == true)
        {
            gr = getgrgid(pw->pw_gid);
            imprimirDatosGrupo(gr);
        }
    }

    //Se ha activado la opcion --active
    if (aflag == true)
    {
        //char * usuario_activo = getlogin();
        char *usuario_activo = getenv("USER");
        pw = getpwnam(usuario_activo);

        imprimirDatosUsuario(pw);

        if (mflag == true)
        {
            gr = getgrgid(pw->pw_gid);
            imprimirDatosGrupo(gr);
        }
    }

    //Se ha activado la opcion --group
    if (gvalue != NULL)
    {
        char *endptr = NULL;
        long gid = strtol(gvalue, &endptr, 10);
        if (((*gvalue) != '\0') && ((*endptr) == '\0'))
        {
            //strtol tiene éxito, la cadena contiene un número
            if ((gr = getgrgid(gid)) == NULL)
            {
                printf("El GID de grupo no existe en el sistema.\n");
                return 1;
            }
        }
        else
        {
            //strtol ha encontrado un error, la cadena NO contiene un número
            if ((gr = getgrnam(gvalue)) == NULL)
            {
                printf("El nombre de grupo no existe en el sistema.\n");
                return 1;
            }
        }

        imprimirDatosGrupo(gr); /*LLamamos a la función de imprimir los datos pasandole l variable gr*/
    }

    //Se ha activado la opcion --allgroups
    if (sflag == true)
    {
        FILE *fich = NULL;               /*Creamos una variable de tipo fich para leer los grupos*/
        fich = fopen("/etc/group", "r"); /*fich va a guardar el fichero abierto de grupos en modo lectura*/
        if (fich == NULL)
        {
            printf("Error al abrir el fichero /etc/group\n");
            return 1;
        }

        char lineaLeida[500];
        char *nombreGrupo;

        while (fgets(lineaLeida, 500, fich))
        {
            nombreGrupo = strtok(lineaLeida, ":"); /*La función strtok divide la la variable cada vez que encuentra :*/
            gr = getgrnam(nombreGrupo);            /*gr va a guardar la información de los usuarios del grupo*/
            imprimirDatosGrupo(gr);                /*Llamamos a la función que imprime los datos*/
        }

        fclose(fich); /*Cerramos el fichero que teníamos abierto*/
    }

    //CASO VACIO
    if (uvalue == NULL && aflag == false && gvalue == NULL && sflag == false)
    {
        char *usuario_activo = getenv("USER");
        pw = getpwnam(usuario_activo);
        imprimirDatosUsuario(pw);

        gr = getgrgid(pw->pw_gid);
        imprimirDatosGrupo(gr);
    }

    return 0;
}