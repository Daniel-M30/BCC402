#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Nome do problema: 10198 - Counting
// Problema em questão: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=34&page=show_problem&problem=1139

/**
 * Neste problema devemos ajudar Gustavo, uma criança que está aprendendo a contar, que atualmente conhece os numeros de 1 a 4, sendo
 * que para ele o numero 4 é uma forma diferente de escrever o 1, ou seja, para Gustavo 1 = 4. 
 * Gustavo decide brincar com os numeros, escrevendo com os numeros que ele aprendeu um numero qualquer e somando o valor de seus digitos,
 * mas para ele fazer isso de modo manual seria algo extremamente custoso, deste modo, nós iremos fazer essa conta para que Gustavo veja a
 * quantidade de possibilidades em cada caso
 */

// Structs e funções retiradas de https://gist.github.com/jhjonathanlee/6116f4f57ecdb735fd11
typedef struct {
  int *num;
  int digits;
  int size;
} BigInteger;


void expand(int **a, int size);
BigInteger *add(BigInteger *a, BigInteger *b);
BigInteger *createBigInt(char *s);
void freeBigInt(BigInteger *bigInt);
void printBigInt(BigInteger *bigInt);

int main() {
    //Declaração inicial das variaveis
	BigInteger* arrayNumber[1001];
    int n, i;

    arrayNumber[0] = createBigInt("1");
    arrayNumber[1] = createBigInt("2");
    arrayNumber[2] = createBigInt("5");
    arrayNumber[3] = createBigInt("13");


    // Loop principal que recebe qual é a soma desejada por Gustavo
	while(scanf("%d", &n) == 1) {
        for(i = 4; i <= n; i++) {
            // Inicialização da varivel para o valor 0
            arrayNumber[i] = createBigInt("0");

            // Soma dos termos anteriores para verificação da quantidade
            arrayNumber[i] = add(arrayNumber[i], arrayNumber[i - 1]);
            arrayNumber[i] = add(arrayNumber[i], arrayNumber[i - 2]);
            arrayNumber[i] = add(arrayNumber[i], arrayNumber[i - 3]);
            arrayNumber[i] = add(arrayNumber[i], arrayNumber[i - 1]);
        }

        printBigInt(arrayNumber[n]);
	}

    return 0;
}

/**
 * Implementação das funções referentes ao BigInteger, todas as implementações foram retiradas do link
 * citado abaixo, novamente
 * Link: https://gist.github.com/jhjonathanlee/6116f4f57ecdb735fd11
 */

BigInteger *createBigInt(char *s) {
  int digits = strlen(s);
  int size = digits * 2;
  
  BigInteger *bigInt = (BigInteger *) malloc(sizeof(BigInteger));
  bigInt->num = malloc(sizeof(int)*size);
  memset(bigInt->num, 0, sizeof(int)*size); 
  bigInt->digits = digits;
  bigInt->size = size;

  for (int i = digits - 1; i >= 0; i--) {
    bigInt->num[i] = s[digits - i - 1] - 48;
  }

  return bigInt;
}

void freeBigInt(BigInteger *bigInt) {
  free(bigInt->num);
  free(bigInt);
}

void printBigInt(BigInteger *bigInt) {
  for (int i = bigInt->digits - 1; i >= 0; i--) {
    printf("%d", bigInt->num[i]);
  }
  printf("\n");
}

void expand(int **a, int size) {
  *a = realloc(*a, sizeof(*a)*size*2);
  memset(&((*a)[size]), 0, sizeof(*a)*size);
}

BigInteger *add(BigInteger *a, BigInteger *b) {
  BigInteger *retval = (BigInteger *) malloc(sizeof(BigInteger));
  BigInteger *biggerInt = (a->digits >= b->digits) ? a : b;
  BigInteger *smallerInt = (a->digits >= b->digits) ? b : a;
  retval->size = biggerInt->size;
  
  int *arr = malloc(sizeof(int)*biggerInt->size);
  memset(arr, 0, sizeof(*arr)*biggerInt->size);
  int n1, n2, i;
  n1 = 0;
  n2 = 0;

  // add smaller int to bigger int
  for (i = 0; i < smallerInt->digits; i++) {
    n1 = biggerInt->num[i] + smallerInt->num[i] + n2;
    n2 = 0;
    if (n1 >= 10) {
      n2 = 1;
      n1 -= 10;
    }
    arr[i] = n1;
  }

  if (n2 > 0) {
    if (i >= biggerInt->size) {
      expand(&arr, biggerInt->size);
      retval->size = biggerInt->size*2;
    }
    do {
      n1 = i < biggerInt->digits ? biggerInt->num[i] : 0;
      arr[i] = n1 + n2;
      if (arr[i] > 10) {
        arr[i] -= 10;
        n2 = 1;
      } else {
        n2 = 0;
      }
      i++;
    } while (n2 > 0);
  }
  while (i < biggerInt->digits) {
    arr[i] = biggerInt->num[i];
    i++;
  }
  retval->num = arr;
  retval->digits = i;
  return retval;
}