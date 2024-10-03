#include <stdio.h>
#include <stdlib.h>

int main() {
    char continuar = 'S';
    char fileira, tipoPassagem;
    int col;
    int linha;

    // criando a matriz
    char matriz[5][5] = {
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'},
        {'0', '0', '0', '0', '0'}
    };

    while (continuar == 'S' || continuar == 's') {
        // mostra a matriz
        printf("\n---------------------------------------------------------------------");
        printf("\n     POLTRONAS");
        printf("\n   A  B  C  D  E");
        printf("\n");

        for (int i = 0; i < 5; ++i) {
            printf("%i |", i + 1);  // mostra o número da linha
            for (int j = 0; j < 5; ++j) {
                printf(" %c ", matriz[i][j]);
            }
            printf("\n");
        }

        printf("\n---------------------------------------------------------------------");

    
        printf("\nDigite o tipo de passagem (E para Economico ( fileiras: B,C e D), X para Executivo (fileiras: A e E)): ");
        scanf(" %c", &tipoPassagem);

    
        printf("\nDigite a fileira desejada (A-E): ");
        scanf(" %c", &fileira);

        printf("\nDigite a linha desejada (1-5): ");
        scanf("%i", &linha);

        // validação da entrada do passageiro
        if ((fileira >= 'A' && fileira <= 'E') && (linha >= 1 && linha <= 5)) {
            // converte a fileira para índice da matriz (é uma forma de converter a letra da fileira (ex: 'A', 'B', 'C', ...) em um índice numérico que pode ser usado para acessar a matriz.)
            col = fileira - 'A';
            linha -= 1;  // ajusta a linha para índice da matriz (0-4)

            // verificação das regras de reserva para o tipo de passagem
            if (tipoPassagem == 'E' || tipoPassagem == 'e') {
                // econômica (E): Proíbe assentos nas colunas A (0) e E (4)
                if (col == 0 || col == 4) {
                    printf("\nAssentos nas fileiras A e E sao exclusivos para passagem Executiva. Tente outra fileira.\n");
                } else {
                    if (matriz[linha][col] == '0') {
                        matriz[linha][col] = 'X';
                        printf("\nAssento reservado com sucesso!\n");
                    } else {
                        printf("\nAssento já está ocupado, escolha outro!!!!\n");
                    }
                }
            } else if (tipoPassagem == 'X' || tipoPassagem == 'x') {
                // executiva (X): Recomenda assentos nas colunas A (0) e E (4)
                if (col == 0 || col == 4) {
                    if (matriz[linha][col] == '0') {
                        matriz[linha][col] = 'X';
                        printf("\nAssento reservado com sucesso!\n");
                    } else {
                        printf("\nAssento já está ocupado, escolha outro!!!!!\n");
                    }
                } else {
                    printf("\nRecomendamos escolher um assento nas fileiras A e F (exclusivas para classe Executiva).\n");
                    if (matriz[linha][col] == '0') {
                        matriz[linha][col] = 'X';
                        printf("\nAssento reservado com sucesso!\n");
                    } else {
                        printf("\nAssento já está ocupado, escolha outro!!!!!\n");
                    }
                }
            } else {
                printf("\nTipo de passagem inválido, insira 'E' para Econômico ou 'X' para Executivo.\n");
            }
        } else {
            printf("\n Inválido!!! Por favor, insira valores corretos.\n");
        }

        // pergunta se o passageiro deseja continuar reservando
        printf("\nDeseja continuar reservando? (S/N): ");
        scanf(" %c", &continuar);

    }

    printf("\nEncerrando o sistema de reservas...\n");
    return 0;
}
