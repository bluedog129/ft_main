#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    // std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
    // std::cout << "BitcoinExchange destructor called" << std::endl;
}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &other) {
    std::cout << "BitcoinExchange copy constructor called" << std::endl;
    *this = other;
}

BitcoinExchange &BitcoinExchange::operator=(BitcoinExchange const &other) {
    std::cout << "BitcoinExchange assignation operator called" << std::endl;
    if (this != &other) {
        this->exchangeRates = other.exchangeRates;
    }
    return *this;
}

bool BitcoinExchange::loadExchangeRates(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        return false;
    }

    std::string line, date;
    float rate;
    while (getline(file, line)) {
        std::istringstream iss(line);
        if (getline(iss, date, ',') && (iss >> rate)) {
            exchangeRates[date] = rate;
        }
    }

    return true;
}

float BitcoinExchange::getExchangeRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = exchangeRates.lower_bound(date);
    if (it == exchangeRates.end()) {
        // If we reached the end, there are no rates on or after this date, so we return the last known rate
        if (!exchangeRates.empty()) {
            --it;
            return it->second;
        }
        // Handle the case where there are no rates at all
        return -1; // or some other indication that the rate was not found
    }

    if (it->first == date) {
        // Exact date match
        return it->second;
    }

    if (it != exchangeRates.begin()) {
        // If it's not the beginning, use the previous (which is the closest earlier rate)
        --it;
        return it->second;
    }

    // If there's no earlier rate, you might want to handle this edge case differently.
    return -1; // or some other indication that the rate was not found
}

void BitcoinExchange::printExchangeRateForDate(const std::string& date, float bitcoinAmount) const {
    float rate = getExchangeRate(date);

    if (rate != -1) {
        std::cout << date << " => " << bitcoinAmount << " = " << (bitcoinAmount * rate) << std::endl;
    } else {
        std::cout << "Error: Exchange rate for date " << date << " not found." << std::endl;
    }
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    // Assuming the date format is YYYY-MM-DD
    if (date.length() != 10) return false;
    if (date[4] != '-' || date[7] != '-') return false;

    int year, month, day;
    year = std::atoi(date.substr(0, 4).c_str());
    month = std::atoi(date.substr(5, 2).c_str());
    day = std::atoi(date.substr(8, 2).c_str());

    // Check year range (bitcoin exchange rates are available from 2009 to 2022)
    if (year < 2009 || year > 2022) return false;

    // Check month range
    if (month < 1 || month > 12) return false;

    // Check day range
    if (day < 1 || day > 31) return false;

    // Check February for leap year(윤년)
    if (month == 2) {
        bool leapYear = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (leapYear ? 29 : 28)) return false;
    }

    // Check months with 30 days
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
        return false;
    }

    return true;
}

void BitcoinExchange::exchangeToBitcoin(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open()) {
        throw std::runtime_error("Error: could not open input file.");
    }

    std::string line;
    std::getline(file, line); // Skip the header

    while (std::getline(file, line)) {
        // Remove whitespace from the line
        line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());

        std::istringstream iss(line);
        std::string date, valueStr;
        float value;

        try {
            if (!(std::getline(iss, date, '|') && std::getline(iss, valueStr))) {
                throw std::runtime_error("Error: bad input => " + line);
            }

            // Check if the date is valid
            if (!isValidDate(date)) {
                throw std::runtime_error("Error: invalid date format.");
            }

            // Check if the value is valid
            std::istringstream convert(valueStr);
            double doubleValue;
            if (!(convert >> doubleValue)) {
                throw std::runtime_error("Error: invalid number format.");
            }
            
            if (doubleValue < 0) {
                throw std::out_of_range("Error: not a positive number.");
            }
            
            if (doubleValue > 1000) {
                throw std::out_of_range("Error: too large a number.");
            }

            value = static_cast<float>(doubleValue);
            printExchangeRateForDate(date, value);

        } catch (const std::exception& e) {
            std::cout << e.what() << std::endl;
            continue;
        }
    }
}