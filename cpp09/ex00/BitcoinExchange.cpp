#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void) : _database() {
	try {
		_loadDatabase();
	}
	catch (std::exception &e) {
		throw DatabaseLoadException(e.what());
	}
	_min_date = _database.begin()->first;
	_max_date = _database.rbegin()->first;
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) {
	this->_database = other._database;
}

BitcoinExchange::~BitcoinExchange(void) {
	return;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &other) {
	this->_database = other._database;
	return *this;
}

void BitcoinExchange::_loadDatabase(void) {
	std::string filename = DATA_FILE;
	std::ifstream file(filename.c_str());
	std::string line;
	std::string date;
	std::string value;
	float fvalue;

	if (!file.is_open())
		throw DatabaseNotFoundException();
	std::getline(file, line);
	if (!_checkHeader(line, DATABASE))
		throw BadDatabaseFormatException();
	else {
		while (std::getline(file, line)) {
			try {
				_checkLine(line, DATABASE);
			}
			catch (std::exception &e) {
				std::cerr << "Error: " << e.what() << std::endl;
				throw BadDatabaseFormatException();
				break;
			}
			date = line.substr(0, line.find(','));
			value = line.substr(line.find(',') + 1);
			fvalue = std::atof(value.c_str());
			_database[date] = fvalue;
		}
	}
	file.close();
}

void BitcoinExchange::readInput(std::string filename) {
	std::ifstream file(filename.c_str());
	std::string line;
	std::string date;
	std::string value;
	float fvalue;

	if (!file.is_open())
		throw InputNotFoundException();
	std::getline(file, line);
	if (!_checkHeader(line, INPUT))
		throw BadInputFormatException();
	while (std::getline(file, line)) {
		try {
			_checkLine(line, INPUT);
		}
		catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
			continue;;
		}
		date = line.substr(0, line.find('|'));
		value = line.substr(line.find('|') + 1);
		fvalue = std::atof(value.c_str());
		_btc(date, fvalue);
	}
}

void BitcoinExchange::_btc(std::string date, float value) {
	std::map<std::string, float>::iterator it = _database.find(date);
	std::string			last_date;
	float				last_value;

	if (it != _database.end()) {
		std::cout << date << " -> " << value << " = " << value * it->second << std::endl;
		return;
	}
	for (it = _database.begin(); it != _database.end(); it++) {
		if (it->first > date)
			break;
		last_date = it->first;
		last_value = it->second;
	}
	std::cout << date << " -> " << value << " = " << value * last_value << std::endl;
}

bool BitcoinExchange::_checkHeader(std::string header, file_type type) {
	char delimiter = (type == DATABASE) ? ',' : '|';
	std::string cell1 = "date";
	std::string cell2 = (type == DATABASE) ? "exchange_rate" : "value";

	if (std::count(header.begin(), header.end(), delimiter) != 1)
		return false;
	std::string header1 = header.substr(0, header.find(delimiter));
	std::string header2 = header.substr(header.find(delimiter) + 1);
	_trimCell(header1);
	_trimCell(header2);
	_trimCell(cell1);
	_trimCell(cell2);
	if (header1 != cell1 || header2 != cell2)
		return false;
	return true;
}

void BitcoinExchange::_checkLine(std::string line, file_type type) {
	char delimiter = (type == DATABASE) ? ',' : '|';

	if (std::count(line.begin(), line.end(), delimiter) != 1)
		throw BadInputDataException(line);
	std::string date = line.substr(0, line.find(delimiter));
	std::string value = line.substr(line.find(delimiter) + 1);
	_trimCell(date);
	_trimCell(value);
	if (!date.length() || !value.length())
		throw BadInputDataException(line);
	else if (!_checkDate(date, type))
		throw BadDateException(date);
	else if (!_checkValue(value, type)) {
		if (std::atof(value.c_str()) < 0)
			throw NegativeValueException();
		else if (std::atof(value.c_str()) > 1000)
			throw TooLargeValueException();
		else
			throw BadInputDataException(line);
	}
}

bool BitcoinExchange::_checkDate(std::string date, file_type type) {
	if (date.length() != 10)
		return false;
	for (int i = 0; i < 10; i++) {
		if (i == 4 || i == 7) {
			if (date[i] != '-')
				return false;
		}
		else if (!std::isdigit(date[i]))
			return false;
	}
	if (type == INPUT && (date < _min_date))
		return false;
	int month = std::atoi(date.substr(5, 2).c_str());
	if (month < 1 || month > 12)
		return false;
	int day = std::atoi(date.substr(8, 2).c_str());
	if (day < 1 || day > 31)
		return false;
	if (month == 2 && day > 28)
		return false;
	if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
		return false;
	return true;
}

bool BitcoinExchange::_checkValue(std::string value, file_type type) {
	bool dot = false;

	for (size_t i = 0; i < value.length(); i++) {
		if (value[i] == '.') {
			if (dot)
				return false;
			dot = true;
		}
		else if (!std::isdigit(value[i]))
			return false;
	}
	if (type == INPUT && std::atof(value.c_str()) < 0)
		return false;
	else if (type == INPUT && std::atof(value.c_str()) > 1000)
		return false;
	return true;
}

void BitcoinExchange::_trimCell(std::string &cell) {
	cell.erase(std::remove_if(cell.begin(), cell.end(), ::isspace), cell.end());
}

BitcoinExchange::DatabaseLoadException::DatabaseLoadException(std::string error_message) : _error_message(error_message) {
	return;
}

const char *BitcoinExchange::DatabaseLoadException::what() const throw() {
	return _error_message.c_str();
}

const char *BitcoinExchange::DatabaseNotFoundException::what() const throw() {
	return "Database file not found. Please make sure a file named 'database.csv' is present in the current directory.";
}

const char *BitcoinExchange::BadDatabaseFormatException::what() const throw() {
	return "Database file has an invalid format. Please make sure the file is a CSV file with the following header: 'date,exchange_rate'.";
}

const char *BitcoinExchange::BadDatabaseDataException::what() const throw() {
	return "Database file has invalid data. Please make sure the file is a CSV file with the following header: 'date,exchange_rate'.";
}

const char *BitcoinExchange::InputNotFoundException::what() const throw() {
	return "Input file not found. Please make sure the file exists and is accessible.";
}

const char *BitcoinExchange::BadInputFormatException::what() const throw() {
	return "Input file has an invalid format. Please make sure the file is a CSV file with the following header: 'date|value'.";
}

BitcoinExchange::BadInputDataException::BadInputDataException(std::string error_message) : _error_message(error_message) {
	return;
}

const char *BitcoinExchange::BadInputDataException::what() const throw() {
	return _error_message.c_str();
}

BitcoinExchange::BadDateException::BadDateException(std::string date) : _error_message("Invalid date: " + date) {
	return;
}

const char *BitcoinExchange::BadDateException::what() const throw() {
	return _error_message.c_str();
}

const char *BitcoinExchange::NegativeValueException::what() const throw() {
	return "Negative value found in input file. Please make sure all values are positive.";
}

const char *BitcoinExchange::TooLargeValueException::what() const throw() {
	return "Value found in input file is too large. Please make sure all values are less than 1000.";
}