#include <stdio.h>
#include "vetor.h"

int main() {
    Vetor v1, v2, resultado;
    float escalar ; // valor fixo para multiplicação por escalar
    float prod_escalar;

    printf("digite os valores para x,y,z \n");
    scanf("%f %f %f", &v1.x, &v1.y, &v1.z);
    printf("digite os valores para x,y,z \n");
    scanf("%f %f %f", &v2.x, &v2.y, &v2.z);

    printf("digite o seu escalar: ");
    scanf("%f",&escalar);

    printf("soma");
    resultado = soma(v1, v2);
    imprime_vetor(resultado);
    printf("\n");

    printf("subtracao");
    resultado = subtrai(v1, v2);
    imprime_vetor(resultado);
    printf("\n");

    printf("produto escalar \n");
    prod_escalar = produto_escalar(v1, v2);
    printf("%.2f\n", prod_escalar);

    printf("Multiplica v1 por escalar \n");
    resultado = multiplica_escalar(v1, escalar);
    imprime_vetor(resultado);
    printf("\n");

    printf("Multiplica v2 por escalar \n");
    resultado = multiplica_escalar(v2, escalar);
    imprime_vetor(resultado);
    printf("\n");

    printf("normaliza Vetor V1 \n");
    imprime_vetor_normalizado(v1);
    printf("\n");

    printf("normaliza Vetor V2 \n");
    imprime_vetor_normalizado(v2);
    printf("\n");

    printf("produto vetorial \n");
    resultado = produto_vetorial(v1,v2);
    imprime_vetor(resultado);
    printf("\n");

    return 0;
}
