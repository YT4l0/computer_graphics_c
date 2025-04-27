#include <stdio.h>

void DesenharT(const char *filename, int height, int width) {
    FILE *file = fopen(filename, "w");

    if (file == NULL) {
        printf("Erro ao abrir arquivo %s\n", filename);
        return;
    }

    
    fprintf(file, "P3\n%d %d\n255\n", width, height);

    
    int meio = width / 2;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
           
            if (i == 0 && j >= meio - 2 && j <= meio + 2) {
                fprintf(file, "255 255 255 "); 
            }
            
            else if (j == meio && i < height) {
                fprintf(file, "255 255 255 "); 
            } else {
                fprintf(file, "0 0 0 "); 
            }
        }
        fprintf(file, "\n");
    }
    fclose(file);
}

int main() {
    int altura = 10;
    int largura = 10;

    DesenharT("letra_t.ppm", altura, largura);
    printf("Arquivo 'letra_t.ppm' gerado com sucesso!\n");

    return 0;
}