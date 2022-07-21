#include <stdio.h>
#include <stdlib.h>
typedef int Item;

int main() {
  int n = 1, cod, maiorCod, indexMaiorCod;

  while(1) {
    scanf("%d", &n);

    if(!n) break;

    Item *v = calloc(n, sizeof(Item) * n);

    maiorCod = 0;
    indexMaiorCod = 0;

    for(int i = 0; i < n; i++) {
      scanf("%d", &cod);
      v[cod]++;

      if(maiorCod < v[cod]) {
        maiorCod = v[cod];
        indexMaiorCod = cod;
      }
    }
    
    printf("%d\n", indexMaiorCod);
    
    free(v);
  }
  return 0;
}