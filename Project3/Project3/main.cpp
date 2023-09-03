//Name: Nhan Thai
//Date: 9/18/2020
//Description: Exam 1 - Volume Calculators

#include <iostream>;
#include "input.h";

using namespace std;

// functions prototyes
void menu();
void annulus_shape();
void rhombus_shape();
void parallelogram_shape();
void equilateralTriangle_shape();
void stadium_shape();

int main()
{
	srand(static_cast<unsigned int>(time(0)));

	do
	{
		system("cls");
		menu();

		int option;
		cin >> option;
		cin.clear();
		cin.ignore(999, '\n');

		switch (option)
		{
		case 0: exit(1); break;
		case 1: system("cls"); annulus_shape(); break;
		case 2: system("cls"); rhombus_shape(); break;
		case 3: system("cls"); parallelogram_shape(); break;
		case 4: system("cls"); equilateralTriangle_shape(); break;
		case 5: system("cls"); stadium_shape(); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
	return EXIT_SUCCESS;
}

void menu()
{
	cout << "\n\tPlane Geometry Calculators\n";
	cout << "\n\t" + string(60, char(205));
	cout << "\n\n\t1) Annulus Shape";
	cout << "\n\n\t2) Rhombus Shape";
	cout << "\n\n\t3) Parallelogram Shape";
	cout << "\n\n\t4) Equilateral Triangle Shape";
	cout << "\n\n\t5) Stadium Shape\n";
	cout << "\n\t" + string(60, char(196));
	cout << "\n\t\t0) Quit";
	cout << "\n\t" + string(60, char(205));
	cout << "\n\t\tOption: ";
}



void annulus_shape()
{
	cout << "\n\n\t1) Annulus Shape:\n";
	cout << "\t-----------------------------------------------------------------------------------\n\n";

	// Initialize the variables
	const double PI = 3.14159;

	int outerRadius = inputDouble("Enter the outer radius: ", true);
	int innerRadius = inputDouble("Enter the inner radius: ", true);
	// Set up equations
	double circumferenceOuter = 2 * PI * (double)outerRadius;
	double circumferenceInner = 2 * PI * (double)innerRadius;

	double areaOuter = PI * (double)outerRadius * (double)outerRadius;
	double areaInner = PI * (double)innerRadius * (double)innerRadius;

	double totalArea = areaOuter - areaInner;
	double totalCircumference = circumferenceInner + circumferenceOuter;

	// Output
	cout << "\t      *  *  *\n";
	cout << "\t   *    *|*     *\n";
	cout << "\t *    *  |   *    *   \tOuter radius r1 : " << outerRadius << "\n";
	cout << "\t*   *    |     *   *  \tInner radius r2 : " << innerRadius << "\n";
	cout << "\t*   *    +-----*   *  \tpi              : " << PI << "\n";
	cout << "\t*   *          *   *  \tcircumference  C: " << totalCircumference << "\n";
	cout << "\t *   *       *    *   \tArea           K: " << totalArea << "\n";
	cout << "\t   *    * *     *\n";
	cout << "\t      *  *  *\n";
}

void rhombus_shape()
{
	cout << "\n\n\t2)Rhombus Shape:\n";
	cout << "\t-----------------------------------------------------------------------------------\n\n";

	// Initialize the variables
	double diagonalPRhombus = inputDouble("Enter the diagonal PRhombus: ", true);
	double diagonalQRhombus = inputDouble("Enter the diagonal QRhombus: ", true);

	// Set up equations
	double sideLength = sqrt((diagonalPRhombus * diagonalPRhombus + diagonalQRhombus * diagonalQRhombus) / 4);
	double perimeterRhombus = 4 * sideLength;
	double areaRhombus = diagonalPRhombus * diagonalQRhombus / 2;

	// Output
	cout << "\t           *\n";
	cout << "\t       *   |   *         \tDiagonal  p : " << diagonalPRhombus << "\n";
	cout << "\t   *       |       *     \tDiagonal  q : " << diagonalQRhombus << "\n";
	cout << "\t*----------+-----------* \tPerimeter p : " << perimeterRhombus << "\n";
	cout << "\t   *       |       *     \tArea      K : " << areaRhombus << "\n";
	cout << "\t       *   |   *\n";
	cout << "\t           *\n";
}

void parallelogram_shape()
{
	cout << "\n\n\t3) Parallelogram Shape:\n";
	cout << "\t-----------------------------------------------------------------------------------\n\n";

	// Initialize the variables
	double sideLengthAParallelogram = inputDouble("Enter the side length:", true);
	double baseParallelogram = inputDouble ("Enter the base: ", true);
	double heightParallelogram = inputDouble ("Enter the height: ", true);

	// Set up the equations
	double areaParallelogram = (double)baseParallelogram * (double)heightParallelogram;
	double perimeterParallelogram = 2 * (double)baseParallelogram + 2 * (double)sideLengthAParallelogram;

	// Output
	cout << "\t            ************************" << "\n";
	cout << "\t          * |                    *  \tBase        b :" << baseParallelogram << "\n";
	cout << "\t        *   |                  *    \tHeight      h :" << heightParallelogram << "\n";
	cout << "\t      *     |                *      \tSide height a :" << sideLengthAParallelogram << "\n";
	cout << "\t    *       |              *        \tPerimeter   P :" << perimeterParallelogram << "\n";
	cout << "\t  *         |            *          \tArea        K :" << areaParallelogram << "\n";
	cout << "\t************************" << "\n";
}

void equilateralTriangle_shape()
{
	cout << "\n\n\t4) Equilateral Triangle Shape:\n";
	cout << "\t-----------------------------------------------------------------------------------\n\n";

	// Initialize the variable
	const double PI = 3.14159;
	double heightEquilateralTriangle = inputDouble ("Enter the height: ", true);

	// Set up the equations
	double sideEquilateralTriangle = heightEquilateralTriangle * (2 / sqrt(3));
	double perimeterEquilateralTriangle = 3 * sideEquilateralTriangle;
	double areaEquilateralTriangle = sideEquilateralTriangle * sideEquilateralTriangle * sqrt(3) / 4;

	// Output
	cout << "\t          *\n";
	cout << "\t        * | *\n";
	cout << "\t      *   |   *      \theight    h : " << heightEquilateralTriangle << "\n";
	cout << "\t    *     |     *    \tPerimeter p : " << perimeterEquilateralTriangle << "\n";
	cout << "\t  *       |       *  \tArea      K : " << areaEquilateralTriangle << "\n";
	cout << "\t* * * * * * * * * * *\n";


}

void stadium_shape()
{
	cout << "\n\n\t5) Stadium Shape:\n";
	cout << "\t-----------------------------------------------------------------------------------\n\n";

	// Initialize the variables
	const double PI = 3.14159;

	double radiusStadium = inputDouble("Enter the radius: ",true);
	double sideLengthStadium = inputDouble ("Enter the side length: ", true);

	// Set up the equations
	double perimeterStadium = 2 * (PI * radiusStadium + sideLengthStadium);
	double areaStadium = PI * radiusStadium * radiusStadium + 2 * radiusStadium * sideLengthStadium;

	// Output
	cout << "\t       *  * * * * * * * * * *  *\n";
	cout << "\t   *      |                 |      * \n";
	cout << "\t *        |                 |        *  \tRadius r      : " << radiusStadium << "\n";
	cout << "\t*         |                 |         * \tSide length a : " << sideLengthStadium << "\n";
	cout << "\t*         |                 +---------* \tpi            : " << PI << "\n";
	cout << "\t*         |                 |         * \tPerimeter   p : " << perimeterStadium << "\n";
	cout << "\t *        |                 |        *  \tArea        K : " << areaStadium << "\n";
	cout << "\t   *      |                 |      *\n";
	cout << "\t       *  * * * * * * * * * *  *\n";
}