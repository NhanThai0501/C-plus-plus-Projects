// Name: Nhan Thai
// Date: 9/25/2020
// Description: Chapter 3 - Challenge 3

#include <iostream>
using namespace std;

int main()
{
	cout << "Test Average by Nhan Thai\n\n";

	// Declare the variables
	int score1, score2, score3, score4, score5, sum;
	double average;

	// Input values
	cout << "Enter the first test score: "; // input positive integer value for test score and test score is less than 2,147,483,647
	cin >> score1;
	cin.clear();
	cin.ignore(999, '\n');

	cout << "Enter the second test score: "; // input positive integer value for test score and test score is less than 2,147,483,647
	cin >> score2;
	cin.clear();
	cin.ignore(999, '\n');

	cout << "Enter the third test score: "; // input positive integer value for test score and test score is less than 2,147,483,647
	cin >> score3;
	cin.clear();
	cin.ignore(999, '\n');

	cout << "Enter the fourth test score: "; // input positive integer value for test score and test score is less than 2,147,483,647
	cin >> score4;
	cin.clear();
	cin.ignore(999, '\n');

	cout << "Enter the fifth test score: "; // input positive integer value for test score and test score is less than 2,147,483,647
	cin >> score5;
	cin.clear();
	cin.ignore(999, '\n');

	// Set the equations
	sum = score1 + score2 + score3 + score4 + score5;
	average = static_cast<double>(sum) / 5;

	// Output
	cout << "The test average is " << average << ".\n";

	return EXIT_SUCCESS;
}