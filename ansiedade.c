#include <stdio.h>

int main() {
	int triagens = 0, perguntas = 0, sim = 0;
  char resposta[4];

  while(scanf("%s", resposta) != EOF) {
    perguntas++;
    if(perguntas >= 10) {
      sim = 0;
      perguntas = 0;
    }
    if(resposta[0] == 's') {
      sim++;
    }
    if(sim >= 2) {
      triagens++;
    }
  }
  // char sims[4] = "sim";
  // printf("%d\n", sims[0] == 's');
  printf("%d\n", triagens);

	return 0;
}
