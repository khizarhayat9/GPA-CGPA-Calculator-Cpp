#include <iostream>
#include <iomanip>  // for formatting output
using namespace std;

// Convert marks into grade points
float getGradePoint(int marks) {
    if (marks >= 90 && marks <= 100)
        return 4.0;
    else if (marks >= 80)
        return 3.7;
    else if (marks >= 70)
        return 3.0;
    else if (marks >= 60)
        return 2.0;
    else
        return 0.0;
}

// GPA Calculator
float calculateGPA() {
    int subjects;

    cout << "\nEnter number of subjects: ";
    cin >> subjects;

    // Validate subject count
    if (subjects <= 0) {
        cout << "Invalid number of subjects!\n";
        return -1;
    }

    float totalGradePoints = 0, gradePoint;
    int marks;

    for (int i = 1; i <= subjects; i++) {

        // Input marks with validation
        cout << "Enter marks of subject " << i << " (0-100): ";
        cin >> marks;

        if (marks < 0 || marks > 100) {
            cout << "Invalid marks! Please enter between 0-100.\n";
            i--;     // repeat same subject
            continue;
        }

        gradePoint = getGradePoint(marks);
        cout << "Grade Point: " << gradePoint << endl;

        totalGradePoints += gradePoint;
    }

    float gpa = totalGradePoints / subjects;
    return gpa;
}

// CGPA Calculator
float calculateCGPA() {
    int semesters;

    cout << "\nEnter number of semesters: ";
    cin >> semesters;

    if (semesters <= 0) {
        cout << "Invalid semester count!\n";
        return -1;
    }

    float gpa, total = 0;

    for (int i = 1; i <= semesters; i++) {
        cout << "Enter GPA of semester " << i << " (0.0–4.0): ";
        cin >> gpa;

        if (gpa < 0.0 || gpa > 4.0) {
            cout << "Invalid GPA! Please enter between 0.0–4.0.\n";
            i--;     // redo same semester
            continue;
        }

        total += gpa;
    }

    float cgpa = total / semesters;
    return cgpa;
}

int main() {

    int choice;

    cout << fixed << setprecision(2); // format output to 2 decimals

    while (true) {   // Loop menu until user exits

        cout << "\n======= GPA & CGPA CALCULATOR =======\n";
        cout << "1. Calculate GPA\n";
        cout << "2. Calculate CGPA\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {

        case 1: {
            float gpa = calculateGPA();

            if (gpa >= 0)
                cout << "\nYour GPA is: " << gpa << endl;
            break;
        }

        case 2: {
            float cgpa = calculateCGPA();

            if (cgpa >= 0)
                cout << "\nYour CGPA is: " << cgpa << endl;
            break;
        }

        case 3:
            cout << "Exiting program... Goodbye!\n";
            return 0;

        default:
            cout << "Invalid choice! Please select again.\n";
        }
    }

    return 0;
}

