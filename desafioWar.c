#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TERRITORIOS 5
#define TAM_NOMES 20

//-----ESTRUTURA-----
typedef struct  {
    char nome [TAM_NOMES];
    char cor [TAM_NOMES];
    int tropas;
} Territorio;

//---limpar buffer de entrada.---
void limparBufferEntrada() {
    int c;
    while ((c = getchar ()) != '\n' && c != EOF);
}

//-----PROTÓTIPOS-----
void cadastrarTerritorios(Territorio territorios[], int tamanho);
void exibirMapa(const Territorio territorios[], int tamanho);

//-----função principal (main)-----
int main () {
    Territorio territorios[MAX_TERRITORIOS];

    printf("Cadastre seus 5 primeiros Territórios:\n");
    cadastrarTerritorios(territorios, MAX_TERRITORIOS);

    printf("====================================\n");
    printf("  MAPA DO MUNDO - ESTADO ATUAL\n");
    printf("====================================");
    exibirMapa(territorios, MAX_TERRITORIOS);

    return 0;
  
}

//função para cadastrar os 5 territórios.
void cadastrarTerritorios(Territorio territorios[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("\n--- Território %d ---\n", i + 1);

        printf("Nome do território: ");
        fgets(territorios[i].nome, TAM_NOMES, stdin);
        territorios[i].nome[strcspn(territorios[i].nome, "\n")] = '\0'; // remover '\n'

        printf("Cor do exército: ");
        fgets(territorios[i].cor, TAM_NOMES, stdin);
        territorios[i].cor[strcspn(territorios[i].cor, "\n")] = '\0';

        printf("Número de tropas: ");
        scanf("%d", &territorios[i].tropas);
        getchar(); // limpar buffer

     } }


     // Função para exibir o mapa (apenas leitura -> const)
    void exibirMapa(const Territorio territorios[], int tamanho) {
     for (int i = 0; i < tamanho; i++) {
        printf("\n==Território %d:==\n", i + 1);
        printf("  - Nome: %s\n", territorios[i].nome);
        printf("  - Dominado por: Exército %s\n", territorios[i].cor);
        printf("  - Tropas: %d\n", territorios[i].tropas);
    }
}

