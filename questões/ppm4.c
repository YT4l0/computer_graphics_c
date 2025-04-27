#include <stdio.h>
#include <stdlib.h>

// Função para criar uma imagem totalmente branca
void criar_imagem_branca(const char *filename, int width, int height)
{
    FILE *file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("Erro ao criar arquivo\n");
        return;
    }

    // Escreve o cabeçalho PPM
    fprintf(file, "P3\n%d %d\n255\n", width, height);

    // Preenche todos os pixels com branco (255,255,255)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i < 30)
            {
                fprintf(file, "255 255 255\n");
            }
            else
            {
                fprintf(file, "0 0 0\n");
            }
        }
    }

    fclose(file);
    printf("Imagem branca %dx%d salva como '%s'\n", width, height, filename);
}

int main()
{

    int largura = 100;
    int altura = 100;

    criar_imagem_branca("imagem_branca.ppm", largura, altura);

    return 0;
}