#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include "input.h"
using namespace std;

// function prototype
double surfaceArea(double sideLength);
double volume(double sideLength);
void cube();

double sphereSurfaceArea(double radius);
double sphereVolume(double radius);
void sphere();

double hemisphereSurfaceArea(double radius);
double hemisphereVolume(double radius);
void hemisphere();

double surfaceArea(double length, double width, double height);
double volume(double length, double width, double height);
void rectangularPrism();

double conicalSurfaceArea(double firstRadius, double secondRadius, double height);
double conicalVolume(double firstRadius, double secondRadius, double height);
void conicalFrustum();

double tetrahedronSurfaceArea(double length);
double tetrahedronVolume(double length);
void face4();
void face6();
double octahedronSurfaceArea(double length);
double octahedronVolume(double length);
void face8();
double dodecahedronSurfaceArea(double length);
double dodecahedronVolume(double length);
void face12();
double icosahedronSurfaceArea(double length);
double icosahedronVolume(double length);
void face20();
void regularPolyhedron();

int main()
{
    srand(static_cast<unsigned int>(time(0)));

    do
    {
        system("cls");
        cout << "\n\t\tSolid Geometry Calculators";
        cout << "\n\t" + string(60, char(205));
        cout << "\n\t\t  1: Cube                         ";
        cout << "\n\t\t  2. Sphere                       ";
        cout << "\n\t\t  3. Hemisphere                   ";
        cout << "\n\t\t  4. Rectangular Prism            ";
        cout << "\n\t\t  5. Conical Frustum              ";
        cout << "\n\t\t  6. Regular Polyhedron       ";
        cout << "\n\t" + string(60, char(196));
        cout << "\n\t\t  0. Quit";
        cout << "\n\t" + string(60, char(205));
        cout << "\n\t\t  Option: ";

        int option;
        cin >> option;
        cin.clear();
        cin.ignore(999, '\n');

        switch (option)
        {
        case 0: exit(1); break;
        case 1: system("cls"); cube(); break;
        case 2: system("cls"); sphere(); break;
        case 3: system("cls"); hemisphere(); break;
        case 4: system("cls"); rectangularPrism(); break;
        case 5: system("cls"); conicalFrustum(); break;
        case 6: system("cls"); regularPolyhedron(); break;
        default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
        }
        cout << "\n";
        system("pause");
    } while (true);
    return EXIT_SUCCESS;
}

// cube Program

double surfaceArea(double sideLength)
{
    double surfaceArea = 6.0 * pow(sideLength, 2.0);
    return surfaceArea;

}
double volume(double sideLength)
{
    double volume = pow(sideLength, 3.0);
    return volume;
}
void cube()
{
    cout << "1: Cube Shape\n\n";

    // Input
    double sideLength = inputDouble("\tEnter the side length (a): ", true);

    int decimal = inputInteger("\tSet the decimal precision (1..9): ", 1, 9);

    char output = inputChar("\tDo you want output to C-console or F-file: ", toupper('C'), toupper('F'));

    // Set the conditions and output
    if (output == 'C' || output == 'c')
    {
        cout << "\n\tCube Shape       \n\n";
        cout << "\t      * * * * * *    \n";
        cout << "\t   *         *//*    \n";
        cout << "\t* * * * * */////*    \n";
        cout << "\t*         */////*    \n";
        cout << "\t*         */////*    \n";
        cout << "\t*         */////*    \n";
        cout << "\t*         *//*       \n";
        cout << "\t* * * * * *        \n\n";

        cout << "\tLength side       a = " << fixed << setprecision(decimal) << sideLength << "\n";
        cout << "\tSurface area      S = " << fixed << setprecision(decimal) << surfaceArea(sideLength) << "\n";
        cout << "\tVolume            V = " << fixed << setprecision(decimal) << volume(sideLength) << "\n";
    }

    if (output == 'F' || output == 'f')
    {
        ofstream outputFile;
        outputFile.open("CUBE.TXT");

        outputFile << "\n\tCube Shape          \n\n";
        outputFile << "\t      * * * * * *       \n";
        outputFile << "\t   *         *//*       \n";
        outputFile << "\t* * * * * */////*       \n";
        outputFile << "\t*         */////*       \n";
        outputFile << "\t*         */////*       \n";
        outputFile << "\t*         */////*       \n";
        outputFile << "\t*         *//*          \n";
        outputFile << "\t* * * * * *           \n\n";

        outputFile << "\tLength side       a = " << fixed << setprecision(decimal) << sideLength << "\n";
        outputFile << "\tSurface area      S = " << fixed << setprecision(decimal) << surfaceArea(sideLength) << "\n";
        outputFile << "\tVolume            V = " << fixed << setprecision(decimal) << volume(sideLength) << "\n";

        outputFile.close();

        cout << "\nFile: CUBE.TXT, has been created\n";

    }

}

// sphere Program

double sphereSurfaceArea(double radius)
{
    double const PI = 3.1415926535898;
    double surfaceArea = 4.0 * PI * pow(radius, 2.0);
    return surfaceArea;
}
double sphereVolume(double radius)
{
    double const PI = 3.1415926535898;
    double volume = 4.0 / 3.0 * PI * pow(radius, 3.0);
    return volume;
}
void sphere()
{
    cout << "\n2: Sphere Shape\n\n";
    double const PI = 3.1415926535898;

    // Input

    double radius = inputDouble("\tEnter the radius (r): ", true);

    int decimal = inputInteger("\tSet the decimal precision (1..9): ", 1, 9);

    char output = inputChar("\tDo you want output to C-console or F-file: ", toupper('C'), toupper('F'));
    // Set the conditions and output

    if (output == 'C' || output == 'c')
    {
        cout << "\n\tSphere Shape           \n\n";
        cout << "\t        * * *              \n";
        cout << "\t    * .  . .. ..*          \n";
        cout << "\t  *.  .  . . .. ..*        \n";
        cout << "\t *. .      . .. ...*       \n";
        cout << "\t *. .      . .. ...*       \n";
        cout << "\t *. . .  . . .. ...*       \n";
        cout << "\t  * . .  . . . ...*        \n";
        cout << "\t    *  .  . .. ..*         \n";
        cout << "\t        * * *            \n\n";

        cout << "\tRadius              r = " << fixed << setprecision(decimal) << radius << "\n";
        cout << "\tPi                    = " << fixed << setprecision(decimal) << PI << "\n";
        cout << "\tSurface area        S = " << fixed << setprecision(decimal) << sphereSurfaceArea(radius) << "\n";
        cout << "\tVolume              V = " << fixed << setprecision(decimal) << sphereVolume(radius) << "\n";
    }

    if (output == 'F' || output == 'f')
    {
        ofstream outputFile;
        outputFile.open("SPHERE.TXT");

        outputFile << "\n\tSphere Shape           \n\n";
        outputFile << "\t        * * *              \n";
        outputFile << "\t    * .  . .. ..*          \n";
        outputFile << "\t  *.  .  . . .. ..*        \n";
        outputFile << "\t *. .      . .. ...*       \n";
        outputFile << "\t *. .      . .. ...*       \n";
        outputFile << "\t *. . .  . . .. ...*       \n";
        outputFile << "\t  * . .  . . . ...*        \n";
        outputFile << "\t    *  .  . .. ..*         \n";
        outputFile << "\t        * * *            \n\n";

        outputFile << "\tRadius              r = " << fixed << setprecision(decimal) << radius << "\n";
        outputFile << "\tPi                    = " << fixed << setprecision(decimal) << PI << "\n";
        outputFile << "\tSurface area        S = " << fixed << setprecision(decimal) << sphereSurfaceArea(radius) << "\n";
        outputFile << "\tVolume              V = " << fixed << setprecision(decimal) << sphereVolume(radius) << "\n";

        outputFile.close();

        cout << "\nFile: SPHERE.TXT, has been created\n";

    }

}

// hemisphere Program

double hemisphereSurfaceArea(double radius)
{
    double const PI = 3.1415926535898;
    double surfaceArea = 3.0 * PI * pow(radius, 2.0);
    return surfaceArea;

}
double hemisphereVolume(double radius)
{
    double const PI = 3.1415926535898;
    double volume = (2.0 / 3.0) * PI * pow(radius, 3.0);
    return volume;

}
void hemisphere()
{
    cout << "3: Hemisphere Shape\n\n";

    double const PI = 3.1415926535898;

    // Input
    double radius = inputDouble("\tEnter the radius (r): ", true);

    int decimal = inputInteger("\tSet the decimal precision (1..9): ", 1, 9);

    char output = inputChar("\tDo you want output to C-console or F-file: ", toupper('C'), toupper('F'));

    // Set the conditions and output
    if (output == 'C' || output == 'c')
    {
        cout << "\n\tHemisphere Shape           \n\n";
        cout << "\t        * * *                  \n";
        cout << "\t    * .  . .. ..*              \n";
        cout << "\t  *.  .  . . .. ..*            \n";
        cout << "\t *. .      . .. ...*           \n";
        cout << "\t *. . .    . .. ..*            \n";
        cout << "\t     * * * * * *             \n\n";

        cout << "\tRadius             r = " << fixed << setprecision(decimal) << radius << "\n";
        cout << "\tPi                   = " << fixed << setprecision(decimal) << PI << "\n";
        cout << "\tSurface area       S = " << fixed << setprecision(decimal) << hemisphereSurfaceArea(radius) << "\n";
        cout << "\tVolume             V = " << fixed << setprecision(decimal) << hemisphereVolume(radius) << "\n";
    }

    if (output == 'F' || output == 'f')
    {
        ofstream outputFile;
        outputFile.open("HEMISPHERE.TXT");

        outputFile << "\n\tHemisphere Shape           \n\n";
        outputFile << "\t        * * *                  \n";
        outputFile << "\t    * .  . .. ..*              \n";
        outputFile << "\t  *.  .  . . .. ..*            \n";
        outputFile << "\t *. .      . .. ...*           \n";
        outputFile << "\t *. . .  . . .. ..*            \n";
        outputFile << "\t     * * * * * *             \n\n";

        outputFile << "\tRadius             r = " << fixed << setprecision(decimal) << radius << "\n";
        outputFile << "\tPi                   = " << fixed << setprecision(decimal) << PI << "\n";
        outputFile << "\tSurface area       S = " << fixed << setprecision(decimal) << hemisphereSurfaceArea(radius) << "\n";
        outputFile << "\tVolume             V = " << fixed << setprecision(decimal) << hemisphereVolume(radius) << "\n";

        outputFile.close();

        cout << "\nFile: HEMISPHERE.TXT, has been created\n";

    }

}

// rectangularPrism Program

double surfaceArea(double length, double width, double height)
{
    double surfaceArea = 2.0 * (length * width + length * height + width * height);
    return surfaceArea;

}
double volume(double length, double width, double height)
{
    double volume = length * width * height;
    return volume;
}
void rectangularPrism()
{
    cout << "4: Rectangular Prism Shape\n\n";

    // Input

    double length = inputDouble("\tEnter the length (l): ", true);
    double width = inputDouble("\tEnter the width (w): ", true);
    double height = inputDouble("\tEnter the height (h): ", true);

    int decimal = inputInteger("\tSet the decimal precision (1..9): ", 1, 9);

    char output = inputChar("\tDo you want output to C-console or F-file: ", toupper('C'), toupper('F'));

    double cubeVolume = volume(length, width, height);
    double cubeSurfaceArea = surfaceArea(length, width, height);

    // Set up the conditions and output
    if (output == 'C' || output == 'c')
    {
        cout << "\n\tRectangular Prism Shape         \n\n";
        cout << "\t      * * * * * * * * *             \n";
        cout << "\t    *               */*             \n";
        cout << "\t  *               *///*             \n";
        cout << "\t* * * * * * * * */////*             \n";
        cout << "\t*               */////*             \n";
        cout << "\t*               *///*               \n";
        cout << "\t*               */*                 \n";
        cout << "\t* * * * * * * * *                 \n\n";

        cout << "\tLength             l = " << fixed << setprecision(decimal) << length << "\n";
        cout << "\tWidth              w = " << fixed << setprecision(decimal) << width << "\n";
        cout << "\tHeight             h = " << fixed << setprecision(decimal) << height << "\n";
        cout << "\tSurface area       S = " << fixed << setprecision(decimal) << surfaceArea(length, width, height) << "\n";
        cout << "\tVolume             V = " << fixed << setprecision(decimal) << volume(length, width, height) << "\n";
    }

    if (output == 'F' || output == 'f')
    {
        ofstream outputFile;
        outputFile.open("RECTANGULARPRISM.TXT");

        outputFile << "\n\tRectangular Prism Shape         \n\n";
        outputFile << "\t      * * * * * * * * *             \n";
        outputFile << "\t    *               */*             \n";
        outputFile << "\t  *               *///*             \n";
        outputFile << "\t* * * * * * * * */////*             \n";
        outputFile << "\t*               */////*             \n";
        outputFile << "\t*               *///*               \n";
        outputFile << "\t*               */*                 \n";
        outputFile << "\t* * * * * * * * *                 \n\n";

        outputFile << "\tLength             l = " << fixed << setprecision(decimal) << length << "\n";
        outputFile << "\tWidth              w = " << fixed << setprecision(decimal) << width << "\n";
        outputFile << "\tHeight             h = " << fixed << setprecision(decimal) << height << "\n";
        outputFile << "\tSurface area       S = " << fixed << setprecision(decimal) << surfaceArea(length, width, height) << "\n";
        outputFile << "\tVolume             V = " << fixed << setprecision(decimal) << volume(length, width, height) << "\n";

        outputFile.close();

        cout << "\nFile: RECTANGULARPRISM.TXT, has been created\n";

    }

}

// conicalFrustum Program

double conicalSurfaceArea(double firstRadius, double secondRadius, double height)
{
    double const PI = 3.1415926535898;
    double base = firstRadius - secondRadius;
    double surfaceArea = PI * (pow(firstRadius, 2.0) + pow(secondRadius, 2.0) + (firstRadius + secondRadius) * sqrt(pow(base, 2.0) + pow(height, 2.0)));
    return surfaceArea;

}
double conicalVolume(double firstRadius, double secondRadius, double height)
{
    double const PI = 3.1415926535898;
    double volume = (1.0 / 3.0) * PI * height * (pow(firstRadius, 2.0) + pow(secondRadius, 2.0) + (firstRadius * secondRadius));
    return volume;
}
void conicalFrustum()
{
    cout << "5: Conical Frustum Shape\n\n";

    double const PI = 3.1415926535898;

    // Input

    double firstRadius = inputDouble("\tEnter the radius (r1): ", true);
    double secondRadius = inputDouble("\tEnter the radius (r2): ", true);
    double height = inputDouble("\tEnter the height (h): ", true);

    int decimal = inputInteger("\tSet the decimal precision (1..9): ", 1, 9);

    char output = inputChar("\tDo you want output to C-console or F-file: ", toupper('C'), toupper('F'));

    // Set up the conditions and output
    if (output == 'C' || output == 'c')
    {
        cout << "\n\tConical Frustum Shape       \n\n";
        cout << "\t        * * *                   \n";
        cout << "\t    *           *               \n";
        cout << "\t   *   * *.* ..***              \n";
        cout << "\t  *     . .. ..****             \n";
        cout << "\t *     . . .. ..****            \n";
        cout << "\t*     . . . .. ..****           \n";
        cout << "\t *  . . . . .. ..***            \n";
        cout << "\t    * * * * * * *             \n\n";

        cout << "\tRadius              r1 = " << fixed << setprecision(decimal) << firstRadius << "\n";
        cout << "\tRadius              r2 = " << fixed << setprecision(decimal) << secondRadius << "\n";
        cout << "\tHeight               h = " << fixed << setprecision(decimal) << height << "\n";

        cout << "\tPi                     = " << fixed << setprecision(decimal) << PI << "\n";
        cout << "\tSurface area         S = " << fixed << setprecision(decimal) << conicalSurfaceArea(firstRadius, secondRadius, height) << "\n";
        cout << "\tVolume               V = " << fixed << setprecision(decimal) << conicalVolume(firstRadius, secondRadius, height) << "\n";
    }

    if (output == 'F' || output == 'f')
    {
        ofstream outputFile;
        outputFile.open("CONICALFRUSTUM.TXT");

        outputFile << "\n\tConical Frustum Shape       \n\n";
        outputFile << "\t        * * *                   \n";
        outputFile << "\t    *           *               \n";
        outputFile << "\t   *   * *.* ..***              \n";
        outputFile << "\t  *     . .. ..****             \n";
        outputFile << "\t *     . . .. ..****            \n";
        outputFile << "\t*     . . . .. ..****           \n";
        outputFile << "\t *  . . . . .. ..***            \n";
        outputFile << "\t    * * * * * * *             \n\n";

        outputFile << "\tRadius              r1 = " << fixed << setprecision(decimal) << firstRadius << "\n";
        outputFile << "\tRadius              r2 = " << fixed << setprecision(decimal) << secondRadius << "\n";
        outputFile << "\tHeight               h = " << fixed << setprecision(decimal) << height << "\n";

        outputFile << "\tPi                     = " << fixed << setprecision(decimal) << PI << "\n";
        outputFile << "\tSurface area         S = " << fixed << setprecision(decimal) << conicalSurfaceArea(firstRadius, secondRadius, height) << "\n";
        outputFile << "\tVolume               V = " << fixed << setprecision(decimal) << conicalVolume(firstRadius, secondRadius, height) << "\n";

        outputFile.close();

        cout << "\nFile: CONICALFRUSTUM.TXT, has been created\n";
    }

}

// Regular Tetrahedron Shape

double tetrahedronSurfaceArea(double length)
{
    double surfaceArea = sqrt(3.0) * pow(length, 2.0);
    return surfaceArea;
}
double tetrahedronVolume(double length)
{
    double volume = (sqrt(2.0) / 12.0) * pow(length, 3.0);
    return volume;
}

void face4()
{
    int face = 4;

    // Input
    int length = inputInteger("\tEnter the length of the edge (l): ", true);
    int decimal = inputInteger("\tSet the decimal precision (1..9): ", 1, 9);
    char output = inputChar("\tDo you want output to C-console or F-file: ", toupper('C'), toupper('F'));

    // Set up the conditions and output
    if (output == 'C' || output == 'c')
    {
        cout << "\n\tRegular Tetrahedron Shape \n\n";
        cout << "\t          *                     \n";
        cout << "\t        * * *                   \n";
        cout << "\t      *   * * *                 \n";
        cout << "\t    *     * * * *               \n";
        cout << "\t  *       * * * * *             \n";
        cout << "\t*         * * * * * *           \n";
        cout << "\t   *      * * * * *             \n";
        cout << "\t      *   * * *                 \n";
        cout << "\t          *                   \n\n";

        cout << "\tFaces               f = " << fixed << setprecision(decimal) << face << "\n";
        cout << "\tLength edge         l = " << fixed << setprecision(decimal) << length << "\n";
        cout << "\tSurface area        S = " << fixed << setprecision(decimal) << tetrahedronSurfaceArea(length) << "\n";
        cout << "\tVolume              V = " << fixed << setprecision(decimal) << tetrahedronVolume(length) << "\n";
    }
    if (output == 'F' || output == 'f')
    {
        ofstream outputFile;
        outputFile.open("REGULARPOLYHEDRON.TXT");

        outputFile << "\n\tRegular Tetrahedron Shape\n\n";
        outputFile << "\t          *                     \n";
        outputFile << "\t        * * *                   \n";
        outputFile << "\t      *   * * *                 \n";
        outputFile << "\t    *     * * * *               \n";
        outputFile << "\t  *       * * * * *             \n";
        outputFile << "\t*         * * * * * *           \n";
        outputFile << "\t   *      * * * * *             \n";
        outputFile << "\t      *   * * *                 \n";
        outputFile << "\t          *                   \n\n";

        outputFile << "\tFaces               f = " << fixed << setprecision(decimal) << face << "\n";
        outputFile << "\tLength edge         l = " << fixed << setprecision(decimal) << length << "\n";
        outputFile << "\tSurface area        S = " << fixed << setprecision(decimal) << tetrahedronSurfaceArea(length) << "\n";
        outputFile << "\tVolume              V = " << fixed << setprecision(decimal) << tetrahedronVolume(length) << "\n";

        outputFile.close();
        cout << "\nFile: REGULARPOLYHEDRON.TXT, has been created.\n";
    }
}

// Cube Shape
void face6()
{
    int face = 6;
    // Input

    int length = inputInteger("\tEnter the length of the edge (l): ", true);
    int decimal = inputInteger("\tSet the decimal precision (1..9): ", 1, 9);
    char output = inputChar("\tDo you want output to C-console or F-file: ", toupper('C'), toupper('F'));

    // Set up the conditions and output
    if (output == 'C' || output == 'c')
    {
        cout << "\n\tCube Shape\n\n";
        cout << "\t      * * * * * *    \n";
        cout << "\t   *         ****    \n";
        cout << "\t* * * * * *******    \n";
        cout << "\t*         *******    \n";
        cout << "\t*         *******    \n";
        cout << "\t*         *******    \n";
        cout << "\t*         ****       \n";
        cout << "\t* * * * * *        \n\n";

        cout << "\tFaces               f = " << fixed << setprecision(decimal) << face << "\n";
        cout << "\tLength edge         l = " << fixed << setprecision(decimal) << length << "\n";
        cout << "\tSurface area        S = " << fixed << setprecision(decimal) << surfaceArea(length) << "\n";
        cout << "\tVolume              V = " << fixed << setprecision(decimal) << volume(length) << "\n";
    }

    if (output == 'F' || output == 'f')
    {
        ofstream outputFile;
        outputFile.open("REGULARPOLYHEDRON.TXT");

        outputFile << "\n\tCube Shape\n\n";
        outputFile << "\t      * * * * * *    \n";
        outputFile << "\t   *         ****    \n";
        outputFile << "\t* * * * * *******    \n";
        outputFile << "\t*         *******    \n";
        outputFile << "\t*         *******    \n";
        outputFile << "\t*         *******    \n";
        outputFile << "\t*         ****       \n";
        outputFile << "\t* * * * * *        \n\n";

        outputFile << "\tFaces               f = " << fixed << setprecision(decimal) << face << "\n";
        outputFile << "\tLength edge         l = " << fixed << setprecision(decimal) << length << "\n";
        outputFile << "\tSurface area        S = " << fixed << setprecision(decimal) << surfaceArea(length) << "\n";
        outputFile << "\tVolume              V = " << fixed << setprecision(decimal) << volume(length) << "\n";

        outputFile.close();
        cout << "\nFile: REGULARPOLYHEDRON.TXT, has been created.\n";
    }

}
// Regular Octahedron Shape

double octahedronSurfaceArea(double length)
{
    double surfaceArea = 2.0 * sqrt(3.0) * pow(length, 2.0);
    return surfaceArea;
}
double octahedronVolume(double length)
{
    double volume = (sqrt(2.0) / 3.0) * pow(length, 3.0);
    return volume;
}

void face8()
{
    int face = 8;

    // Input
    int length = inputInteger("\tEnter the length of the edge (l): ", true);
    int decimal = inputInteger("\tSet the decimal precision (1..9): ", 1, 9);
    char output = inputChar("\tDo you want output to C-console or F-file: ", toupper('C'), toupper('F'));

    // Set up the conditions and output
    if (output == 'C' || output == 'c')
    {
        cout << "\n\tRegular Octahedron Shape \n\n";
        cout << "\t        **                     \n";
        cout << "\t      *  ---*                  \n";
        cout << "\t    *      ----*               \n";
        cout << "\t  *         ------*            \n";
        cout << "\t*------------********          \n";
        cout << "\t  *---------******             \n";
        cout << "\t    *------****                \n";
        cout << "\t      *---***                  \n";
        cout << "\t        **                   \n\n";

        cout << "\tFaces               f = " << fixed << setprecision(decimal) << face << "\n";
        cout << "\tLength edge         l = " << fixed << setprecision(decimal) << length << "\n";
        cout << "\tSurface area        S = " << fixed << setprecision(decimal) << octahedronSurfaceArea(length) << "\n";
        cout << "\tVolume              V = " << fixed << setprecision(decimal) << octahedronVolume(length) << "\n";
    }
    if (output == 'F' || output == 'f')
    {
        ofstream outputFile;
        outputFile.open("REGULARPOLYHEDRON.TXT");

        outputFile << "\n\tRegular Octahedron Shape\n\n";
        outputFile << "\t        **                     \n";
        outputFile << "\t      *  ---*                  \n";
        outputFile << "\t    *      ----*               \n";
        outputFile << "\t  *         ------*            \n";
        outputFile << "\t*------------********          \n";
        outputFile << "\t  *---------******             \n";
        outputFile << "\t    *------****                \n";
        outputFile << "\t      *---***                  \n";
        outputFile << "\t        **                   \n\n";

        outputFile << "\tFaces               f = " << fixed << setprecision(decimal) << face << "\n";
        outputFile << "\tLength edge         l = " << fixed << setprecision(decimal) << length << "\n";
        outputFile << "\tSurface area        S = " << fixed << setprecision(decimal) << octahedronSurfaceArea(length) << "\n";
        outputFile << "\tVolume              V = " << fixed << setprecision(decimal) << octahedronVolume(length) << "\n";

        outputFile.close();
        cout << "\nFile: REGULARPOLYHEDRON.TXT, has been created.\n";
    }

}

// Regular Dodecahedron Shape
double dodecahedronSurfaceArea(double length)
{
    double surfaceArea = 3.0 * sqrt(25.0 + (10.0 * sqrt(5))) * pow(length, 2.0);
    return surfaceArea;
}
double dodecahedronVolume(double length)
{
    double volume = (15.0 + (7 * sqrt(5.0))) / 4.0 * pow(length, 3.0);
    return volume;
}
void face12()
{
    int face = 12;

    //Input
    int length = inputInteger("\tEnter the length of the edge (l): ", true);
    int decimal = inputInteger("\tSet the decimal precision (1..9): ", 1, 9);
    char output = inputChar("\tDo you want output to C-console or F-file: ", toupper('C'), toupper('F'));

    // Set up the conditions and output
    if (output == 'C' || output == 'c')
    {
        cout << "\n\tRegular Dodecahedron Shape  \n\n";
        cout << "\t        * * *                   \n";
        cout << "\t    * ......... *               \n";
        cout << "\t  *     * * *******             \n";
        cout << "\t*         ***********           \n";
        cout << "\t*         ***********           \n";
        cout << "\t*       ....*********           \n";
        cout << "\t * . ..........*****            \n";
        cout << "\t    *............*              \n";
        cout << "\t        * * *                   \n\n";

        cout << "\tFaces               f = " << fixed << setprecision(decimal) << face << "\n";
        cout << "\tLength edge         l = " << fixed << setprecision(decimal) << length << "\n";
        cout << "\tSurface area        S = " << fixed << setprecision(decimal) << dodecahedronSurfaceArea(length) << "\n";
        cout << "\tVolume              V = " << fixed << setprecision(decimal) << dodecahedronVolume(length) << "\n";
    }
    if (output == 'F' || output == 'f')
    {
        ofstream outputFile;
        outputFile.open("REGULARPOLYHEDRON.TXT");

        outputFile << "\n\tRegular Dodecahedron Shape    \n\n";
        outputFile << "\t        * * *                     \n";
        outputFile << "\t    * ......... *                 \n";
        outputFile << "\t  *     * * *******               \n";
        outputFile << "\t*         ***********             \n";
        outputFile << "\t*         ***********             \n";
        outputFile << "\t*       ....*********             \n";
        outputFile << "\t * . ..........*****              \n";
        outputFile << "\t    *............*                \n";
        outputFile << "\t        * * *                   \n\n";

        outputFile << "\tFaces               f = " << fixed << setprecision(decimal) << face << "\n";
        outputFile << "\tLength edge         l = " << fixed << setprecision(decimal) << length << "\n";
        outputFile << "\tSurface area        S = " << fixed << setprecision(decimal) << dodecahedronSurfaceArea(length) << "\n";
        outputFile << "\tVolume              V = " << fixed << setprecision(decimal) << dodecahedronVolume(length) << "\n";

        outputFile.close();
        cout << "\nFile: REGULARPOLYHEDRON.TXT, has been created.\n";
    }

}

// Regular Icosahedron Shape
double icosahedronSurfaceArea(double length)
{
    double surfaceArea = 5.0 * sqrt(3.0) * pow(length, 2.0);
    return surfaceArea;
}
double icosahedronVolume(double length)
{
    double volume = ((5.0 * (3.0 + sqrt(5.0)) / 12.0)) * pow(length, 3.0);
    return volume;
}
void face20()
{
    int face = 20;

    // Input
    int length = inputInteger("\tEnter the length of the edge (l): ", true);
    int decimal = inputInteger("\tSet the decimal precision (1..9): ", 1, 9);
    char output = inputChar("\tDo you want output to C-console or F-file: ", toupper('C'), toupper('F'));

    // Set up the conditions and output
    if (output == 'C' || output == 'c')
    {
        cout << "\n\tRegular Icosahedron Shape  \n\n";
        cout << "\t     * * *                       \n";
        cout << "\t   *.__. ..--***                 \n";
        cout << "\t *. /  `. ...--***               \n";
        cout << "\t*. .    . . ...--**              \n";
        cout << "\t*. .`__/. . ...-***              \n";
        cout << "\t*. .   .  . ...--**              \n";
        cout << "\t * . .  . ....--**               \n";
        cout << "\t   * . . ..--***                 \n";
        cout << "\t     * * *                       \n\n";

        cout << "\tFaces               f = " << fixed << setprecision(decimal) << face << "\n";
        cout << "\tLength edge         l = " << fixed << setprecision(decimal) << length << "\n";
        cout << "\tSurface area        S = " << fixed << setprecision(decimal) << icosahedronSurfaceArea(length) << "\n";
        cout << "\tVolume              V = " << fixed << setprecision(decimal) << icosahedronVolume(length) << "\n";
    }
    if (output == 'F' || output == 'f')
    {
        ofstream outputFile;
        outputFile.open("REGULARPOLYHEDRON.TXT");

        outputFile << "\n\tRegular Icosahedron Shape  \n\n";
        outputFile << "\t     * * *                       \n";
        outputFile << "\t   *.__. ..--***                 \n";
        outputFile << "\t *. /  `. ...--***               \n";
        outputFile << "\t*. .    . . ...--**              \n";
        outputFile << "\t*. .`__/. . ...-***              \n";
        outputFile << "\t*. .   .  . ...--**              \n";
        outputFile << "\t * . .  . ....--**               \n";
        outputFile << "\t   * . . ..--***                 \n";
        outputFile << "\t     * * *                       \n\n";

        outputFile << "\tFaces               f = " << fixed << setprecision(decimal) << face << "\n";
        outputFile << "\tLength edge         l = " << fixed << setprecision(decimal) << length << "\n";
        outputFile << "\tSurface area        S = " << fixed << setprecision(decimal) << icosahedronSurfaceArea(length) << "\n";
        outputFile << "\tVolume              V = " << fixed << setprecision(decimal) << icosahedronVolume(length) << "\n";

        outputFile.close();
        cout << "\nFile: REGULARPOLYHEDRON.TXT, has been created.\n";
    }

}

// Regular Polyhedron program
void regularPolyhedron()
{
    cout << "\n\t6. Regular Polyhedron Shape\n\n";

    do
    {
        cout << "\n\tNOTE: Enter face: 0 to quit the Regular Polyhedron Shape calculation.\n";
        int face = inputInteger("\tEnter the number of face (face: 0, 4, 6, 8, 12 or 20): ", 0, true);

        if (face == 0)
            break;

        else if (face != 4 && face != 6 && face != 8 && face != 12 && face != 20)
            cout << "INVALID INPUT FOR FACE OF REGULAR POLYHEDRON SHAPE. TRY AGAIN!\n\n";

        else
        {
            switch (face)
            {
            case 4: face4(); break;
            case 6: face6(); break;
            case 8: face8(); break;
            case 12: face12(); break;
            case 20: face20(); break;
            }
        }

    } while (true);

}



