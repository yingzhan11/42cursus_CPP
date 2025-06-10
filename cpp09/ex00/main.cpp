#include "BitcoinExchange.hpp"

#define RED "\033[31m"
#define GLOD "\033[33m"
#define WHITE "\033[0m"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << RED << "Wrong input: ./btc <filename>" << std::endl << WHITE;
        return 1;
    }

    try {
        //load database
        BitcoinExchange exchange("data.csv");
        //process input file
        std::cout << GLOD << "   Date  | Value|Result" << std::endl << WHITE;
        exchange.processFile(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << RED << e.what() << std::endl << WHITE;
        return 1;
    }
    return 0;
}