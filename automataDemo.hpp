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
    // maybe replase all unsuccessful attempt states to "CANCELD" state?
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
        auto menuIt = menu.begin();
        auto pricesIT = prices.begin();

        for (; menuIt != menu.end() && pricesIT != prices.end(); ++menuIt, ++pricesIT) {
            std::cout << "\n" << *menuIt << "\t" << *pricesIT;
        }
        // for (const auto& menuOption : menu) {
        //     std::cout << "\n" << menuOption;
        // }

        // FIX ME do not work
    }

    // implement wait func

    void coin() {
        std::string userResponse;
        int depositedMoney = 0;
        // ask amount of money
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << '\n' << "Enter money (zero or empty to cancel operation): ";
        std::cin >> userResponse;

        if (userResponse.empty() || userResponse == " " || userResponse == "\t") {
            state = STATES::MONEY_NOT_ACCEPTED;
            return;
        }
        else {
            try {
                depositedMoney = std::stoi(userResponse);
            }
            catch (const std::invalid_argument& err) {
                state = STATES::MONEY_NOT_ACCEPTED;
                return;
            }
            cash += depositedMoney;
        }
        return;
    }

    void choice() {

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

        std::cout << "\n" << "Deposited cash: " << cash;
        while (state != STATES::OFF) {
            switch (state) {
            case STATES::ON: coin(); continue;
            case STATES::MONEY_ACCEPTED: choice(); continue;
            default:
                break;
            }
        }

        // if (trigger == true) { off(); return;}
    }



    void off() {
        state = STATES::OFF;
    }
};


#endif