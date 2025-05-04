#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define ALTURA 256
#define LARGURA 256

#define NUM_LINHAS 9 // Número total de linhas da casa

unsigned char imagem[ALTURA][LARGURA][3];

// Estrutura para representar um ponto 2D
typedef struct {
    int x;
    int y;
} Ponto;

// Estrutura para representar uma linha da casa
typedef struct {
    Ponto inicio;
    Ponto fim;
    unsigned char r, g, b;
} LinhaCasa;

// Rotaciona um ponto ao redor de um centro
void rotacionarPonto(Ponto *ponto, Ponto centro, float anguloGraus) {
    float anguloRad = anguloGraus * M_PI / 180.0;  // Usando M_PI para maior precisão
    float cosTheta = cos(anguloRad);
    float sinTheta = sin(anguloRad);

    int xTransladado = ponto->x - centro.x;
    int yTransladado = ponto->y - centro.y;

    ponto->x = round(xTransladado * cosTheta - yTransladado * sinTheta) + centro.x;
    ponto->y = round(xTransladado * sinTheta + yTransladado * cosTheta) + centro.y;
}

// Aumenta a escala de um ponto em relação a um centro
void aumentarEscala(Ponto *ponto, Ponto centro, float fatorEscala) {
    ponto->x = round((ponto->x - centro.x) * fatorEscala + centro.x);
    ponto->y = round((ponto->y - centro.y) * fatorEscala + centro.y);
}

// Limita as coordenadas para que fiquem dentro dos limites da imagem
void limitarCoordenadas(Ponto *ponto) {
    if (ponto->x < 0) ponto->x = 0;
    if (ponto->x >= LARGURA) ponto->x = LARGURA - 1;
    if (ponto->y < 0) ponto->y = 0;
    if (ponto->y >= ALTURA) ponto->y = ALTURA - 1;
}

// Define a cor de um pixel na imagem
void definirPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b) {
    if (x >= 0 && x < LARGURA && y >= 0 && y < ALTURA) {
        imagem[y][x][0] = r;
        imagem[y][x][1] = g;
        imagem[y][x][2] = b;
    }
}

// Limpa a imagem (preenche com branco)
void limparImagem() {
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            imagem[i][j][0] = 255; // Vermelho
            imagem[i][j][1] = 255; // Verde
            imagem[i][j][2] = 255; // Azul
        }
    }
}

// Salva a imagem em um arquivo .ppm
void salvarImagemArquivo(const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");
    if (!arquivo) {
        perror("Erro ao abrir o arquivo para escrita");
        return;
    }

    fprintf(arquivo, "P3\n%d %d\n255\n", LARGURA, ALTURA);
    for (int i = 0; i < ALTURA; i++) {
        for (int j = 0; j < LARGURA; j++) {
            fprintf(arquivo, "%d %d %d ", imagem[i][j][0], imagem[i][j][1], imagem[i][j][2]);
        }
        fprintf(arquivo, "\n");
    }

    fclose(arquivo);
}

// Desenha uma linha na imagem
void desenharLinha(Ponto inicio, Ponto fim, unsigned char r, unsigned char g, unsigned char b) {
    for (float t = 0.0; t <= 1.0; t += 0.0001) {
        int x = inicio.x + t * (fim.x - inicio.x);
        int y = inicio.y + t * (fim.y - inicio.y);
        definirPixel(x, y, r, g, b);
    }
}

// Função principal
int main() {
    limparImagem();

    Ponto centro = {64, 64};
    float anguloRotacao, fatorEscala;

    // Entradas do usuário
    printf("Digite o angulo de rotacao: ");
    scanf("%f", &anguloRotacao);

    printf("Digite o fator de escala (1.0 para tamanho original): ");
    scanf("%f", &fatorEscala);

    // Definição das linhas da casa
    LinhaCasa casa[NUM_LINHAS] = {
        {{0, 64}, {64, 0}, 255, 0, 0},
        {{64, 0}, {128, 64}, 255, 0, 0},
        {{0, 64}, {128, 64}, 0, 0, 255},
        {{0, 64}, {0, 128}, 0, 255, 0},
        {{128, 64}, {128, 128}, 0, 255, 0},
        {{0, 128}, {128, 128}, 0, 0, 255},
        {{48, 128}, {48, 98}, 255, 255, 0},
        {{80, 128}, {80, 98}, 255, 255, 0},
        {{48, 98}, {80, 98}, 255, 255, 0}
    };

    // Aplicar rotação, aumento de escala e limitar coordenadas para manter dentro da imagem
    for (int i = 0; i < NUM_LINHAS; i++) {
        Ponto inicio = casa[i].inicio;
        Ponto fim = casa[i].fim;

        // Rotacionar e aumentar a escala
        rotacionarPonto(&inicio, centro, anguloRotacao);
        rotacionarPonto(&fim, centro, anguloRotacao);
        aumentarEscala(&inicio, centro, fatorEscala);
        aumentarEscala(&fim, centro, fatorEscala);

        // Limitar as coordenadas para que fiquem dentro da imagem
        limitarCoordenadas(&inicio);
        limitarCoordenadas(&fim);

        casa[i].inicio = inicio;
        casa[i].fim = fim;
    }

    // Desenhar todas as linhas
    for (int i = 0; i < NUM_LINHAS; i++) {
        desenharLinha(casa[i].inicio, casa[i].fim, casa[i].r, casa[i].g, casa[i].b);
    }

    
    salvarImagemArquivo("casa.ppm");

    return 0;
}
