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

void BitcoinExchange::readDatabase(const std::string &filename)
{
    //open and read from file
    std::ifstream database(filename); //input file stream
    if (!database.is_open()) {
        throw std::runtime_error("Wrong file: could not open the file");
    }
    //drop first line
    std::string line;
    std::getline(database, line);
    while (std::getline(database, line)) {
        std::istringstream iss(line); //input string stream
        std::string dateStr;
        float rate;
        //before , is date, reminder part is rate
        if (std::getline(iss, dateStr, ',') && iss >> rate) {
            exchangeRates[dateStr] = rate;
        }
    }
}

void BitcoinExchange::processFile(const std::string &filename) const
{
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Wrong file: could not open the file");
    }
    //check is empty file
    if (file.peek() == std::ifstream::traits_type::eof())
        throw std::runtime_error("Wrong file: input file is empty");
    //read line and check validation
    std::string line;
    std::getline(file, line);
    //first line
    // if(line != "date | value")
    //     throw std::runtime_error("Wrong line: wrong header line");
    //data line
    while (std::getline(file, line)) {
        if (line.empty()) {
            std::cout << "Wrong line: empty line" << std::endl;
            continue ; //if line is empty, move the next line
        }
        //find pipe in line
        size_t pipe = line.find(" | ");
        if (pipe == std::string::npos) {
            std::cout << "Wrong line: no | >> " << line << std::endl;
            continue ;
        }
        //if pipe, divide the line to two part
        std::string dateStr = line.substr(0, pipe);
        std::string valueStr = line.substr(pipe + 3); //pipe length is 3
        //data validation check
        if (dateStr.empty() || valueStr.empty()) {
            std::cout << "Wrong line: empty data >> " << line << std::endl;
            continue ;
        }
        if (!isValidDate(dateStr, line) || !isValidValue(valueStr, line))
            continue ;
        //calculate result
        try {
            float rate = getExchangeRate(dateStr);
            float value = std::stof(valueStr);
            float result = rate * value;
            std::cout << dateStr << " => " << value << " = " << result << std::endl;
        } catch (const std::exception &e) {
            std::cout << e.what() << std::endl;
        }
        file.close();
    }
}

bool BitcoinExchange::isValidDate(const std::string &dateStr, const std::string &line) const {
    //check the begin and end of data, cannot be spaces/tab/nl
    if (dateStr.find_first_not_of(" \t\n\v\f\r") != 0
        || dateStr.find_last_not_of(" \t\n\v\f\r") != dateStr.length() - 1)
    {
        std::cout << "Wrong date: extra space >> " << line << std::endl;
        return false;
    }
    if (dateStr.length() != 10 || dateStr[4] != '-' || dateStr[10] != '-') {
        std::cout << "Wrong date: wrong format >> " << line << std::endl;
        return false;
    }
    //get year, month and day value
    int year, month, day;
    try {
        year = std::stoi(dateStr.substr(0, 4));
        month = std::stoi(dateStr.substr(5, 2));
        day = std::stoi(dateStr.substr(8, 2));
    } catch (const std::exception &) {
        std::cout << "Wrong date: cannot do stoi >> " << line << std::endl;
        return false;
    }
    //check year, month and day value
    int lastDay[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        lastDay[1] = 29;
    if (year >= 1 && month >= 1 && month <= 12 && day >= 1 && day <= lastDay[month - 1])
        return true;
    std::cout << "Wrong date: wrong year/month/day >> " << line << std::endl;
    return false;
}

bool BitcoinExchange::isValidValue(const std::string &valueStr, const std::string &line) const {
    //check the begin and end of data, cannot be spaces/tab/nl
    if (valueStr.find_first_not_of(" \t\n\v\f\r") != 0
        || valueStr.find_last_not_of (" \t\n\v\f\r") != valueStr.length() - 1)
    {
        std::cout << "Wrong value: extra space >> " << line << std::endl;
        return false;
    }
    std::istringstream iss(valueStr);
    float value;
    if (!(iss >> value) || !iss.eof()) {
        std::cout << "Wrong value: wrong format >> " << line << std::endl;
        return false;
    }
    if (value < 0 || value > 1000) {
        std::cout << "Wrong value: should between 0-1000 >> " << line << std::endl;
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

