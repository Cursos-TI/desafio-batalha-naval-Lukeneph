#include <stdio.h>

// Inicio do codigo, função do tabuleiro naval
int main() {
    char linha[10] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};
    int Tabuleiro[10][10];

// Inicializa o tabuleiro com (zeros = agua)

    for (int Numero1 = 0; Numero1 < 10; Numero1++) {
        for (int Numero2 = 0; Numero2 < 10; Numero2++) {
            Tabuleiro[Numero1][Numero2] = 0;
        }
    }

// Coloca o tamanho do navio no tabuleiro

    int NavioHorizontal[3] = {3, 3, 3};
    int NavioVertical[3] = {3, 3, 3};

// Define a posição do navio no tabuleiro

    int linhaX = 3, colunaX = 7;
    int LinhaY = 6, colunaY = 3;

// Coloca o navio horizontal no tabuleiro

    if (linhaX >= 0 && linhaX < 10 && colunaX >= 0 && colunaX + 2 < 10) {
        int sobreposicao = 0;
        for (int i = 0; i < 3; i++) {
            if (Tabuleiro[linhaX][colunaX + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (sobreposicao == 0) {
            for (int i = 0; i < 3; i++) {
                Tabuleiro[linhaX][colunaX + i] = NavioHorizontal[i];
            }
        } else {
            printf("Erro: Sobreposição de navios na posição horizontal.\n"); // mensagem de erro
            return 1;
        }
    } else {
        printf("Erro: Posição do navio horizontal fora dos limites do tabuleiro.\n"); // mensagem de erro
        return 1;
    }

// Coloca o navio vertical no tabuleiro

    if (LinhaY >= 0 && LinhaY + 2 < 10 && colunaY >= 0 && colunaY < 10) {
        int sobreposicao = 0;
        for (int i = 0; i < 3; i++) {
            if (Tabuleiro[LinhaY + i][colunaY] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (sobreposicao == 0) {
            for (int i = 0; i < 3; i++) {
                Tabuleiro[LinhaY + i][colunaY] = NavioVertical[i];
            }
        } else {
            printf("Erro: Sobreposição de navios na posição vertical.\n"); // mensagem de erro
            return 1;
        }
    } else {
        printf("Erro: Posição do navio vertical fora dos limites do tabuleiro.\n"); // mensagem de erro
        return 1;
    }
// imprime as Letras no tabuleiro

    printf("  ");
    for (int c = 0; c < 10; c++) {
        printf(" %c ", linha[c]);
    }
    printf("\n");
// imprime os numeros no tabuleiro
    for (int Numero1 = 0; Numero1 < 10; Numero1++) {
        int Numero2 = Numero1 + 1;

        if (Numero2 < 10) {
            printf("%d ", Numero2);
        } else {
            printf("%d", Numero2);
        }
        for (int Numero3 = 0; Numero3 < 10; Numero3++) {
            printf(" %d ", Tabuleiro[Numero1][Numero3]);
        }
        printf("\n");
    }
    return 0;
}

