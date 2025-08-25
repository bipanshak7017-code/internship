#include <iostream>
#include <cstdlib>  
#include <ctime>     
using namespace std;

int main() {
    
    srand(time(0));

    int numberToGuess = rand() % 100 + 1;  
    int guess = 0;
    int attempts = 0;

    cout << " Welcome to the Number Guessing Game!" << endl;
    cout << "I have chosen a number between 1 and 100." << endl;
    cout << "Try to guess it!" << endl;

    
    while (guess != numberToGuess) {
        cout << "Enter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > numberToGuess) {
            cout << "Too high! Try again." << endl;
        } else if (guess < numberToGuess) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "🎉 Congratulations! You guessed the number in " 
                 << attempts << " attempts." << endl;
        }
    }

    return 0;
}
