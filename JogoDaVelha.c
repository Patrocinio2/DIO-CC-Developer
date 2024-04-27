#include <stdio.h>
#include <stdlib.h>

#define TAMANHO_TABULEIRO 3

// Definição do tipo de dados para o tabuleiro
typedef char Tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

// Função para inicializar o tabuleiro
void inicializar_tabuleiro(Tabuleiro tabuleiro) {
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = ' ';
        }
    }
}

// Função para imprimir o tabuleiro
void imprimir_tabuleiro(Tabuleiro tabuleiro) {
    printf("\n  0 1 2\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        printf("%d ", i);
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("|%c", tabuleiro[i][j]);
        }
        printf("|\n");
    }
}

// Função para verificar se uma posição está disponível no tabuleiro
int posicao_disponivel(Tabuleiro tabuleiro, int linha, int coluna) {
    return tabuleiro[linha][coluna] == ' ';
}

// Função para verificar se houve um vencedor
char verificar_vencedor(Tabuleiro tabuleiro) {
    // Verificar linhas e colunas
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        if (tabuleiro[i][0] != ' ' && tabuleiro[i][0] == tabuleiro[i][1] && tabuleiro[i][0] == tabuleiro[i][2])
            return tabuleiro[i][0]; // Vencedor encontrado na linha i
        if (tabuleiro[0][i] != ' ' && tabuleiro[0][i] == tabuleiro[1][i] && tabuleiro[0][i] == tabuleiro[2][i])
            return tabuleiro[0][i]; // Vencedor encontrado na coluna i
    }

    // Verificar diagonais
    if (tabuleiro[0][0] != ' ' && tabuleiro[0][0] == tabuleiro[1][1] && tabuleiro[0][0] == tabuleiro[2][2])
        return tabuleiro[0][0]; // Vencedor encontrado na diagonal principal
    if (tabuleiro[0][2] != ' ' && tabuleiro[0][2] == tabuleiro[1][1] && tabuleiro[0][2] == tabuleiro[2][0])
        return tabuleiro[0][2]; // Vencedor encontrado na diagonal secundária

    return ' '; // Não há vencedor ainda
}

// Função principal
int main() {
    Tabuleiro tabuleiro;
    inicializar_tabuleiro(tabuleiro);

    printf("\nBem-vindo ao Jogo da Velha!\n");
    printf("Jogador 1: X\n");
    printf("Jogador 2: O\n\n");

    int jogador_atual = 1; // Começa com o jogador 1
    int jogadas = 0;
    while (1) {
        imprimir_tabuleiro(tabuleiro);

        // Entrada do movimento do jogador
        int linha, coluna;
        printf("\nJogador %d, faca o seu movimento (linha coluna): ", jogador_atual);
        scanf("%d %d", &linha, &coluna);

        // Verificar se a posição é válida
        if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO || !posicao_disponivel(tabuleiro, linha, coluna)) {
            printf("Posicao invalida. Tente novamente.\n");
            continue;
        }

        // Fazer o movimento
        if (jogador_atual == 1)
            tabuleiro[linha][coluna] = 'X';
        else
            tabuleiro[linha][coluna] = 'O';

        jogadas++;

        // Verificar se há um vencedor ou empate
        char vencedor = verificar_vencedor(tabuleiro);
        if (vencedor != ' ' || jogadas == TAMANHO_TABULEIRO * TAMANHO_TABULEIRO) {
            imprimir_tabuleiro(tabuleiro);
            if (vencedor != ' ')
                printf("\nParabens, jogador %d (\"%c\") venceu!\n", jogador_atual, vencedor);
            else
                printf("\nEmpate!\n");
            break;
        }

        // Alternar jogador
        jogador_atual = (jogador_atual == 1) ? 2 : 1;
    }

    return 0;
}
