/* @JUDGE ID:1275459 100 C “The 3n + 1 problem” */
/* @BEGIN OF SOURCE CODE */
#include <stdio.h>

int main() {
    int i, j, maior, menor;

    while(scanf("%d %d", &i, &j) != EOF) {
        // Coloca em ordem a tupla recebida    
        if(i < j) {
            maior = j;
            menor = i;
        }

        else {
            maior = i;
            menor = j;
        }

        int n;
        int max = -1;
        for(n = menor; n <= maior; n++) {
            int cicle = n;
            int qtd = 1;

            // realiza os calculos necessarios
            while(cicle != 1) {
                if(cicle % 2 == 0)
                    cicle = cicle / 2;

                else
                    cicle = cicle * 3 + 1;

                qtd++;
            }

            // Verifica se valor atual é maior que o armazenado anteriormente
            if(qtd > max)
                max = qtd;
        }

        printf("%d %d %d\n", menor, maior, max);
    }

    return 0;
}
/* @END OF SOURCE CODE */