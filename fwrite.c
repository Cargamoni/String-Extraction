#include <stdio.h>
char bellekbolgesi[15];

int main()
{
	FILE *pointer;
	// dosyayı aç
	if((pointer = fopen("fwrite_ornek.txt", "a")) == NULL)
	{
			printf("dosya acilamadi!");
			return 0;
	}
	scanf("Bir cümle giriniz %s :", bellekbolgesi);
	fwrite(bellekbolgesi, sizeof(char), 15, pointer);
	for(int i = 0; i< 15; i++)
		printf("%c", bellekbolgesi[i]);
	fwrite(bellekbolgesi, sizeof(char), 15, pointer);
	// tamponda kalanları da
	fclose(pointer);
	return 0;
}
