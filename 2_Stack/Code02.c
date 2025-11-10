#include <stdio.h>
#include <string.h>
#define MAX 100

int stack[MAX], top = -1;

void push() {
    int val;
    if (top == MAX - 1)
        printf("Overflow!\n");
    else {
        printf("Enter value: ");
        scanf("%d", &val);
        stack[++top] = val;
        printf("%d pushed.\n", val);
    }
}

void pop() {
    if (top == -1)
        printf("Underflow!\n");
    else
        printf("%d popped.\n", stack[top--]);
}

void display() {
    if (top == -1)
        printf("Stack empty!\n");
    else {
        printf("Stack: ");
        for (int i = top; i >= 0; i--)
            printf("%d ", stack[i]);
        printf("\n");
    }
}

void palindrome() {
    char str[100], rev[100];
    int i, j = 0;
    top = -1;

    printf("Enter string: ");
    scanf("%s", str);

    for (i = 0; str[i] != '\0'; i++)
        stack[++top] = str[i];

    while (top != -1)
        rev[j++] = stack[top--];
    rev[j] = '\0';

    if (strcmp(str, rev) == 0)
        printf("Palindrome!\n");
    else
        printf("Not Palindrome!\n");
}

int main() {
    int ch;
    while (1) {
        printf("Enter choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: palindrome(); break;
            case 5: return 0;
            default: printf("Invalid!\n");
        }
    }
}