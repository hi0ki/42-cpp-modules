#include "BitcoinExchange.hpp"

/*
    ------------- checkes -------------
    format : date | value
    date format : YYYY-MM-DD
    value : float or a positive int between 0 and 1000
*/


int main(int ac , char **av) {
    (void) ac;
    BitcoinExchange btc;
    std::ifstream data_base("data.csv");
    std::ifstream file(av[1]);
    if (data_base.fail() || file.fail())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    try
    {
        btc.store_data(data_base, file);
        btc.parse_data();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    data_base.close();
    file.close();
    return 0;
}