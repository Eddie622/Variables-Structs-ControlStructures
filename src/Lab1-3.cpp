//============================================================================
// Name        : Lab1-3.cpp
// Author      : Heriberto Torres
// Version     : 1.0
// Copyright   : Copyright © 2017 SNHU COCE
// Description : Lab 1-3 Up to Speed in C++
//============================================================================

#include <algorithm>
#include <iostream>

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================

double strToDouble(string str, char ch);

// FIXME (1): Define a data structure to hold bid information together as a single unit of storage.
struct bidInfo{
	string title;
	string fund;
	string vehicle;
	double bidAmount;
};

// FIXME (4): Display the bid values passed in data structure
/**
 * Display the bid information
 *
 * @param ?type? data structure containing the bid info
 */
void displayBid(bidInfo SomeBidInfo) {
    cout << "Title: " << SomeBidInfo.title << endl;
    cout << "Fund: " << SomeBidInfo.fund << endl;
    cout << "Vehicle: " << SomeBidInfo.vehicle << endl;
    cout << "Bid Amount: " << SomeBidInfo.bidAmount << endl;

    return;
}

// FIXME (3): Store input values in data structure
/**
 * Prompt user for bid information
 *
 * @return data structure containing the bid info
 */
bidInfo getBid() {
    bidInfo YourBidInfo;

    cout << "Enter title: ";
    cin.ignore();
    getline(cin, YourBidInfo.title);

    cout << "Enter fund: ";
    cin >> YourBidInfo.fund;

    cout << "Enter vehicle: ";
    cin.ignore();
    getline(cin, YourBidInfo.vehicle);

    cout << "Enter amount: ";
    cin.ignore();
    string strAmount;
    getline(cin, strAmount);
    YourBidInfo.bidAmount = strToDouble(strAmount, '$');

    return YourBidInfo;
}

/**
 * Simple C function to convert a string to a double
 * after stripping out unwanted char
 *
 * credit: http://stackoverflow.com/a/24875936
 *
 * @param ch The character to strip out
 */
double strToDouble(string str, char ch) {
    str.erase(remove(str.begin(), str.end(), ch), str.end());
    return atof(str.c_str());
}


/**
 * The one and only main() method
 */
int main() {

    // FIXME (2): Declare instance of data structure to hold bid information
	bidInfo newBidInfo;

    // loop to display menu until exit chosen
    int choice = 0;
    while (choice != 9) {
        cout << "Menu:" << endl;
        cout << "  1. Enter Bid" << endl;
        cout << "  2. Display Bid" << endl;
        cout << "  9. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        // FIXME (5): Complete the method calls then test the program
        switch (choice) {
            case 1:
            	newBidInfo = getBid();
                break;
            case 2:
                displayBid(newBidInfo);
                break;
        }
    }

    cout << "Good bye." << endl;

    return 0;
}
