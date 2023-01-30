#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

void play();
int generateNumber();
int compare(int number, int answer);
void showHighscore(std::string filename);
void updateHighscore(int score, std::string filename);
void readHighscore(int &score, std::string &name, std::string filename);
void writeHighscore(int &score, std::string &name, std::string filename);

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

    system("cls");
    std::cout << "Goodbye! See you again." << std::endl;
    system("pause");
}

void play() {
    std::string _HIGHSCOREFILE_ = "highscore.dat";

    system("cls");
    std::cout << "Guess the number!" << std::endl;
    std::cout << "-----------------" << std::endl;
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
            std::cout << "-----------------" << std::endl;
            std::cout << "You win!\n";
            std::cout << "After " << count << " guess." << std::endl;
            updateHighscore(count, _HIGHSCOREFILE_);
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

void showHighscore(std::string filename) {
    int score;
    std::string name;
    readHighscore(score, name, filename);
    std::cout << "Highscore: " << score << " by " << name << std::endl;
    std::cout << "Try to beat!" << std::endl;
    std::cout << "-----------------" << std::endl;
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
        file << score << std::endl;
        file << name;
    }
    file.close();
}