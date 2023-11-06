#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
        if (argc != 3) {
        std::cerr << "Usage: " << argv[0] << " <exchange_rates_filename> <input_filename>" << std::endl;
        return 1;
    }

    BitcoinExchange exchange;
    if (!exchange.loadExchangeRates(argv[1])) {
        std::cerr << "Error: could not open exchange rates file." << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[2]);
    if (!inputFile.is_open()) {
        std::cerr << "Error: could not open input file." << std::endl;
        return 1;
    }

    std::string line, date;
    float value;
    getline(inputFile, line); // 첫번째 줄 미리 빼놓기
    while (getline(inputFile, line)) {
        std::istringstream iss(line);
        if (getline(iss, date, '|') && (iss >> value)) {
            // 처리 로직, 유효성 검사 등을 여기에 추가할 수 있습니다.
            exchange.printExchangeRateForDate(date, value);
        } else {
            std::cerr << "Error: bad input format in line '" << line << "'" << std::endl;
        }
    }

    return 0;
}