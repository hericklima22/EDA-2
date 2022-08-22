#include <stdlib.h>
#include <stdio.h>

typedef struct {
  int v, w;
} Edge;

typedef struct {
  int V, E, **adj;
} Graph;

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

void G_Insert(Graph G, Edge *E) {
  int v = E -> v, w = E ->w;

  if(G.adj[v][w] == 0) G.E++;
  G.adj[v][w] = 1;
  G.adj[w][v] = 1;
}

static int pre[100000];

void dfs_r(Graph G, Edge *E) {
  int v = E -> v, w = E -> w;
  pre[w] = v;

  for(int i = 0; i < G.V; i++) {
    if(G.adj[w][i] == 1 && pre[i] == -1) {
      dfs_r(G, EDGE(w, i));
    }
  }
}

int search(Graph G) {
  for(int i = 0; i < G.V; i++) {
    pre[i] = -1;
  }

  int cont = 0;

  for(int i = 0; i < G.V; i++) {
    if(pre[i] == -1) {
      cont++;
      dfs_r(G, EDGE(i, i));
    }
  }

  return cont;
}

int main() {
  int n;

  scanf("%d", &n);

  Graph *g = G_Init(n);

  int v, w;

  while(scanf("%d %d", &v, &w) == 2) {
    G_Insert(*g, EDGE(v, w));
  }
  // for(int i = 0; i < g -> V; i++) {
  //   for(int j = 0; j < g -> V; j++)
  //     printf("%d ", g->adj[i][j]);
  //   printf("\n");
  // }

  printf("%d\n", search(*g));

  return 0;
}