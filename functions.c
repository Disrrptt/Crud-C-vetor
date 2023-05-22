#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAXIMO_USUARIOS 1000

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

int adicionarUsuario(int id, char nome[100], char email[100], char sexo[10], char endereco[100], double altura, int vacina, int numUsuarios, int universalID[MAXIMO_USUARIOS],
    char universalNome[MAXIMO_USUARIOS][100],
    char universalEmail[MAXIMO_USUARIOS][100],
    char universalSexo[MAXIMO_USUARIOS][10],
    char universalEndereco[MAXIMO_USUARIOS][100],
    double universalAltura[MAXIMO_USUARIOS],
    int universalVacina[MAXIMO_USUARIOS]){
    
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
int EditarUsuario(char email[100]){
    int id, vacina, validacao, encontrado = 0;
    char nome[100], sexo[10], endereco[100];
    double altura;

    for(int i = 0; i < numUsuarios + 1; i++){
        if(strcmp(universalEmail[i], email) == 0){

            printf("id: %d\n", universalID[i]);
            printf("nome: %s\n", universalNomeCompleto[i]);
            printf("sexo: %s\n", universalSexo[i]);
            printf("endereco: %s\n", universalEndereco[i]);
            printf("altura: %.2lf\n", universalAltura[i]);
            printf("status de vacinacao: %d\n", universalVacina[i]);

            printf("Digite seu nome completo: ");
            scanf(" %[^\n]", nome);

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

            strcpy(universalNomeCompleto[i], nome);
            strcpy(universalEmail[i], email);
            strcpy(universalSexo[i], sexo);
            strcpy(universalEndereco[i], endereco);
            universalAltura[i] = altura;
            universalVacina[i] = vacina;

            printf("novo nome: %s\n", universalNomeCompleto[i]);
            printf("novo sexo: %s\n", universalSexo[i]);
            printf("novo endereco: %s\n", universalEndereco[i]);
            printf("nova altura: %.2lf\n", universalAltura[i]);
            printf("novo status de vacinacao: %d\n", universalVacina[i]);

            return 0;
        }
    } 
    printf("Usuario nao encontrado.\n");
    return -1;
}