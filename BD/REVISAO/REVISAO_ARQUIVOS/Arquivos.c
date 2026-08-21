#include <stdio.h>
#include <stdlib.h>

void main()
{
	char x[] = "ABCDEF55";
	int y = 0xABCDEF55;
	char z[] = "Coltec";

	FILE* arquivoTxt = fopen("A.txt", "w+a");
	if (arquivoTxt == NULL)
	{ 
		printf("Erro ao abri o arquivo!");
		return;
	}

	FILE* arquivoBin = fopen("A.bin", "wb");
	if (arquivoBin == NULL)
	{
		printf("Erro ao abri o arquivo!");
		fclose(arquivoTxt);
		return;
	}

	fprintf(arquivoTxt, "%s\n", x);
	fprintf(arquivoTxt, "%d\n", y);
	fprintf(arquivoTxt, "%s\n", z);

	fwrite(x, sizeof(char), sizeof(x) - 1, arquivoBin);
	fwrite(&y, sizeof(int), 1, arquivoBin);
	fwrite(z, sizeof(char), sizeof(z) - 1, arquivoBin);

	fclose(arquivoTxt);
	fclose(arquivoBin);
}