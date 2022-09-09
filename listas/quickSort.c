#include <stdio.h>
#include <stdlib.h>
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
    int j = i;
    Item tmp = arr[j];
    while(less(tmp, arr[j - 1])) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = tmp;
  }
}

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
}