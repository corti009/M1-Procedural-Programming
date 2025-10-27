#include <iostream>
#include <iomanip>
#include <string>
#include <cmath> 

using namespace std;
const int NUM_STUDENTS = 6;
const int NUM_TESTS = 5;
void readData(string names[], int scores[][NUM_TESTS]);
void calculateAverages(const int scores[][NUM_TESTS], double averages[]);
double calculateTestAverage(const int scores[][NUM_TESTS], int testNum);
char calculateLetterGrade(double average);
void printReport(const string names[], const int scores[][NUM_TESTS], 
                 const double averages[], const char letterGrades[]);

int main() {
    string studentNames[NUM_STUDENTS];
    int testScores[NUM_STUDENTS][NUM_TESTS];
    double studentAverages[NUM_STUDENTS];
    char letterGrades[NUM_STUDENTS];
    readData(studentNames, testScores);
    calculateAverages(testScores, studentAverages);
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        letterGrades[i] = calculateLetterGrade(studentAverages[i]);
    }


    printReport(studentNames, testScores, studentAverages, letterGrades);

    
    cout << "\n======================================================\n";
    cout << "           Overall Test Averages\n";
    cout << "======================================================\n";

    for (int i = 0; i < NUM_TESTS; ++i) {
        double avg = calculateTestAverage(testScores, i);
        cout << fixed << setprecision(2);
        cout << "Test " << (i + 1) << " Average: " << avg << endl;
    }

    cout << "======================================================\n";

    return 0;
}



void readData(string names[], int scores[][NUM_TESTS]) {

    names[0] = "Aaliyah";
    scores[0][0] = 82; scores[0][1] = 72; scores[0][2] = 91; scores[0][3] = 74; scores[0][4] = 82;

    names[1] = "Briana";
    scores[1][0] = 87; scores[1][1] = 97; scores[1][2] = 82; scores[1][3] = 84; scores[1][4] = 94;

    names[2] = "Devon";
    scores[2][0] = 92; scores[2][1] = 98; scores[2][2] = 91; scores[2][3] = 100; scores[2][4] = 85;

    names[3] = "Javier";
    scores[3][0] = 85; scores[3][1] = 82; scores[3][2] = 72; scores[3][3] = 84; scores[3][4] = 85;

    names[4] = "Johnathan";
    scores[4][0] = 78; scores[4][1] = 60; scores[4][2] = 63; scores[4][3] = 79; scores[4][4] = 81;

    names[5] = "Vanessa";
    scores[5][0] = 74; scores[5][1] = 91; scores[5][2] = 77; scores[5][3] = 74; scores[5][4] = 80;
}

void calculateAverages(const int scores[][NUM_TESTS], double averages[]) {
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        int sum = 0;
        for (int j = 0; j < NUM_TESTS; ++j) {
            sum += scores[i][j];
        }
       
        averages[i] = static_cast<double>(sum) / NUM_TESTS;
    }
}

double calculateTestAverage(const int scores[][NUM_TESTS], int testNum) {
    int sum = 0;
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        sum += scores[i][testNum];
    }
   
    return static_cast<double>(sum) / NUM_STUDENTS;
}

char calculateLetterGrade(double average) {
    
    if (average >= 90) {
        return 'A';
    } else if (average >= 80) {
        return 'B';
    } else if (average >= 70) {
        return 'C';
    } else if (average >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

void printReport(const string names[], const int scores[][NUM_TESTS], 
                 const double averages[], const char letterGrades[]) {

   
    const int NAME_WIDTH = 12;
    const int SCORE_WIDTH = 6;
    const int AVG_WIDTH = 8;
    const int GRADE_WIDTH = 6;

    cout << fixed << setprecision(2); 
    cout << "========================================================================\n";
    cout << setw(NAME_WIDTH) << left << "STUDENT" 
         << setw(SCORE_WIDTH * NUM_TESTS) << "TEST SCORES"
         << setw(AVG_WIDTH) << "AVERAGE" 
         << setw(GRADE_WIDTH) << "GRADE" << endl;
    cout << "------------------------------------------------------------------------\n";

   
    cout << setw(NAME_WIDTH) << "";
    for (int i = 0; i < NUM_TESTS; ++i) {
        cout << setw(SCORE_WIDTH) << "T" + to_string(i + 1);
    }
    cout << endl;
    cout << "========================================================================\n";

   
    for (int i = 0; i < NUM_STUDENTS; ++i) {
        cout << setw(NAME_WIDTH) << left << names[i];

       
        for (int j = 0; j < NUM_TESTS; ++j) {
            cout << setw(SCORE_WIDTH) << scores[i][j];
        }

       
        cout << setw(AVG_WIDTH) << averages[i] 
             << setw(GRADE_WIDTH) << letterGrades[i] << endl;
    }
    cout << "========================================================================\n";
}
