#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: ./bitcoin_exchange <filename>" << std::endl;
        return 1;
    }

    BitcoinExchange exchange;
    std::string fileName = argv[1];

    std::ifstream file(argv[1]);

    if (!exchange.loadExchangeRates(fileName)) {
        return 1;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::string date;
        float value;
        std::replace(line.begin(), line.end(), ',', ' ');
        std::istringstream iss(line);
        if (!(iss >> date >> value)) {
            std::cerr << "Error reading exchange rate from file: " << argv[1] << std::endl;
            return 1;
        }

        float rate = exchange.getExchangeRate(date);
        if (rate == -1.0f) {
            std::cout << "No exchange rate found for date: " << date << std::endl;
            return 1;
        }

        std::cout << date << " => " << value << " = " << value * rate << std::endl;
    }

    file.close();
    return 0;
}