#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

int binarySearch(Item *arr, int x, int l, int r) {
  while(l <= r) {
    int index = (r - l) / 2 + l;

    if(arr[index] == x) {
      return arr[index];
    }

    if(arr[index] < x) {
      l = index + 1;
    } else {
      r = index - 1;
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


int main() {
  int m, n, x;
  scanf("%d", &n);

  Item *arr = malloc(sizeof(Item) * n);

  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  mergeSort(arr, 0, n - 1);

  while(scanf("%d", &x) != EOF) {
    printf("%s\n", binarySearch(arr, x, 0, n - 1) >= 0 ? "sim" : "nao");
  }
  free(arr);

  return 0;
}