#include <stdio.h>
int main()
{
  //Dosyanın adresini taşıyacak pointer değişkeni
  FILE *dosyaPointer;
  //Dosyanın pointer içerisine aktarılması ve fopen ile yazmak için açılması.
  //w ile açıldığında
  dosyaPointer = fopen("okubeni", "w");
  //putc fonksiyonunun return ettiği dosya içerisine yazılan karaterin ascii karşılğıdır. Aşağıdaki şekilde de kullanılabilir.
  //printf("%d",putc('H', dosyaPointer));
  putc('b', dosyaPointer);
  putc('i', dosyaPointer);
  putc('r', dosyaPointer);
  putc('n', dosyaPointer);
  putc('u', dosyaPointer);
  putc('r', dosyaPointer);
  //Doya kapatma işlemi fclose ile yapılmaktadır. Dosya kapatma işlemi başarılı ise return olarak 0 değerini döndürür.
  //Eğer başarılı değilse EOF değerini döndürür.
  if(!fclose(dosyaPointer))
    printf("Dosya Kapatıldı.\n");
  else
    printf("%d Dosya Kapatılamadı", fclose(dosyaPointer));

  FILE *dosyaPointer2;
  dosyaPointer2 = fopen("okubeni", "r");
  //getc() fonksiyonu dosya açıldığında ilk karakterden başlayarak okuma yapar
  //Komut tekrar çağırıldığında bir sonraki karaktere geçer ve yeniden okuma yapar
  printf("%d",feof(dosyaPointer2));
  printf("%c", getc(dosyaPointer2));
  printf("%c", getc(dosyaPointer2));
  printf("%c", getc(dosyaPointer2));
  printf("%c", getc(dosyaPointer2));
  printf("%c", getc(dosyaPointer2));
  printf("%c", getc(dosyaPointer2));
  printf("%d",feof(dosyaPointer2));
  //printf("%d", EOF);
  if(feof(dosyaPointer2) && getc(dosyaPointer2) == EOF)
    printf("\nDosyanın sonuna geldiniz\n");
  else
    printf("\nDosyanın sonuna gelmediniz\n");
  fclose(dosyaPointer2);

  //Verilerin Döngüler yardımıyla okunması
  FILE *dosyaPointer3;
  dosyaPointer3 = fopen("okubeni","r");
  /* Aşağıdaki kullanımda her getc() fonksiyonu değer okuyacağı için tüm değerleri ekranda göremeyeceğiz
  // Doğru uygulama bir karater tipli değişken oluşturup onun üzerinden yazdırma işlemi yapmak ve EOF değerini onun üzerinden kontrol etmek olacaktır.
  do
  {
    printf("%c",getc(dosyaPointer3));
  }while(getc(dosyaPointer3) != EOF);
  */
  char karakter = ' ';
  do {
    karakter = getc(dosyaPointer3);
    if(karakter != EOF)
      printf("%c", karakter);
    else if(karakter == EOF)
      printf("\n");
  } while(karakter != EOF);
  //Yukarıda görüldüğü gibi okunan karakterler karakter değişkenine aktarılarak ekranda yazdırılmaktadır.
  //Dosya sonuna gelindiğinde ise döngü durdurulup dosya kapatılmaktadır.
  fclose(dosyaPointer3);

  //feof() fonksiyonu ve while döngüsü ile okuma yapalım.
  FILE *dosyaPointer4;
  dosyaPointer4 = fopen("okubeni","r");
  while(!feof(dosyaPointer4))
    printf("%c",getc(dosyaPointer4));
  printf("\n");
  fclose(dosyaPointer4);

  FILE *dosyaPointer5;
  dosyaPointer5 = fopen("okubeni","r");
  for(;!feof(dosyaPointer5);)
    printf("%c",getc(dosyaPointer5));
  printf("\n");
  fclose(dosyaPointer5);

  FILE *dosyaPointer6;
  dosyaPointer6 = fopen("okubeni","r");
  char string[20];
  fgets(string, 15, dosyaPointer6);
  printf("%s\n", string);
  fclose(dosyaPointer6);


  FILE *dosyaPointer7;
  char *str;
  char *str2;
  char str3[40];
  dosyaPointer7 = fopen("okubeni","a");
  str = "Bu bir deneme yazısıdır,";
  str2 = "Bu bir deneme yazısıdır.\n";
  fputs("\n",dosyaPointer7);
  fputs(str,dosyaPointer7);
  fputs(str2,dosyaPointer7);
  dosyaPointer7 = fopen("okubeni","r");
  fgets(str3, 35, dosyaPointer7);
  printf("%s\n", str3);
  fclose(dosyaPointer7);

  FILE *dosyaPointer8;
  dosyaPointer8 = fopen("okubeni","a");
  char veri[20];
  scanf("%s",veri);
  fprintf(dosyaPointer8, "%s", veri);
  //printf("%d",fprintf(dosyaPointer8, "%s", veri));
  fclose(dosyaPointer8);

  FILE *dosyaPointer9;
  dosyaPointer9 = fopen("okubeni","r");
  char okuVeri[20];
  fscanf(dosyaPointer9, "%s", okuVeri);
  for(int i = 0; i< 20; i++)
      printf("%c",okuVeri[i]);
  fclose(dosyaPointer9);

  //fseek(file, miktar, baslangic)
  //baslangic = 0 > Dosyanın başına götürür.
  //baslangic = 1 > Göstergeçin bulunduğu noktayı hedef alır.
  //baslangic = 2 > Dosyanın sonuna götürür.
  FILE *dosyaPointer10;
  dosyaPointer10 = fopen("okubeni","r");
  printf("\n%lo\n", ftell(dosyaPointer10));
  char str4[20];
  fgets(str4, 7, dosyaPointer10);
  printf("%lo\n", ftell(dosyaPointer10));
  printf("%s",str4);
  fseek(dosyaPointer10, 4, SEEK_CUR);
  fgets(str4, 13, dosyaPointer10);
  printf("%lo\n", ftell(dosyaPointer10));
  printf("%s",str4);
  fclose(dosyaPointer10);
}
