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

int main() {

  Item arr[50000];
  int index = 0;

  while(scanf("%d", &arr[index]) != EOF) {
    index++;
  }
  // CHAME A FUNÇÃO DE ORDENAÇÃO AQUI
  insertion(arr, 0, index);
  /////////////////////////////////// 

  for(int i = 0; i < index; i++) {
    printf("%d", arr[i]);
    if(i < index - 1) {
      printf(" ");
    }
  }
  printf("\n");
  return 0;
}