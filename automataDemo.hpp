#ifndef AUTOMATA_DEMO_HPP
#define AUTOMATA_DEMO_HPP


#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>


enum class STATES {
    INITIAL_STATE
};


class Automata {
private:
    int cash;
    std::vector<std::string> menu;
    int prices;
    STATES state;

public:
    Automata() = default;
    Automata(int _cash) : cash{_cash}, prices{0}, state{STATES::INITIAL_STATE} {}

    void setMenu() {
        char menuSetMode;
        menu.clear();
        while (true) {
            std::cout << "\nEnter F - if you would like to load menu from file, or C if you prefer to enter from console: ";  
            std::cin >> menuSetMode;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string menuOption;

            if ('F' == menuSetMode || 'f' == menuSetMode) {
                std::ifstream file("menu.txt");
                if (!file) {
                    std::cerr << "Unable to open file menu.txt";
                    return;
                }

                while (std::getline(file, menuOption)) {
                    menu.push_back(menuOption);
                }

                file.close();
                break;
            }

            if ('C' == menuSetMode || 'c' == menuSetMode) {
                std::cout << "\nEnter options one by one (enter 's' to srop input): ";
                std::getline(std::cin, menuOption);
                while (menuOption != "s") {
                    menu.push_back(menuOption);
                    std::getline(std::cin, menuOption);
                }

                break;
            }
        }
    }
};


#endif