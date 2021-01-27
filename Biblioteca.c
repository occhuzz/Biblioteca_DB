#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char usuario[20];
    char password[20];

} login;

void cargarUsuarios()
{
    FILE* archivoUsuarios;

    if(archivoUsuarios = fopen("log_usuarios.txt","r") == NULL)
    {
        printf("No existe el archivo de usuarios\n...Creando archivo de usuarios...\n");
        archivoUsuarios = fopen("log_usuarios.txt","a+");
    }
    else
    {
        archivoUsuarios = fopen("log_usuarios.txt","ra+");

    }
    printf("Archivo de usuarios abierto");


}

int main()
{
    cargarUsuarios();

    return 0;
}