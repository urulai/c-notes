#include <stdio.h>

union weight {
  int grams;
  double kilograms;
};

int main(void)
{
  /* Two ways to initialize union members, one uses period and other uses colon. */
  union weight oranges = { .grams = 1100 }, apples = { kilograms: 1.567 },  bananas;
  bananas.grams = 22100;
  
  printf("****  Weight ****\n");
  printf("Oranges: %.2f kilograms\n", (float)(oranges.grams)/1000);
  printf("Apples: %.0f grams\n", (apples.kilograms)*1000);
  printf("Bananas: %d grams, %.2f kilograms\n", bananas.grams, (float)(bananas.grams)/1000);
  
  printf("Union weight is %zu bytes long.\n", sizeof(union weight));
  return 0;
}
