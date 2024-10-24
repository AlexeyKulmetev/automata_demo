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
                //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                while (std::getline(file, readLine)) {
                    menu.push_back(readLine);
                }
                file.close();

                file.open("prices.txt");
                if (!file) {
                    std::cerr << "Unable to open file prices.txt";
                    return;
                }
                //std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
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
                std::cout << "\nEnter options one by one (enter 's' to srop input): ";
                std::getline(std::cin, readLine);
                while (readLine != "s") {
                    menu.push_back(readLine);
                    std::getline(std::cin, readLine);
                }
                std::cout << "Debug load from console worked";
                break;
            }
        }
    }
