#include <stdio.h>
#include <string.h> // Necessário para manipular strings (como strcpy)

// --- DEFINIÇÕES DE DADOS DAS CARTAS (HARDCODED PARA ESTE NÍVEL) ---
// Usaremos dados fixos para simular as cartas cadastradas anteriormente.

// Dados Carta 1: São Paulo
char estado1 = 'A';
char codigo1[4] = "A01";
char nomeCidade1[50] = "São Paulo";
int populacao1 = 12396372; // População (int)
float area1 = 1521.11;     // Área em km² (float)
float pib1 = 700.00;       // PIB em bilhões de reais (float)
int pontosTuristicos1 = 50;

// Dados Carta 2: Rio de Janeiro
char estado2 = 'B';
char codigo2[4] = "B02";
char nomeCidade2[50] = "Rio de Janeiro";
int populacao2 = 6718903;  // População (int)
float area2 = 1200.25;     // Área em km² (float)
float pib2 = 300.50;       // PIB em bilhões de reais (float)
int pontosTuristicos2 = 30;

// --- VARIÁVEIS PARA CÁLCULOS DERIVADOS ---
float densidade1, pibPerCapita1;
float densidade2, pibPerCapita2;

// --- ATRIBUTO ESCOLHIDO PARA COMPARAÇÃO (Requisito: Escolha no código) ---
// 1 = População, 2 = Área, 3 = PIB, 4 = Densidade, 5 = PIB Per Capita
#define ATRIBUTO_PARA_COMPARACAO 1 // Escolhemos População para este exemplo

// Função principal
int main() {
    printf("\n=== Super Trunfo - Nível 2: Cálculo e Comparação ===\n");

    // =========================================================
    // 1. CÁLCULO DOS ATRIBUTOS DERIVADOS
    // =========================================================

    // Cálculo Carta 1
    densidade1 = populacao1 / area1;
    // O PIB per capita é o PIB total (que está em BILHÕES) dividido pela população.
    // Multiplicamos pib1 por 1.000.000.000 para converter para reais.
    pibPerCapita1 = (pib1 * 1000000000.0) / populacao1;

    // Cálculo Carta 2
    densidade2 = populacao2 / area2;
    pibPerCapita2 = (pib2 * 1000000000.0) / populacao2;
    
    printf("\n--- Dados Derivados Calculados ---\n");
    printf("%s (C1) - Densidade: %.2f hab/km², PIB Per Capita: R$ %.2f\n", nomeCidade1, densidade1, pibPerCapita1);
    printf("%s (C2) - Densidade: %.2f hab/km², PIB Per Capita: R$ %.2f\n", nomeCidade2, densidade2, pibPerCapita2);
    
    // =========================================================
    // 2. LÓGICA DE COMPARAÇÃO (IF e IF-ELSE)
    // =========================================================

    float valorC1 = 0.0;
    float valorC2 = 0.0;
    const char *nomeAtributo = "";
    int maiorVence = 1; // 1 = Maior valor vence; 0 = Menor valor vence

    // --- SELEÇÃO DO ATRIBUTO ESCOLHIDO (Simulado por #define) ---
    switch (ATRIBUTO_PARA_COMPARACAO) {
        case 1: // População
            nomeAtributo = "População";
            valorC1 = (float)populacao1; // Conversão int para float para a comparação
            valorC2 = (float)populacao2;
            maiorVence = 1;
            break;
        case 2: // Área
            nomeAtributo = "Área (km²)";
            valorC1 = area1;
            valorC2 = area2;
            maiorVence = 1;
            break;
        case 3: // PIB
            nomeAtributo = "PIB (bilhões)";
            valorC1 = pib1;
            valorC2 = pib2;
            maiorVence = 1;
            break;
        case 4: // Densidade Populacional (Menor valor vence)
            nomeAtributo = "Densidade Populacional (hab/km²)";
            valorC1 = densidade1;
            valorC2 = densidade2;
            maiorVence = 0; // REQUISITO: Menor valor vence
            break;
        case 5: // PIB Per Capita
            nomeAtributo = "PIB Per Capita (R$)";
            valorC1 = pibPerCapita1;
            valorC2 = pibPerCapita2;
            maiorVence = 1;
            break;
        default:
            nomeAtributo = "N/A - Atributo Invalido";
            // Para evitar erros, podemos sair da comparação
            return 1;
    }

    printf("\n========================================\n");
    printf("Comparação de Cartas (Atributo: %s)\n", nomeAtributo);
    printf("Carta 1 - %s (%c): ", nomeCidade1, estado1);
    // Formatação de saída para garantir a legibilidade
    if (ATRIBUTO_PARA_COMPARACAO == 5) {
         printf("R$ %.2f\n", valorC1);
    } else {
        printf("%.2f\n", valorC1);
    }
    printf("Carta 2 - %s (%c): ", nomeCidade2, estado2);
    if (ATRIBUTO_PARA_COMPARACAO == 5) {
         printf("R$ %.2f\n", valorC2);
    } else {
        printf("%.2f\n", valorC2);
    }
    printf("========================================\n");


    // --- ESTRUTURAS DE DECISÃO IF e IF-ELSE ---

    if (maiorVence) {
        // Lógica: Maior valor vence (População, Área, PIB, PIB Per Capita)
        if (valorC1 > valorC2) {
            printf("Resultado: Carta 1 (%s) VENCEU! (Maior valor)\n", nomeCidade1);
        } else if (valorC2 > valorC1) { // Usa-se if-else if para a vitória da C2, senão o else final seria apenas o empate
            printf("Resultado: Carta 2 (%s) VENCEU! (Maior valor)\n", nomeCidade2);
        } else {
            // Último caso possível: Empate
            printf("Resultado: EMPATE!\n");
        }

    } else {
        // Lógica: Menor valor vence (Densidade Populacional)
        if (valorC1 < valorC2) {
            printf("Resultado: Carta 1 (%s) VENCEU! (Menor valor)\n", nomeCidade1);
        } else if (valorC2 < valorC1) {
            printf("Resultado: Carta 2 (%s) VENCEU! (Menor valor)\n", nomeCidade2);
        } else {
            // Último caso possível: Empate
            printf("Resultado: EMPATE!\n");
        }
    }


    return 0;
}