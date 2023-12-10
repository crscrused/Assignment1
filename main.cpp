// File Name : SanJose_PA2.cpp
// Author : John Cris San Jose
// Email Address : jcsanjose@gbox.adnu.edu.ph
// PA Number: 1

// Include necessary headers
#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int IntegersOnly();

// Main function
int main()
{
    // Declare variables
    char choice = 'a';

    // Main loop
    while (true)
    {
        // Declare variables for user inputs and calculations
        double DistanceToRim, Initialvelocity, CeilingHeight;
        double ReleaseAngle, HorizontalDistance;
        double OptimalAngleSmall, OptimalAngleLarge;
        double OptimalAngleS, OptimalAngleL;
        const double RimDiameter = 0.45;
        const double Gravity = 9.8;

        // Prompt the user for inputs
        cout << "Computing the Optimal Release Angle for a Basketball Robot" << endl;
        cout << "Enter the distance of the robot�s shooting hand from the center of the basketball rim (in meters): ";
        DistanceToRim = IntegersOnly();

        cout << "Enter the initial ball speed (in meters/second): ";
        Initialvelocity = IntegersOnly();

        cout << "Enter the height of the ceiling (in meters): ";
        CeilingHeight = IntegersOnly();

        // Optimal Angle calculation
        ReleaseAngle = .5 * asin(Gravity * DistanceToRim / pow(Initialvelocity, 2));
        ReleaseAngle = ReleaseAngle * 180.0 / M_PI; // Convert radians to degrees

        // OptimalAngle Small to large (Computations and Formula)
        OptimalAngleSmall = Gravity * (DistanceToRim - (RimDiameter / 2)) / pow(Initialvelocity, 2);
        OptimalAngleS = 0.5 * (asin(OptimalAngleSmall) * 180 / M_PI); // Convert radians to degrees
        OptimalAngleLarge = Gravity * (DistanceToRim + (RimDiameter / 2)) / pow(Initialvelocity, 2);
        OptimalAngleL = 0.5 * (asin(OptimalAngleLarge) * 180 / M_PI); // Convert radians to degrees

        // MaxHeight calculation                                            Converts degrees to radian (M_PI / 180)
        double MaxHeight = pow(Initialvelocity, 2) * pow(sin(ReleaseAngle * M_PI / 180), 2) / (2 * Gravity);
        // Display the results
        cout << "\nHere are the results..." << endl;
        cout << "The optimal angle to launch the ball is " << fixed << setprecision(3) << ReleaseAngle << " degrees." << endl;
        cout << "Smallest angle to make the shot is " << fixed << setprecision(3) << OptimalAngleS << " degrees." << endl;
        cout << "Largest angle to make the shot is " << fixed << setprecision(3) << OptimalAngleL << " degrees." << endl;
        cout << "The basketball will reach a maximum height of " << fixed << setprecision(3) << MaxHeight << " meters." << endl;

        // Check if the maximum trajectory is greater than the height of the ceiling
        if (MaxHeight >= CeilingHeight)
        {
            cout << "The basketball will hit the ceiling." << endl;
        }
        else
        {
            cout << "The basketball will not hit the ceiling." << endl;
        }

        // Prompt user to repeat or exit
        cout << "\nPress any key to do this again, press 'X' or 'x' to exit." << endl;
        cin >> choice;
        if (choice == 'X' || choice == 'x')
        {
            break;
        }
    }
    // Exit the program
    return 0;
}

int IntegersOnly()
{
    int Number;
    while (!(cin >> Number))
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Invalid Input. Enter Numbers Only: ";
    }
    return Number;
}
