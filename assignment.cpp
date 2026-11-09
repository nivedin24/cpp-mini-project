#include <iostream>
using namespace std;

// Function to read marks
void readMarks(int marks[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter mark of student " << i + 1 << ": ";
        cin >> marks[i];
    }
}

// Function to calculate total
int findTotal(int marks[], int n)
{
    int total = 0;

    for (int i = 0; i < n; i++)
    {
        total = total + marks[i];
    }

    return total;
}

// Function to calculate average
double findAverage(int marks[], int n)
{
    int total = findTotal(marks, n);

    return (double)total / n;
}

// Function to find highest mark
int findHighest(int marks[], int n)
{
    int highest = marks[0];

    for (int i = 1; i < n; i++)
    {
        if (marks[i] > highest)
        {
            highest = marks[i];
        }
    }

    return highest;
}

// Function to find lowest mark
int findLowest(int marks[], int n)
{
    int lowest = marks[0];

    for (int i = 1; i < n; i++)
    {
        if (marks[i] < lowest)
        {
            lowest = marks[i];
        }
    }

    return lowest;
}

// Function to count passed students
int countPassed(int marks[], int n)
{
    int pass = 0;

    for (int i = 0; i < n; i++)
    {
        if (marks[i] >= 40)
        {
            pass++;
        }
    }

    return pass;
}

// Function to display the report
void printReport(int marks[], int n)
{
    int total = findTotal(marks, n);
    double average = findAverage(marks, n);
    int highest = findHighest(marks, n);
    int lowest = findLowest(marks, n);
    int pass = countPassed(marks, n);
    int fail = n - pass;

    cout << "\n========== STUDENT REPORT ==========" << endl;

    cout << "Total Marks  : " << total << endl;
    cout << "Average      : " << average << endl;
    cout << "Highest Mark : " << highest << endl;
    cout << "Lowest Mark  : " << lowest << endl;
    cout << "Passed       : " << pass << endl;
    cout << "Failed       : " << fail << endl;

    cout << "====================================" << endl;
}

int main()
{

    int marks[100];
    int n;
    char choice;

    do
    {
        cout << "\n============================" << endl;
        cout << "   STUDENT MARKS ANALYZER" << endl;
        cout << "============================" << endl;

        cout << "Enter number of students: ";
        cin >> n;

        if (n < 1 || n > 100)
        {
            cout << "Invalid number! Enter between 1 and 100." << endl;
        }
        else
        {
            readMarks(marks, n);
            printReport(marks, n);
        }

        cout << "\nDo you want to analyze again? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    cout << "\nThank you for using Student Marks Analyzer!" << endl;

    return 0;
}