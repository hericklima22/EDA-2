#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define less(A,B) (A<B)
#define lesseq(A,B) (A<=B)
#define exch(A,B) {Semente t=A;A=B;B=A;}
#define cmpexch(A,B) {if(less(B.code,A.code)) exch(A,B);}

typedef struct {
  long code;
  long nota;
} Semente;

int separa(Semente *v, int l, int r) {
  int i = l - 1, j = r;
  Semente c = v[r];

  while(1) {
    while(less(v[++i].nota, c.nota));
    while(less(c.nota, v[--j].nota)) if(i == j) break;
    if(i >= j) break;
    int selecao = (v[i].nota == c.nota) ? v[i].code < c.code : v[i].nota < c.nota;
    if(selecao) {
      exch(v[i], v[j]);
    }
  }
  exch(v[i], v[r]);
  return i;
}

void quickSelect(Semente *v, int l, int r, int p) {
  int j = separa(v, l, r);
  if(j == p) return;
  else if(j < p) {
    quickSelect(v, j + 1, r, p);
  } else {
    quickSelect(v, l, j - 1, p);
  }
}

void merge(Semente *arr, int l, int m, int r) {
  int l1 = l, l1i = l1;
  int l2 = m + 1, l2i = l2;

  Semente *aux = malloc(sizeof(Semente) * (r - l + 1));

  int ci = 0, lc = 0, rc = r - l;

  while(l1i <= m && l2i <= r) {
    if(less(arr[l1i].code, arr[l2i].code)) {
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

void mergeSort(Semente *arr, int l, int r) {
  if(l >= r) {
    return;
  }

  int meio = (r - l) / 2 + l;
  mergeSort(arr, l, meio);
  mergeSort(arr, meio + 1, r);

  merge(arr, l, meio, r);
}

int main() {
  int n, index = 0, size;

  scanf("%d", &n);
  size = n;
  Semente *sementes = malloc(sizeof(Semente) * (size * size));

  while(scanf("%ld %ld", &sementes[index].code, &sementes[index].nota) != EOF) {
    index++;
    if(index == n - 1) {
      size *= 2;
      sementes = realloc(sementes, sizeof(Semente) * (size));
    }
  }

  quickSelect(sementes, 0, index - 1, n);
  mergeSort(sementes,0, n - 1);

  printf("\n");

  for(int i = 0; i < index; i++) {
    printf("%ld %ld\n", sementes[i].code, sementes[i].nota);
  }

  free(sementes);
  return 0;
}