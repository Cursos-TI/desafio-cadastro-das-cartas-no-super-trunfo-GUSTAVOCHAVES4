#include <stdio.h>

int main() {
    // Carta 1
    unsigned long int populacao1;
    float area1, pib1;
    int pontos1;
    float densidade1, pibPerCapita1, superPoder1;

    // Carta 2
    unsigned long int populacao2;
    float area2, pib2;
    int pontos2;
    float densidade2, pibPerCapita2, superPoder2;

    // Entrada Carta 1
    printf("Cadastro da Carta 1:\n");
    printf("População: ");
    scanf("%lu", &populacao1);
    printf("Área (km²): ");
    scanf("%f", &area1);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib1);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos1);

    // Entrada Carta 2
    printf("\nCadastro da Carta 2:\n");
    printf("População: ");
    scanf("%lu", &populacao2);
    printf("Área (km²): ");
    scanf("%f", &area2);
    printf("PIB (em bilhões): ");
    scanf("%f", &pib2);
    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos2);

    // Cálculos
    densidade1 = (float) populacao1 / area1;
    pibPerCapita1 = pib1 * 1000000000.0 / populacao1;
    densidade2 = (float) populacao2 / area2;
    pibPerCapita2 = pib2 * 1000000000.0 / populacao2;

    superPoder1 = populacao1 + area1 + pib1 + pontos1 + pibPerCapita1 + (1.0 / densidade1);
    superPoder2 = populacao2 + area2 + pib2 + pontos2 + pibPerCapita2 + (1.0 / densidade2);

    // Saída
    printf("\n--- Resultados da Comparação ---\n");
    printf("População: %d\n", (populacao1 > populacao2));
    printf("Área: %d\n", (area1 > area2));
    printf("PIB: %d\n", (pib1 > pib2));
    printf("Pontos Turísticos: %d\n", (pontos1 > pontos2));
    printf("Densidade Populacional: %d\n", (densidade1 < densidade2)); // menor vence
    printf("PIB per Capita: %d\n", (pibPerCapita1 > pibPerCapita2));
    printf("Super Poder: %d\n", (superPoder1 > superPoder2));

    return 0;
}