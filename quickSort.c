#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD
#include <time.h>
typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

int separa(Item *arr, int l, int r) {
  int i = l - 1, j = r;
  Item c = arr[r];

  while(1) {
    while(less(arr[++i], c));
    while(less(c, arr[--j]))
      if(i == j) 
        break;
    if(i >= j)
      break;

    exch(arr[i], arr[j]);
  }
  exch(arr[i], arr[r]);
  return i;
}

void quickSort(Item *arr, int l, int r) {
  if(r - l <= 32) return;
  exch(arr[r - 1], arr[(r - l) / 2 + 1]);
  cmpexch(arr[l], arr[r - 1]);
  cmpexch(arr[l], arr[r]);
  cmpexch(arr[r - 1], arr[r]);

  int j = separa(arr, l + 1, r - 1);

  quickSort(arr, l, j - 1);
  quickSort(arr, j + 1, r);
}

void insertionSort(Item *arr, int l, int r) {
  for(int i = r; i > l; i--) {
    cmpexch(arr[i - 1], arr[i]);
  }

  for(int i = l + 2; i <= r; i++) {
=======
typedef int Item;
#define less(A,B) (A < B)
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

int separa(Item *v, int l, int r) {
    int i = l - 1, j = r;
    Item c = v[r];
    while(1) {
        while(less(v[++i], c));
        while(less(c, v[--j])) if(i == j) break;
        if(i >= j) break;

        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}

void quickSort(Item *v, int l, int r) {
    if(r - l <= 32) return;

    exch(v[(l + r) / 2],v[r - 1]);
    cmpexch(v[l], v[r - 1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[r - 1], v[r]);

    int j = separa(v, l, r);

    quickSort(v, l, j - 1);
    quickSort(v, j + 1, r);
}

void insertionSort(Item *arr, int left, int right) {
  for(int i = right; i > left; i--) {
    cmpexch(arr[i - 1], arr[i]);
  }

  for(int i = left + 2; i <= right; i++) {
>>>>>>> cf9352f5c97d3ee642e4b5aa475b7dee805657c3
    int j = i;
    Item tmp = arr[j];
    while(less(tmp, arr[j - 1])) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = tmp;
  }
}

<<<<<<< HEAD
void ordena(Item *arr, int l, int r) {
  quickSort(arr, l, r);
  insertionSort(arr, l, r);
}

int main() {
  int n;
  scanf("%d", &n);

  Item *arr = malloc(sizeof(Item) * n);

  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  // srand(time(NULL));
  // for(int i=0;i<n;i++) arr[i] = rand() % 1000;

  ordena(arr, 0, n - 1);

  for(int i = 0; i < n; i++) {
    printf("%d", arr[i]);
    if(i < n - 1) printf(" ");
    
  }
  printf("\n");
  return 0;
=======
void ordenacao(Item *v, int l, int r) {
    quickSort(v, l, r);
    insertionSort(v, l, r);
}

void print(Item *v, int l, int r) {
    for(int i = l; i < r; i++) {
        printf("%d", v[i]);
        if(i < r - 1) printf(" ");
    } 
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);
    Item *v = malloc(sizeof(Item) * n);

    for(int i = 0; i < n; i++) {
      scanf("%d", &v[i]);
    }

    // quickSort(v, 0, n - 1);
    ordenacao(v, 0, n - 1);

    print(v, 0, n);
    free(v);
    return 0;
>>>>>>> cf9352f5c97d3ee642e4b5aa475b7dee805657c3
}