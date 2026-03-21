#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
	*this = other;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other) {
		this->data_base = other.data_base;
		this->input_file = other.input_file;
	}
	return (*this);
}

BitcoinExchange::~BitcoinExchange() {};


//    Utils

void BitcoinExchange::store_data(std::ifstream &data_base, std::ifstream &input_file)
{
	std::string line;
	std::getline(data_base, line);
	while (std::getline(data_base, line))
	{
		this->data_base[line.substr(0, line.find(","))] = line.substr(line.find(",") + 1);
	}
	std::getline(input_file, line);
	if (line != "date | value")
		throw std::runtime_error("Error: No header found.");
	while (std::getline(input_file, line))
		this->input_file += line + "\n";
}

float find_value_in_db(const std::string &date, std::map<std::string ,std::string> &data_base)
{
	std::map<std::string, std::string>::iterator it = data_base.upper_bound(date);
	if (it == data_base.begin())
		return (-1);
	--it;
	float value = std::atof((*it).second.c_str());
	return (value);
}

void BitcoinExchange::calculate_value(const std::string &date, float numOfBTC)
{
	float btc_value = find_value_in_db(date, this->data_base);
	if (btc_value < 0)
	{
		std::cerr << "Error: This date is out of range => " + date << std::endl;
		return ;
	}
	std::cout << date + " => " << numOfBTC << " = " << (btc_value * numOfBTC) << std::endl;
}

bool check_date_chars(std::string line)
{
	size_t pos = line.find('|');
	if (pos + 1 == line.size())
		return (false);
	std::string numofbtc = line.substr(pos + 2, line.size());
	if (numofbtc.empty())
		return (false);
	for( size_t i = 0; i < line.size() && i <= numofbtc.size(); i++)
	{
		if (i < line.size() && !isdigit(line[i]) && line[i] != '-' && line[i] != '|' && line[i] != ' ' && line[i] != '.')
			return (false);
		if ((i < numofbtc.size() && !isdigit(numofbtc[i]) && numofbtc[i] != '.' && numofbtc[i] != '-'))
			return (false);
	}
	line = line.substr(0, line.find('|') - 1); 
	if (line.size() != 10)
		return (false);
	int year = std::atoi(line.substr(0, 4).c_str());
	int month = std::atoi(line.substr(5, 2).c_str());
	int day = std::atoi(line.substr(8, 2).c_str());
	if (year < 1000 || year > 9999)
		return (false);
	if (month < 1 || month > 12)
		return (false);
	if (day < 1 || day > 31)
		return (false);
	return (true);
}

void BitcoinExchange::parse_data()
{
	std::string line;
	std::string date;
	float NumOfBTC;
	size_t pos;
	for (; !input_file.empty(); input_file.erase(0, input_file.find('\n') + 1))
	{
		line = input_file.substr(0, input_file.find('\n'));
		pos = line.find('|');
		if (pos == std::string::npos || check_date_chars(line) == false)
		{
			std::cerr << "Error: bad input => " + line << std::endl;
			continue;
		}
		date = line.substr(0, pos - 1);
		NumOfBTC = std::atof(line.substr(pos + 2).c_str());
		if (NumOfBTC < 0)
		{
			std::cerr << "Error: not a positive number." << std::endl;
			continue;
		}
		if (NumOfBTC > 1000)
		{
			std::cerr << "Error: too large a number." << std::endl;
			continue;
		}
		this->calculate_value(date, NumOfBTC);
	}
}
