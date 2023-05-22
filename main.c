#include <stdio.h>
#include "functions.h"
#include <string.h>

void AbrirMenu();
int AdicionarUsuario();

int main() {
    char opcao = ' ';

    while (opcao != '0'){
        AbrirMenu();
        scanf(" %c", &opcao);

        switch (opcao)
        {
        case '1':
            AdicionarUsuario();
            break;
        case '2':
            EditarUsuario();
        case '3':
            ExcluirUsuario();
        case '4':
            BuscarPorEmail();
        case '5':
            ImprimirUsuarios();
        case '6':
            BackUp();
        case '7':
            RestaurarDados();
        case '0':
            printf("--------Fechando programa--------\n");
            break;
        default:
            printf("Opcao invalida\n");
            break;
        }
    }
}