#include <stdio.h>

// Definindo a estrutura para a carta
typedef struct
{
  int id;
  float pib;
  float area;
  char code[4];
  char state[100];
  float pibPerCapita;
  char cityName[100];
  float populationDensity;
  unsigned long int population;
  int numberTouristAttractions;
} Card;

// funcao para imprimir os dados da carta
void printCard(Card card)
{
  printf("Carta %d:\n", card.id);
  printf("Estado: %c\n", card.state[0]);
  printf("Codigo: %s\n", card.code);
  printf("Nome da Cidade: %s\n", card.cityName);
  printf("Populacao: %lu\n", card.population);
  printf("Area: %.2f km quadrados\n", card.area);
  printf("PIB: %.2f bilhoes de reais\n", card.pib);
  printf("Numero de Pontos Turisticos: %d\n", card.numberTouristAttractions);
  printf("Densidade Populacional: %.2f hab/km quadrados\n", card.populationDensity);
  printf("PIB per Capita: %.2f reais\n", card.pibPerCapita);
}

// funcao que sera responsavel por criar as cartas
void createCard(Card *card, int id)
{
  card->id = id;

  // pedindo para o usuario digitar os dados
  printf("Digite o nome do estado: ");
  scanf("%s", card->state);

  printf("Digite o codigo da carta: ");
  scanf("%s", card->code);

  printf("Digite o nome da cidade: ");
  scanf("%s", card->cityName);

  printf("Digite a quantidade de populacao: ");
  scanf("%lu", &card->population);

  printf("Digite o numero de area: ");
  scanf("%f", &card->area);

  printf("Digite o numero de PIB: ");
  scanf("%f", &card->pib);

  printf("Digite o numero de pontos turisticos: ");
  scanf("%d", &card->numberTouristAttractions);

  // calculando a densidade populacional e o PIB per capita
  card->populationDensity = card->area > 0 ? card->population / card->area : 0;
  card->pibPerCapita = card->population > 0 ? card->pib / card->population : 0;

  // imprimindo os dados
  printf("\n");
  printCard(*card);
}

// funcao para calcular o super poder da carta
float calculateSuperPower(Card card)
{
  float inverseDensity = 1 / card.populationDensity;

  float superPower = (float)card.population + card.area + card.pib +
                     (float)card.numberTouristAttractions + card.pibPerCapita +
                     inverseDensity;

  return superPower;
}

// funcao para imprimir o resultado da comparacao
void printComparisonResult(const char *type, int card1Id, int card2Id, int comparisonResult)
{
  printf("%s: Carta %d venceu (%d)\n", type, comparisonResult ? card1Id : card2Id, comparisonResult);
}

// funcao para comparar as cartas
void compareCards(Card card1, Card card2)
{
  float superPower1 = calculateSuperPower(card1);
  float superPower2 = calculateSuperPower(card2);

  printf("Comparacao de Cartas:\n");

  printComparisonResult("Populacao", card1.id, card2.id, card1.population > card2.population);
  printComparisonResult("Area", card1.id, card2.id, card1.area > card2.area);
  printComparisonResult("PIB", card1.id, card2.id, card1.pib > card2.pib);
  printComparisonResult("Pontos Turisticos", card1.id, card2.id, card1.numberTouristAttractions > card2.numberTouristAttractions);
  printComparisonResult("Densidade Populacional", card1.id, card2.id, card1.populationDensity < card2.populationDensity);
  printComparisonResult("PIB per Capita", card1.id, card2.id, card1.pibPerCapita > card2.pibPerCapita);
  printComparisonResult("Super Poder", card1.id, card2.id, superPower1 > superPower2);
}

// funcao para comparar a carta que venceu comparando a densidade populacional
void checkVictoryCardPopulationDensity(Card card1, Card card2)
{
  int cardVictory = 0;

  if (card1.pibPerCapita > card2.pibPerCapita)
  {
    cardVictory = 1;
  }
  else
  {
    cardVictory = 2;
  }

  printf("Carta 1 - PIB per Capita: %.2f reais\n", card1.populationDensity);
  printf("Carta 2 - PIB per Capita: %.2f reais\n", card2.populationDensity);

  printf("Resultado: Carta %d venceu!\n", cardVictory);
}

int main()
{
  Card card1, card2;

  // Chamando a funcao para criar as cartas
  printf("\n");
  createCard(&card1, 1);
  printf("\n");
  createCard(&card2, 2);
  printf("\n");

  // Chamando a funcao para comparar as cartas
  compareCards(card1, card2);
  printf("\n");

  // Chamando a funcao para comparar a carta que venceu comparando a densidade populacional
  checkVictoryCardPopulationDensity(card1, card2);
  printf("\n");

  return 0;
}