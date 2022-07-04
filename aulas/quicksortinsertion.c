#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define less(a,b) (a < b)
#define lesseq(a,b) (a <= b)
#define exch(a,b) {Item t=a;a=b;b=t;}
#define cmpexch(a,b) {if(less(b, a)) exch(a, b);}

int separa(Item *arr, int l, int r) {
  int i = l - 1, j = r;
  Item c = arr[r]; //pivô

  while(1) {
    while(less(arr[++i], c));
    while(less(c, arr[--j]))
      if(i == j) break;
    
    if(i >= j) break;

    exch(arr[i], arr[j]);
  }
  exch(arr[i], arr[j]);
  return i;
}

void quickSort(Item *arr, int l, int r) {
  if(r - l < 32) return;
  exch(arr[r - 1], arr[(r - l) / 2 + 1]);
  cmpexch(arr[l], arr[r - 1]);
  cmpexch(arr[r - 1], arr[r]);

  int j = separa(arr, l + 1, r - 1);

  quickSort(arr, l, j - 1);
  quickSort(arr, j + 1, r);
}

void insertionSort(Item *arr, int l, int r) {
  for(int i = r - 1; i > l; i--) {
    cmpexch(arr[i - 1], arr[i]);
  }

  for(int i = l + 2; i < r; i++) {
    int j = i;
    Item tmp = arr[j];
    while(less(tmp, arr[j - 1])) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = tmp;
  }
}

void quickSortInsertion(Item *arr, int l, int r) {
  quickSort(arr, l, r);
  insertionSort(arr, l, r);
}