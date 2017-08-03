#include <stdio.h>
int main()
{
  FILE *dosyaPointer;
  char satir[200];

  //Dosya açma işlemi
  if((dosyaPointer = fopen("konumtest", "r")) == NULL)
  {
    printf("Dosya Açılamadı!");
    return 0;
  }

  //Konum göstergecinin yerinin yazdırılması
  printf("Konum göstergecinin yeri: %lo\n\n", ftell(dosyaPointer));

  //Dosyadan bir karakter okuma işlemi
  printf("Dosyadan bir karakter okunuyor...\n");
  fgetc(dosyaPointer);

  //Konum göstericinin okumadan sonraki yerinin
  printf("Konum göstergecinin yeri: %lo\n\n", ftell(dosyaPointer));

  //Konum gösterici ikinci satırın başına ilerletilir
  printf("Konumu ikinci satırın başına götür: \n");
  fseek(dosyaPointer, 39, SEEK_SET);

  //Bu satır okunur ve ekrana yazdırılır
  printf("Bu satırı oku ve ekrana yazdır: \n");
  fgets(satir,200,dosyaPointer);
  printf("%s", satir);

  //Konum göstergecinin okumadan sonraki yeri
  printf("Konum göstergecinin yeri: %lo\n\n", ftell(dosyaPointer));

  //Konum göstergecini satırın başına gönderme ve konumun ekrana yazdırılması
  printf("Konum göstergeci dosyanın başına gidiyor...\n");
  rewind(dosyaPointer);
  printf("Konum göstergecinin yeri: %lo\n\n", ftell(dosyaPointer));

  fclose(dosyaPointer);
}
