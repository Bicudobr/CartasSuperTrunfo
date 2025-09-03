#include <stdio.h> // Biblioteca padrão de entrada e saída
#include <string.h> // Biblioteca para manipulação de strings

// criando estrutura de codigos das cartas
typedef struct { // Estrutura logica das cartas
    char estado;                // Letra entre A e H
    char codigo[5];             // Exemplo: A01, B03
    char nomeCidade[50];       // Nome da cidade
    int populacao;             // População da cidade
    float area;                // Área em km²
    float pib;                 // PIB em bilhões
    int pontosTuristicos;      // Número de pontos turísticos
} Carta;

// Função para cadastrar os dados de uma carta
void cadastrarCarta(Carta *carta, int numero) { //comando para ser inserido as info
    printf("\n--- Cadastro da Carta %d ---\n", numero); //exibe dados da carta

    // Lê o estado (letra de A a H)  
    printf("Digite o Estado (A-H): "); //exibe dados do estado
    scanf(" %c", &carta->estado);   //comandos das informacoes inseridas

    // Lê o código da carta
    printf("Digite o Código da Carta (ex: A01): "); //exibe dados inseridos
    scanf(" %4s", carta->codigo); // Limita leitura a 4 caracteres

    // Limpa dados ja inseridso
    getchar();

    // Lê o nome da cidade
    printf("Digite o Nome da Cidade: ");
    fgets(carta->nomeCidade, sizeof(carta->nomeCidade), stdin);
    carta->nomeCidade[strcspn(carta->nomeCidade, "\n")] = '\0'; // Remove \n

    // Lê os demais dados numéricos
    printf("Digite a População: ");
    scanf("%d", &carta->populacao);

    printf("Digite a Área (em km²): ");
    scanf("%f", &carta->area);

    printf("Digite o PIB (em bilhões de reais): ");
    scanf("%f", &carta->pib);

    printf("Digite o Número de Pontos Turísticos: ");
    scanf("%d", &carta->pontosTuristicos);
}

// Função para exibir os dados de uma carta
void exibirCarta(Carta carta, int numero) {
    printf("\nCarta %d:\n", numero);
    printf("Estado: %c\n", carta.estado);
    printf("Código: %s\n", carta.codigo);
    printf("Nome da Cidade: %s\n", carta.nomeCidade);
    printf("População: %d\n", carta.populacao);
    printf("Área: %.2f km²\n", carta.area);
    printf("PIB: %.2f bilhões de reais\n", carta.pib);
    printf("Número de Pontos Turísticos: %d\n", carta.pontosTuristicos);
}

int main() { // funcao principal
    Carta carta1, carta2;

    printf("=== Cadastro de Cartas do Super Trunfo ===\n");

    // Cadastra as duas cartas
    cadastrarCarta(&carta1, 1);
    cadastrarCarta(&carta2, 2);

    // Exibe as duas cartas
    printf("\n=== Cartas Cadastradas ===");
    exibirCarta(carta1, 1);
    exibirCarta(carta2, 2);

    return 0; // fim do programa
}