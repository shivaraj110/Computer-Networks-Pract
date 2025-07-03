#include <stdio.h>

// Function to compute (base^exp) % mod using modular exponentiation
int mod_exp(int base, int exp, int mod) {
  int result = 1;
  base = base % mod;

  while (exp > 0) {
    if (exp % 2 == 1)
      result = (result * base) % mod;

    exp = exp >> 1; // exp /= 2
    base = (base * base) % mod;
  }

  return result;
}

int main() {
  // RSA Parameters based on your example
  int p, q, D, E;
  printf("enter p and q values:\n");
  scanf("%d %d", &p, &q);

  int N = p * q;             // N = 33
  int z = (p - 1) * (q - 1); // z = 20
  printf("enter the value of E:\n");
  scanf("%d", &E);
  for (D = 1; D < z; D++) {
    if ((E * D) % z == 1)
      break;
  }

  printf("Check: (E * D) %% z = %d\n", (E * D) % z);

  int message = 7;
  printf("Original Message: %d\n", message);

  // Encryption
  int cipher = mod_exp(message, E, N);
  printf("Encrypted Message (cipher): %d\n", cipher);

  int c;
  printf("enter the encrypted messege to decrypt:\n");
  scanf("%d", &c);
  if (c == cipher) {
    printf("entered encrypted data is correct...the decrypted messege is as "
           "fallowed.\n");
    // Decryption
    int decrypted = mod_exp(cipher, D, N);
    printf("Decrypted Message: %d\n", decrypted);
  } else
    printf("entered encrypted data is not correct...\n");

  return 0;
}
