// Name: Nhan Thai
// Date: 9/25/2020
// Description: Chapter 3 - Challenge 8

#include <iostream>
using namespace std;

int main()
{
	cout << "How Many Widgets by Nhan Thai\n\n";

	//Declare variables
	double const ONE_WIDGET_WEIGHT = 12.5;
	double palletWeight, widgetNumber, palletWithWidgetWeight, widgetWeight;

	// Input
	cout << "The weight of the pallet itself: "; // input postive number for pallet's weight
	cin >> palletWeight;
	cin.clear();
	cin.ignore(999, '\n');

	cout << "The weight of the pallet with the widgets stacked on it: "; // input positive number for pallet's weight with widgets, it should bigger than pallet's weight.
	cin >> palletWithWidgetWeight;
	cin.clear();
	cin.ignore(999, '\n');

	// Set up the equations
	widgetWeight = palletWithWidgetWeight - palletWeight;
	widgetNumber = static_cast<int>(widgetWeight / ONE_WIDGET_WEIGHT);

	//Output
	cout << "The number of widgets stacked on the pallet is " << widgetNumber << ".\n";

	return EXIT_SUCCESS;
}