#include <iostream>

int main() {
    std::cout << "Hello! Let's play a game." << std::endl;
    std::cout << "You have 10 cards, you play versus the machine and at each turn, you can remove 3 or 4 cards." << std::endl;
    std::cout << "The player who has to play and there is no card left looses." << std::endl;
    std::cout << std::endl;

    bool is_finished = false;
    int nb_of_cards = 10;
    bool human_turn = true;
    bool player_wins = true;

    while (is_finished == false) {
        if (human_turn) {
            int player_choice;
            std::cout << "Your turn ! Please enter a valid (3 or 4) number of cards you want to remove knowing that there are still " << nb_of_cards << " cards left : " << std::endl;
            std::cin >> player_choice;
            if (player_choice == 3) {
                if (nb_of_cards >= 3) {
                    nb_of_cards = nb_of_cards - 3;
                    std::cout << "There are still " << nb_of_cards << " cards left." << std::endl;
                }
                else {
                    std::cout << "Game ends !! YOU LOST" << std::endl;
                    is_finished = true;
                    player_wins = false;
                }
            }
            else if (player_choice == 4) {
                if (nb_of_cards >= 4) {
                    nb_of_cards = nb_of_cards - 4;
                    std::cout << "There are still " << nb_of_cards << " cards left." << std::endl;
                    std::cout << std::endl;
                }
                else {
                    std::cout << "Game ends !! YOU LOST" << std::endl;
                    is_finished = true;
                    player_wins = false;
                }
            }
            else {
                std::cout << "You have to enter a valid number !";
                is_finished = true;
            }
            human_turn = false;
        }
        else {
            std::cout << "Machine is playing... " << std::endl;
            human_turn = true;
            if (nb_of_cards == 7) {
                nb_of_cards = nb_of_cards - 3;
                std::cout << "There are still " << nb_of_cards << " cards left." << std::endl;
                std::cout << std::endl;
            }
            else if (nb_of_cards == 6) {
                nb_of_cards = nb_of_cards - 4;
                std::cout << "There are still " << nb_of_cards << " cards left." << std::endl;
                std::cout << std::endl;
            }
            else if (nb_of_cards == 4) {
                nb_of_cards = nb_of_cards - 3;
                std::cout << "There are still " << nb_of_cards << " cards left." << std::endl;
                std::cout << std::endl;
            }
            else if (nb_of_cards == 3) {
                nb_of_cards = nb_of_cards - 3;
                std::cout << "There are still " << nb_of_cards << " cards left." << std::endl;
                std::cout << std::endl;
            }
            else {
                std::cout << "Machine lost" << std::endl;
                is_finished = true;
            }
        }
    }
    if (player_wins == true) {
        std::cout << "HUMAN PLAYER WINS !" << std::endl;
    }
    else {
        std::cout << "MACHINE PLAYER WINS !" << std::endl;
    }
}