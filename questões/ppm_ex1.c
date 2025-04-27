#include <stdio.h>

int main() {
    int width = 100;
    int height = 100;

    printf("P3\n%d %d\n255\n", width, height);

    for(int i = 0; i < height; i++) { 
        for(int j = 0; j < width; j++) {  
            if(i == 50 && j == 50) {
                printf("%d %d %d\n", 255, 0, 0);  
            } else {
                printf("%d %d %d\n", 0, 0, 0);  
            }
        }
    }

    return 0;
}