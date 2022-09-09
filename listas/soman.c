#include <stdio.h>

int main() {
	int qtd, num = 0, total = 0;

  scanf("%d", &qtd);

  for(int i = 0; i < qtd; i++) {
    scanf("%d", &num);
    total += num;
  }

  printf("%d\n", total);

	return 0;
}
