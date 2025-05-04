#include <stdio.h>

#define ALTURA 555
#define LARGURA 555
#define MAX_COLOR 255

unsigned char img[ALTURA][LARGURA][3];

void setPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b){

    img[x][y][0] = r;
    img[x][y][1] = g;
    img[x][y][2] = b;
}

void clearImage(){
    for (int i = 0; i < ALTURA; i++){
        for (int j = 0; j < LARGURA; j++){
            for (int c = 0; c < 3; c++){
                img[i][j][c] = 255; 
            }
        }
    }
}

void saveImage(){
    printf("P3\n %d \t %d\n %d\n", ALTURA, LARGURA, MAX_COLOR);

    for (int i = 0; i < ALTURA; i++){
        for (int j = 0; j < LARGURA; j++){
            for (int c = 0; c < 3; c++){
               printf("%d \t", img[i][j][c]); 
            }
        }
        printf("\n");
    }
}

void drawline(int x1, int y1, int x2, int y2, unsigned char r, unsigned char g, unsigned char b){
    for (float t = 0.0; t < 1; t = t + 0.0001){
        setPixel((int)((x2 - x1) * t + x1), (int)((y2 - y1) * t + y1), r, g, b);
    }
}

int main(){

    
    int meio = (int) ALTURA / 2;
    clearImage();

    // linha horizontal
    drawline(meio, 75, meio, 180, 255, 0, 0); 
    drawline(meio + 75, 75, meio + 75, 180, 255, 255, 0); 

    // linha vertical
    drawline(meio, meio + 51, 203, meio + 51, 255, 255, 0);
    drawline(meio, 75, 203, 75, 255, 0, 0);

    // telhado
    drawline(meio - 60, meio, meio, meio - 52, 0, 0, 255);
    drawline(meio - 60, meio, meio, meio + 52, 0, 0, 255); 

    drawline(meio - 51, meio + 6, meio, meio - 40, 0, 0, 0);
    drawline(meio - 45, meio + 14, meio, meio - 25, 0, 0, 0);
    drawline(meio - 36, meio + 22, meio, meio - 10, 0, 0, 0);
    drawline(meio - 27, meio + 30, meio, meio + 5, 0, 0, 0);
    drawline(meio - 18, meio + 38, meio, meio + 20, 0, 0, 0);
    drawline(meio - 9, meio + 46, meio, meio + 35, 0, 0, 0);

    // porta
    drawline(meio + 30, meio - 15, meio + 30, meio + 15, 255, 0, 0); 
    drawline(meio + 30, meio - 15, 203, meio - 15, 255, 0, 0);
    drawline(meio + 30, meio + 15, 203, meio + 15, 255, 0, 0);

    saveImage(); 
    return 0;

}