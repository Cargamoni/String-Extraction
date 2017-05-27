#include <stdio.h>

int fileLengthShow()
{
  FILE *filePointer;                      //Dosyası işaret eden file tipli pointer
  filePointer = fopen("todoList.txt","r");
  int fileLength = 0;

  do
  {
    getc(filePointer);
    fileLength++;
  } while(getc(filePointer) != EOF);
  fclose(filePointer);
  return fileLength*2;
}

int getComments()
{
  FILE *filePointer, *getComment;
  filePointer = fopen("calismalar.c", "r");
  do
  {
    char holder[300];
    fgets(holder,3,filePointer);
    if(holder[0] == '/' && holder[1] == '/')
    {
      int a = ftell(filePointer);
      fseek(filePointer, -2, SEEK_CUR);
      fgets(holder,250,filePointer);
      printf("%s",holder);
      printf("%d",a);
    }
  }while(!feof(filePointer));
}

int cloneFile(char *dir, char *cloneName)
{
  FILE *veriAktarma, *veriOkuma;
  veriAktarma = fopen(cloneName, "w");
  veriOkuma = fopen(dir, "r");
  char a;
  do
  {
    a = getc(veriOkuma);
    fputc(a, veriAktarma);
  }while(!feof(veriOkuma));
  fclose(veriAktarma);
  fclose(veriOkuma);
}

int main()
{
  char fileDir[50], fileName[50];
  printf("\nKopyalanacak dosyanın tam adını giriniz: ");
  scanf("%s", fileDir);
  printf("\nKlon dosyanın adını giriniz : ");
  scanf("%s", fileName);
  cloneFile(fileDir,fileName);
  printf("%d", fileLengthShow());
  //getComments();
}
