#pragma once

#include <iostream>
#include <fstream> //read file
#include <sstream> //parse string stream
#include <map> //map container
#include <string>
#include <exception>
// #include <ctime> //handle date and time

class BitcoinExchange {
    private:
        std::map<std::string, float> exchangeRates;
        bool isValidDate(const std::string &dateStr, const std::string &line) const;
        bool isValidValue(const std::string &valueStr, const std::string &line) const;
        float getExchangeRate(const std::string &date) const;
        

    public:
        BitcoinExchange();
        BitcoinExchange(const std::string &databaseFile);
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        void readDatabase(const std::string &filename);
        void processFile(const std::string &filename) const;
};