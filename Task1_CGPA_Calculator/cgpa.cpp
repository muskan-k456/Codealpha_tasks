#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    int n;
    float totalCredits = 0, totalGradePoints = 0;

    cout << "========== CGPA CALCULATOR ==========\n";
    cout << "Enter the number of courses: ";
    cin >> n;

    string courseName[n];
    float grade[n], credit[n];

    for (int i = 0; i < n; i++)
    {
        cout << "\nCourse " << i + 1 << endl;

        cout << "Enter Course Name: ";
        cin.ignore();
        getline(cin, courseName[i]);

        cout << "Enter Grade Point (0 - 10): ";
        cin >> grade[i];

        while (grade[i] < 0 || grade[i] > 10)
        {
            cout << "Invalid Grade! Enter again (0 - 10): ";
            cin >> grade[i];
        }

        cout << "Enter Credit Hours: ";
        cin >> credit[i];

        totalCredits += credit[i];
        totalGradePoints += grade[i] * credit[i];
    }

    float cgpa = totalGradePoints / totalCredits;

    cout << "\n========== RESULT ==========\n";
    cout << left << setw(20) << "Course"
         << setw(12) << "Grade"
         << setw(12) << "Credits" << endl;

    for (int i = 0; i < n; i++)
    {
        cout << left << setw(20) << courseName[i]
             << setw(12) << grade[i]
             << setw(12) << credit[i] << endl;
    }

    cout << "\nTotal Credits      : " << totalCredits << endl;
    cout << "Total Grade Points : " << totalGradePoints << endl;
    cout << fixed << setprecision(2);
    cout << "Semester GPA / CGPA: " << cgpa << endl;

    return 0;
}