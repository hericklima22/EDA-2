#include <stdio.h>
#include <stdlib.h>
typedef int Item;
#define less(A,B) (A < B)
#define lesseq(A,B) (A <= B)
#define exch(A,B) {Item tmp=A;A=B;B=tmp;}
#define cpmech(A,B) {if(less(B,A) exch(A,B);)}

int separa(Item *arr, int l, int r) {
  int i = l - 1, j = r;
  Item c = arr[r];  //pivô

  while(1) {
    while(less(arr[++i], c));
    while(less(c, arr[--j])) {
      if(i == j) break;
    }

    if(i >= j) 
      break;
    
    exch(arr[i], arr[j]);
  }

  exch(arr[i], arr[r]);
  return i;
}

void quickSelect(Item *arr, int l, int r, int p) {
  int j = separa(arr, l, r);

  if(j == p) return;

  else if(j < p) 
    quickSelect(arr, j + 1, r, p);
  else
    quickSelect(arr, l, j - 1, p);
}