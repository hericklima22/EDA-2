#include <stdio.h>

int main() {
	char frases[100][100], comando[9];
	int index = 0, indexFrase = 0;

	while(scanf(" %s", comando) != EOF) {
    if(comando[0] == 'i') { // inserir
      scanf(" %[^\n]", frases[indexFrase]);
      indexFrase++;
    }
    if(comando[0] == 'd') { // desfazer
      if(indexFrase == 0) {
        printf("NULL\n");
      }
      else {
        printf("%s\n", frases[--indexFrase]);
      }
    }
  }
	return 0;
}
