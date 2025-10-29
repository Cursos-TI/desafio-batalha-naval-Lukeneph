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

    int Navio[3] = {3, 3, 3};

// Define a posição do navio no tabuleiro
// No Tabuleiro e de 0 a 9, onde 0 é a primeira linha/coluna e 9 a ultima linha/coluna
// Masmostra 1 a 10 para o usuario por questão de visualização

    int linhaX1 = 5, colunaX1 = 7;

    int linhaY2 = 7, colunaY2 = 5;

    int linhaX3 = 1, colunaX3 = 2;

    int linhaY4 = 2, colunaY4 = 7;

// Coloca o navio 1 horizontal no tabuleiro

    if (linhaX1 >= 0 && linhaX1 < 10 && colunaX1 >= 0 && colunaX1 + 2 < 10) {
        int sobreposicao = 0;
        for (int i = 0; i < 3; i++) {
            if (Tabuleiro[linhaX1][colunaX1 + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (sobreposicao == 0) {
            for (int i = 0; i < 3; i++) {
                Tabuleiro[linhaX1][colunaX1 + i] = Navio[i];
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

    if (linhaY2 >= 0 && linhaY2 + 2 < 10 && colunaY2 >= 0 && colunaY2 < 10) {
        int sobreposicao = 0;
        for (int i = 0; i < 3; i++) {
            if (Tabuleiro[linhaY2 + i][colunaY2] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (sobreposicao == 0) {
            for (int i = 0; i < 3; i++) {
                Tabuleiro[linhaY2 + i][colunaY2] = Navio[i];
            }
        } else {
            printf("Erro: Sobreposição de navios na posição vertical.\n"); // mensagem de erro
            return 1;
        }
    } else {
        printf("Erro: Posição do navio vertical fora dos limites do tabuleiro.\n"); // mensagem de erro
        return 1;
    }

// Coloca navio 3 diagonal no tabuleiro

    if (linhaX3 >= 0 && linhaX3 + 2 < 10 && colunaX3 >= 0 && colunaX3 + 2 < 10) {
        int sobreposicao = 0;
        for (int i = 0; i < 3; i++) {
            if (Tabuleiro[linhaX3 + i][colunaX3 + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (sobreposicao == 0) {
            for (int i = 0; i < 3; i++) {
                Tabuleiro[linhaX3 + i][colunaX3 + i] = Navio[i];
            }
        } else {
            printf("Erro: Sobreposição de navios na posição diagonal.\n"); // mensagem de erro
            return 1;
        }
    } else {
        printf("Erro: Posição do navio diagonal fora dos limites do tabuleiro.\n"); // mensagem de erro
        return 1;
    }

// Coloca navio 4 diagonal invertido no tabuleiro

    if (linhaY4 - 2 >= 0 && linhaY4 < 10 && colunaY4 >= 0 && colunaY4 + 2 < 10) {
        int sobreposicao = 0;
        for (int i = 0; i < 3; i++) {
            if (Tabuleiro[linhaY4 - i][colunaY4 + i] != 0) {
                sobreposicao = 1;
                break;
            }
        }
        if (sobreposicao == 0) {
            for (int i = 0; i < 3; i++) {
                Tabuleiro[linhaY4 - i][colunaY4 + i] = Navio[i];
            }
        } else {
            printf("Erro: Sobreposição de navios na posição diagonal invertida.\n"); // mensagem de erro
            return 1;
        }
    } else {
        printf("Erro: Posição do navio diagonal invertida fora dos limites do tabuleiro.\n"); // mensagem de erro
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