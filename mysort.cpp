//Krisha Hemani
// Class (CECS 325)
// Project Name (Prog 3 - BubbleSort)
// Due Date (03/12/2024)
//
// I certify that this program is my own original work. I did not copy any part of this program// from any other source. I further certify that I typed each and every line of code in this
// program
//mysort.cpp
#include <iostream>
#include <fstream>

using namespace std;

void bubble(int A[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (A[j] > A[j + 1]) {
                // Swap A[j] and A[j+1]
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " input_file output_file" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Error: Unable to open input file " << argv[1] << endl;
        return 1;
    }

    ofstream outputFile(argv[2]);
    if (!outputFile) {
        cerr << "Error: Unable to create output file " << argv[2] << endl;
        return 1;
    }

    const int MAX_SIZE = 1000000;
    int numbers[MAX_SIZE];
    int count = 0;

    // Read numbers from input file
    while (inputFile >> numbers[count]) {
        count++;
    }

    // Sort the numbers
    bubble(numbers, count);

    // Write sorted numbers to output file
    for (int i = 0; i < count; ++i) {
        outputFile << numbers[i] << endl;
    }

    cout << "Sorted numbers written to " << argv[2] << endl;

    return 0;
}// mysort.cpp
