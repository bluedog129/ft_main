#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <exchange_rates_filename> <input_filename>" << std::endl;
        return 1;
    }

    BitcoinExchange exchange;

    try {
        if (!exchange.loadExchangeRates("data.csv")) {
            std::cerr << "Error: could not open exchange rates file." << std::endl;
            return 1;
        }

        exchange.processInputFile(argv[1]);
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    return 0;
}