#include <stdio.h>

int main() {
	// char a = '0';
	// int cvt = (int)a - 48;
	// printf("%d\n", cvt < 10 && cvt >= 0);

	int count = 0, total = 0, index = 0, cvt;
	char vet[100];

	scanf("%d ", &count);

	for(int i = 0; i < count; i++) {
		total = index = 0;
		scanf(" %s", vet);
		while(vet[index] != '\0') {
			index++;
			cvt = (int)vet[index] - 48;
			if(cvt >= 0 && cvt < 10) {
				total += cvt;
			}
		}
		printf("%d\n", total);
	}

	return 0;
}
