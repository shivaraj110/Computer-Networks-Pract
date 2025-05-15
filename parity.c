#include <stdio.h>

int main() {
  unsigned int n;
  int ch;
  int count = 0;
  int binarynum[32] = {0};
  int i = 0;

  printf("Enter a number: ");
  scanf("%u", &n);

  // Convert to binary and store in array
  unsigned int temp = n;
  while (temp > 0) {
    binarynum[i] = temp % 2;
    temp = temp / 2;
    i++;
  }

  printf("Binary representation is: ");
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binarynum[j]);
  }
  printf("\n");

  printf("Select parity type:\n1. Even\n2. Odd\nChoice: ");
  scanf("%d", &ch);

  // Count number of 1s
  for (int j = 0; j < i; j++) {
    if (binarynum[j] == 1)
      count++;
  }

  int parity_bit;
  if (ch == 1) { // Even parity
    parity_bit = (count % 2 == 0) ? 0 : 1;
  } else if (ch == 2) { // Odd parity
    parity_bit = (count % 2 == 0) ? 1 : 0;
  } else {
    printf("Invalid choice.\n");
    return 1;
  }

  printf("Number of 1s: %d\n", count);
  printf("Codeword with parity bit: ");
  for (int j = i - 1; j >= 0; j--) {
    printf("%d", binarynum[j]);
  }
  printf("%d\n", parity_bit);

  return 0;
}
