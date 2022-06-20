#include <stdio.h>
#include <stdlib.h>

// Nome do problema: 10038 - Jolly Jumpers
// Problema em questão: 

/**
 * Neste problema é apresentado para nós o termo Jolly, que no caso corresponde quando uma sequencia de numeros fazem co-relação direta
 * com as posições do vetor, a diferença entre os valores sequentes devem corresponder a uma posição do vetor, onde todos as diferenças
 * correspondam a uma posição, caso nao aconteça isso não se trata de um Jolly.
 * A partir de um numero corresponde ao tamanho do vetor, temos que verificar se todas as diferenças pelos numeros dados façam referencia
 * a uma posição
 */

int main() {
    int qtdNum;
    while(scanf("%d", &qtdNum) != EOF) {
        int i;
        int* vector = malloc(qtdNum * sizeof(int));
        int* correct = malloc((qtdNum - 1) * sizeof(int));
        // Recebe posições relacionadas ao vetor, inserindo no vetor os valores que serão utilizados na etapa seguinte
        for(i = 0; i < qtdNum; i++) {
            scanf("%d", &vector[i]);

            if(i < qtdNum - 1)
                correct[i] = 0;
        }
        
        int prev = vector[0];
        int notJolly = 0;
        for(i = 1; i < qtdNum; i++) {
            int diff = prev - vector[i];
            int curr = abs(diff);
            prev = vector[i];
            
            if(curr <= 0 || curr > qtdNum || correct[curr - 1] == 1) {
                // Já verifica na entrada se o valor inserido é maior que o tamanho do array ou se o campo no array ja foi preenchido
                notJolly = 1;
                break;
            }

            correct[curr - 1] = 1;
        }
        
        int isJolly = 1;
        if(notJolly == 0) {
            for(i = 0; i < (qtdNum - 1); i++) {
                // Verifica se todos os casos de entrada foram preenchidos
                if(correct[i] == 0) {
                    isJolly = 0;
                    break;
                }
            }
        }

        if(isJolly == 1 && notJolly == 0)
            printf("Jolly\n");

        else
            printf("Not jolly\n");

        // Libera vetores alocados
        free(vector);
        free(correct);
    }

    return 0;
}