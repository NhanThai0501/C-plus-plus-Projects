// Name: Nhan Thai
// Date: 9/25/2020
// Description: Chapter 3 - Challenge 6

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	cout << "Ingredient Adjuster by Nhan Thai\n\n";

	// Declare the variables
	double sugarInitial, butterInitial, flourInitial;
	const int COOKIE = 48;

	// Set up equations
	sugarInitial = 1.5 / COOKIE;
	butterInitial = 1.0 / COOKIE;
	flourInitial = 2.75 / COOKIE;

	// Output
	cout << "The ingredients for making one cookie are:\n";
	cout << setprecision(3) << sugarInitial << " cups of sugar.\n";
	cout << butterInitial << " cups of butter.\n";
	cout << flourInitial << " cups of flour.\n";

	// Declare variable
	double cookiesAmount;
	
	// Input
	cout << "\nThe number of cookies that you want to make (ex: 48): "; // input positive integer value of cookies
	cin >> cookiesAmount;
	cin.clear();
	cin.ignore(999, '\n');

	// Output
	cout << "You will need:\n";
	cout << cookiesAmount * sugarInitial << " cups of sugar.\n";
	cout << cookiesAmount * butterInitial << " cups of butter.\n";
	cout << cookiesAmount * flourInitial << " cups of flour.\n";
	
	return EXIT_SUCCESS;
}