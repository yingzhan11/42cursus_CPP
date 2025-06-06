#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Wrong input: ./btc <filename>" << std::endl;
        return 1;
    }

    try {
        //load database
        BitcoinExchange exchange("data.csv");
        //process input file
        exchange.processFile(argv[1]);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 0;
}