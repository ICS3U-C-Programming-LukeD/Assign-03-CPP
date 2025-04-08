// Copyright (c) 2025 Luke Di Bert All rights reserved.
//
// Created by: Luke Di Bert
// Date: April 8, 2025
//
// This program calculates the fine
// and gives a message depending on the user's speed.

// adds math library
#include <cmath>

// adds iomanip library for rounding
#include <iomanip>

// adds iostream library
#include <iostream>

// adds string library
#include <string>

int main() {
    std::string userSpeedString;
    int speedLimit = 60;

    std::cout << "The speed limit in the zone is 60 km/h. "
                 "What is your current speed? (km/h): ";
    std::cin >> userSpeedString;

    try {
        int userSpeedInt = std::stoi(userSpeedString);
        int overSpeed = userSpeedInt - speedLimit;
        float fine = 0;

        // Calculates fine and
        // message depending on user's speed
        if (userSpeedInt <= speedLimit) {
            std::cout << "You are within the speed limit. Good job!"
                      << std::endl;
        } else if (overSpeed >= 1 && overSpeed <= 20) {
            std::cout << "Warning! Please slow down." << std::endl;
        } else if (overSpeed >= 21 && overSpeed <= 30) {
            fine = overSpeed * 4.50;
            std::cout << "Your fine is $" << std::fixed
                      << std::setprecision(2) << fine << std::endl;
        } else if (overSpeed >= 31 && overSpeed <= 50) {
            fine = overSpeed * 7;
            std::cout << "Due to higher speeds your fine is $"
                      << std::fixed << std::setprecision(2) << fine
                      << std::endl;
        } else {  // overSpeed > 50
            std::cout << "Due to extreme speeds your license has been "
                         "suspended for 30 days."
                      << std::endl;
        }

        // Nested if statements that display different outro messages
        // depending on your speed before
        if (overSpeed <= 0) {
            std::cout << "Thanks for being a safe driver!" << std::endl;
        } else {
            if (overSpeed <= 20) {
                std::cout << "Remember, even small speeding can be dangerous!"
                          << std::endl;
            } else if (overSpeed <= 30) {
                std::cout << "Pay attention to speed signs next time!"
                          << std::endl;
            } else if (overSpeed <= 50) {
                std::cout << "You were going way too fast, "
                             "slow down next time!"
                          << std::endl;
            } else {
                std::cout << "That was reckless driving! Be careful."
                          << std::endl;
            }
        }
    } catch (std::invalid_argument) {
        std::cout << userSpeedString << " wasn't a valid integer."
                  << std::endl;
    }

    // Program outro message
    std::cout << "Thank you for using this program!" << std::endl;
}
