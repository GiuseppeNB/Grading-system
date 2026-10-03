#include <stdio.h>

float calcularMedia(float notas[], int quantEstudantes) {
    float soma = 0.0, media = 0.0;
    int i;
    
    for (i = 0; i < quantEstudantes; i++) {
        soma += notas[i];
    }
    media = soma / quantEstudantes;
    return media;
}

int contarAcimaMedia(float mediaTurma, float notas[], int quantEstudantes) {
    int quantAcimaMedia = 0, i;
    
    for (i = 0; i < quantEstudantes; i++) {
        if (notas[i] > mediaTurma) {
            quantAcimaMedia++;
        }
    }
    return quantAcimaMedia;
}

float verificarMaiorNota(float notas[], int quantEstudantes) {
    float maiorNota = 0;
    int i;
    
    for (i = 0; i < quantEstudantes; i++) {
        if (notas[i] > maiorNota) {
            maiorNota = notas[i];
        }
    }
    return maiorNota;
}

int main() {
    int i, n, quantAcimaMedia;
    float notas[50], maiorNota, mediaTurma, percentualAcima;
    
    do {
        printf("\nDigite a quantidade de estudantes: ");
        scanf("%d", &n);
        if (n < 1 || n > 50) {
            printf("Erro! Quantidade de alunos inválido!\n");
        }
    } while (n < 1 || n > 50);
    
    for (i = 0; i < n; i++) {
        do {
            printf("\nDigite a nota do aluno %d: ", i + 1);
            scanf("%f", &notas[i]);
            
            if (notas[i] < 0.0 || notas[i] > 10.0) {
                printf("Erro! Nota inválida!\n");
            }
        } while (notas[i] < 0.0 || notas[i] > 10.0);
    }
    
    mediaTurma = calcularMedia(notas, n);
    quantAcimaMedia = contarAcimaMedia(mediaTurma, notas, n);
    maiorNota = verificarMaiorNota(notas, n);
    percentualAcima = ((float)quantAcimaMedia/n)*100;
    
    printf("Média da turma: %.2f\n", mediaTurma);
    printf("Maior notas da turma: %.2f\n", maiorNota);
    printf("Quantidade acima da média: %d\n", quantAcimaMedia);
    printf("Percentual acima da média com relação a turma inteira: %.2f%%\n", percentualAcima);

    return 0;
}