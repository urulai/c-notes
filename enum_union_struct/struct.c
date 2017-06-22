#include <stdio.h>

struct person {
  int _age;
  int _height_in_cms;
  float _weight_in_kilograms;
};

#define STRINGIFY(x) #x

int main(void)
{
  /* Two ways to initialize struct members, one uses period and other uses colon. */
  struct person james = { ._age = 30, ._height_in_cms = 167, ._weight_in_kilograms = 65.4 }, \
       april = { _age : 33, _height_in_cms : 157, _weight_in_kilograms : 45.4 };

  printf("*** Person ***\n");
  printf("%s\tAge: %d, height: %dcms, weight: %.3f kilos\n", STRINGIFY(James), james._age, james._height_in_cms, james._weight_in_kilograms);
  printf("%s\tAge: %d, height: %dcms, weight: %.3f kilos\n", STRINGIFY(April), april._age, april._height_in_cms, april._weight_in_kilograms);
  
  return 0;
}
