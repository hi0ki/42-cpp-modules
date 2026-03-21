#pragma once

#include <iostream>
#include <fstream>
#include <map>
#include <algorithm>

class BitcoinExchange {
    private:
        std::map<std::string, std::string> data_base;
        std::string input_file;
    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange &operator=(const BitcoinExchange &other);
        ~BitcoinExchange();
        //     Utils
        void store_data(std::ifstream &data_base, std::ifstream &input_file);
        void parse_data();
        void calculate_value(const std::string &date, float value);
};