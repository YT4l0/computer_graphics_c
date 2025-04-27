#ifndef VETOR_H
#define VETOR_H

typedef struct {
    float x, y, z;
} Vetor;

Vetor cria_vetor(float x1, float y1, float z1, float x2, float y2, float z2);
Vetor ler_vetor_por_pontos();
Vetor ler_vetor_direto();
Vetor normaliza(Vetor v);
Vetor soma(Vetor v1, Vetor v2);
Vetor subtrai(Vetor v1, Vetor v2);
Vetor multiplica_escalar(Vetor v, float num);
float produto_escalar(Vetor v1, Vetor v2);
Vetor produto_vetorial(Vetor v1, Vetor v2);
void imprime_vetor(Vetor v);
void imprime_vetor_normalizado(Vetor v);


#endif
