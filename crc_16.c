#include<stdio.h>
#define DIVIDEND_SIZE 24
#define DIVISOR_SIZE 17
#define REMAINDER_SIZE 16
// Function to perform binary division and return the 16-bit remainder

void binary_division(int dividend[], int divisor[], int remainder[]) {
    int temp[DIVISOR_SIZE] = {0};
    
    // Copy first DIVISOR_SIZE bits from dividend to temp
    for (int i = 0; i < DIVISOR_SIZE; i++) {
        temp[i] = dividend[i];
    }
    
    // Perform binary long division
    for (int i = DIVISOR_SIZE; i < DIVIDEND_SIZE+1; i++) {
        if (temp[0] == 1) {
            // Perform XOR with divisor
            for (int j = 0; j < DIVISOR_SIZE; j++) {
                temp[j] = temp[j] ^ divisor[j];
            }
        }
        
        // Shift left and bring down next bit
        if (i < DIVIDEND_SIZE) {
            for (int j = 0; j < DIVISOR_SIZE - 1; j++) {
                temp[j] = temp[j + 1];
            }
            temp[DIVISOR_SIZE - 1] = dividend[i];
        }
    }
    
    // Copy the remainder
    for (int i = 0; i < REMAINDER_SIZE; i++) {
        remainder[i] = temp[i+1];
    }
}


int main(){
int remainder[16];
int dataword[24];
int divisor[17] = {1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1};
printf("Enter 8 bit data : \n");
for(int i=0;i<8;i++){
	scanf("%d",&dataword[i]);
	}

printf("dataword entered by user : \n");
for(int i=0;i<8;i++){
	printf("%d\t",dataword[i]);
	}
// filling remaining bits with 0
for(int i=8;i<24;i++){
dataword[i]=0;
}

    printf("\nDataword after filling 0 till 24 bits\n");

for(int i=0;i<23;i++){
        printf("%d\t",dataword[i]);
        }
// performing division
binary_division(dataword,divisor,remainder);

printf("\nThe remainder on sender side is :\n");
for(int i=0;i<16;i++){
printf("%d\t",remainder[i]);
}

for(int i=0;i<16;i++){
        dataword[i+8] = remainder[i];
    }

printf("\nFinal dataword at receiver side :\n");

for(int i=0;i<24;i++){
	printf("%d\t",dataword[i]);
	}
printf("\n");

binary_division(dataword,divisor,remainder);

printf("\nThe remainder on reciever side is :\n");
int error = 0;
for(int i=0;i<16;i++){
    if(remainder[i] == 1){
            error = 1;
            printf("error at %d th bit\n",i);
            break;
        }
    printf("%d\t",remainder[i]);
    }

    if(!error){
        printf("Data is valid and free of errors !");
    }
    else
        printf("retry once again!");


return 0;

}
