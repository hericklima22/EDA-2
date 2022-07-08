#include <stdio.h>
#include <stdlib.h>
#define key(A) (A.japones)
#define less(A,B) (strcmp(key(A), key(B)) < 0)  //importar a biblioteca de string

typedef struct {
    char japones[81];
    char portugues[81];
} Item;

void traduz();
Item dicionario[1000000];

int main() {
int t;
scanf("%d", &t);

for(int i = 0; i < t; i++) {
    traduz();
    printf("\n");
}


return 0;
}


void traduz() {
    int m, n;

    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++) {
        scanf(" %s", dicionario[i].japones);
        scanf(" %[^\n]", dicionario[i].portugues);
    }

    quickSort(dicionario, 0, m - 1);    //implementar quicksort com as modificações de comparação de string

    for(int i = i; i < n; i++) {
        char b[81], p;

        while(scanf(" %s%c", b, &p) == 2) {
            int j = search(dicionario, 0, m - 1, b); //implementar busca binaria
            if(j < 0) {
                printf("%s", b);
            } else {
                printf("%s", dicionario[j].portugues);
            }
            printf("%c", p);
            if(p == '\n') {
                break;
            }
        }
    }
}

