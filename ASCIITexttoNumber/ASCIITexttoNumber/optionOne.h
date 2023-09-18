// optionOne.h

#ifndef	OPTIONONE_LOCK
#define OPTIONONE_LOCK

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

//PreCondition: input is type string
//PostCondition: returns a string of ACSII numbers converted from string input
std::string asciiConverter(std::string userInput)
{
	std::string temp = "";
	for (int i = 0; i < userInput.length(); i++)
	{
		temp += std::to_string(int(userInput[i])) + " ";
	}
	return temp;
}

//PreCondition: input is type string
//PostCondition: saves content of string input to file called "test.bin"
void saveToFile(std::string inputText)
{
	
	ofstream outfile("test.bin", ofstream::binary);
	int size = inputText.size();
	outfile.write(reinterpret_cast<char*>(&size), sizeof(size));
	outfile.write(inputText.c_str(), inputText.size());
	outfile.close();
}

//PreCondition: NA
//PostCondition: returns a string of contents in file "test.bin" if file exists
std::string readFromFile(void)
{
	ifstream inFile("test.bin", ios::in | ios::binary);
	if (!inFile) return "cannot open file";
	int size = 0;
	char* buffer;
	std::string returnText = "";

	inFile.read(reinterpret_cast<char*>(&size), sizeof(int));
	buffer = new char[size];
	inFile.read(buffer, size);
	returnText.append(buffer, size);

	return returnText;
}

//PreCondition: input is type string
//PostCondition: displays output of input string, error if string is empty
void displayAscii(std::string asciiString)
{
	if (asciiString == "") std::cout << "\n\t\t\tERROR: empty input text." << std::endl;
	else
	{
		std::cout << "\n\t\t\tConverted to ASCII numbers:" << std::endl;
		std::cout << "\t\t\t" + asciiString << std::endl;
	}
}

//PreCondition: input is type string
//PostCondition: displays output of input string, error if string is empty
void displaySaveToFile(std::string inputText)
{
	if (inputText == "") std::cout << "\n\t\t\tERROR: empty binary text." << std::endl;
	else
	{
		saveToFile(inputText);
		std::cout << "\n\t\t\tFile, test.bin, has been written and saved." << std::endl;
	}
}

//PreCondition: NA
//PostCondition: displays output of "test.bin" file, error if file does not exist
void displayReadFromFile(void)
{
	std::string textFromFile = readFromFile();
	if (textFromFile == "cannot open file") std::cout << "\n\t\t\tERROR: Cannot open file, test.bin." << std::endl;
	else
	{
		std::cout << "\n\t\t\tReading file, test.bin...";
		std::cout << "\n\t\t\t" + textFromFile << std::endl;
	}
}

#endif
