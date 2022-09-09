#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char str[16];
  int key;
} ht_t;

#define key(A) (A.key)
#define less(A,B) (key(A) < key(B))
#define exch(A,B) {ht_t t = A; A = B; B = t;}
#define cmpexch(A,B) {if(less((B),(A))) exch(A,B);}

int separa(ht_t *v, int l, int r) {
    int i = l - 1, j = r;
    ht_t c = v[r];
    while(1) {
        while(less(v[++i], c));
        while(less(c, v[--j])) if(i == j) break;
        if(i >= j) break;

        exch(v[i], v[j]);
    }
    exch(v[i], v[r]);
    return i;
}

void quickSort(ht_t *v, int l, int r) {
    if(r - l <= 32) return;

    exch(v[(l + r) / 2],v[r - 1]);
    cmpexch(v[l], v[r - 1]);
    cmpexch(v[l], v[r]);
    cmpexch(v[r - 1], v[r]);

    int j = separa(v, l, r);

    quickSort(v, l, j - 1);
    quickSort(v, j + 1, r);
}

void insertionSort(ht_t *arr, int left, int right) {
  for(int i = right; i > left; i--) {
    cmpexch(arr[i - 1], arr[i]);
  }

  for(int i = left + 2; i <= right; i++) {
    int j = i;
    ht_t tmp = arr[j];
    while(less(tmp, arr[j - 1])) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = tmp;
  }
}

void ordenacao(ht_t *v, int l, int r) {
    quickSort(v, l, r);
    insertionSort(v, l, r);
}

int hash(char *v, int m) {
  int i = 0;
  long long int a, r = 0;

  while(v[i] != '\0') {
    a = (int) v[i] * (i + 1);
    r = r + a;
    i++;
  }
  return (19 * r) % m;
}

void initHash(ht_t *ht, int m) {
  for(int i = 0; i < m; i++) {
    ht[i].key = -1;
  }
}

void insert(ht_t *ht, char *v) {
  int index = hash(v, 101);
  int try = 0;

  if(ht[index].key == -1) {
    ht[index].key = index;
    strcpy(ht[index].str, v);
  }
}

void delete(ht_t *ht, char *v) {
  int index = hash(v, 101);
  if(ht[index].key != -1) {
    ht[index].key = -1;
  }
}

int main() {
  int casos, operacoes;
  char tag[4], str[16];
  ht_t *ht;

  scanf("%d", &casos);

  for(int i = 0; i < casos; i++) {
    scanf("%d", &operacoes);
    ht = malloc(sizeof(ht_t) * 101);
    initHash(ht, 101);
    for(int j = 0; j < operacoes; j++) {
      scanf(" %[^:]:", tag);
      if(tag[0] == 'A') {
        scanf(" %s", str);
        insert(ht, str);
      }
      if(tag[0] == 'D') {
        scanf(" %s", str);
        delete(ht, str);
      }
    }
    ordenacao(ht, 0, 100);
    int contador = 0;
    for(int a = 0; a < 101; a++) {
      if(ht[a].key != -1) contador++;
    }

    printf("%d\n", contador);
    for(int a = 0; a < 101; a++) {
      if(ht[a].key != -1) printf("%d:%s\n", ht[a].key, ht[a].str);
    }
    free(ht);
  }
  

  return 0;
}