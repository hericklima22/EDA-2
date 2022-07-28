#include <stdio.h>
#include <stdlib.h>

typedef struct {
  long long int qtd;
} Nota;

int main() {
  long long int n, nota, maiorNota = 0, codMaiorNota = 0;

  scanf( "%lld", &n );

  Nota notas[10001];

  for( int i = 0; i < n; i++ ) {
    notas[i].qtd = 0;
  }
  
  for( int i = 0; i < n; i++ ) {

    scanf( "%d", &nota );

    notas[nota].qtd++;

    if(notas[nota].qtd >= maiorNota) {
      if(notas[nota].qtd == maiorNota) {
        codMaiorNota = (nota > codMaiorNota) ? nota : codMaiorNota;
      } else {
        codMaiorNota = nota;
      }
      maiorNota = notas[nota].qtd;
    }
  }
  printf("%d\n", codMaiorNota);
  return 0;
}