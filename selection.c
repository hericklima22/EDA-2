#include <stdio.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void selection() {
  
}

int main() {

  Item array[1000];
  int index = 0;

  while(scanf("%d", &array[index]) != EOF) {
    index++;
  }
  // CHAME A FUNÇÃO DE ORDENAÇÃO AQUI

  /////////////////////////////////// 

  for(int i = 0; i < index; i++) {
    printf("%d", array[i]);
    if(i < index - 1) {
      printf(" ");
    }
  }
  printf("\n");
  return 0;
}