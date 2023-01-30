#include <iostream>
#include <cstdlib>
#include <ctime>

void play();
int generateNumber();
int compare(int number, int answer);

int main() {
    while(true) {
        play();
    
        std::cout << "Do you want to play again? (y/n): ";
        char choice;
        std::cin >> choice;
        if (choice != 'y') {
            break;
        }
    }
}

void play() {
    int answer = generateNumber();
    int count = 0;

    bool playing = true;    
    while (playing) {
        int number;
        std::cout << "Enter a number: ";
        std::cin >> number;

        count++; 
        int result = compare(number, answer);
        if (result == 0) {
            std::cout << "You win!\nAfter " << count << " guess." << std::endl;
            break;
        } else if (result == 1) {
            std::cout << "Too high!" << std::endl;
        } else {
            std::cout << "Too low!" << std::endl;
        }
    }
}

int compare(int number, int answer) {
    if (number == answer) {
        return 0;
    } else if (number > answer) {
        return 1;
    } else {
        return -1;
    }
}

int generateNumber() {
    srand(time(NULL));
    int number;
    number = rand() % 100 + 1;
    return number;
}