#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int key;
  int qtd;
} Nota;

int main() {
  int n, nota, maiorNota = 0, codMaiorNota = 0;

  scanf( "%d", &n );

  Nota *notas = malloc(sizeof(Nota) * n);

  for( int i = 0; i < n; i++ ) {
    notas[i].qtd = 0;
  }
  
  for( int i = 0; i < n; i++ ) {

    scanf( "%d", &nota );

    notas[nota].qtd++;
    notas[nota].key = nota;

    if(notas[nota].qtd >= maiorNota) {
      if(notas[nota].qtd == maiorNota) {
        codMaiorNota = (notas[nota].key >= codMaiorNota) ? notas[nota].key : codMaiorNota;
      } else {
        codMaiorNota = notas[nota].key;
      }
      maiorNota = notas[nota].qtd;
    }
  }
  printf("%d\n", codMaiorNota);
  free(notas);
  return 0;
}