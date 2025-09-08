#include <stdio.h>

int main() {
    // --------- Escolha do nível ----------
    int nivel;
    printf("Escolha o nível do desafio:\n");
    printf("1 - Novato\n");
    printf("2 - Aventureiro\n");
    printf("3 - Mestre\n");
    printf("Digite sua escolha: ");
    scanf("%d", &nivel);

    // --------- Declaração das variáveis ----------
    unsigned long int populacao1, populacao2;
    float area1, area2;
    float pib1, pib2;
    int pontos1, pontos2;

    // Variáveis calculadas (Aventureiro/Mestre)
    float densidade1, densidade2;
    float pibpc1, pibpc2;

    // Super Poder (Mestre)
    float superpoder1, superpoder2;

    // --------- Entrada de dados ----------
    printf("\nCadastro da Carta 1:\n");
    printf("Populacao: ");
    scanf("%lu", &populacao1);
    printf("Area: ");
    scanf("%f", &area1);
    printf("PIB: ");
    scanf("%f", &pib1);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontos1);

    printf("\nCadastro da Carta 2:\n");
    printf("Populacao: ");
    scanf("%lu", &populacao2);
    printf("Area: ");
    scanf("%f", &area2);
    printf("PIB: ");
    scanf("%f", &pib2);
    printf("Numero de pontos turisticos: ");
    scanf("%d", &pontos2);

    // --------- Exibição (Nível Novato) ----------
    printf("\n==== Carta 1 ====\n");
    printf("Populacao: %lu\n", populacao1);
    printf("Area: %.2f\n", area1);
    printf("PIB: %.2f\n", pib1);
    printf("Pontos turisticos: %d\n", pontos1);

    printf("\n==== Carta 2 ====\n");
    printf("Populacao: %lu\n", populacao2);
    printf("Area: %.2f\n", area2);
    printf("PIB: %.2f\n", pib2);
    printf("Pontos turisticos: %d\n", pontos2);

    // --------- Cálculos (Nível Aventureiro/Mestre) ----------
    if (nivel >= 2) {
        densidade1 = populacao1 / area1;
        densidade2 = populacao2 / area2;
        pibpc1 = pib1 / populacao1;
        pibpc2 = pib2 / populacao2;

        printf("\n==== Atributos Calculados ====\n");
        printf("Carta 1 - Densidade Populacional: %.2f | PIB per Capita: %.2f\n", densidade1, pibpc1);
        printf("Carta 2 - Densidade Populacional: %.2f | PIB per Capita: %.2f\n", densidade2, pibpc2);
    }

    // --------- Comparações e Super Poder (Nível Mestre) ----------
    if (nivel == 3) {
        superpoder1 = populacao1 + area1 + pib1 + pontos1 + pibpc1 + (1.0 / densidade1);
        superpoder2 = populacao2 + area2 + pib2 + pontos2 + pibpc2 + (1.0 / densidade2);

        printf("\n==== Comparacao das Cartas ====\n");
        printf("Populacao: %d\n", (populacao1 > populacao2));
        printf("Area: %d\n", (area1 > area2));
        printf("PIB: %d\n", (pib1 > pib2));
        printf("Pontos turisticos: %d\n", (pontos1 > pontos2));
        printf("Densidade Populacional: %d\n", (densidade1 < densidade2)); // menor vence
        printf("PIB per Capita: %d\n", (pibpc1 > pibpc2));
        printf("Super Poder: %d\n", (superpoder1 > superpoder2));

        printf("\n==== Super Poder ====\n");
        printf("Carta 1: %.2f\n", superpoder1);
        printf("Carta 2: %.2f\n", superpoder2);
    }

    return 0;
}