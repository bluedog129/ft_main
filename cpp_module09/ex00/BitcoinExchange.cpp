#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {
    std::cout << "BitcoinExchange constructor called" << std::endl;
}

BitcoinExchange::~BitcoinExchange() {
    std::cout << "BitcoinExchange destructor called" << std::endl;
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

bool BitcoinExchange::loadExchangeRates(std::string& filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cout << "Failed to open file: " << filename << std::endl;
        return false;
    }

    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string currency;
        double rate;
        if (!(iss >> currency >> rate)) {
            std::cout << "Error: reading exchange rate from file: " << filename << std::endl;
            return false;
        }
        exchangeRates[currency] = rate;
    }
    file.close();
    return true;
}

void BitcoinExchange::updateExchangeRates(std::string& date, float rate) {
    exchangeRates[date] = rate;
}

float BitcoinExchange::getExchangeRate(std::string& date) {
    return exchangeRates[date];
}

float BitcoinExchange::getExchangeRate(std::string& date, std::string& currency) {
    return exchangeRates[date] * exchangeRates[currency];
}
