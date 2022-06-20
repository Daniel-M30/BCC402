#include <stdio.h>

// Nome do problema: 10035 - Primary Arithmetic
// Problema em questão: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=33&page=show_problem&problem=976

/**
 * Neste problema a ideia é somar os numeros da mesma forma que uma criança faria, pegando digito por digito.
 * Deste modo, existem algumas somas que ultrapassam de um digito, o que chamamos de "carry".
 * O objetivo deste algoritmo é verificar a quantidade de operações "carry" que foram realizadas na soma entre dois numeros.
 */

int main() {
    // Declaração inicial das variaveis
    unsigned long number1, number2;
    int count, carry;

    // Loop principal que valida se a entrada é valida e se os numeros digitados são os que resultam na parada da execução (0 0)
    while(scanf("%lu %lu", &number1, &number2) == 2 && (number1 != 0 || number2 != 0)) {
        count = 0;
        carry = 0;

        while(number1 != 0 || number2 != 0) {
            /**
             * Neste ponto, pegamos o valor do digito mais a direita de ambos os numeros e somamos, em alguns casos pode ser 
             * que temos um digito para ser somado da operação anterior, por isso há a soma com a variavel carry
             */
            carry = (carry + (number1 % 10) + (number2 % 10)) / 10;

            /**
             * Como ja realizamos a soma do digito mais a direita, devemos atualizar este valor para realizar a soma do prosimo digito,
             * para isso, estou realizando a divisão entre inteiros por 10, que basicamente remove o ultimo digito do numero, fazendo com
             * que o nosso digito mais a direita seja o que queremos. Ele vai fazendo esses operações até não existir mais digitos para
             * serem somados.
             */
            number1 /= 10;
            number2 /= 10;
            count += carry;
        }

        if(count == 1)
            printf("1 carry operation.\n");

        else if(count > 1)
            printf("%d carry operations.\n", count);

        else
            printf("No carry operation.\n");
    }

    return 0;
}