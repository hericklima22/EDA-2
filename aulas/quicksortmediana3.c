#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

///////////////// IMPLEMENTAÇÂO DO PROFESSOR

int separa(Item *arr, int l, int r) {   // NÂO É ESTÁVEL
    int i = l - 1, j = r;
    Item c = arr[r];

    while(1) {
        while(less(arr[++i], c));
        while(less(c, arr[--j]))
            if(i == j) break;

        if(i >= j) break;
        exch(arr[i], arr[j]);
    }

    exch(arr[i], arr[r]);
    return i;
}

void quickSort(Item *arr, int l, int r) {
    if(l >= r) return;

    exch(arr[r - 1], arr[(r - l) / 2 + 1]);
    cmpexch(arr[l], arr[r - 1]);
    cmpexch(arr[r - 1], arr[r]);

    int j = separa(arr, l + 1, r - 1);

    quickSort(arr, l, j - 1);
    quickSort(arr, j+ 1, r);
}

int main() {
  int n;
  scanf("%d", &n);

  Item *arr = malloc(sizeof(Item) * n);

  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  quickSort(arr, 0, n - 1);

  for(int i = 0; i < n; i++) {
    printf("%d%c", arr[i], (i < n - 1) ? ' ' : 0);
  }
  printf("\n");
  return 0;
}