#include<stdio.h> 
#include<string.h>
#include<stdlib.h>

char str[1000][200]; 
char ch[50]={"the quick brown fox jumps over the lazy dog"};
char encode[27];
int num;

int matchAll(int t) {  
    int j;
    // Preenche todos os espaços do array com o valor 0
    for(j = 0; j < 26; j++)  
        encode[j] = '0';  
        
    for(j = 0; j < 43; j++) {  
        if(ch[j] != ' ') {
            // Vai decodificando letra a letra ate passar por toda a chave
            if(encode[str[t][j] - 'a'] == '0') 
                encode[str[t][j] - 'a'] = ch[j];
   
            else if(encode[str[t][j] - 'a'] != ch[j]) 
                return 0;
        }  
    }  
    
    // Caso uma das casas não tiveram seu valor modificado, não foi encontrado uma solução
    for(j = 0; j < 26; j++) {  
        if(encode[j] == '0')
            return 0;  
    }  
    
    return 1; 
}

int judge() {  
    int i, len;  
    for(i = 0; i < num; i++) {  
        len = strlen(str[i]);  
        if(len == 43) {
            if(str[i][3] == ' ' && str[i][9] == ' ' && str[i][15] == ' ' && str[i][19] == ' ' &&
                str[i][25] == ' ' && str[i][30] == ' ' && str[i][34] == ' ' && str[i][39] == ' ') {
                if(matchAll(i))
                    return 1;
            }  
        }  
    }  
    
    return 0; 
}

void print() {  
    int i, j, len;  
    for(i = 0; i < num; i++) {  
        len = strlen(str[i]);  
        for(j = 0; j < len; j++) {
            if(str[i][j] != ' ')
                str[i][j] = encode[str[i][j] - 'a'];  
        }  
    }  
    
    for(i = 0; i < num; i++)  
        printf("%s\n", str[i]); 
}

int main() {  
    int i, t;  
    scanf("%d", &t);  

    // Removendo '\n' da entrada
    getchar();  
    getchar();  
    while(t--) {  
        i = 0;  
        memset(str, 0, sizeof(str));  
        while(1) {
            fgets(str[i], 200, stdin);
            // Remove '\n' inserido no final pela função fgets
            str[i][strlen(str[i]) - 1] = '\0';
            
            if(strcmp(str[i], "") == 0)
                break;

            i++;  
        }  
    
        num = i;  
        if(judge())  
            print();  
        
        else
            printf("No solution.\n");  
            
        if(t >= 1)
            printf("\n");  
    }  
    
    return 0; 
}