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

void BitcoinExchange::processInputFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    std::getline(file, line); // Skip the header

    while (std::getline(file, line)) {
        // Remove whitespace from the line
        line.erase(std::remove_if(line.begin(), line.end(), ::isspace), line.end());

        std::istringstream iss(line);
        std::string date, valueStr;
        float value;

        if (!(std::getline(iss, date, '|') && std::getline(iss, valueStr))) {
            std::cerr << "Error: bad input " << line << std::endl;
            continue;
        }

        try {
            double doubleValue = std::stod(valueStr);
            if (doubleValue < 0) {
                throw std::out_of_range("Error: not a positive number.");
            }
            if (doubleValue > static_cast<double>(INT_MAX)) {
                std::cout << "lalala";
                throw std::out_of_range("Error: too large a number.");
            }
            value = static_cast<float>(doubleValue);
        } catch (const std::exception& e) {
            std::cerr << e.what() << std::endl;
            continue;
        }

        float rate = getExchangeRate(date);
        if (rate < 0) {
            std::cerr << "Error: No exchange rate available for date " << date << std::endl;
            continue;
        }

        std::cout << date << " => " << value << " = " << (rate * value) << std::endl;
    }
}