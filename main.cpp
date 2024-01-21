#include <iostream>
#include <ctime>

char getUserChoice();

char getComputerChoice();

void showChoice(char choice);

void chooseWinner(char player, char computer);

char askToContinue();

int main() {
    char player;
    char computer;
    char continueGame;

    do {
        player = getUserChoice();
        std::cout << "\nUser Choice: ";
        showChoice(player);

        computer = getComputerChoice();
        std::cout << "Computer Choice: ";
        showChoice(computer);

        chooseWinner(player, computer);

        continueGame = askToContinue();
    } while (continueGame == 'y' || continueGame == 'Y');

    return 0;
}


char getUserChoice() {
    char player;
    std::cout << "-----------------------------------" << std::endl;
    std::cout << "Rock-Paper-Scissors Game!" << std::endl;
    std::cout << "-----------------------------------" << std::endl;

    do {
        std::cout << "Choose one of the following: " << std::endl;
        std::cout << "'r' for rock" << std::endl;
        std::cout << "'p' for paper" << std::endl;
        std::cout << "'s' for scissors" << std::endl;
        std::cin >> player;

    } while (player != 'r' && player != 'p' && player != 's');

    return player;
}

char getComputerChoice() {
    srand(time(0));
    int num = rand() % 3 + 1;

    switch (num) {
        case 1:
            return 'r';
        case 2:
            return 'p';
        case 3:
            return 's';
    }

}

void showChoice(char choice) {
    switch (choice) {
        case 'r':
            std::cout << "Rock" << std::endl;
            break;
        case 'p':
            std::cout << "Paper" << std::endl;
            break;
        case 's':
            std::cout << "Scissors" << std::endl;
            break;
        default:
            std::cout << "I N V A L I D" << std::endl;
            break;
    }

}

void chooseWinner(char player, char computer) {
    switch (player) {
        case 'r':
            if (computer == 'r') {
                std::cout << "It's a tie!" << std::endl;
            } else if (computer == 'p') {
                std::cout << "You lose!" << std::endl;
            } else {
                std::cout << "You Win!" << std::endl;
            }
            break;
        case 'p':
            if (computer == 'r') {
                std::cout << "You Win!" << std::endl;
            } else if (computer == 'p') {
                std::cout << "It's a tie!" << std::endl;
            } else {
                std::cout << "You lose!" << std::endl;
            }
            break;
        case 's':
            if (computer == 'r') {
                std::cout << "You lose!" << std::endl;
            } else if (computer == 'p') {
                std::cout << "You Win!" << std::endl;
            } else {
                std::cout << "It's a tie!" << std::endl;
            }
            break;
        default:
            std::cout << "I N V A L I D" << std::endl;
            break;
    }

}

char askToContinue() {
    char response;
    std::cout << "Would you like to continue playing? (y/n): ";
    std::cin >> response;
    return response;
}
