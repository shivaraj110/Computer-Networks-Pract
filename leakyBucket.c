#include <stdio.h>
#include <stdlib.h>
#define BUCKET_SIZE 50 // Maximum capacity of the bucket
#define OUTPUT_RATE 10 // Number of packets leaked per time unit
// Structure of leaky bucket
typedef struct {
  int capacity;
  int current_level;
  int output_rate;
} LeakyBucket;

// Initialize the bucket
void init_bucket(LeakyBucket *bucket, int capacity, int rate) {
  bucket->capacity = capacity;
  bucket->current_level = 0;
  bucket->output_rate = rate;
}

// add packets to the bucket
int add_packets(LeakyBucket *bucket, int packets) {
  if (bucket->current_level + packets > bucket->capacity) {
    printf("Bucket overflow! Dropping %d packets\t current level : %d/%d\n",
           packets, bucket->current_level, bucket->capacity);
    bucket->current_level = bucket->capacity;
    return -1; // Return -1 to indicate packet loss
  }

  bucket->current_level += packets;
  printf("Added %d packets. Current level: %d/%d\n", packets,
         bucket->current_level, bucket->capacity);
  return 0; // Success
}

// leaking the packets from bucket
void leak(LeakyBucket *bucket) {
  int to_leak = (bucket->current_level < bucket->output_rate)
                    ? bucket->current_level
                    : bucket->output_rate;

  bucket->current_level -= to_leak;

  printf("Leaked %d packets. Current level: %d/%d\n", to_leak,
         bucket->current_level, bucket->capacity);
}

int main() {
  LeakyBucket bucket;
  int choice, packets;

  // Initialize the bucket
  init_bucket(&bucket, BUCKET_SIZE, OUTPUT_RATE);
  printf("Leaky Bucket Initialized with capacity %d and output rate %d\n",
         BUCKET_SIZE, OUTPUT_RATE);

  while (1) {
    printf("\n1. Add packets\n");
    printf("2. Leak packets (simulate time unit)\n");
    printf("3. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter number of packets to add: ");
      scanf("%d", &packets);
      add_packets(&bucket, packets);
      break;

    case 2:
      leak(&bucket);
      break;

    case 3:
      printf("Exiting program\n");
      exit(0);

    default:
      printf("Invalid choice. Try again.\n");
      break;
    }
  }

  return 0;
}
