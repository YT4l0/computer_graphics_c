#include <stdio.h>

void save(const char *filename, int height, int width) {
    FILE *file = fopen(filename, "w");

    if(file == NULL) {
        printf("Erro ao criar arquivo");
        return;  // Adicionei return para sair se houver erro
    }

    fprintf(file, "P3\n%d %d\n255\n", width, height);  // Corrigi a ordem para width x height

    for(int i = 0; i < height; i++) {
        for(int j = 0; j < width; j++) {
            fprintf(file, "%d %d %d\n", i % 256, j % 256, j % 256);  // Adicionei % 256 para limitar a 0-255
        }
    }
    fclose(file);

    printf("Imagem salva como '%s'\n", filename);  // Mensagem mais informativa
}

int main() {
    int width = 100, height = 100;

    save("imagem.ppm", height, width);  // Corrigi a ordem dos parâmetros

    return 0;
}