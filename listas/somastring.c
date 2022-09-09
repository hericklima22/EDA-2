#include <stdio.h>

int main() {
	int count = 0, total = 0, index = 0, cvt, res[100];
	char vet[100];

	scanf("%d ", &count);

	for(int i = 0; i < count; i++) {
		total = index = 0;
		scanf(" %s", vet);
		while(vet[index] != '\0') {
			cvt = (int)vet[index] - 48;
			if(cvt >= 0 && cvt < 10) {
				total += cvt;
			}
			index++;
		}
		// printf("%d\n", total);
    res[i] = total;
	}

  for(int i = 0; i < count; i++) {
    printf("%d\n", res[i]);
  }

	return 0;
}
