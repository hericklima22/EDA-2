#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct {
  char primeroNome[51];
  char ultimoNome[51];
  char nascimento[11];
  char telefone[17];
  int id;
  int index;
} Pessoa;

typedef int Item;

#define ARRAYSIZE 100000
#define hash(A, B) ((int) floor(A % B))
#define less(A,B) (A < B)
#define exch(A,B) {Item t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

int separa(Item *v, int l, int r) {
    int i = l - 1, j = r;
    Item c = v[r];
    while(1) {
        while(less(v[++i], c));
        while(less(c, v[--j])) if(i == j) break;
        if(i >= j) break;

        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}

void quickSort(Item *v, int l, int r) {
    if(r - l <= 32) return;

    exch(v[(l + r) / 2],v[r - 1]);
    cmpexch(v[l], v[r - 1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[r - 1], v[r]);

    int j = separa(v, l, r);

    quickSort(v, l, j - 1);
    quickSort(v, j + 1, r);
}

void insertionSort(Item *arr, int left, int right) {
  for(int i = right; i > left; i--) {
    cmpexch(arr[i - 1], arr[i]);
  }

  for(int i = left + 2; i <= right; i++) {
    int j = i;
    Item tmp = arr[j];
    while(less(tmp, arr[j - 1])) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = tmp;
  }
}

void ordenacao(Item *v, int l, int r) {
    quickSort(v, l, r);
    insertionSort(v, l, r);
}

void add(Pessoa *p, int size, int *a, int *iadd) {
  char primeroNome[51], ultimoNome[51], nascimento[11] ,telefone[17];
  int id;
  scanf("%d", &id);
  int chave = hash(id, size);
  
  if(p[chave].id == id) {
    scanf(" %s %s %s %s", primeroNome, ultimoNome, nascimento, telefone);
    printf("ID %d ja cadastrado.\n", id);
  }
  else {
    scanf(" %s %s %s %s", p[chave].primeroNome, p[chave].ultimoNome, p[chave].nascimento, p[chave].telefone);
    p[chave].id = chave;
    p[chave].index = *iadd;
    a[*iadd] = chave;
    *iadd = *iadd + 1;
  }
}

void del(Pessoa *p, int size, int *a) {
  int id;
  scanf("%d", &id);
  int chave = hash(id, size);
  
  if(p[chave].id == -1) {
    printf("ID %d nao existente.\n", id);
  } else {
    p[chave].id = -1;
    a[p[chave].index] = -1;
  }
}

void info(Pessoa *p, int size) {
  int id;
  scanf("%d", &id);
  int chave = hash(id, size);

  if(p[chave].id == -1) {
    printf("ID %d nao existente.\n", id);
  } else {
    Pessoa tmp = p[chave];
    printf("%s %s %s %s\n", tmp.primeroNome, tmp.ultimoNome, tmp.nascimento, tmp.telefone);
  }
}

void query(Pessoa *p, int *a, int *iadd) {
  char tag[3], buffer;
  int tmp[10000];
  int fn = 0, ln = 0, bd = 0, pn = 0, contaTag = 0, contaCriterio = 0, index = 0;
  Pessoa pessoaTemp;

  while(scanf(" %[^:]:", tag) == 1) {
    switch(tag[0]) {
      case 'f':
        scanf(" %s%c", pessoaTemp.primeroNome, &buffer);
        fn = 1;
        contaTag++;
        break;
      case 'l':
        scanf(" %s%c", pessoaTemp.ultimoNome, &buffer);
        ln = 1;
        contaTag++;
        break;
      case 'b':
        scanf(" %s%c", pessoaTemp.nascimento, &buffer);
        bd = 1;
        contaTag++;
        break;
      case 'p':
        scanf(" %s%c", pessoaTemp.telefone, &buffer);
        pn = 1;
        contaTag++;
        break;
      default:
        break;
    }
    if(buffer == '\n') break;
  }

  printf("IADD: %d\n", *iadd);

  for(int i = 0; i < *iadd; i++) {
    if(a[i] == -1) i++;
    int chave = hash(a[i], ARRAYSIZE);
    contaCriterio = 0;

    if(fn && !strcmp(pessoaTemp.primeroNome, p[chave].primeroNome)) { contaCriterio++; }
    if(ln && !strcmp(pessoaTemp.ultimoNome, p[chave].ultimoNome)) { contaCriterio++; }
    if(bd && !strcmp(pessoaTemp.nascimento, p[chave].nascimento)) { contaCriterio++; }
    if(pn && !strcmp(pessoaTemp.telefone, p[chave].telefone)) { contaCriterio++; }

    if(contaCriterio == contaTag) tmp[index++] = chave; 
  }

  ordenacao(tmp, 0, index - 1);
  for(int i = 0; i < index; i++) {
    printf("%d ", tmp[i]);
  }
  printf("\n");
}

Pessoa p[ARRAYSIZE];
int adicionadas[ARRAYSIZE], indexAdicionada = 0;

int main() {
  char comando[6];

  while(scanf("%s", comando) != EOF) {
    switch(comando[0]){
      case 'a':
        add(p, ARRAYSIZE, adicionadas, &indexAdicionada);
        break;
      case 'd':
        del(p, ARRAYSIZE, adicionadas);
        break;
      case 'i':
        info(p, ARRAYSIZE);
        break;
      case 'q':
        query(p, adicionadas, &indexAdicionada);
        break;
      default:
        break;
    }
  }

  return 0;
}