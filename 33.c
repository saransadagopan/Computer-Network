#include <stdio.h>
#include <string.h>

#define MAX 100

// Function to perform bit stuffing
void bitStuffing(int input[], int n) {
    int output[MAX], count = 0, j = 0;

    for (int i = 0; i < n; i++) {
        output[j++] = input[i];

        if (input[i] == 1) {
            count++;
        } else {
            count = 0;
        }

        // If 5 consecutive 1s are found, insert a 0
        if (count == 5) {
            output[j++] = 0;
            count = 0;
        }
    }

    printf("Stuffed Data: ");
    for (int i = 0; i < j; i++) {
        printf("%d", output[i]);
    }
    printf("\n");
}

// Function to perform bit destuffing
void bitDestuffing(int stuffed[], int n) {
    int destuffed[MAX], count = 0, j = 0;

    for (int i = 0; i < n; i++) {
        destuffed[j++] = stuffed[i];

        if (stuffed[i] == 1) {
            count++;
        } else {
            count = 0;
        }

        // If 5 consecutive 1s are found, remove the stuffed 0
        if (count == 5 && stuffed[i + 1] == 0) {
            i++; // Skip the stuffed 0
            count = 0;
        }
    }

    printf("Destuffed Data: ");
    for (int i = 0; i < j; i++) {
        printf("%d", destuffed[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int n, data[MAX];

    printf("Enter the number of bits in input data: ");
    scanf("%d", &n);

    printf("Enter the data bits (0s and 1s only): ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    printf("\nOriginal Data: ");
    for (int i = 0; i < n; i++) {
        printf("%d", data[i]);
    }
    printf("\n");

    // Perform bit stuffing
    bitStuffing(data, n);

    // Perform bit destuffing for ve
