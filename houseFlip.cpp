/* Name: Bria Weisblat
Date: 11/18/2022
Section: 4
Assignment: Homework 6 Problem 2- House Flipping
Due Date: 11/18/2022
About this project: This program reads in a user entered house image, flips it, and prints that mirror image
Assumptions: Assume that the house images will be of a maximum of 500 lines, with a maximum of 500 characters each.
Assume that all the lines will be of equal length. Assume that spaces, #, , + and -produce the same character (itself) upon
mirroring, but [ becomes ], and vice versa; and / becomes\, and vice versa.

All work below was performed by Bria Weisblat */

#include <iostream>
#include <cstring>
using namespace std;

// Function declarations
void readHouse (char stringMat[][500], int numLines);
void flipHouse (char stringMat[][500], int numLines);
char printHouse(char stringMat[][500], int numLines);

int main() {

    int N;
    char stringMat[500][500];

    cout << "Enter the number of lines: ";
    cin >> N;

    cout << endl << "Enter the house image: " << endl;

    readHouse(stringMat, N);
    flipHouse(stringMat, N);
    printHouse(stringMat, N);

    return 0;
}

// Function Definitions
void readHouse (char stringMat[][500], int N ){
    // Ignores the delimeter before cin begins
    cin.ignore(1);
    // Iterate down the columns
    for (int i = 0; i < N; i++) {
        cin.getline(stringMat[i], 500);
    }
}

void flipHouse (char stringMat[][500], int N ) {
    int numChars = 0;
    // Number of characters in each row (assuming every row has the same number of characters)
    numChars = strlen(stringMat[N-1]);

    int i;
    char swapChar;
    // Iterate down the columns
    for (i = 0; i <= N; i++) {
        // Swap characters x times, x = numChars/2
        for (int j = 0; j < numChars/2; j++) {
            // Saves "left" characters so they are not overwritten
            swapChar = stringMat[i][j];
            //  Overwrites "left" indices with "right" corresponding characters
            stringMat[i][j] = stringMat[i][numChars - 1 - j];
            // Places the saved "left" characters into the corresponding "right" indices
            stringMat[i][numChars - 1 - j] = swapChar;

        }
    }

    // Iterate down the columns
    for (i = 0; i <= N; i++) {
        // Reverse every character in every row
        for (int j = 0; j < numChars; j++){
            // Reverses [,],/,\ characters
            switch (stringMat[i][j]) {

                case '[':
                    (stringMat[i][j]) = ']';
                    break;

                case ']':
                    (stringMat[i][j]) = '[';
                    break;

                case '/':
                    (stringMat[i][j]) = '\\';
                    break;

                case '\\':
                    (stringMat[i][j]) = '/';
                    break;
                default:
                    break;
            }
        }


    }
}

char printHouse(char stringMat[][500], int N) {
    int numChars = 0;
    numChars = strlen(stringMat[N-1]);

    // For each column
    cout << endl << "The mirrored house is: " << endl;
    for (int i = 0; i < N; i++) {
        // Print every element in every row
        for (int j = 0; j < numChars; j++) {
            cout <<  stringMat[i][j];
        }
        cout << endl;
    }
}

/*
  ____||____
 ///////////\
///////////  \
|    _    |  |
|[] | | []|[]|
|___|_|___|  |
 */