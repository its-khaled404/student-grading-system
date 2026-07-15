
// Students GradeBook With Everything

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define STUDENTS 5
#define SUBJECTS 4
#define PASSMARK 33
#define FAILMARK 32

// Function to animate printing
void animatedPrint(const char *text, int delayMs) {
    for (int i = 0; text[i] != '\0'; i++) {
        printf("%c", text[i]);
        fflush(stdout);
        usleep(delayMs * 1000); // delay in milliseconds
    }
}

// Function to calculate grade
char *getGrade(int mark) {
    if (mark >= 80) return "A+";
    else if (mark >= 70) return "A";
    else if (mark >= 60) return "A-";
    else if (mark >= 50) return "B";
    else if (mark >= 40) return "C";
    else if (mark >= 33) return "D";
    else return "F";
}

// Function to show grade scale
void showGradeScale() {
    animatedPrint("\nGrade Scale:\n", 15);
    printf("+------+------------+\n");
    printf("| A+   | 80 - 100   |\n");
    printf("| A    | 70 - 79    |\n");
    printf("| A-   | 60 - 69    |\n");
    printf("| B    | 50 - 59    |\n");
    printf("| C    | 40 - 49    |\n");
    printf("| D    | 33 - 39    |\n");
    printf("| F    |  0 - 32    |\n");
    printf("+------+------------+\n");
}

// Function to clear screen (cross-platform)
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to show loading animation
void loadingAnimation() {
    animatedPrint("Loading student data", 40);
    fflush(stdout);
    for (int i = 0; i < 3; i++) {
        sleep(1);
        printf(".");
        fflush(stdout);
    }
    sleep(1);
    printf("\n");
    sleep(1);
    clearScreen();
}

int main() {
    FILE *fp;
    int ids[STUDENTS];
    char names[STUDENTS][50];
    int marks[STUDENTS][SUBJECTS];
    char *subjects[SUBJECTS] = {"Math", "Physics", "English", "CSE"};
    int i, j;

    fp = fopen("students.txt", "r");
    if (fp == NULL) {
        animatedPrint("Error: Could not open file 'students.txt'\n", 15);
        return 1;
    }

    // Read data from file (ID, Name, 4 Marks)
    for (i = 0; i < STUDENTS; i++) {
        fscanf(fp, "%d %s", &ids[i], names[i]);
        for (j = 0; j < SUBJECTS; j++) {
            fscanf(fp, "%d", &marks[i][j]);
        }
    }
    fclose(fp);

    // Show loading animation before main menu
    loadingAnimation();

    // Pre-calculate overall stats
    int totalSum = 0, totalCount = 0;
    int overallHighest = 0, overallLowest = 100;
    int highCount = 0, lowCount = 0;
    int highStudent[STUDENTS * SUBJECTS], highSubject[STUDENTS * SUBJECTS];
    int lowStudent[STUDENTS * SUBJECTS], lowSubject[STUDENTS * SUBJECTS];

    for (i = 0; i < STUDENTS; i++) {
        for (j = 0; j < SUBJECTS; j++) {
            totalSum += marks[i][j];
            totalCount++;

            // Highest
            if (marks[i][j] > overallHighest) {
                overallHighest = marks[i][j];
                highCount = 0;
                highStudent[highCount] = i;
                highSubject[highCount] = j;
                highCount++;
            } else if (marks[i][j] == overallHighest) {
                highStudent[highCount] = i;
                highSubject[highCount] = j;
                highCount++;
            }

            // Lowest
            if (marks[i][j] < overallLowest) {
                overallLowest = marks[i][j];
                lowCount = 0;
                lowStudent[lowCount] = i;
                lowSubject[lowCount] = j;
                lowCount++;
            } else if (marks[i][j] == overallLowest) {
                lowStudent[lowCount] = i;
                lowSubject[lowCount] = j;
                lowCount++;
            }
        }
    }

    double overallAverage = (double) totalSum / totalCount;

    int choice;
    while (1) {
        clearScreen();  // ðŸ§¹ Clean screen before showing menu

        animatedPrint("=====================================\n", 1);
        animatedPrint("   STUDENT GRADE MANAGEMENT SYSTEM\n", 1);
        animatedPrint("=====================================\n\n", 1);

        animatedPrint("====================================\n", 1);
        animatedPrint("          STUDENT MENU\n", 1);
        animatedPrint("====================================\n", 1);
        printf("+-----+--------+----------------+\n");
        printf("| No. | ID     | Name           |\n");
        printf("+-----+--------+----------------+\n");
        for (i = 0; i < STUDENTS; i++) {
            printf("| %-3d | %-6d | %-14s |\n", i + 1, ids[i], names[i]);
        }
        printf("+-----+--------+----------------+\n");
        printf("|  0  | Exit                     |\n");
        printf("+--------------------------------+\n");

        animatedPrint("Enter the serial number to view grades.\n", 15);
        animatedPrint("To exit, enter 0: ", 15);
        scanf("%d", &choice);

        if (choice == 0) {
            clearScreen();
            animatedPrint("\nExiting program , See You Next Time : Goodbye!\n", 20);
            break;
        }

        if (choice < 1 || choice > STUDENTS) {
            animatedPrint("\nInvalid choice! Try again.\n", 20);
            sleep(1);
            continue;
        }

        int selected = choice - 1;
        clearScreen();

        animatedPrint("------------------------------------------------------------\n", 1);
        printf("Student ID: %d\n", ids[selected]);
        printf("Student Name: %s\n", names[selected]);
        animatedPrint("------------------------------------------------------------\n", 1);
        printf("| %-10s | %-5s | %-5s | %-40s |\n", "Subject", "Marks", "Grade", "Status");
        animatedPrint("------------------------------------------------------------\n", 1);

        int sum = 0, passed = 0, failed = 0;

        for (j = 0; j < SUBJECTS; j++) {
            int mark = marks[selected][j];
            sum += mark;

            char status[50];
            if (mark < PASSMARK) {
                failed++;
                sprintf(status, "Failed in this subject (Fail mark=%d)", FAILMARK);
            } else {
                passed++;
                sprintf(status, "Passed in this subject (Pass mark=%d)", PASSMARK);
            }

            printf("| %-10s | %-5d | %-5s | %-40s |\n",
                   subjects[j], mark, getGrade(mark), status);
        }

        double avg = (double) sum / SUBJECTS;
        animatedPrint("------------------------------------------------------------\n", 1);
        printf("Summary for %s (ID: %d):\n", names[selected], ids[selected]);
        animatedPrint("------------------------------------------------------------\n", 1);
        printf("Total Marks : %d\n", sum);
        printf("Average Marks : %.2f\n", avg);
        printf("Subjects Passed: %d\n", passed);
        printf("Subjects Failed: %d\n", failed);
        showGradeScale();

        // Overall stats
        animatedPrint("\nOverall Stats among all students:\n", 15);
        printf("Highest Mark : %d\n", overallHighest);
        for (i = 0; i < highCount; i++) {
            printf("  Student: %s (ID: %d)  Subject: %s\n",
                   names[highStudent[i]], ids[highStudent[i]], subjects[highSubject[i]]);
        }

        printf("Lowest Mark  : %d\n", overallLowest);
        for (i = 0; i < lowCount; i++) {
            printf("  Student: %s (ID: %d)  Subject: %s\n",
                   names[lowStudent[i]], ids[lowStudent[i]], subjects[lowSubject[i]]);
        }

        printf("Overall Average: %.2f\n", overallAverage);
        animatedPrint("------------------------------------------------------------\n", 1);

        animatedPrint("\nPress Enter to return to the menu...", 15);
        getchar(); // consume newline
        getchar(); // wait for enter key
    }

    return 0;
}
