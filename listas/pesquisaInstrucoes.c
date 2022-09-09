#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

typedef struct {
  int key;
  char instrucao[16];
} Comando;

void insertion(Comando *arr, int left, int right) {
  for(int i = right - 1; i > left; i--) {
    if(less(arr[i].key, arr[i - 1].key)) {
      Comando tmp = arr[i];
      arr[i] = arr[i - 1];
      arr[i - 1] = tmp;
    }
  }
  
  for(int i = left + 2; i < right; i++) {
    int j = i;
    Comando tmp = arr[j];
    while(less(tmp.key, arr[j - 1].key)) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = tmp;
  }
}

int search(Comando *arr, int x, int left, int right) {
  while(left <= right) {
    int k = left + (right - left) / 2;

    if(arr[k].key == x) {
      return k;
    }
    
    if(arr[k].key < x) {
      left = k + 1;
    } else {
      right = k - 1;
    }
  }
  return -1;
}

int main() {
  Comando Comandos[50000];
  int qtdComandos, consulta, res;

  scanf("%d", &qtdComandos);

  for(int i = 0; i < qtdComandos; i++) {
    scanf("%d %s", &Comandos[i].key, Comandos[i].instrucao);
  }

  insertion(Comandos, 0, qtdComandos);

  while(scanf("%d", &consulta) != EOF) {
    // REALIZA BUSCA
    res = search(Comandos, consulta, 0, qtdComandos);
    if(res >= 0) {
      printf("%s\n", Comandos[res].instrucao);
    } else {
      printf("undefined\n");
    }
  }
  
  return 0;
}