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

    bool loadExchangeRates(std::string& filename);
    void updateExchangeRates(std::string& date, float rate);
    float getExchangeRate(std::string& date);
    float getExchangeRate(std::string& date, std::string& currency);
};

#endif