#include <stdio.h>

int grafo_m[2000][2000];

int main() {
  int visitados[2000], n, m, j;

  scanf("%d %d %d", &n, &m, &j);

  for(int i = 0; i < n; i++) {
    int vizinhos;
    scanf("%d", &vizinhos);
    grafo_m[i][i] = 1;
    for(int j = 0; j < vizinhos; j++) {
      int local;
      scanf("%d", &local);
      grafo_m[i][local] = 1;
    }
  }

  for(int i = 0; i < m; i++) {
    int local;
    scanf("%d", &local);

    for(int j = 0; j < n; j++) {
      if(grafo_m[local][j] == 1) visitados[j] = 1;
    }
  }

  for(int i = 0; i < j; i++) {
    int visitado;
    scanf("%d", &visitado);
    if(visitados[visitado] == 1) {
      printf("Eu vou estar la\n");
    } else {
      printf("Eu nao vou estar la\n");
    }
  }

  return 0;
}