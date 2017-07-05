#include <stdio.h>
#include <string.h>

int main(void)
{
  char buffer[1024] = {0};
  scanf("%s", buffer);

  unsigned int N = strlen(buffer);

  int i = 0, l = N-1;
  while((i < N/2) && buffer[i++] == buffer[l--])
  ;
  if(i == N/2)
   printf("palindrome\n");
  else
   printf("Try again.\n");
  
  return 0;
}
