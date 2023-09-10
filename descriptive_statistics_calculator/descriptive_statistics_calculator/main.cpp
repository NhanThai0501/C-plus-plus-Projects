using namespace std;
#include <iostream>
#include <iomanip>
#include <ctime>
#include <string>
#include <fstream>
#include <vector>
#include "input.h"
#include "SearchAndSort.h"

// function prototypes
const int MAX_SIZE = 150; // global variable

int menuOption(int& option);
void GenerateDataFile(string& fileName);
void ReadDataFromFile(string fileName, int dataset[MAX_SIZE], int& size);
void Displaydataset(const int dataset[MAX_SIZE], int size);
void DisplayStatisticsdataset(const int dataset[MAX_SIZE], int size);
void WriteDescriptiveStatisticsToFile(const int dataset[MAX_SIZE], int size);
int mostFrequent(const int arr[], int n);

int main()
{
    // Initialize the variables
    string fileName;
    int dataset[MAX_SIZE] = { 0 };
    int size = 0;

    cout << "\n\tDescriptive statistics summarize certain aspects of a data set sample using\n";
    cout << "\n\tnumeric calculations. This calculator generates Minimum, Maximum, Range, Size,\n";
    cout << "\n\tSum, Mean, Median, Mode, and Standard Deviation of data set.\n\n";
    do
    {
        int option;
        do
        {
            cout << "\n\tDescriptive Statistics Calculator";
            cout << "\n\t" + string(60, char(205));
            cout << "\n\t  1. Generate a data file with random data values                                ";
            cout << "\n\t  2. Read data values from the file and store into the dataset                   ";
            cout << "\n\t  3. Diplay all data values from the dataset                                     ";
            cout << "\n\t  4. Display the descriptive statistics of the dataset                           ";
            cout << "\n\t  5. Write the descriptive statistics of the dataset to a file                   ";
            cout << "\n\t" + string(60, char(196));
            cout << "\n\t  0. Quit";
            cout << "\n\t" + string(60, char(205));

            switch (menuOption(option))
            {
            case 0: exit(0); break;
            case 1: GenerateDataFile(fileName); size = 0; break;
            case 2: ReadDataFromFile(fileName, dataset, size); break;
            case 3: Displaydataset(dataset, size); break;
            case 4: DisplayStatisticsdataset(dataset, size);  break;
            case 5: WriteDescriptiveStatisticsToFile(dataset, size); break;
            }
        } while (true);
    } while (true);
    return 0;
}

// Ask user to input the choice to run the program
int menuOption(int& option)
{
    option = inputInteger("\n\tOption: ", 0, 5);
    cin.clear();
    cin.ignore();
    return option;
}

// option 1 
void GenerateDataFile(string& fileName)
{
    srand(time(0));
    int dataset[MAX_SIZE] = { 0 };
    int size = rand() % 100 + 1;

    cout << "\n\tEnter the file name to store random generated date: ";
    getline(cin, fileName);
    fileName += ".txt";

    // Generate random number in txt file
    ofstream outputFile;
    outputFile.open(fileName);

    for (int i = 0; i < size; i++)
    {
        int randomNumber = rand() % 100 + 1;
        outputFile << randomNumber << "\n";
    }

    outputFile.close();

    cout << "\n\tOutput " << fileName << " has been generated with " << size << " random numbers\n";
}

// option 2
void ReadDataFromFile(string fileName, int dataset[MAX_SIZE], int& size)
{

    size = 0;
    if (fileName == "")
    {
        cout << "\n\tERROR: Data file has not specified and generated.\n";
    }
    else
    {

        ifstream inputFile;
        inputFile.open(fileName);

        // Read data from the file that has created in option 1
        while (!(inputFile.eof()))
        {
            inputFile >> dataset[size];
            if (inputFile.eof())
                break;
            size++;
        }

        inputFile.close();
        cout << "\n\tInput " << fileName << " has been read in and " << size << " numbers have been stored into dataset.\n";

        // Sorting the dataset before reaching option 3
        selectionSort(dataset, size);

    }
}

// option 3
void Displaydataset(const int dataset[MAX_SIZE], int size)
{
    string fileName = "";
    if (size == 0)
    {
        cout << "\n\tERROR: Dataset is empty with no stored numbers.\n";
    }
    else
    {
        cout << "\n\tDataset: ";
        // Print out all value in dataset on screen
        for (int i = 1; i < size; i++)
        {
            cout << dataset[i] << ", ";
        }
        cout << "\n\n";

    }

}

// option 4
void DisplayStatisticsdataset(const int dataset[MAX_SIZE], int size)
{

    // Initialize the variables
    int range = 0;
    int sum = 0;
    double mean = 0;
    double medianEven;
    int index;
    double deviation = 0;

    // Check the conditions
    if (size == 0)
    {
        cout << "\n\tERROR: Cannot display statistics of dataset. Data has not been read into dataset.\n";
    }
    else
    {
        // Output value
        cout << "\n\n\tDescriptive Statistics: \n";
        cout << "\tMinimum               = " << dataset[0] << "\n";
        cout << "\tMaximum               = " << dataset[size - 1] << "\n";
        range = dataset[size - 1] - dataset[0];
        cout << "\tRange                 = " << range << "\n";
        cout << "\tSize                  = " << size << "\n";

        for (int i = 0; i < size; i++)
        {
            sum += dataset[i];
        }
        cout << "\tSum                   = " << sum << "\n";
        mean = static_cast<double>(sum) / static_cast<double>(size);
        cout << "\tMean                  = " << mean << "\n";

        // Check whether 'size' is odd or even to calculate 'median'
        if (size % 2 != 0)
        {
            index = (size - 1) / 2;
            cout << "\tMedian                = " << dataset[index] << "\n";
        }
        if (size % 2 == 0)
        {
            index = size / 2;
            medianEven = static_cast<double>((dataset[index] + dataset[index - 1])) / 2.0;
            cout << "\tMedian                = " << medianEven << "\n";
        }

        cout << "\tMode                  = " << mostFrequent(dataset, size) << "\n";

        // Calculate standard deviation 
        int bottom = size - 1;
        double top = 0;

        for (int i = 0; i < size; i++)
        {
            top += pow((dataset[i] - mean), 2.0);
        }

        deviation = static_cast<double>(sqrt(top / bottom));
        cout << "\tStandard Deviation    = " << deviation << "\n";

    }
}

// option 5
void WriteDescriptiveStatisticsToFile(const int dataset[MAX_SIZE], int size)
{
    string fileName;
    int range = 0;
    int sum = 0;
    double mean = 0;
    double medianEven;
    int index;
    double deviation = 0;

    // Check the conditions
    if (size == 0)
    {
        cout << "\n\tERROR: Cannot write statistics of dataset to a file. Data have not been read into dataset.\n";
    }
    else
    {
        cout << "\n\tEnter the file name to Write the descriptive statistics of the dataset: ";
        getline(cin, fileName);
        fileName += ".txt";

        // Output all data and information on new file txt
        ofstream outputFile;
        outputFile.open(fileName);

        outputFile << "\tDateset: ";
        for (int i = 0; i < size; i++)
        {
            outputFile << dataset[i] << " ";
        }

        outputFile << "\n\n\tDescriptive Statistics: \n";
        outputFile << "\tMinimum               = " << dataset[0] << "\n";
        outputFile << "\tMaximum               = " << dataset[size - 1] << "\n";
        range = dataset[size - 1] - dataset[0];
        outputFile << "\tRange                 = " << range << "\n";
        outputFile << "\tSize                  = " << size << "\n";

        for (int i = 0; i < size; i++)
        {
            sum += dataset[i];
        }
        outputFile << "\tSum                   = " << sum << "\n";
        mean = static_cast<double>(sum) / static_cast<double>(size);
        outputFile << "\tMean                  = " << mean << "\n";

        if (size % 2 != 0)
        {
            index = (size - 1) / 2;
            outputFile << "\tMedian                = " << dataset[index] << "\n";
        }
        if (size % 2 == 0)
        {
            index = size / 2;
            medianEven = static_cast<double>((dataset[index] + dataset[index - 1])) / 2.0;
            outputFile << "\tMedian                = " << medianEven << "\n";
        }

        outputFile << "\tMode                  = " << mostFrequent(dataset, size) << "\n";

        // Calculate standard deviation 
        int bottom = size - 1;
        double top = 0;

        for (int i = 0; i < size; i++)
            top += pow((dataset[i] - mean), 2.0);

        deviation = static_cast<double>(sqrt(top / bottom));
        outputFile << "\tStandard Deviation    = " << deviation << "\n";

        outputFile.close();

        cout << "\n\tOutput ," << fileName << " has been created. \n";
    }
}

// function to indicate which value appears frequently
int mostFrequent(const int arr[], int n)
{

    // find the max frequency using linear traversal 
    int max_count = 1, res = arr[0], curr_count = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1])
            curr_count++;
        else {
            if (curr_count >= max_count) {
                max_count = curr_count;
                res = arr[i - 1];
            }
            curr_count = 1;
        }
    }

    // If last element is most frequent 
    if (curr_count >= max_count)
    {
        max_count = curr_count;
        res = arr[n - 1];
    }

    return res;
}