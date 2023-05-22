#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAXIMO_USUARIOS 1000


//dados dos usuarios
int universalID[MAXIMO_USUARIOS];
char universalNome[MAXIMO_USUARIOS][100];
char universalEmail[MAXIMO_USUARIOS][100];
char universalSexo[MAXIMO_USUARIOS][10];
char universalEndereco[MAXIMO_USUARIOS][100];
double universalAltura[MAXIMO_USUARIOS];
int universalVacina[MAXIMO_USUARIOS];
//backup para as informacoes 
int backupID[MAXIMO_USUARIOS];
char backupNome[MAXIMO_USUARIOS][100];
char backupEmail[MAXIMO_USUARIOS][100];
char backupSexo[MAXIMO_USUARIOS][10];
char backupEndereco[MAXIMO_USUARIOS][100];
double backupAltura[MAXIMO_USUARIOS];
int backupVacina[MAXIMO_USUARIOS];


void AbrirMenu(){
    printf("1 - Adicionar um novo Usuario\n");
    printf("2 - Editar Usuario\n");
    printf("3 - Excluir usuario\n");
    printf("4 - Buscar usuario por Email\n");
    printf("5 - Imprimir todos os usuarios existentes\n");
    printf("6 - Fazer Backup dos usuarios\n");
    printf("7 - Restaurar os dados do usuario\n");
    printf("0 - Fechar o algoritimo\n");
 

}

int adicionarUsuario(int id, char nome[100], char email[100], char sexo[10], char endereco[100], double altura, int vacina, int numUsuarios){
    universalID[numUsuarios] = id;
    strcpy(universalNome[numUsuarios], nome);
    strcpy(universalEmail[numUsuarios], email);
    strcpy(universalSexo[numUsuarios], sexo);
    strcpy(universalEndereco[numUsuarios], endereco);
    universalAltura[numUsuarios] = altura;
    universalVacina[numUsuarios] = vacina;
    numUsuarios++;

    return numUsuarios;


}