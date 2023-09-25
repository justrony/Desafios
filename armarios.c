#include <stdio.h>
#include <stdlib.h>
#include <time.h>

unsigned char armarios = 0;

void ocuparArmario() {
    if (armarios == 255) {
        printf("Não há armários livres\n");
        return;
    }
    int numArmario;
    do {
        numArmario = rand() % 8;
    } while ((armarios >> numArmario) & 1);
    armarios |= (1 << numArmario);
    printf("Armario %d ocupado!\n", numArmario);
}

void liberarArmario() {
    int numArmario;
    printf("Qual armario deve ser liberado?[0-7]: ");
    if (scanf("%d", &numArmario) != 1) {
        printf("Erro ao ler o número do armario\n");
        return;
    }

    if (numArmario >= 0 && numArmario <= 7) {
        if ((armarios >> numArmario) & 1) {
            armarios &= ~(1 << numArmario); 
            printf("Armario %d liberado!\n", numArmario);
        } else {
            printf("Armario já está livre!\n");
        }
    } else {
        printf("Armario Invalido\n");
    }
}

int main() {
    
    srand(time(NULL));
    int op;

    do {
        printf("Menu\n[1] Ocupar Armario\n[2] Liberar Armarios\n[3] Sair\n: ");
        if (scanf("%d", &op) != 1) {
            printf("Erro ao ler a opção do menu\n");
            return 1;
        }

        switch (op) {
            case 1:
                ocuparArmario();
                break;
            case 2:
                liberarArmario();
                break;
            case 3:
                puts("Finalizado!");
                break;
            default:
                puts("Opção inválida");
                break;
        }
    } while (op != 3);

    return 0;
}
