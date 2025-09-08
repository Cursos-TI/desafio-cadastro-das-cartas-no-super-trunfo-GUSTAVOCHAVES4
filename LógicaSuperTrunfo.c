#include <stdio.h>
#include <string.h>

// Estrutura para armazenar os dados da carta
typedef struct {
    char estado;
    char codigo[4];
    char cidade[50];
    int populacao;
    float area;
    float pib;
    int pontosTuristicos;
    float densidadePop;
    float pibPerCapita;
} Carta;

// Função para cadastrar os dados de uma carta
void cadastrarCarta(Carta *carta, int numero) {
    printf("\nCadastro da Carta %d:\n", numero);
    printf("Digite o Estado (A-H): ");
    scanf(" %c", &carta->estado);

    printf("Digite o Código da Carta (ex: A01): ");
    scanf("%s", carta->codigo);

    printf("Digite o Nome da Cidade: ");
    scanf(" %[^\n]", carta->cidade);

    printf("Digite a População: ");
    scanf("%d", &carta->populacao);

    printf("Digite a Área (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);

    // Calcula atributos derivados
    carta->densidadePop = carta->populacao / carta->area;
    carta->pibPerCapita = carta->pib * 1000000000.0 / carta->populacao; 
}

// Função para exibir os dados da carta
void exibirCarta(Carta carta, int numero) {
    printf("\n--- Carta %d ---\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Cidade: %s\n", carta.cidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões\n", carta.pib);
    printf("Pontos Turísticos: %d\n", carta.pontosTuristicos);
    printf("Densidade Populacional: %.2f hab/km²\n", carta.densidadePop);
    printf("PIB per capita: %.2f R$\n", carta.pibPerCapita);
}

// Função de comparação básica (pré-definida no código)
void compararBasico(Carta c1, Carta c2) {
    // Exemplo: comparação por População
    printf("\nComparação de cartas (Atributo: População)\n");
    printf("Carta 1 - %s (%c): %d\n", c1.cidade, c1.estado, c1.populacao);
    printf("Carta 2 - %s (%c): %d\n", c2.cidade, c2.estado, c2.populacao);

    if (c1.populacao > c2.populacao) {
        printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade);
    } else if (c2.populacao > c1.populacao) {
        printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade);
    } else {
        printf("Resultado: Empate!\n");
    }
}

// Função para comparar atributos escolhidos no menu (nível intermediário)
void compararIntermediario(Carta c1, Carta c2, int atributo) {
    float valor1, valor2;
    char nomeAtributo[30];

    switch (atributo) {
        case 1: valor1 = c1.populacao; valor2 = c2.populacao; strcpy(nomeAtributo, "População"); break;
        case 2: valor1 = c1.area; valor2 = c2.area; strcpy(nomeAtributo, "Área"); break;
        case 3: valor1 = c1.pib; valor2 = c2.pib; strcpy(nomeAtributo, "PIB"); break;
        case 4: valor1 = c1.pontosTuristicos; valor2 = c2.pontosTuristicos; strcpy(nomeAtributo, "Pontos Turísticos"); break;
        case 5: valor1 = c1.densidadePop; valor2 = c2.densidadePop; strcpy(nomeAtributo, "Densidade Populacional"); break;
        case 6: valor1 = c1.pibPerCapita; valor2 = c2.pibPerCapita; strcpy(nomeAtributo, "PIB per capita"); break;
        default: printf("Opção inválida!\n"); return;
    }

    printf("\nComparação de cartas (Atributo: %s)\n", nomeAtributo);
    printf("Carta 1 - %s: %.2f\n", c1.cidade, valor1);
    printf("Carta 2 - %s: %.2f\n", c2.cidade, valor2);

    if (atributo == 5) { // Densidade → menor vence
        if (valor1 < valor2) printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade);
        else if (valor2 < valor1) printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade);
        else printf("Resultado: Empate!\n");
    } else {
        if (valor1 > valor2) printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade);
        else if (valor2 > valor1) printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade);
        else printf("Resultado: Empate!\n");
    }
}

// Função para o nível avançado: dois atributos e soma
void compararAvancado(Carta c1, Carta c2, int attr1, int attr2) {
    float v1a, v2a, v1b, v2b, soma1, soma2;

    // Pega valores do atributo 1
    switch (attr1) {
        case 1: v1a = c1.populacao; v2a = c2.populacao; break;
        case 2: v1a = c1.area; v2a = c2.area; break;
        case 3: v1a = c1.pib; v2a = c2.pib; break;
        case 4: v1a = c1.pontosTuristicos; v2a = c2.pontosTuristicos; break;
        case 5: v1a = c1.densidadePop; v2a = c2.densidadePop; break;
        case 6: v1a = c1.pibPerCapita; v2a = c2.pibPerCapita; break;
    }
    // Pega valores do atributo 2
    switch (attr2) {
        case 1: v1b = c1.populacao; v2b = c2.populacao; break;
        case 2: v1b = c1.area; v2b = c2.area; break;
        case 3: v1b = c1.pib; v2b = c2.pib; break;
        case 4: v1b = c1.pontosTuristicos; v2b = c2.pontosTuristicos; break;
        case 5: v1b = c1.densidadePop; v2b = c2.densidadePop; break;
        case 6: v1b = c1.pibPerCapita; v2b = c2.pibPerCapita; break;
    }

    soma1 = v1a + v1b;
    soma2 = v2a + v2b;

    printf("\nComparação avançada:\n");
    printf("Carta 1 - %s: %.2f + %.2f = %.2f\n", c1.cidade, v1a, v1b, soma1);
    printf("Carta 2 - %s: %.2f + %.2f = %.2f\n", c2.cidade, v2a, v2b, soma2);

    if (soma1 > soma2) printf("Resultado: Carta 1 (%s) venceu!\n", c1.cidade);
    else if (soma2 > soma1) printf("Resultado: Carta 2 (%s) venceu!\n", c2.cidade);
    else printf("Resultado: Empate!\n");
}

int main() {
    Carta c1, c2;
    int opcao, attr1, attr2;

    // Cadastro das cartas
    cadastrarCarta(&c1, 1);
    cadastrarCarta(&c2, 2);

    // Exibição
    exibirCarta(c1, 1);
    exibirCarta(c2, 2);

    // Menu principal
    printf("\n--- Menu ---\n");
    printf("1 - Comparação Básica (pré-definida)\n");
    printf("2 - Comparação Intermediária (escolher atributo)\n");
    printf("3 - Comparação Avançada (dois atributos)\n");
    printf("Escolha: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            compararBasico(c1, c2);
            break;
        case 2:
            printf("\nAtributos disponíveis:\n1 - População\n2 - Área\n3 - PIB\n4 - Pontos Turísticos\n5 - Densidade Populacional\n6 - PIB per capita\n");
            printf("Escolha um atributo: ");
            scanf("%d", &attr1);
            compararIntermediario(c1, c2, attr1);
            break;
        case 3:
            printf("\nEscolha o primeiro atributo (1 a 6): ");
            scanf("%d", &attr1);
            printf("Escolha o segundo atributo (1 a 6, diferente do primeiro): ");
            scanf("%d", &attr2);
            if (attr1 == attr2) {
                printf("Erro: não pode escolher o mesmo atributo duas vezes!\n");
            } else {
                compararAvancado(c1, c2, attr1, attr2);
            }
            break;
        default:
            printf("Opção inválida!\n");
    }

    return 0;
}