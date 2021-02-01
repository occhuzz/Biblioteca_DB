#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>
#include<string.h>

typedef struct
{
    char nombre[20];
    char usuario[20];
    char password[20];
    char accion[100];
    int tipoUsuario;
    struct NODO_USUARIO *siguiente;
} NODO_USUARIO;

NODO_USUARIO* crearNodoUsuario(int tipo, char nombre[20], char usuario[20], char password[20])
{
    NODO_USUARIO *nuevo=NULL;

    nuevo=(NODO_USUARIO*)malloc(sizeof(NODO_USUARIO));

    if(nuevo!= NULL)
    {
        strcpy(nuevo->nombre,nombre);
        strcpy(nuevo->usuario,usuario);
        strcpy(nuevo->password,password);
        nuevo->tipoUsuario = tipo;
        nuevo->siguiente = NULL;
    }
    return nuevo;
}

int cargarUsuarios()
{
    FILE* archivoUsuarios;

    if(archivoUsuarios = fopen("log_usuarios.txt","r") == NULL)
    {
        printf("No existe el archivo de usuarios\n...Creando archivo de usuarios...\n");
        archivoUsuarios = fopen("log_usuarios.txt","a+");

        NODO_USUARIO* nuevo = NULL;
        char nombre[20];
        char usuario[20];
        char password[20];

        printf("Ingrese el nombre del Administrador: ");
        gets(nombre);
        printf("Ingrese un usuario para el Administrador: ");
        gets(usuario);
        printf("Ingrese el password para el Administrador: ");
        gets(password);

        nuevo = crearNodoUsuario(1, nombre, usuario, password);

        fprintf(archivoUsuarios,"%d %s %s %s",nuevo->tipoUsuario, nuevo->nombre, nuevo->usuario, nuevo->password);

        printf("\nADMIN CARGADO DESDE CONSOLA:\nTipo: %d\nNombre: %s\nUsuario: %s\nPassword: %s",nuevo->tipoUsuario, nuevo->nombre, nuevo->usuario, nuevo->password);
    }
    else
    {
        archivoUsuarios = fopen("log_usuarios.txt","ra+");
        printf("Archivo de usuarios abierto");

        NODO_USUARIO* nuevo = NULL;
        int tipo;
        char nombre[20];
        char usuario[20];
        char password[20];

        fscanf(archivoUsuarios,"%d %s %s %s", &tipo, &nombre, &usuario, &password);

        nuevo = crearNodoUsuario(tipo, nombre, usuario, password);

        printf("\nADMIN LEIDO DESDE TXT:\nTipo: %d\nNombre: %s\nUsuario: %s\nPassword: %s",nuevo->tipoUsuario, nuevo->nombre, nuevo->usuario, nuevo->password);
    }

    fclose(archivoUsuarios);

    return 0;
}

int main()
{
    NODO_USUARIO *cabeza=NULL;

    int user = cargarUsuarios(&cabeza);

    return 0;
}