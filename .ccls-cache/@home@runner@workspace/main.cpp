#include <iostream>
#include <string>
#include <limits>
#include <random> 
#include <algorithm> 
using namespace std;
const int ROCK = 1;
const int PAPER = 2;
const int SCISSORS = 3;
const int QUIT = 0;
const int WIN_LIMIT = 3; 
int getComputerChoice() {
    random_device randomEngine;
    uniform_int_distribution<int> distribution(ROCK, SCISSORS);
    return distribution(randomEngine);
}

string choiceToString(int choice) {
    if (choice == ROCK) return "ROCK";
    if (choice == PAPER) return "PAPER";
    if (choice == SCISSORS) return "SCISSORS";
    return "QUIT"; 
}

int getHumanChoice() {
    string input;
    int choice = -1;
    while (choice == -1) {
        cout << "\nEnter your choice (R)ock, (P)aper, (S)cissors, or (Q)uit: ";
        if (!(cin >> input)) {
            cout << "Input error. Exiting." << endl;
            return QUIT;
        }

       
        if (!input.empty()) {
            transform(input.begin(), input.end(), input.begin(), ::toupper);
        }

        if (input == "R") {
            choice = ROCK;
        } else if (input == "P") {
            choice = PAPER;
        } else if (input == "S") {
            choice = SCISSORS;
        } else if (input == "Q") {
            choice = QUIT;
        } else {
            cout << "Invalid input. Please enter R, P, S, or Q." << endl;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    return choice;
}

char determineWinner(int compChoice, int humanChoice) {
    if (compChoice == humanChoice) {
        return 'D';
    }

    if ((humanChoice == PAPER && compChoice == ROCK) ||
        (humanChoice == SCISSORS && compChoice == PAPER) ||
        (humanChoice == ROCK && compChoice == SCISSORS)) {
        return 'H';
    }

    return 'C';
}

void updateScore(char winner, int &humanScoreRef, int &compScoreRef, int &drawsRef) {
    cout << "--- Round Result ---" << endl;
    if (winner == 'H') {
        humanScoreRef++;
        cout << "Human wins the round!" << endl;
    } else if (winner == 'C') {
        compScoreRef++;
        cout << "Computer wins the round!" << endl;
    } else {
        drawsRef++;
        cout << "The round is a DRAW." << endl;
    }
    cout << "--------------------" << endl;
}

void declareTournamentWinner(int humanScore, int compScore) {
    cout << "\n======================================" << endl;
    cout << "         TOURNAMENT COMPLETE          " << endl;
    cout << "======================================" << endl;

    if (humanScore >= WIN_LIMIT && humanScore > compScore) {
        cout << "CONGRATULATIONS! YOU WIN THE TOURNAMENT!" << endl;
    } else if (compScore >= WIN_LIMIT && compScore > humanScore) {
        cout << "GAME OVER. THE COMPUTER WINS THE TOURNAMENT!" << endl;
    } else if (humanScore == compScore) {
         cout << "The tournament ends in a TIE!" << endl;
    } else {
        cout << "Tournament ended early (Quit/Error)." << endl;
    }

    cout << "Final Score: Human " << humanScore << " - " << compScore << " Computer" << endl;
    cout << "======================================" << endl;
}


int main() {
    int humanScore = 0;
    int compScore = 0;
    int draws = 0;

    cout << "=================================================" << endl;
    cout << "        ROCK, PAPER, SCISSORS TOURNAMENT         " << endl;
    cout << "=================================================" << endl;
    cout << "The first player to reach " << WIN_LIMIT << " wins takes the tournament." << endl;
    cout << "Current Score: Human " << humanScore << " - " << compScore << " Computer" << endl;
    while (humanScore < WIN_LIMIT && compScore < WIN_LIMIT) {
        int humanChoice = getHumanChoice();
        if (humanChoice == QUIT) {
            cout << "\nGame quit by user." << endl;
            break; 
        }

        int compChoice = getComputerChoice();

        cout << "\nHuman chooses: " << choiceToString(humanChoice) << endl;
        cout << "Computer chooses: " << choiceToString(compChoice) << endl;
        char winner = determineWinner(compChoice, humanChoice);
        updateScore(winner, humanScore, compScore, draws);
        cout << "\nTournament Score: Human " << humanScore
             << " | Computer " << compScore
             << " | Draws " << draws << endl;
        cout << "------------------------------------------" << endl;
    }
    declareTournamentWinner(humanScore, compScore);

    return 0;
}
