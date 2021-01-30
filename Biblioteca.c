#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

typedef struct
{
    char nombre[20];
    char usuario[20];
    char password[20];
    char accion[100];
    int tipoUsuario;
    struct NODO_USUARIO *siguiente;
} NODO_USUARIO;

NODO_USUARIO* crearNodoUsuario(int tipo)
{
    NODO_USUARIO *nuevo=NULL;
    char nombre[20];
    char usuario[20];
    char password[20];

    nuevo=(NODO_USUARIO*)malloc(sizeof(NODO_USUARIO));

    if(nuevo!= NULL)
    {
        printf("Ingrese el nombre del Administrador: ");
        gets(nuevo->nombre);
        printf("Ingrese un usuario para el Administrador: ");
        gets(nuevo->usuario);
        printf("Ingrese el password para el Administrador: ");
        gets(nuevo->password);
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

        nuevo = crearNodoUsuario(1);

        fprintf(archivoUsuarios,"Nombre Admin: %s\nUser Admin: %s\nPass Admin: %s\nTipo Usuario: %d",nuevo->nombre, nuevo->usuario, nuevo->password, nuevo->tipoUsuario);
    }
    else
    {
        archivoUsuarios = fopen("log_usuarios.txt","ra+");
    }
    printf("Archivo de usuarios abierto");

    fclose(archivoUsuarios);

    return 0;
}

int main()
{
    NODO_USUARIO *cabeza=NULL;

    int user = cargarUsuarios(&cabeza);

    return 0;
}