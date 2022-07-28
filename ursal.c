#include <stdio.h>
#include <stdlib.h>

#define ARRSIZE 1000000
#define keyV(A) (A.votos)
#define keyN(A) (A.numero)
#define lessVotos(A,B) (keyV(A) < keyV(B))
#define lessNumero(A,B) (keyN(A) < keyN(B))
#define eq(A,B) (keyV(A) == keyV(B))
#define exch(A,B) {Votacao t = A; A = B; B = t;}
#define cmpexch(A,B) {if(compara((B),(A))) exch(A,B);}

typedef struct {
  long long int votos;
  long long int numero;
} Votacao;

int compara(Votacao a, Votacao b) {
  if(a.votos == b.votos) {
    return a.numero < b.numero;
  } 
  return a.votos < b.votos;
}

int separa(Votacao *v, int l, int r) {
    int i = l - 1, j = r;
    Votacao c = v[r];
    while(1) {
        while(compara(v[++i], c));
        while(compara(c, v[--j])) if(i == j) break;
        if(i >= j) break;

        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}

void quickSort(Votacao *v, int l, int r) {
    if(r - l <= 32) return;

    exch(v[(l + r) / 2],v[r - 1]);
    cmpexch(v[l], v[r - 1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[r - 1], v[r]);

    int j = separa(v, l, r);

    quickSort(v, l, j - 1);
    quickSort(v, j + 1, r);
}

void insertionSort(Votacao *arr, int left, int right) {
  for(int i = right; i > left; i--) {
    cmpexch(arr[i - 1], arr[i]);
  }

  for(int i = left + 2; i <= right; i++) {
    int j = i;
    Votacao tmp = arr[j];
    while(compara(tmp, arr[j - 1])) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = tmp;
  }
}

void ordenacao(Votacao *v, int l, int r) {
    quickSort(v, l, r);
    insertionSort(v, l, r);
}

void quickSelect(Votacao *arr, int l, int r, int p) {
  int j = separa(arr, l, r);

  if(j == p) return;

  else if(j < p) 
    quickSelect(arr, j + 1, r, p);
  else
    quickSelect(arr, l, j - 1, p);
}

void iniciaVotacao(Votacao *v, int n) {
  for(int i = 0; i < n; i++) {
    v[i].votos = 0;
  }
}

Votacao votacao[ARRSIZE];

int main() {
  long long int s = 0, df = 0, de = 0, voto;
  long long int contaVotos = 0, contaNulos = 0;
  long long int presidente = 0;

  scanf("%lld %lld %lld", &s, &df, &de);

  iniciaVotacao(votacao, ARRSIZE);

  while(scanf("%lld", &voto) != EOF) {
    if(voto >= 0) {
      votacao[voto].numero = voto;
      votacao[voto].votos++;

      if(voto < 100) presidente++;

      contaVotos++;
    } else {
      contaNulos++;
    }
  }

  quickSelect(votacao, 0, 99, 99 - 2);  // presidente
  ordenacao(votacao, 99 - 2, 99);

  quickSelect(votacao, 100, 999, 999 - s);  // senador
  ordenacao(votacao, 999 - s, 999);

  quickSelect(votacao, 1000, 9999, 9999 - df);   // dep Fed
  ordenacao(votacao, 9999 - df, 9999);

  quickSelect(votacao, 10000, 99999, 99999 - de);   // dep Fed
  ordenacao(votacao, 99999 - de, 99999);

  printf("%lld %lld\n", contaVotos, contaNulos);

  if((votacao[99].votos < votacao[98].votos + (votacao[98].votos * 0.5))) {
    printf("Segundo turno\n");
  } else {
    printf("%lld\n", votacao[99].numero);
  }

  for(int i = 0; i < s; i++) {
    printf("%lld", votacao[999 - i].numero);
    if(i < s - 1) printf(" ");
  }
  printf("\n");
  for(int i = 0; i < df; i++) {
    printf("%lld", votacao[9999 - i].numero);
    if(i < df - 1) printf(" ");
  }
  printf("\n");
  for(int i = 0; i < de; i++) {
    printf("%lld", votacao[99999 - i].numero);
    if(i < de - 1) printf(" ");
  }
  printf("\n");

}