#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

void AbrirMenu();
#define MAXIMO_USUARIOS 1000
int numUsuarios = 0;
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

int main()
{
    int id, vacina, validacao;
    char nome[100], email[100], sexo[10], endereco[100], vacinas[10], opcao = ' ';
    double altura;

    do {
        AbrirMenu();
        printf("Escolha a sua opcao");
        scanf(" %c",&opcao);
        switch (opcao)
        {
        case '1':
            if (numUsuarios >= MAXIMO_USUARIOS){
                printf("Numero de usuarios alcançou o limite D:\n");
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
                        break;
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
            } while(validacao == 1);
   

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
            numUsuarios = adicionarUsuario(id, nome, email, sexo, endereco, altura, vacina, numUsuarios, universalID, universalNome, universalEmail, universalSexo, universalEndereco, universalAltura, universalVacina);
            break; 
        case '2':
            printf("Digite o email do usuario que voce deseja editar");
            break;
        default: 
            break;
        }
        
    } while (opcao!='0');
}