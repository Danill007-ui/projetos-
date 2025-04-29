#include <stdio.h>

typedef struct {
    char estado[50];
    int codigo;
    char nome[100];
    unsigned long int populacao;
    float area;
    double pib;
    int pontos_turisticos;
    float densidade_populacional;
    double pib_per_capita;
    float super_poder;
} Carta;

float calcularDensidade(unsigned long int populacao, float area) {
    return populacao / area;
}

double calcularPIBperCapita(double pib, unsigned long int populacao) {
    return pib / populacao;
}

float calcularSuperPoder(Carta c) {
    float inverso_densidade = 1.0 / c.densidade_populacional;
    return c.populacao + c.area + c.pib + c.pontos_turisticos + c.pib_per_capita + inverso_densidade;
}

void compararCartas(Carta c1, Carta c2) {
    printf("\nComparação de Cartas:\n");

    printf("População: Carta 1 venceu (%d)\n", c1.populacao > c2.populacao);
    printf("Área: Carta 1 venceu (%d)\n", c1.area > c2.area);
    printf("PIB: Carta 1 venceu (%d)\n", c1.pib > c2.pib);
    printf("Pontos Turísticos: Carta 1 venceu (%d)\n", c1.pontos_turisticos > c2.pontos_turisticos);
    printf("Densidade Populacional: Carta 1 venceu (%d)\n", c1.densidade_populacional < c2.densidade_populacional);
    printf("PIB per Capita: Carta 1 venceu (%d)\n", c1.pib_per_capita > c2.pib_per_capita);
    printf("Super Poder: Carta 1 venceu (%d)\n", c1.super_poder > c2.super_poder);
}

int main() {
    Carta c1, c2;

    
    printf("Digite os dados da Carta 1:\n");
    printf("Estado: "); scanf(" %[^\n]", c1.estado);
    printf("Código: "); scanf("%d", &c1.codigo);
    printf("Nome: "); scanf(" %[^\n]", c1.nome);
    printf("População: "); scanf("%lu", &c1.populacao);
    printf("Área: "); scanf("%f", &c1.area);
    printf("PIB: "); scanf("%lf", &c1.pib);
    printf("Número de pontos turísticos: "); scanf("%d", &c1.pontos_turisticos);

    
    printf("\nDigite os dados da Carta 2:\n");
    printf("Estado: "); scanf(" %[^\n]", c2.estado);
    printf("Código: "); scanf("%d", &c2.codigo);
    printf("Nome: "); scanf(" %[^\n]", c2.nome);
    printf("População: "); scanf("%lu", &c2.populacao);
    printf("Área: "); scanf("%f", &c2.area);
    printf("PIB: "); scanf("%lf", &c2.pib);
    printf("Número de pontos turísticos: "); scanf("%d", &c2.pontos_turisticos);

   
    c1.densidade_populacional = calcularDensidade(c1.populacao, c1.area);
    c1.pib_per_capita = calcularPIBperCapita(c1.pib, c1.populacao);
    c1.super_poder = calcularSuperPoder(c1);

    
    c2.densidade_populacional = calcularDensidade(c2.populacao, c2.area);
    c2.pib_per_capita = calcularPIBperCapita(c2.pib, c2.populacao);
    c2.super_poder = calcularSuperPoder(c2);

    
    compararCartas(c1, c2);

    return 0;
}