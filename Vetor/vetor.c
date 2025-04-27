#include <stdio.h>
#include <math.h>
#include "vetor.h"

Vetor cria_vetor(float x1, float y1, float z1, float x2, float y2, float z2) {
    Vetor v;
    v.x = x2 - x1;
    v.y = y2 - y1;
    v.z = z2 - z1;
    return v;
}

Vetor ler_vetor_por_pontos() {
    float x1, y1, z1, x2, y2, z2;
    scanf("%f %f %f", &x1, &y1, &z1);
    scanf("%f %f %f", &x2, &y2, &z2);
    return cria_vetor(x1, y1, z1, x2, y2, z2);
}

Vetor ler_vetor_direto() {
    Vetor v;
    scanf("%f %f %f", &v.x, &v.y, &v.z);
    return v;
}

Vetor normaliza(Vetor v) {
    float norma = sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
    Vetor normalizado = {0, 0, 0};

    if (norma != 0.0f) {
        normalizado.x = v.x / norma;
        normalizado.y = v.y / norma;
        normalizado.z = v.z / norma;
    }
    return normalizado;
}

Vetor soma(Vetor v1, Vetor v2) {
    Vetor resultado;
    resultado.x = v1.x + v2.x;
    resultado.y = v1.y + v2.y;
    resultado.z = v1.z + v2.z;
    return resultado;
}

Vetor subtrai(Vetor v1, Vetor v2) {
    Vetor resultado;
    resultado.x = v1.x - v2.x;
    resultado.y = v1.y - v2.y;
    resultado.z = v1.z - v2.z;
    return resultado;
}

Vetor multiplica_escalar(Vetor v, float num) {
    Vetor resultado;
    resultado.x = v.x * num;
    resultado.y = v.y * num;
    resultado.z = v.z * num;
    return resultado;
}

float produto_escalar(Vetor v1, Vetor v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vetor produto_vetorial(Vetor v1, Vetor v2){
    Vetor resultado;

    

    resultado.x = v1.y * v2.z - v1.z * v2.y;
    resultado.y = v1.z * v2.x - v1.x * v2.z;
    resultado.z = v1.x * v2.y - v1.y * v2.x;


    return resultado;

}

void imprime_vetor(Vetor v) {
    printf("(%.2f, %.2f, %.2f)", v.x, v.y, v.z);
}

void imprime_vetor_normalizado(Vetor v) {
    Vetor norm = normaliza(v);
    printf("(%.2f, %.2f, %.2f)", norm.x, norm.y, norm.z);
}
