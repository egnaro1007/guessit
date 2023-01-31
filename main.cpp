#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void computerVShuman();
void computerVScomputer();
void play();
int generateNumber();
int compare(int number, int answer);
void showHighscore(std::string filename);
void updateHighscore(int score, std::string filename);
void readHighscore(int &score, std::string &name, std::string filename);
void writeHighscore(int &score, std::string &name, std::string filename);
void computerGuess(const int number, int left, int right);

int main() {
    std::cout << "Welcome to Guess It!" << "\n";
    std::cout << "--------------------" << "\n";
    std::cout << "1. Computer vs Human" << "\n";
    std::cout << "2. Computer vs Computer" << "\n";    
    std::cout << "3. Exit" << "\n";
    std::cout << "\n";
    std::cout << "Enter your choice: ";
    char choice;
    std::cin >> choice;
    if (choice == '1') {
        computerVShuman();
    } else if (choice == '2') {
        computerVScomputer();
    } else if (choice == '3') {
        system("cls");
        std::cout << "Goodbye! See you again." << "\n";
    }
    system("pause");
}

void computerVShuman() {
    while(true) {
            play();
        
            std::cout << "Do you want to play again? (y/n): ";
            char choice;
            std::cin >> choice;
            if (choice != 'y') {
                break;
            }
        }

        system("cls");
        std::cout << "Goodbye! See you again." << "\n";
        system("pause");
}
void computerVScomputer() {
    std::cout << "Binary search algorithm" << "\n";
    std::cout << "-----------------------" << "\n";
    int guessNumber = generateNumber();
        computerGuess(guessNumber, 1, 100);
}


void play() {
    std::string _HIGHSCOREFILE_ = "highscore.dat";

    system("cls");
    std::cout << "Guess the number!" << "\n";
    std::cout << "-----------------" << "\n";
    showHighscore(_HIGHSCOREFILE_);

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
            std::cout << "-----------------" << "\n";
            std::cout << "You win!\n";
            std::cout << "After " << count << " guess." << "\n";
            updateHighscore(count, _HIGHSCOREFILE_);
            break;
        } else if (result == 1) {
            std::cout << "Too high!" << "\n";
        } else {
            std::cout << "Too low!" << "\n";
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

void showHighscore(std::string filename) {
    int score;
    std::string name;
    readHighscore(score, name, filename);
    std::cout << "Highscore: " << score << " by " << name << "\n";
    std::cout << "Try to beat!" << "\n";
    std::cout << "-----------------" << "\n";
}
void updateHighscore(int score, std::string filename) {
    int oldScore;
    std::string oldName;
    readHighscore(oldScore, oldName, filename);

    if (score < oldScore) {
        std::string name;
        std::cout << "-----------------\n";
        std::cout << "New highscore!\nEnter your name (no space): ";
        std::cin >> name;
        writeHighscore(score, name, filename);
    }
}
void readHighscore(int &score, std::string &name, std::string filename) {
    std::ifstream file;
    file.open(filename);
    if (file.is_open()) {
        file >> score;
        file >> name;
    }
    file.close();
}
void writeHighscore(int &score, std::string &name, std::string filename) {
    std::ofstream file;
    file.open(filename);
    if (file.is_open()) {
        file << score << "\n";
        file << name;
    }
    file.close();
}


void computerGuess(const int number, int left, int right) {
    int guess = (left + right) / 2;
    int result = compare(guess, number);
    if (result == 0) {
        std::cout << "-------------------------" << "\n";
        std::cout << "Done! The number is: " << guess  << "\n";
    } else if (result == 1) {
        std::cout << "Guess: " << guess << "\t";
        std::cout << "Too high!" << "\n";
        computerGuess(number, left, guess);
    } else {
        std::cout << "Guess: " << guess << "\t";
        std::cout << "Too low!" << "\n";
        computerGuess(number, guess, right);
    }
}