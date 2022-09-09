#include <stdio.h>
#include <stdlib.h>
typedef struct {
  int qtd;
  char letra;
  int index;
} Item;

#define less(A,B) (A < B)
#define moreeq(A,B) (A >= B)
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexchLess(A,B) {if(less(B,A)) exch(A,B);}
#define cmpexchEq(A,B) {if(lesseq(B,A)) exch(A,B);}

void merge(Item *v, int l, int m, int r) {
  int l1i = l;
  int l2i = m + 1;

  Item *aux = malloc(sizeof(Item) * (r - l + 1));

  int ci = 0, rc = r - l;

  while(l1i <= m && l2i <= r) {
    if(moreeq(v[l1i].qtd, v[l2i].qtd)) {
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

Item resultado[100000];

int main() {

  char s[100001];
  int indexSequencia = 0, contaSequencia = 0, indexTotal = 0, index = 0, indexResultado = 0;

  scanf(" %s", s);

  while(s[index] != '\0') {
    while(s[index] == s[indexSequencia]) {
      contaSequencia++;
      indexSequencia++;
    }

    resultado[indexResultado].qtd = contaSequencia;
    resultado[indexResultado].letra = s[index];
    resultado[indexResultado].index = index;

    index += contaSequencia;
    indexSequencia = index;
    contaSequencia = 0;
    indexResultado++;
  }

  mergeSort(resultado, 0, indexResultado - 1);

  for(int i = 0; i < indexResultado; i++) {
    printf("%d %c %d\n", resultado[i].qtd, resultado[i].letra, resultado[i].index);
  }

  return 0;
}