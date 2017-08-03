#include <stdio.h>

int main()
{
  /*FILE *ptDosya, *ptDosya2;
  char ch;
  //Dosya Açma --Okuma amaçlı açıldığını r ile ifade ediliyor.
  ptDosya = fopen("todoList.txt","r");
  //Bir karakter okuma || Getch her seferinde bir karakter okur.
  do {
    ch = getc(ptDosya);
    printf("%c", ch);
  } while(ch != EOF);

  fclose(ptDosya);

  ptDosya2 = fopen("todoList.txt","r");
  do{
    ch = getc(ptDosya2);
    printf("%c", ch);
  }while(!feof(ptDosya2));

  //dosyayı kapatma
  fclose(ptDosya2);

  //Verilerin Topluca Okunması
  FILE *topluOku;
  topluOku = fopen("todoList.txt", "r");
  char veri[50];
  //fgets fonksiyonu string, (int)uzunluk ve dosya parametrelerini alıyor
  fgets(veri, 50, topluOku);
  puts(veri);

  //Dosyayı kapatma
  fclose(topluOku);

  //Verilerin Yazılması (Bu işlem içerisindeki tüm verileri silip belirtilen veriyi ekler)
  FILE *yazma;
  char *veri1;
  char *veri2;
  yazma = fopen("todoList.txt", "w");

  veri1 ="bilisim ";
  veri2 = "teknolojileri";

  fputs(veri1, yazma);
  fputs(veri2, yazma);
  fclose(yazma);*/

  //Dosyadaki iceriğin kopyalanması.
  FILE *veriAktarma, *veriOkuma;
  veriAktarma = fopen("todoList.txt", "w");
  veriOkuma = fopen("stringExtractionTest.c", "r");
  char a;
  do
  {
    a = getc(veriOkuma);
    fputc(a, veriAktarma);
  }while(!feof(veriOkuma));
  fclose(veriAktarma);
  fclose(veriOkuma);

  return 0;
}
