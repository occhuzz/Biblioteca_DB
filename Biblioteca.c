#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<time.h>

typedef struct login
{
    char usuario[20];
    char password[20];
    struct login*sig;
}  nodo;

void cargarUsuarios()
{
    FILE* archivoUsuarios;
    char usuario[20];
    char password[20];

    if(archivoUsuarios = fopen("log_usuarios.txt","r") == NULL)
    {
        printf("No existe el archivo de usuarios\n...Creando archivo de usuarios...\n");
        archivoUsuarios = fopen("log_usuarios.txt","a+");
        printf("Ingrese un nombre de usuario para el Administrador: ");
        gets(usuario);
        printf("Ingrese el password para el Administrador: ");
        gets(password);

        printf("%s\t%s",usuario,password);
    }
    else
    {
        archivoUsuarios = fopen("log_usuarios.txt","ra+");

    }
    printf("Archivo de usuarios abierto");

    fclose(archivoUsuarios);
}

int main()
{
    nodo*raiz=NULL;
    cargarUsuarios();

    return 0;
}