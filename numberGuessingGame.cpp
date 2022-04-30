// Copyright (c) 2022 Miguel Santacruz All rights reserved
//
// Created by: Miguel Santacruz
// Created on: Apr 2022
// This program is a number guessing game

#include <iostream>
#include <string>
#include <random>

int main() {
    // This function checks the number
    int number;
    std::string numberAsString;
    int someRandomNumber;
    float decimal;

    while (true) {
        std::random_device rseed;
        std::mt19937 rgen(rseed());  // mersenne_twister
        std::uniform_int_distribution<int> idist(0, 9);  // [0, 9]
        someRandomNumber = idist(rgen);

        // Input
        std::cout << "Enter a number between 0 - 9: ";
        std::cin >> numberAsString;

    // Process & Output
        try {
        number = std::stoi(numberAsString);
        decimal = std::stof(numberAsString);
        if (number != decimal) {
            std::cout << decimal << " is not an integer. Try again."
            << std::endl;
            std::cout << std::endl;
        } else if (number < 0) {
            std::cout << number << " is not positive. Try again." << std::endl;
            std::cout << std::endl;
        } else if (number > 9) {
            std::cout << number << " is out of range. Try again." << std::endl;
            std::cout << std::endl;
        } else if (number == someRandomNumber) {
            std::cout << "You guessed right!" << std::endl;
            break;
        } else {
            std::cout << "You guessed wrong. The right answer was "
            << someRandomNumber << ". Try again." << std::endl;
            std::cout << std::endl;
        }
        } catch (std::invalid_argument) {
            std::cout << numberAsString << " is not a number. Try again."
            << std::endl;
            std::cout << std::endl;
        }
    }

std::cout << "\nDone" << std::endl;
}
