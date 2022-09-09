#include <stdio.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void bubble(Item *arr, int n) {
  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; j < n - i - 1; j++) {
      cmpexch(arr[j], arr[j + 1]);
    }
  }
}

int main() {

  Item array[1000];
  int index = 0;

  while(scanf("%d", &array[index]) != EOF) {
    index++;
  }
  bubble(array, index);

  for(int i = 0; i < index; i++) {
    printf("%d", array[i]);
    if(i < index - 1) {
      printf(" ");
    }
  }
  printf("\n");
  return 0;
}