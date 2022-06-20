#include <stdio.h>

// Nome do problema: 100 - The 3n + 1 problem
// Problema em questão: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=36

/**
 * Neste problema é nos apresentado um problema considerando numeros pares e impares que segue as seguintes regras, caso o numero em questao
 * seja um numero par, devemos dividir esse numero por 2, mas caso seja um numero impar, devemos multiplicar esse numero por 3 e somar com 1,
 * este procedimento é repetido ate que o numero fique igual a um
 * Nosso objetivo nesse programa é verificar quantas etapas são necessarias nesse algoritmo para que o numero fique igual a uma
 */

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

        printf("%d %d %d\n", i, j, max);
    }

    return 0;
}
