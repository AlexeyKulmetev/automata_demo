#ifndef AUTOMATA_DEMO_HPP
#define AUTOMATA_DEMO_HPP


#include <fstream>
#include <iostream>
#include <limits>
#include <string>
#include <vector>


enum class STATES {
    OFF,
    ON, // ??
    READY_TO_START, // ??
    MONEY_ACCEPTED,
    MONEY_NOT_ACCEPTED,
    MONEY_EQUAL,
    MONEY_MORE,
    MONEY_LESS
    // FIX ME add other states
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
    int cash = 0;
    std::vector<std::string> menu;
    std::vector<int> prices;
    STATES state = STATES::OFF;

public:
    Automata() = default;
    // Automata(int _cash) : cash{_cash} {} not nessecary

    void setMenu();

    void printState() {
        std::cout << '\n' << state;
    }

    void printMenu() {
        for (const auto& menu_option : menu) {
            std::cout << "\n" << menu_option;
        }
    }

    // implement wait func

    void coin() {
        int depositedMoney = 0;
        // ask amount of money
        std::cout << '\n' << "Enter money (zero or empty to cancel operation): ";
        std::cin >> depositedMoney;

        // change cash
        // add possibility to cancel
        
    }

    void on() {
        // based on infinite loop ??
        // start with wait state
        // implement chosing of operation
        // run coin func
        // run check func
        // run cook func
        // return to wait state
        state = STATES::ON;
        while (state != STATES::OFF) {
            switch (state) {
            case STATES::ON: coin(); continue;
            
            default:
                break;
            }
        }

        // if (trigger == true) { off(); return;}
    }

    void choice() {}



    void off() {
        state = STATES::OFF;
    }
};


#endif