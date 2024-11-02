#ifndef AUTOMATA_DEMO_HPP
#define AUTOMATA_DEMO_HPP


#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>


enum class STATES {
    OFF,
    ON,
    READY_TO_START,
    MONEY_ACCEPTED,
    MONEY_NOT_ACCEPTED,
    COOKED,
    MONEY_LESS
};

// Just for debug
inline std::ostream& operator << (std::ostream& out, const STATES& st) { 
    switch (st) {
    case STATES::OFF: out << "OFF";
        break;
    case STATES::ON: out << "ON";    
    default:
        break;
    }
    return out;
}


class Automata {
private:
    unsigned int cash = 0;
    std::vector<std::string> menu;
    std::vector<unsigned int> prices;
    STATES state = STATES::OFF;

public:
    Automata() = default;

    void setMenu();

    void printState() {
        std::cout << '\n' << state;
    }

    void printMenu() {
        auto menuIt = menu.begin();
        auto pricesIT = prices.begin();

        for (unsigned int i = 0; i < menu.size() && i < prices[i]; ++i) {
            std::cout << "\n" << i + 1 << ". " << menu[i] << "\t" << prices[i];
        }
    }

    void coin();

    void finish() {
        std::string response;
        std::cout << "Would you like to order another drink? (enter y to order or another letter to stop): ";
        std::cin >> response;
        state = (response == "y") ? STATES::ON : STATES::OFF;
    }

    void giveChange() {
        if (cash > 0) {
            std::cout << "\nYour change is: " << cash;
        }
    }

    void choice() {
        unsigned int num;
        printMenu();
        std::cout << "\nEnter number of drink: ";
        std::cin >> num;
        
        if (cash >= prices[num - 1]) {
            cook(num + 1);
        }
        else {
            state = STATES::MONEY_LESS;
            cancel();
        }
    }

    void cook(unsigned int index = 0) {

        cash -= prices[index];
        std::cout << "\n" << menu[index] << " cooked!";
        state = STATES::COOKED;
    }

    void on() {
        state = STATES::ON;
        std::string responce;
        coin();
        std::cout << "\n" << "Deposited cash: " << cash;
        while (state != STATES::OFF) {
            switch (state) {
            case STATES::ON: coin(); break; 
            case STATES::MONEY_ACCEPTED: choice(); break;
            case STATES::MONEY_NOT_ACCEPTED: cancel(); break;
            case STATES::COOKED:
                std::cout << "\nWould you like to make another order? (y or Y if yes): ";
                std::cin >> responce;
                if (responce != "y" && responce != "Y") {
                    state = STATES::OFF; break;
                }
                else {
                    state = STATES::ON; break;
                }
                break;
            default:
                break;
            }
        }
        std::cout << "Bon appetit! Goodbye";
    }

    void cancel() {
        std::string responce;
        switch (state) {
        case STATES::MONEY_NOT_ACCEPTED:
            std::cout << "\nPress y if you would like to continue: ";
            std::cin >> responce;
            if (responce != "y" && responce != "Y") {
                state = STATES::ON; return;
            }
            else {
                state = STATES::OFF; return;
            }
        case STATES::MONEY_LESS: coin(); return;
        }
            
    }

    void off() {
        state = STATES::OFF;
    }
};


#endif