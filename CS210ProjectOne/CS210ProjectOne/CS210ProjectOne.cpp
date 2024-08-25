/*
Date: 7/14/2024
Author: Jonathon Davis 

        This program displays two clocks, one with military time, and one twelve hour clock. The user has a menu where they can add an hour, minute, second, or exit. 

*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// 12-hour clock variables
int hour12 = 12;
int minute12 = 0;
int second12 = 0;

// 24-hour clock variables
int hour24 = 0;
int minute24 = 0;
int second24 = 0;

// Boolean to alternate between AM and PM
bool PM = false;

// Function to add one hour to both clocks
void addHour() {
    // Update 12-hour clock
    hour12++;
    if (hour12 > 12) {
        hour12 = 1;
    }
    if (hour12 == 12) {
        PM = !PM;  // Toggle AM/PM when it becomes 12
    }

    // Update 24-hour clock
    hour24++;
    if (hour24 >= 24) {
        hour24 = 0;
    }
}

// Function to add one minute to both clocks
void addMinute() {
    // Update 12-hour clock
    minute12++;
    if (minute12 >= 60) {
        minute12 = 0;
        addHour();  // Add an hour if minutes overflow
    }

    // Update 24-hour clock
    minute24++;
    if (minute24 >= 60) {
        minute24 = 0;
        addHour();  // Add an hour if minutes overflow
    }
}

// Function to add one second to both clocks
void addSecond() {
    second12++;
    if (second12 >= 60) {
        second12 = 0;
        minute12++;
        if (minute12 >= 60) {
            minute12 = 0;
            hour12++;
            if (hour12 > 12) {
                hour12 = 1;
            }
            if (hour12 == 12) {
                PM = !PM;  // Toggle AM/PM when it becomes 12
            }
        }
    }
    second24++;
    if (second24 >= 60) {
        second24 = 0;
        minute24++;
        if (minute24 >= 60) {
            minute24 = 0;
            hour24++;
            if (hour24 >= 24) {
                hour24 = 0;
            }
        }
    }
}

// Function to display both of the clocks 
void displayClocks() {
    // Display headers
    cout << "**************************        **************************\n";
    cout << "*      12-Hour Clock     *        *     24-Hour Clock      *\n";
    cout << "*        ";

    // Display 12-hour clock
    cout << setfill('0') << setw(2) << hour12 << ":"
        << setfill('0') << setw(2) << minute12 << ":"
        << setfill('0') << setw(2) << second12 << " "
        << (PM ? "PM" : "AM");
    cout << "     *        ";

    // Display 24-hour clock
    cout << "*         ";
    cout << setfill('0') << setw(2) << hour24 << ":"
        << setfill('0') << setw(2) << minute24 << ":"
        << setfill('0') << setw(2) << second24;
    cout << "       *\n";

    // Display footers
    cout << "**************************        **************************\n";
}

// Function to display the menu to the user
void displayMenu() {
    cout << "**************************\n";
    cout << "*    1 - Add One Hour    *\n";
    cout << "*    2 - Add One Minute  *\n";
    cout << "*    3 - Add One Second  *\n";
    cout << "*    4 - Exit            *\n";
    cout << "**************************\n";
}

int main()
{
    int choice;

    do {
        // Displays the clock and menu
        displayClocks();
        displayMenu();

        //Get user input
        cin >> choice;

        // Decision tree depending on user choice
        if (choice == 1) {
            addHour();
        }
        else if (choice == 2) {
            addMinute();
        }
        else if (choice == 3) {
            addSecond();
        }
        else if (choice == 4) {
            cout << "Exiting program";
        }
        else {
            cout << "Invalid choice";
        }
    } while (choice != 4); // Loops until user chooses 4
    return 0;
}

