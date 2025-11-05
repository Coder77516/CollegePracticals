#include <stdio.h>
#define MAX 100

char queue[MAX];
int front = -1, rear = -1;

// Function to insert element
void insert() {
    char ch;
    if (rear == MAX - 1)
        printf("Queue Overflow!\n");
    else {
        printf("Enter character to insert: ");
        scanf(" %c", &ch); // space before %c to ignore newline
        if (front == -1) front = 0;
        queue[++rear] = ch;
        printf("'%c' inserted.\n", ch);
    }
}

// Function to delete element
void delete() {
    if (front == -1 || front > rear)
        printf("Queue Underflow!\n");
    else {
        printf("'%c' deleted.\n", queue[front]);
        front++;
        if (front > rear) front = rear = -1; // reset when empty
    }
}

// Function to display queue
void display() {
    if (front == -1)
        printf("Queue is empty!\n");
    else {
        printf("Queue: ");
        for (int i = front; i <= rear; i++)
            printf("%c ", queue[i]);
        printf("\n");
    }
}

// Main menu
int main() {
    int choice;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: insert(); break;
            case 2: delete(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice!\n");
        }
    }
}