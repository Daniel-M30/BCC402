#include <stdio.h>
#include <stdlib.h>

int main() {
    int qtdNum;
    while(scanf("%d", &qtdNum) != EOF) {
        int i;
        int* vector = malloc(qtdNum * sizeof(int));
        int* correct = malloc((qtdNum - 1) * sizeof(int));
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