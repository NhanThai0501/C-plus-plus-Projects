#include <iostream>
#include <string>
#include "input.h"
#include "optionOne.h"

using namespace std;

void displayOptionOneMenu(void);

int main()
{
    string userStringInput = "";
    string asciiString = "";

    displayOptionOneMenu();

    do
    {
        int option = inputChar("\n\t\t\tOption: ");

        switch (option)
        {
        case '0': exit(1);  break;
        case 'a': case 'A': userStringInput = inputString("\n\t\t\tEnter a text line: ", true); displayOptionOneMenu(); break;
        case 'b': case 'B': asciiString = asciiConverter(userStringInput);
            displayAscii(asciiString); displayOptionOneMenu(); break;
        case 'c': case 'C': displaySaveToFile(asciiString); displayOptionOneMenu(); break;
        case 'd': case 'D': displayReadFromFile(); displayOptionOneMenu(); break;
        default: cout << "\t\tERROR-1A: Invalid input. Must be '0','A','B','C', or 'D'"; continue;
        }
    } while (true);

    return 0;
}

//PreCondition: NA
//PostCondition: displays option one menu options
void displayOptionOneMenu(void)
{
    cout << "\n\t\t1> ASCII Text To ASCII Numbers" << endl;
    cout << "\t\t" + string(70, char(205)) << endl;
    cout << "\t\t\tA> Enter a text string" << endl;
    cout << "\t\t\tB> Convert the text string to ASCII numbers" << endl;
    cout << "\t\t\tC> Save the converted ASCII numbers into a binary file" << endl;
    cout << "\t\t\tD> Read the binary file" << endl;
    cout << "\t\t" + string(70, char(196));
    cout << "\n\t\t\t0> return" << endl;
    cout << "\t\t" + string(70, char(205));
}