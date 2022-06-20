#include <stdio.h>

// Nome do problema: 10177 - (2/3/4)-D Sqr/Rects/Cubes/Boxes?
// Problema em questão: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=40&page=show_problem&problem=1118

/**
 * Neste problema a ideia é verificar qual é quantidade de quadrados e retangulos que podemos encontrar em uma grid de diversas dimensões, 
 * no nosso caso, grids de 2 a 4 dimensões. Deste modo, verificando dimensão por dimensão, iremos pegar os valores correspondentes de cada uma
 */

int main() {
    /**
     * Declaração inicial das variaveis
     * A escolha pelo tipo unsigned long long se deve ao fato de que em alguns casos podemos ter valores muito grandes, devido a isso peguei o 
     * tipo que que aceita um maior valor inteiro
     */
	unsigned long long n, quadTwo, retTwo, quadThree, retThree, quadFour, retFour, i;

    // Loop principal que recebe qual é o tamanho das grids, que são todas do mesmo tamanho
	while(scanf("%llu", &n) == 1) {
        quadFour = 0;

        /**
         * A seguir se encontram as formulas utilizadas para encontrar a quantidade de quadrados e retangulos em cada caso, a formula usada no
         * "quadTwo" e no "quadFour" são as unicas diferentes, onde cada uma serve inteiramente para o caso de quadrados, já as outras foram baseadas
         * no calculo de retangulos, visto que em mais dimensões o calculo de quadrados funcionaria de forma semelhante, por isso há sempre a exclusão
         * dos quadrados nos calculos dos retangulos
         * https://www.quora.com/How-does-the-formula-n-n-1-2n-1-6-come
         * https://acervolima.com/numero-de-retangulos-na-grade-n-m/
         */
		quadTwo = n * (n + 1) * (2 * n + 1) / 6;
		retTwo = (n + 1) * n / 2 * (n + 1) * n / 2 - quadTwo;
		quadThree = n * (n + 1) / 2 * n * (n + 1) / 2;
		retThree = (n + 1) * n / 2 * (n + 1) * n / 2 * (n + 1) * n / 2 - quadThree;
		for(i = 1; i <= n; i++)	
            quadFour += i * i * i * i;

		retFour = (n + 1) * n / 2 * (n + 1) * n / 2 * (n + 1) * n / 2 * (n + 1) * n / 2 - quadFour;

		printf("%llu %llu %llu %llu %llu %llu\n", quadTwo, retTwo, quadThree, retThree, quadFour, retFour);
	}

    return 0;
}