#include <stdio.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void selection(Item *arr, int length) {
  int min;
  for(int i = 0; i < length - 1; i++) {
    min = i;
    for(int j = i + 1; j < length; j++) {
      if(arr[j] < arr[min]) {
        min = j;
      }
    }
    exch(arr[min], arr[i]);
  }
}

int main() {

  Item arr[1000];
  int index = 0;

  while(scanf("%d", &arr[index]) != EOF) {
    index++;
  }
  // CHAME A FUNÇÃO DE ORDENAÇÃO AQUI
  selection(arr, index);
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