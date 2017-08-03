#include <stdio.h>
char bellekbolgesi[300];
int main()
{
  FILE *pointer;
  if((pointer = fopen("okumaokuma","r")) == NULL)
    printf("Dosya Acilmadi!");

  fread(bellekbolgesi, sizeof(char), 3500, pointer);
  puts(bellekbolgesi);
  fclose(pointer);
}
