#include <stdio.h>

int fileLengthShow()
{
  FILE *filePt;                      //Dosyası işaret eden file tipli pointer
  filePt = fopen("todoList.txt","r");
  int fileLength = 0;

  do
  {
    getc(filePt);
    fileLength++;
  } while(getc(filePt) != EOF);
  fclose(filePt);
  return fileLength*2;
}

int getComments()
{
  FILE *filePt;
  filePt = fopen("stringExtraction.c", "r");
  
}

int main()
{
  printf("%d", fileLengthShow());
}
