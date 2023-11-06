#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>

struct Entry
{
    std::string date;
    float value;
};

class BitcoinExchange {
private:
    std::map<std::string, float> exchangeRates;

public:
    BitcoinExchange();
    ~BitcoinExchange();
    BitcoinExchange(BitcoinExchange const &other);
    BitcoinExchange &operator=(BitcoinExchange const &other);

    bool loadExchangeRates(const std::string& filename);
    float getExchangeRate(const std::string& date) const;
    void printExchangeRateForDate(const std::string& date, float bitcoinAmount) const;
};

#endif