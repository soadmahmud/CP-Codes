#include <iostream>
#include <random>

int main() {
    // Seed the random number generator with the current time
    std::random_device rd;
    std::mt19937 gen(rd());

    int n;

    std::cin >> n;

    while(n--)
    {

        // Define the range for the random number
        int minNumber = 1;
        int maxNumber = 1000;

        // Generate a random number
        std::uniform_int_distribution<int> dist(minNumber, maxNumber);
        int randomNumber = dist(gen);

        // Print the random number
        std::cout << "Random Number: " << randomNumber << std::endl;
    }

    return 0;
}