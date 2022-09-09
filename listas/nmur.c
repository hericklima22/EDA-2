#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

int removeRepetido(Item *arr, int n) {
  Item *tmp = malloc(sizeof(Item) * n);
  int j = 0;

  for(int i = 0; i < n - 1; i++) {
    if(arr[i] != arr[i + 1]) {
      tmp[j++] = arr[i];
    }
  }

  tmp[j++] = arr[n - 1];

  for(int i = 0; i < j; i++) {
    arr[i] = tmp[i];
  }
  free(tmp);
  return j;
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

int search(Item *arr, int x, int l, int r) {
  while(l <= r) {
    int k = (r - l) / 2 + l;
    if(arr[k] == x) {
      return k;
    }
    if(arr[k] < x) {
      l = k + 1;
    } else {
      r = k - 1;
    }
  }
  return -1;
}

int main() {
  int n, soma = 0, tmpIndex = 0;
  scanf("%d", &n);

  Item *arr = malloc(sizeof(Item) * n);
  Item *temp = malloc(sizeof(Item) * n * 2);

  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  mergeSort(arr, 0, n - 1);

  int size = removeRepetido(arr, n);
  if(size % 2) {
    arr[size] = 1000000000;
    size++;
  }

  for(int i = 0; i < size; i+=2) {
    temp[tmpIndex] = arr[i];
    temp[tmpIndex + 1] = arr[i + 1];

    soma = temp[tmpIndex] + temp[tmpIndex + 1];
    tmpIndex += 2;
    if(search(arr, soma, i, size - 1) == -1) {
      temp[tmpIndex++] = soma;
    } 
  }
  // for(int i = 0; i < tmpIndex; i++) {
  //   printf("%d ", temp[i]);
  // }

  mergeSort(temp, 0, tmpIndex - 1);

  for(int i = 0; i < tmpIndex; i+=4) {
    printf("%d\n", temp[i]);
  }

  // printf("\n");
  printf("Elementos: %d\n", tmpIndex);

  free(arr);
  free(temp);
  return 0;
}