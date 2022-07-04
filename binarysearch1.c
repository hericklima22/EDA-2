#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void insertion(Item *arr, int left, int right) {
  for(int i = right - 1; i > left; i--) {
    cmpexch(arr[i - 1], arr[i]);
  }

  for(int i = left + 2; i < right; i++) {
    int j = i;
    Item tmp = arr[j];
    while(less(tmp, arr[j - 1])) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = tmp;
  }
}

int search(Item *arr, int x, int tam) {
  int k, r = tam, l = -1;
  while(l < r - 1) {
    k = (r + l) / 2;

    if(arr[k] == x) {
      return k;
    }

    if(arr[k] < x) {
      l = k;
    } else {
      r = k;
    }
  }

  return r;
}

int main() {
  int n, m, x;

  Item *arr = malloc(sizeof(Item) * n);

  scanf("%d %d", &n, &m);

  for(int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  insertion(arr, 0, n);

  for(int i = 0; i < m; i++) {
    scanf("%d", &x);
    printf("%d\n", search(arr, x, n)); 
  }

  free(arr);
  return 0;
}