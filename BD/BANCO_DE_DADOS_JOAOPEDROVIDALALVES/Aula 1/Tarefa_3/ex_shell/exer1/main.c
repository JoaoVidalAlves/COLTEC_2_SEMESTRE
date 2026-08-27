#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *arquivoTxt;
    FILE *arquivoBin;

    arquivoTxt = fopen("teste3.txt", "rb");

    if (arquivoTxt == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    arquivoBin = fopen("arquivo.bin", "wb");

    if (arquivoBin == NULL)
    {
        printf("Erro ao abrir o arquivo\n");
        fclose(arquivoTxt);
        return 1;
    }

    char buffer[1024];
    size_t bytesLidos;

    while ((bytesLidos = fread(buffer, 1, sizeof(buffer), arquivoTxt)) > 0)
    {
        fwrite(buffer, 1, bytesLidos, arquivoBin);
    }

    fclose(arquivoTxt);
    fclose(arquivoBin);

    printf("Arquivo lido e copiado com sucesso!\n");

    return 0;
}
