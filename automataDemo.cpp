#include "automataDemo.hpp"

    void Automata::setMenu() {
        char menuSetMode;
        menu.clear();
        while (true) {
            std::cout << "\nEnter F - if you would like to load menu from file, or C if you prefer to enter from console: ";  
            std::cin >> menuSetMode;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::string readLine;

            if ('F' == menuSetMode || 'f' == menuSetMode) {
                std::ifstream file("menu.txt");
                if (!file) {
                    std::cerr << "Unable to open file menu.txt";
                    return;
                }
                while (std::getline(file, readLine)) {
                    menu.push_back(readLine);
                }
                file.close();

                file.open("prices.txt");
                if (!file) {
                    std::cerr << "Unable to open file prices.txt";
                    return;
                }
                int readPrice;
                while(std::getline(file, readLine)) {
                    readPrice = std::stoi(readLine);
                    prices.push_back(readPrice);
                }
                file.close();

                std::cout << "Debug load from file worked";
                break;
            } // 89040532483 Игорь Юрьевич Горелов договориться на северный на постоянку


            if ('C' == menuSetMode || 'c' == menuSetMode) {
                int tmpCash;
                std::string tmpMenuOption;
                std::cout << "Enter options one by one (enter 's' to srop input):\n";
                //std::getline(std::cin, readLine);

                while (true) {
                    std::cout << "Enter the name: ";
                    std::getline(std::cin, readLine);
                    std::cout << "Enter ther price of " << readLine << ": ";
                    if (readLine == "s") break;
                    tmpMenuOption = readLine;
                    std::getline(std::cin, readLine);
                    if (readLine == "s") break;

                    try {
                        tmpCash = std::stoi(readLine);
                    }
                    catch (const std::invalid_argument& err) {
                        std::cout << "\n" << "Invalid number entered! " << tmpMenuOption << " was not recorded\n";
                        continue;
                    }

                    menu.push_back(tmpMenuOption);
                    prices.push_back(tmpCash);
                }
                std::cout << "Console input finished!";
                break;
            }
        }
    }

    void Automata::coin() {
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