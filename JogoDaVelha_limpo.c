#include <stdio.h>
#include <stdbool.h>

// Tabuleiro do jogo: [linha][coluna]
char tabuleiro[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};

// Imprime o tabuleiro formatado
void imprimirTabuleiro() {
    printf("\n  %c  |  %c  |  %c  ", tabuleiro[0][0], tabuleiro[0][1], tabuleiro[0][2]);
    printf("\n-----|-----|-----");
    printf("\n  %c  |  %c  |  %c  ", tabuleiro[1][0], tabuleiro[1][1], tabuleiro[1][2]);
    printf("\n-----|-----|-----");
    printf("\n  %c  |  %c  |  %c  ", tabuleiro[2][0], tabuleiro[2][1], tabuleiro[2][2]);
}

// Valida e insere jogada em uma posição vazia
void inserirJogada(char jogador, int linha, int coluna) {
    while (tabuleiro[linha][coluna] != ' ') {
        printf("\nPosição ocupada! Jogador %c - digite nova linha (0-2): ", jogador);
        scanf("%d", &linha);
        printf("\nJogador %c - digite nova coluna (0-2): ", jogador);
        scanf("%d", &coluna);
    }
    tabuleiro[linha][coluna] = jogador;
}

// Verifica vitória em linhas
bool verificarLinhas() {
    for (int linha = 0; linha < 3; linha++) {
        if (tabuleiro[linha][0] == tabuleiro[linha][1] && 
            tabuleiro[linha][1] == tabuleiro[linha][2] && 
            tabuleiro[linha][0] != ' ') {
            printf("\nJogador %c ganhou na linha %d!", tabuleiro[linha][0], linha);
            return true;
        }
    }
    return false;
}

// Verifica vitória em colunas
bool verificarColunas() {
    for (int coluna = 0; coluna < 3; coluna++) {
        if (tabuleiro[0][coluna] == tabuleiro[1][coluna] && 
            tabuleiro[1][coluna] == tabuleiro[2][coluna] && 
            tabuleiro[0][coluna] != ' ') {
            printf("\nJogador %c ganhou na coluna %d!", tabuleiro[0][coluna], coluna);
            return true;
        }
    }
    return false;
}

// Verifica vitória em diagonais
bool verificarDiagonais() {
    // Diagonal principal
    if (tabuleiro[0][0] == tabuleiro[1][1] && 
        tabuleiro[1][1] == tabuleiro[2][2] && 
        tabuleiro[0][0] != ' ') {
        printf("\nJogador %c ganhou na diagonal principal!", tabuleiro[0][0]);
        return true;
    }
    // Diagonal secundária
    if (tabuleiro[0][2] == tabuleiro[1][1] && 
        tabuleiro[1][1] == tabuleiro[2][0] && 
        tabuleiro[0][2] != ' ') {
        printf("\nJogador %c ganhou na diagonal secundária!", tabuleiro[0][2]);
        return true;
    }
    return false;
}

// Verifica se houve vitória
bool houveVitoria() {
    return verificarLinhas() || verificarColunas() || verificarDiagonais();
}

int main() {
    int linha, coluna;
    char jogadores[] = {'X', 'O'};
    int turno = 0;

    while (1) {
        imprimirTabuleiro();
        char jogadorAtual = jogadores[turno % 2];

        printf("\n\nJogador %c:", jogadorAtual);
        printf("\nLinha (0-2): ");
        scanf("%d", &linha);
        printf("Coluna (0-2): ");
        scanf("%d", &coluna);

        // Validação básica de entrada
        if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
            printf("\nCoordenadas inválidas! Use valores entre 0 e 2.\n");
            continue;
        }

        inserirJogada(jogadorAtual, linha, coluna);
        if (houveVitoria()) {
            imprimirTabuleiro();
            printf("\n\nFim de jogo! Vitória do %c!\n", jogadorAtual);
            break;
        }

        turno++;
    }

    return 0;
}