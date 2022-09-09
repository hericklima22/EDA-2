#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define key(A) (A.japones)
#define less(A,B) (strcmp(key(A), key(B)) < 0)
#define exch(A,B) {Item t = A; A = B; B = A;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

typedef struct {
    char japones[81];
    char portugues[81];
} Item;

Item dicionario[1000000];

int search(Item *v, int l, int r, char *x) {
    while(l <= r) {
        int k = (r - l) / 2 + l;

        if(strcmp(v[k].japones, x) == 0) return k;

        if(strcmp(v[k].japones, x) < 0) {
            l = k + 1;
        } else {
            r = k - 1;
        }
    }
    return -1;
}

void merge(Item *arr, int l, int m, int r) {
    int l1 = l, l1i = l1;
    int l2 = m + 1, l2i = l2;

    Item *aux = malloc(sizeof(Item) * (r - l + 1));

    int ci = 0, lc = 0, rc = r - l;

    while(l1i <= m && l2i <= r) {
        if(less(arr[l1i], arr[l2i])) {
        aux[ci++] = arr[l1i++];
        } else {
        aux[ci++] = arr[l2i++];
        }
    }

    while(l1i <= m) {
        aux[ci++] = arr[l1i++];
    }

    while(l2i <= r) {
        aux[ci++] = arr[l2i++];
    }

    l1i = l;
    
    for(ci = 0; ci <= rc; ci++) {
        arr[l1i++] = aux[ci];
    }

    free(aux);
}

void mergeSort(Item *arr, int l, int r) {
    if(l >= r) {
        return;
    }

    int meio = (r - l) / 2 + l;
    mergeSort(arr, l, meio);
    mergeSort(arr, meio + 1, r);

    merge(arr, l, meio, r);
}

void traduz() {
    int m, n;

    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++) {
        scanf(" %s", dicionario[i].japones);
        scanf(" %[^\n]", dicionario[i].portugues);
    }

    // quickSort(dicionario, 0, m - 1);
    mergeSort(dicionario, 0, m - 1);

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

int main() {
    int t;
    scanf("%d", &t);

    for(int i = 0; i < t; i++) {
        traduz();
        printf("\n");
    }
return 0;
}