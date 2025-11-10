#include <stdio.h>

struct Student {
    char name[50];
    int roll;
    float m1, m2, m3, avg;
};

int main() {
    struct Student s[100], t;
    int n, i, j;

    printf("Enter number of students: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter name, roll no and 3 marks of student %d:\n", i + 1);
        scanf("%s %d %f %f %f", s[i].name, &s[i].roll, &s[i].m1, &s[i].m2, &s[i].m3);
        s[i].avg = (s[i].m1 + s[i].m2 + s[i].m3) / 3;
    }

    // Bubble Sort (Descending by avg)
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (s[j].avg < s[j + 1].avg) {
                t = s[j];
                s[j] = s[j + 1];
                s[j + 1] = t;
            }
        }
    }

    printf("\nName\tRoll\tAverage\n");
    for (i = 0; i < n; i++)
        printf("%s\t%d\t%.2f\n", s[i].name, s[i].roll, s[i].avg);

    return 0;
}
