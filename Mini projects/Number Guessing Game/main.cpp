#include <iostream>
#include <random> // for the generation of a random number

bool target_is_greater(int, int);

int main() {
    int generated_number;
    int guess;

    // Create a random number generator :
    std::random_device rd;  // Seed for random number generator
    std::mt19937 gen(rd()); // Mersenne Twister engine
    std::uniform_int_distribution<> distr(0, 100); // Define the range
    // Generate a random integer between 0 and 100
    generated_number = distr(gen);
    //

    std::cout << "Hi ! Let's play a number guessing game." << std::endl;
    std::cout << "I generated a random number between 0 and 100 included.";
    std::cout << "Please enter your guess between 0 and 100 included : " << std::endl;
    while (std::cin >> guess) {
        std::cout << "You entered : " << guess << std::endl;
        if (guess < 0 or guess > 100) {
            std::cout << "You did not enter a number between 0 and 100." << std::endl;
            std::cout << "End of the game." << std::endl;
            return 1;
        }
        else if (guess == generated_number) {
            std::cout << "Bravo ! You found the right number : " << generated_number << std::endl;
            return 0;
        }
        else {
            if (target_is_greater(guess, generated_number)) {
                std::cout << "The target number is greater than your guess." << std::endl;
            }
            else {
                std::cout << "The target number is less than your guess." << std::endl;
            }
        }
    }
}

bool target_is_greater(int guess, int target) {
    if (guess < target) {
        return true;
    }
    else {
        return false;
    }
}
