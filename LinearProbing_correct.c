#include<stdio.h>
#include<stdlib.h>

int hash(int arr[], int temp) {
    int i = 0;
    while (arr[(temp + i * i) % 10] != -1) {
        i++;
        if (i == 10) {
            // Break if the hash table is full
            return -1;
        }
    }
    return (temp + i * i) % 10;
}

int main() {
    int hashlist[10], i = 0, choice = 1, values = 0;
    int temp;
    
    for (i = 0; i < 10; i++) {
        hashlist[i] = -1;
    }

    while (choice == 1) {
        printf("\nEnter values: \t");
        scanf("%d", &temp);

        int index = hash(hashlist, temp);
        printf("Storing at index: %d",index);

        if (index == -1) {
            printf("\nHash table is full");
            break;
        }

        hashlist[index] = temp;
        values++;

        if (values > 9) {
            printf("\nHash table is full");
            break;
        }

        printf("\nContinue? (1/0): ");
        scanf("%d", &choice);
    }
int index;
    printf("\nHash table contents: ");
    for (i = 0; i < 10; i++) {
        printf("%d ", hashlist[i]);
    }

    return 0;
}
