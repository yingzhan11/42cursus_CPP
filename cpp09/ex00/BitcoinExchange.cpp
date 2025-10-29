#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const std::string &databaseFile) {
    readDatabase(databaseFile);
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
    : exchangeRates(other.exchangeRates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other) {
    if (this != &other) {
        exchangeRates = other.exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

/**
 * Parsing Database file, get the date and rate value to container
 */
void BitcoinExchange::readDatabase(const std::string &filename)
{
    //check filename is .csv or not
    if (filename.size() < 4 || filename.substr(filename.size() - 4) != ".csv")
        throw std::invalid_argument("Wrong database: the filename should be '*.csv'");
    //open and read from file
    std::ifstream database(filename); //input file stream
    if (!database.is_open())
        throw std::runtime_error("Wrong database: could not open the database file");
    if (database.peek() == std::ifstream::traits_type::eof())
        throw std::runtime_error("Wrong database: empty databse file");
    
    std::string line;
    const std::regex formatDB(R"(^(\d{4}-\d{2}-\d{2}),(-?\d+(?:\.\d+)?)$)");
    // const std::regex formatDB( R"(((^\d{4})-(\d{2})-(\d{2})),([+-]?\d+(\.\d+)?)$)" );
    //skip the first line
    std::getline(database, line);
    while (std::getline(database, line)) {
        if (line.empty())
            throw std::runtime_error("Wrong database: the line is empty");
        std::smatch result;
        if (!std::regex_match(line, result, formatDB))
            throw std::runtime_error("Wrong database: invalid format");
        
        std::string dateStr = result[1].str();
        std::string rateStr = result[2].str();
        if (dateStr.empty() || rateStr.empty())
            throw std::runtime_error("Wrong database: empty data");
        if (!isValidDate(dateStr, line) || !isValidValue(rateStr, line, 0))
            throw std::runtime_error("Wrong database: invalid data");
        //calculate result
        try {
            float rate = std::stof(rateStr);
            exchangeRates[dateStr] = rate;
        } catch (const std::exception &e) {
            std::cout << RED << e.what() << std::endl << WHITE;
        }
    }
    database.close();
}

/**
 * Parsing the inputfile, and calculate the btc rate
 */
void BitcoinExchange::processFile(const std::string &filename) const
{
    std::ifstream file(filename);

    //check file not open || empty
    if (!file.is_open())
        throw std::runtime_error("Wrong file: could not open the file");
    if (file.peek() == std::ifstream::traits_type::eof())
        throw std::runtime_error("Wrong file: input file is empty");

    std::string line;
    //correct format of each line need to match
    const std::regex format(R"(^(\d{4}-\d{2}-\d{2}) \| (-?\d+(\.\d+)?)\s*$)");
    //skip the first line, then check other lines
    std::getline(file, line);
    while (std::getline(file, line)) {
        if (line.empty()) {
            std::cout << RED << "Wrong line: empty line" << std::endl << WHITE;
            continue ; //if line is empty, move the next line
        }
        //match line to the format
        std::smatch result;
        if (!std::regex_match(line, result, format)) {
            std::cout << RED << "Wrong line: invalid format >> " << line << std::endl << WHITE;
            continue;
        }
        std::string dateStr = result[1].str();
        std::string valueStr = result[2].str();
        //data validation check
        if (dateStr.empty() || valueStr.empty()) {
            std::cout << RED << "Wrong line: empty data >> " << line << std::endl << WHITE;
            continue ;
        }
        if (!isValidDate(dateStr, line) || !isValidValue(valueStr, line, 1))
            continue ;
        //calculate result
        try {
            float rate = getExchangeRate(dateStr);
            float value = std::stof(valueStr);
            float result = rate * value;
            std::cout << dateStr << " => " << value << " = " << result << std::endl;
        } catch (const std::exception &e) {
            std::cout << RED << e.what() << std::endl << WHITE;
        }
    }
    file.close();
}

/**
 * Helper functions
 */
bool BitcoinExchange::isValidDate(const std::string &dateStr, const std::string &line) const {
    //get year, month and day value
    int year, month, day;
    try {
        year = std::stoi(dateStr.substr(0, 4));
        month = std::stoi(dateStr.substr(5, 2));
        day = std::stoi(dateStr.substr(8, 2));
    } catch (const std::exception &) {
        std::cout << RED << "Wrong date: cannot do stoi >> " << line << std::endl << WHITE;
        return false;
    }
    //check year, month and day value
    int lastDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        lastDay[1] = 29;
    if (year >= 1 && month >= 1 && month <= 12 && day >= 1 && day <= lastDay[month - 1])
        return true;
    std::cout << RED << "Wrong date: wrong year/month/day >> " << line << std::endl << WHITE;
    return false;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, const std::string &line, const bool isLimited) const {

    float value;
    size_t idx;
    try {
        value = std::stof(valueStr, &idx);
    } catch (const std::exception &) {
        std::cout << RED << "Wrong value: cannot do stof >> " << line << std::endl << WHITE;
        return false;
    }
    if (idx != valueStr.length()) {
        std::cout << RED << "Wrong value: wrong format >> " << line << std::endl << WHITE;
        return false;
    }
    if (value < 0) {
        std::cout << RED << "Wrong value: should be >= 0 >> " << line << std::endl << WHITE;
        return false;
    }
    if (value > 1000 && isLimited) {
        std::cout << RED << "Wrong value: should be < 1000 >> " << line << std::endl << WHITE;
        return false;
    }
    return true;
}

float BitcoinExchange::getExchangeRate(const std::string &date) const
{
    //find date/the closest date (lower one)
    //upper_bound() finds the first element greater than parameter
    //lower_bound() finds the first element greater than or equal to parameter, need to check is equal or not
    auto it = exchangeRates.upper_bound(date);

    if (it == exchangeRates.begin()) {
        throw std::runtime_error("Wrong date: no exchange rate for this date");
    }
    //move to smaller one, must be eqaul or smaller than the date
    --it;
    return it->second;
}


