#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define arrsize 10000
#define strsize 1001

unsigned long long hash(char *v) {
  unsigned long long h, a = 13, b = 17;

  for(h = 0; *v != '\0'; v++) {
    a = a + b % (strsize - 1);
    h = (a * h + *v) % strsize;
  }

  return h;
}

typedef struct {
  char no[strsize], ant[strsize], prox[strsize];
  int visitado;
} Item;

typedef struct {
  char **n;
  int index, tam;
} Pilha_t;

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

void imprimePilha(Pilha_t *p) {
    for(int i = 0; i < p->index; i++) {
      printf("%s", p->n[i]);
      if(i < p->index - 1) printf(" -> ");
    }
    printf("\n");
}

Item buscaProximo(Item *lista, char *aux) {
  unsigned long key = hash(aux);
  return lista[key];
}

Item buscaAnterior(Item *lista, char *aux) {
  unsigned long long key = hash(aux);
  return lista[key];
}

void insere_HT(Item *lista, Item tmp) { // OK
  unsigned long long key = hash(tmp.no);
  strcpy(lista[key].no, tmp.no);
  strcpy(lista[key].prox, tmp.prox);
  strcpy(lista[key].ant, tmp.ant);
}

int estaVazia(Pilha_t *p) {
  if(p->index == 0) return 1;
  return 0;
}

int sanidade(Item *lista, char *PTR1, char *PTR2) {
  Pilha_t p;
  inicializaPilha(&p);

  char *aux = malloc(sizeof(char) * strlen(PTR1));
  strcpy(aux, PTR1);

  while(!!strcmp(aux, PTR2) && aux[0] != 0) {
    empilha(&p, aux);
    
    Item n = buscaProximo(lista, aux);
    // printf("%s\n", n.no);
    if(n.visitado != 0) return 0;
    n.visitado = 1;
    strcpy(aux, n.prox);
  }

  if(!strcmp(aux, PTR2)) empilha(&p, aux);
  else return 0;

  // printf("%s %d %s\n", aux, !!strcmp(aux, PTR1), PTR1);
  // imprimePilha(&p);

  while(aux[0] != 0 && !!strcmp(aux, PTR1)) {
    char t[strsize];
    strcpy(t, desempilha(&p));

    // if(!!strcmp(aux, t)) return 0;


    Item n = buscaAnterior(lista, aux);
    // printf("%s %s %d\n", aux, t, !strcmp(aux, t));
    strcpy(aux, n.ant);
  }

  char t[strsize];
  strcpy(t, desempilha(&p));

  // printf("%s %s %d\n", aux, t, !strcmp(aux, t));
  if(!!strcmp(aux, t)) return 0;

  if(estaVazia(&p)) return 1;
  mataPilha(&p);
  free(aux);
  return 0;
}


int main() {
  char no[strsize], ant[strsize], prox[strsize];
  Item ptr1, ptr2, tmp, lista[arrsize];

  scanf(" %s %s %s", ptr1.no, ptr1.ant, ptr1.prox);


  scanf(" %s %s %s", ptr2.no, ptr2.ant, ptr2.prox);

  insere_HT(lista, ptr1);
  insere_HT(lista, ptr2);

  while(scanf(" %s %s %s", tmp.no, tmp.ant, tmp.prox) == 3) {
    insere_HT(lista, tmp);
  }


  int s = sanidade(lista, ptr1.no, ptr2.no);
  if(s) {
    printf("sana\n");
  } else {
    printf("insana\n");
  }

  return 0;
}