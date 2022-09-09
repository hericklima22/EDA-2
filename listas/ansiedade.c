#include <stdio.h>

int main() {
	int triagens = 0, index = 0, sim = 0, pergunta = 0;
  char resposta[4], ciclo[10];

<<<<<<< HEAD
  udo bem você 
  // char sims[4] = "sim";
  // printf("%d\n", sims[0] == 's');
=======
  while(scanf("%s", resposta) != EOF) {
    ciclo[index] = resposta[0];
    index++;
  }

  for(int i = 0; i < index; i++) {
    if(pergunta < 9) {
      if(ciclo[index] == 's') {
        sim++;
      }
      pergunta++;
    } else {
      if(sim > 1) {
        triagens++;
      }
      pergunta = 0;
      sim = 0;
    }
  }

>>>>>>> f1960326f52e559df4a06f8e94ceee36ff739616
  printf("%d\n", triagens);

	return 0;
}
