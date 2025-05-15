#include "stdio.h"
void encode(int encodedWord[7], int dataword[4]) {
  encodedWord[2] = dataword[0];
  encodedWord[4] = dataword[1];
  encodedWord[5] = dataword[2];
  encodedWord[6] = dataword[3];

  // assigning parity bits
  encodedWord[0] = encodedWord[2] ^ encodedWord[4] ^
                   encodedWord[6]; // 1st parity bit at position 1
  encodedWord[1] = encodedWord[2] ^ encodedWord[5] ^
                   encodedWord[6]; // 2nd parity bit at position 2
  encodedWord[3] = encodedWord[4] ^ encodedWord[5] ^
                   encodedWord[6]; // 3rd parity bit at position 4
}

void decode(int encodedWord[7], int decodedWord[4]) {
  // decoding the parity bits
  int parityBits[3];
  parityBits[0] =
      encodedWord[0] ^ encodedWord[2] ^ encodedWord[4] ^ encodedWord[6];
  parityBits[1] =
      encodedWord[1] ^ encodedWord[2] ^ encodedWord[5] ^ encodedWord[6];
  parityBits[2] =
      encodedWord[3] ^ encodedWord[4] ^ encodedWord[5] ^ encodedWord[6];
  // finding the error position (if any)
  int errPosition = parityBits[0] * 1 + parityBits[1] * 2 + parityBits[2] * 4;
  if (errPosition != 0) {
    printf("error found at position %d correcting...\n", errPosition);
    encodedWord[errPosition - 1] ^= 1;
    printf("error corrected! here is the correced dataword xD : \t");
    for (int i = 0; i < 7; i++) {
      printf("%d\t", encodedWord[i]);
    }
  } else {
    printf("dataword has been decoded without any error\n");
    for (int i = 0; i < 7; i++) {
      printf("%d\t", encodedWord[i]);
    }
  }
  decodedWord[0] = encodedWord[2];
  decodedWord[1] = encodedWord[4];
  decodedWord[2] = encodedWord[5];
  decodedWord[3] = encodedWord[6];
}

// main function

int main() {
  int encodedWord[7], dataword[4], decodedWord[4];
  printf("Enter 4 bit dataword with 1 whitespace given : \n");
  for (int i = 0; i < 4; i++) {
    scanf("%d", &dataword[i]);
  }
  encode(encodedWord, dataword);
  printf("\nEncoded dataword : \n");
  for (int i = 0; i < 7; i++) {
    printf("%d\t", encodedWord[i]);
  }

  printf("Enter the received encoded dataword : \t");
  for (int i = 0; i < 7; i++) {
    scanf("%d", &encodedWord[i]);
  }
  decode(encodedWord, decodedWord);
  return 0;
}
