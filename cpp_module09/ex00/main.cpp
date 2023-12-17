#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " <input_filename>" << std::endl;
        return 1;
    }

    BitcoinExchange exchange;

    try {
        if (!exchange.loadExchangeRates("data.csv")) {
            throw std::runtime_error("Error: could not open exchange rates file.");
        }
        exchange.exchangeToBitcoin(argv[1]);
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        return 1;
    }

    return 0;
}