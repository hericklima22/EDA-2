#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef int Item;
#define less(A,B) (A < B)
#define lesseq(A,B) (A <= B)
#define exch(A,B) {Item tmp=A;A=B;B=tmp;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

typedef struct {
  int v, w;
} Edge;

typedef struct {
  int V, E, **adj;
} Graph;

int hashU(char *v, int lim) {
  int h, a = 53, b = 37;

  for(h = 0; *v != '\0'; v++) {
    a = a + b % (lim - 1);
    h = (a * h + *v) % lim;
  }

  return h;
}

int separa(Item *arr, int l, int r) {
  int i = l - 1, j = r;
  Item c = arr[r];  //pivô

  while(1) {
    while(less(arr[++i], c));
    while(less(c, arr[--j])) {
      if(i == j) break;
    }

    if(i >= j) 
      break;
    
    exch(arr[i], arr[j]);
  }

  exch(arr[i], arr[r]);
  return i;
}

void quickSelect(Item *arr, int l, int r, int p) {
  int j = separa(arr, l, r);

  if(j == p) return;

  else if(j < p) 
    quickSelect(arr, j + 1, r, p);
  else
    quickSelect(arr, l, j - 1, p);
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

Edge *EDGE(int v, int w) {
  Edge *E = malloc(sizeof(E));
  E -> v = v;
  E -> w = w;

  return E;
}

int **M_Init(int l, int c, int init) {
  int **m = malloc(sizeof(int *) * l);

  for(int i = 0; i < l; i++) {
    m[i] = malloc(sizeof(int) * c);
  }

  for(int i = 0; i < l; i++)
    for(int j = 0; j < c; j++)
      m[i][j] = init;

  return m;
}

Graph *G_Init(int V) {
  Graph *G = malloc(sizeof(Graph));
  G -> V = V;
  G -> E = 0;
  G -> adj = M_Init(V, V, 0);
  return G;
}

void G_Insert(Graph *G, Edge *E) {
  int v = E -> v, w = E -> w;

  if(G -> adj[v][w] == 0) G -> E++;
  G -> adj[v][w] = 1;
  G -> adj[w][v] = 1;
}

static int pre[5000];
static int origem[5000];
static int conta_vertice = 0;

void dfs_r(Graph G, Edge *E) {
  int v = E -> v, w = E -> w;
  pre[w] = v;

  for(int i = 0; i < G.V; i++) {
    if(G.adj[w][i] == 1 && pre[i] == -1) {
      dfs_r(G, EDGE(w, i));
      conta_vertice++;
    }
  }
}

int search(Graph G) {
  for(int i = 0; i < G.V; i++) {
    pre[i] = -1;
    origem[i] = 0;
  }

  int cont = 0;

  for(int i = 0; i < G.V; i++) {
    conta_vertice = 1;
    if(pre[i] == -1) {
      cont++;
      dfs_r(G, EDGE(i, i));
      // origem[cont] = conta_vertice;
      printf("vertices = %d\n", conta_vertice);
    }
  }

  quickSelect(origem, 0, G.V - 1, G.V - 1);
  // printf("%d\n")
  return origem[G.V - 1];
}

typedef struct {
  char criatura[31];
  int chave;
} Animal;


int main() {
  int c = 1, r = 1, v, w;
  char v1[31], w1[31], nomes[5001][31];
  Animal animais[5001];


  while(c != 0 && r != 0) {
    scanf("%d %d", &c, &r);
    if(c == 0 && r == 0) break;


    Graph *g = G_Init(c);

    for(int i = 0; i < c; i++) {
      scanf(" %s", nomes[i]);
      int index = hashU(nomes[i], 5001);
      strcpy(animais[index].criatura, nomes[i]);
      animais[index].chave = i;
      G_Insert(g, EDGE(i, i));
    }

    for(int i = 0; i < r; i++) {
      scanf(" %s %s", v1, w1);
      int hash1 = hashU(v1, 5001);
      int hash2 = hashU(w1, 5001);
      G_Insert(g, EDGE(animais[hash1].chave, animais[hash2].chave));
    }

    // for(int i = 0; i < c; i++) {
    //   int index = hashU(nomes[i], 5001);
    //   printf("%s %d\n", animais[index].criatura, animais[index].chave);
    // }


    // for(int i = 0; i < c; i++){
    //   for(int j = 0; j < c; j++)
    //     printf("%d ", g -> adj[i][j]);
    //   printf("\n");
    // }
    // printf("\n");

    // printf("%d\n", g -> E);

    printf("\n", search(*g));
  }

  return 0;
}