#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 500

int num[N];

void insertionSort(int n, int index) {
	int i;
	for (i = index; i && n < num[i - 1]; i--)
		num[i] = num[i - 1];
	
	num[i] = n;
}

int main() {
	int set;
    // Recebe a quantidade de casos que será verificado
	while (scanf("%d", &set) != EOF) {
		while(set--) {
			int index = 0;
			int people, n;
            // Recebe quantidade de casas que a familia possui
			scanf("%d", &people);
			while (people--) {
                // Recebe um inteiro correspondente a cada casa
				scanf("%d", &n);
                
                // Adiciona o valor ja ordenado
				insertionSort(n, index++);
			}

			index--;
            // Pega o valor correpondente a rua que esta no meio que é a melhor localizada
			int mid = index % 2 == 1 ? (num[index / 2] + num[index / 2 + 1]) / 2 : num[index / 2];
			
			int i, sum = 0;
            // Soma as distancias
			for (i = 0; i <= index; i++)
				sum += abs(mid - num[i]);
			printf("%d\n", sum);
		}
	}

	return 0;
}
