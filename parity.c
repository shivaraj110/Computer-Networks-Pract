#include <stdio.h>
int main() {
  unsigned int num;
  int ch, count = 0, binaryRep[32] = {0}, i = 0, parityBit;
  printf("Enter the codeword in decimal format: ");
  scanf("%u", &num);

  // binary representation of the codeword
  unsigned int temp = num;
  while (temp > 0) {
    binaryRep[i] = temp % 2;
    temp /= 2;
    i++;
  }

  printf("the binary representation\n");
  for (int j = i - 1; j >= 0; j--) {
    printf("%d\t", binaryRep[j]);
  }
  printf("\n");

  // ask for parity choice
  printf("1 : even parity | 2 : odd parity\n");
  printf("Enter your choice here : \t");
  scanf("%d", &ch);
  printf("\n");

  // count the number of 1's in the binary representation
  for (int j = 0; j < i; j++) {
    if (binaryRep[j] == 1)
      count++;
  }

  switch (ch) {
  case 1:
    // in case of even parity
    parityBit = count % 2 == 0 ? 0 : 1;
    break;
  case 2:
    // in case of odd parity
    parityBit = count % 2 == 0 ? 1 : 0;
    break;
  default:
    printf("invalid choice :( exiting the program \n");
    return 1;
  }
  printf("number of 1's :%d \n", count);

  printf("dataword along with the parityBit :\n");
  for (int j = i - 1; j >= 0; j--)
    printf("%d\t", binaryRep[j]);
  printf("%d\n", parityBit);
  return 0;
}
