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
    std::ifstream file(filename);
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
        return -1; // or some other indication that the rate was not found
    }
    if (it->first == date) {
        return it->second;
    }
    if (it != exchangeRates.begin()) {
        --it;
    }
    return it->second;
}

void BitcoinExchange::printExchangeRateForDate(const std::string& date, float bitcoinAmount) const {
    float rate = getExchangeRate(date);
    if (rate != -1) {
        std::cout << date << " => " << bitcoinAmount << " = " << (bitcoinAmount * rate) << std::endl;
    } else {
        std::cout << "Error: Exchange rate for date " << date << " not found." << std::endl;
    }
}