//Jason Lahoda, 3/7/2023, CIS2107
//Lab 5 Arrays of Pointers to Functions
//The purpose of this program is to modify existing code related to examslecting 
//grades for individual students in a 2D matrix and determining the minimum, maximum,
//and each average. 
#include <stdio.h>
#include <stdlib.h>

void printArray(int students, int exams, int grades[students][exams]);
void minimum(int students, int exams, int grades[students][exams]);
void maximum(int students, int exams, int grades[students][exams]);
void average(int students, int exams, int grades[students][exams]);

int main() {
    int choice, students, exams, temp;
    printf("Enter the number of students: ");
    scanf("%d", &students);
    printf("\nEnter the number of exams: ");
    scanf("%d", &exams);
    int grades[students][exams];
    printf("\nFor reference: [student][exam]\n");
    for (int i = 0; i < students; i++){
        for (int j = 0; j < exams; j++){
            printf("\tenter [%d][%d]: ", i, j);
            scanf("%d", &temp);
            grades[i][j] = temp;
        }
    }
    puts("");
    void (*processGrades[])(int, int, int[students][exams]) = {printArray, minimum, maximum, average};
    while (choice != 4){
        printf("\nEnter a choice:\n");
        printf("\t0 Print the array of grades\n");
        printf("\t1 Find the minimum grade\n");
        printf("\t2 Find the maximum grade\n");
        printf("\t3 Print the average on all tests for each student\n");
        printf("\t4 End Program\n");
        scanf("%d", &choice);
        switch(choice) {
            case 0:
                processGrades[0](students, exams, grades);
                break;
            case 1:
                processGrades[1](students, exams, grades);
                break;
            case 2:
                processGrades[2](students, exams, grades);
                break;
            case 3:
                processGrades[3](students, exams, grades);
                break;
            case 4:
                exit(0);
            default:
                printf("\nInvalid choice. Please enter a choice from 0 to 4\n");
        }
        
    }
}

void printArray(int students, int exams, int grades[students][exams]) {
    printf("Here is your 2Dim array:\n");
    for (int i = 0; i < students; i++) {
        printf("[");
        for (int j = 0; j < exams; j++) {
            printf("%d", grades[i][j]);
            if (j + 1 != exams) {
                printf(", ");
            }
        }
        puts("]");
    }
}

void minimum(int students, int exams, int grades[students][exams]) {
    int min = grades[0][0];
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < exams; j++) {
            if (grades[i][j] < min) {
                min = grades[i][j];
            }
        }
    }
    printf("\nMinimum grade is: %d\n", min);
}

void maximum(int students, int exams, int grades[students][exams]) {
    int max = grades[0][0];
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < exams; j++) {
            if (grades[i][j] > max) {
                max = grades[i][j];
            }
        }
    }
    printf("\nMaximum grade: %d\n", max);
}

void average(int students, int exams, int grades[students][exams]) {
    int sum = 0;
    int totalNum = 0;
    for (int i = 0; i < students; i++) {
        for (int j = 0; j < exams; j++) {
            sum += grades[i][j];
            totalNum++;
        }
    }
    float avg = (float)sum / totalNum;
    printf("\nAverage grade: %.2f\n", avg);
}