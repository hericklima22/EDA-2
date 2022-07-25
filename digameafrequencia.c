#include <stdio.h>
#include <stdlib.h>

#define TABLESIZE 1000
#define less(A,B) (A < B)
#define eq(A,B) (A == B)
#define lesseq(A,B) (A <= B)
#define moreeq(A,B) (A >= B)
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexchLess(A,B) {if(less(B,A)) exch(A,B);}
#define cmpexchEq(A,B) {if(lesseq(B,A)) exch(A,B);}

typedef struct {
  int codigo;
  int qtd;
} Item;

Item resultado[TABLESIZE];

void merge(Item *v, int l, int m, int r) {
  int l1i = l;
  int l2i = m + 1;

  Item *aux = malloc(sizeof(Item) * (r - l + 1));

  int ci = 0, rc = r - l;

  while(l1i <= m && l2i <= r) {
    int diff = (eq(v[l1i].qtd, v[l2i].qtd)) ? lesseq(v[l1i].codigo, v[l2i].codigo) : lesseq(v[l1i].qtd, v[l2i].qtd);
    if(diff) {
      aux[ci++] = v[l1i++];
    } else {
      aux[ci++] = v[l2i++];
    }
  }

  while(l1i <= m) {
    aux[ci++] = v[l1i++];
  }

  while(l2i <= r) {
    aux[ci++] = v[l2i++];
  }
  l1i = l;

  for(ci = 0; ci <= rc; ci++) {
    v[l1i++] = aux[ci];
  }

  free(aux);
}

void mergeSort(Item *v, int l, int r) {
  if(l >= r) return;

  int m = (r - l) / 2 + l;

  mergeSort(v, l, m);
  mergeSort(v, m + 1, r);

  merge(v, l, m, r);
}

void initTable(Item *v) {
  for(int i = 0; i < TABLESIZE; i++) {
    v[i].qtd = 0;
  }
}


int main() {
  
  char s[1001];

  while(scanf(" %s", s) != EOF) {
    int indexSequencia = 0, contaSequencia = 0, index = 0, indexResultado = 0;
    initTable(resultado);

    while(s[index] != '\0') {
      int chave = s[index];
      resultado[chave].codigo = s[index];
      resultado[chave].qtd++;

      index++;
    }
    mergeSort(resultado, 0, TABLESIZE - 1);

    for(int i = 0; i < TABLESIZE; i++) {
      if(resultado[i].qtd) {
        printf("%d %d\n", resultado[i].codigo, resultado[i].qtd);
      }
    }
    printf("\n");
  }
  return 0;
}
