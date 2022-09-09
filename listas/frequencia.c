#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef int Item;
#define less(A,B) ((A) < (B))
#define lesseq(A,B) ((A) <= (B))
#define exch(A,B) { Item t; t=A;A=B;B=t; }
#define cmpexch(A,B) { if (less(B,A)) exch(A,B); }

void insertion(Item *arr, int left, int right) {
  for(int i = right - 1; i > left; i--) {
    cmpexch(arr[i - 1], arr[i]);
  }

  for(int i = left + 2; i < right; i++) {
    int j = i;
    Item tmp = arr[j];
    while(less(tmp, arr[j - 1])) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = tmp;
  }
}

int search(Item *arr, int x, int left, int right) {
  while(left <= right) {
    int k = left + (right - left) / 2;

    if(arr[k] == x) {
      return k;
    }

    if(arr[k] < x) {
      left = k + 1;
    } else {
      right = k - 1;
    }
  }
  return -1;
}


int main() {
	Item arr[100000], num[100000];
	int n, presente = 0, temp;

	scanf("%d", &n);

	for(int i = 0; i < 100000; i++) {
		arr[i] = 0;
	}

	for(int i = 0; i < n; i++) {
		scanf("%d", &num[i]);
		arr[num[i]]++;
	}

	for(int i = 0; i < n; i++) {
        printf("%d\t", num[i]);
	}

	for(int i = 0; i < n; i++) {
		if(arr[num[i]] == 1) {
			presente++;
		}
	}

	printf("%d\n", presente);
  return 0;
}
