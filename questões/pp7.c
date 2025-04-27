#include <stdio.h>

#define ALTURA 256
#define LARGURA 256
#define MAX_COLOR 255

unsigned char img[ALTURA][LARGURA][3];

void SetPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b){
    img[x][y][0] = r;
    img[x][y][1] = g;
    img[x][y][2] = b;
}

void clearImg(){
    for(int i = 0; i < ALTURA; i++){
        for(int j = 0; j < LARGURA; j++){
            for(int c = 0; c < 3; c++){
                img[i][j][c] = 255;
            }
        }
    }
}

int main(){
    return 0;
}
