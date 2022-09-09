#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define arrsize 100000
#define strsize 101

typedef struct {
  char **n;
  int index, tam;
} Pilha_t;

typedef struct {
  char no[strsize], ant[strsize], prox[strsize];
  int visitado;
} Item;

void inicializaPilha(Pilha_t *p) {
  p -> n = malloc(sizeof(char *) * arrsize);

  for(int i = 0; i < arrsize; i++) {
    p -> n[i] = malloc(sizeof(char) * strsize);
  }
  p -> index = 0;
  p -> tam = arrsize;
}


void mataPilha(Pilha_t *p) {
  for(int i = 0; i < arrsize; i++) {
    free(p -> n[i]);
  }
  free(p -> n);
}

char *desempilha(Pilha_t *p) {
  p -> index--;
  char *aux = malloc(sizeof(char) * strlen(p -> n[p -> index]));
  strcpy(aux, p -> n[p -> index]);
  
  return aux;
}

void empilha(Pilha_t *p, char *n) {
  strcpy(p -> n[p -> index], n);
  p -> index++;
}

unsigned long long hash(char *v) {
  unsigned long long h, a = 13, b = 17;

  for(h = 0; *v != '\0'; v++) {
    a = a + b % (strsize - 1);
    h = (a * h + *v) % strsize;
  }

  return h;
}

void teste(char *v) {
  printf("%s %lld\n", v, hash(v));
}

void insere_HT(Item *lista, Item tmp) { // OK
  unsigned long long key = hash(tmp.no);
  strcpy(lista[key].no, tmp.no);
  strcpy(lista[key].prox, tmp.prox);
  strcpy(lista[key].ant, tmp.ant);
}

int main() {
  Pilha_t p;

  inicializaPilha(&p);

  char nome1[20] = "herick", nome2[20] = "samara", nome3[20] = "biru biru";
  Item lista[1000], tmp1, tmp2, tmp3;

  char *aux = nome1;

  printf("%d\n", !!strcmp(nome1, nome2));

  // printf("%s\n", desempilha(&p));
  // printf("%s\n", desempilha(&p));
  // printf("%s\n", desempilha(&p));


  // free(teste);
  mataPilha(&p);

  return 0;
}