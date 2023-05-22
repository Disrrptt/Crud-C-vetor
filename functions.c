#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_USUARIOS 1000

int numUsuarios = 0;
//dados do usuario
int universalID[MAX_USUARIOS];
char universalNome[MAX_USUARIOS][100];
char universalEmail[MAX_USUARIOS][100];
char universalSexo[MAX_USUARIOS][10];
char universalEndereco[MAX_USUARIOS][100];
double universalAltura[MAX_USUARIOS];
int universalVacina[MAX_USUARIOS];
//backup
int backupID[MAX_USUARIOS];
char backupNome[MAX_USUARIOS][100];
char backupEmail[MAX_USUARIOS][100];
char backupSexo[MAX_USUARIOS][10];
char backupEndereco[MAX_USUARIOS][100];
double backupAltura[MAX_USUARIOS];
int backupVacina[MAX_USUARIOS];

void AbrirMenu(){

    printf("1 - Adicionar Usuario\n");
    printf("2 - Editar Usuario\n");
    printf("3 - Excluir usuario\n");
    printf("4 - Buscar por Email\n");
    printf("5 - Imprimir todos os usuarios\n");
    printf("6 - Fazer Backup dos usuarios\n");
    printf("7 - Restaurar os dados\n");
    printf("0 - Fechar programa\n");
    printf("Digite a opcao escolhida: ");
}

int AdicionarUsuario(){
    int id, vacina, validacao, encontrado = 0;
    char nome[100], email[100], sexo[10], endereco[100];
    double altura;

    if (numUsuarios >= MAX_USUARIOS){
        printf("Numero de usuarios alcançou o limite D:\n");
        return -1;
    }
    
    srand(time(NULL));
    do{
        id = rand() % 100000;

        for(int i = 0; i < numUsuarios; i++)
        {
            if(universalID[i] == id){
                printf("Usuario ja existe\n");
                id = 00000;
                validacao = 1;
                break;
            }
            else{
                validacao = 0;
            }
        }
    }while (validacao == 1);

    printf("Digite seu nome completo: ");
    scanf(" %[^\n]", nome);

    printf("Digite seu email: ");
    scanf(" %[^\n]", email);

    do{
        validacao = 1;
        for (int i = 0; i < strlen(email); i++)
        {
            if (email[i] == '@'){
                validacao = 0;
                break;
            }
        }

        if(validacao == 1){
            printf("Email invalido, tente novamente: ");
            scanf(" %[^\n]", email);
        }
    }
    while(validacao == 1);

    printf("Digite seu sexo(Masculino/Feminino/Indefinido): ");
    scanf(" %[^\n]", sexo);
    sexo[0] = toupper(sexo[0]);

    while(!(strcmp(sexo, "Masculino") == 0 || strcmp(sexo, "Feminino") == 0 || strcmp(sexo, "Indefinido") == 0)){
            printf("Sexo invalido tente novamente: ");
            scanf(" %[^\n]", sexo);
            sexo[0] = toupper(sexo[0]);
    }

    printf("Digite seu endereco: ");
    scanf(" %[^\n]", endereco);

    printf("Digite sua altura: ");
    scanf("%lf", &altura);
    while(altura > 2 || altura < 1){
            printf("Altura invalida, lembre-se a medida esta em metros\n");
            printf("Tente novamente: ");
            scanf("%lf", &altura);
    }

    printf("Digite o estado de sua vacinacao (1 = Vacinado/ 0 = Nao vacinado): ");
    scanf("%d", &vacina);
    
    while(!(vacina == 1 || vacina == 0)){
            printf("So sao aceitos 1 e 0 como valor\n");
            printf("Tente novamente: ");
            scanf("%d", &vacina);
    }

    universalID[numUsuarios] = id;
    strcpy(universalNome[numUsuarios], nome);
    strcpy(universalEmail[numUsuarios], email);
    strcpy(universalSexo[numUsuarios], sexo);
    strcpy(universalEndereco[numUsuarios], endereco);
    universalAltura[numUsuarios] = altura;
    universalVacina[numUsuarios] = vacina;
    numUsuarios++;

    return 0;
}
