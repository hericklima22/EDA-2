#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  unsigned long no, ant, prox;
  int visitado;
} Item;

typedef struct {
  unsigned long *n;
  int index, tam;
} Pilha_t;

#define arrsize 100000
#define hash(A) ((int) floor(A % arrsize))

void inicializaPilha(Pilha_t *p, int tam) { // OK
  p -> n = malloc(sizeof(unsigned long) * tam);
  p -> index = 0;
  p -> tam = tam;
  
}

void mataPilha(Pilha_t *p) { // OK
  free(p->n);
}

void imprimePilha(Pilha_t *p) {
    for(int i = 0; i < p->index; i++) {
      // printf("%c", p->n[i]);
      if(i < p->index - 1) printf(" -> ");
    }
    printf("\n");
}

void empilha(Pilha_t *p, unsigned long n) {
  p -> n[p -> index] = n;
  p -> index++;
}

unsigned long desempilha(Pilha_t *p) {
  p -> index--;
  unsigned long aux = p -> n[p -> index];
  p -> n[p -> index] = 0;

  return aux;
}

Item busca(Item *lista, unsigned long aux) {
  unsigned long key = hash(aux);
  return lista[key];
}

void insere_HT(Item *lista, Item tmp) { // OK
  unsigned long key = hash(tmp.no);
  lista[key].no = tmp.no;
  lista[key].prox = tmp.prox;
  lista[key].ant = tmp.ant;
}

int estaVazia(Pilha_t *p) {
  if(p->index == 0) return 1;
  return 0;
}

int sanidade(Item *lista, unsigned long PTR1, unsigned long PTR2) {
  Pilha_t p;
  inicializaPilha(&p, arrsize);

  unsigned long aux = PTR1;

  while(aux != PTR2 && aux != (unsigned long)NULL) {
    empilha(&p, aux);
    
    
    Item n = busca(lista, aux);

    if(n.visitado != 0) {return 0;}
    lista[hash(aux)].visitado = 1;
    aux = n.prox;
  }
  printf("%c\n", (char) aux);
  if(aux == PTR2) {empilha(&p, aux);}
  else {return 0;}

  // imprimePilha(&p);
  int encontrou = 0;
  while(aux != 0 && aux != PTR1) {
    unsigned long t = desempilha(&p); 
    // printf("%lx\n", t);
    if(aux != t) return 0;
    if(aux == PTR2) encontrou = 1;

    Item n = busca(lista, aux);
    aux = n.ant;
  }

  unsigned long t = desempilha(&p);
  if(aux != t) return 0;
  if(!encontrou) return 0;
  if(estaVazia(&p)) {return 1;}
  mataPilha(&p);
  return 0;
}

unsigned long hashU(char *v) {
  unsigned long h, a = 53, b = 37;

  for(h = 0; *v != '\0'; v++) {
    a = a + b % (1000001 - 1);
    h = (a * h + *v) % 1000001;
  }

  return h;
}


int main() {
  char no[1000001], ant[1000001], prox[1000001];
  Item ptr1, ptr2, tmp, lista[arrsize];

  // scanf("%lx %lx %lx", &ptr1.no, &ptr1.ant, &ptr1.prox);
  scanf(" %s %s %s", no, ant, prox);
  ptr1.no = hashU(no);
  ptr1.ant = hashU(ant);
  ptr1.prox = hashU(prox);

  // scanf("%lx %lx %lx", &ptr2.no, &ptr2.ant, &ptr2.prox);

  scanf(" %s %s %s", no, ant, prox);
  ptr2.no = hashU(no);
  ptr2.ant = hashU(ant);
  ptr2.prox = hashU(prox);

  insere_HT(lista, ptr1);
  insere_HT(lista, ptr2);

  while(scanf(" %s %s %s", no, ant, prox) == 3) {
    tmp.no = hashU(no);
    tmp.ant = hashU(ant);
    tmp.prox = hashU(prox);
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