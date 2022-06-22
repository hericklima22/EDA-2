#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void insertionSimple(Item *arr, int left, int right) {
  for(int i = left + 1; i < right; i++) {
    for(int j = i; j > left; j--) {
      cmpexch(arr[j - 1], arr[j]);
    }
  }
}

int main() {

  int limite = 100;

  Item arr[1000];
  // time_t t;
  // srand((unsigned) time(&t));

  // for(int i = 0; i < limite; i++) {
  //   arr[i] = rand() % limite;
  // }
  int index = 0;

  while(scanf("%d", &arr[index]) != EOF) {
    index++;
  }
  // CHAME A FUNÇÃO DE ORDENAÇÃO AQUI
  insertionSimple(arr, 0, index);
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