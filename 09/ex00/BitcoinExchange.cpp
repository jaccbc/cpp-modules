/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:07:26 by joandre-          #+#    #+#             */
/*   Updated: 2025/12/13 17:51:12 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*
  function responsible for opening database file
  parses the content to a std::map container
  throw an exception if it cannot open database file
*/
void BitcoinExchange::dbOpen() {
  std::ifstream dataFile(DB_FILE, std::ios::in);
  if (!dataFile.is_open()) {
    std::string err(std::string("unable to open file ==> ")
      + std::string(DB_FILE));
    throw std::ios_base::failure(err);
  }
  std::string line;
  std::getline(dataFile, line);
  while (std::getline(dataFile, line)) {
    std::istringstream ss(line);
    std::string date;
    std::string rate;
    if (!std::getline(ss, date, ',') || !std::getline(ss, rate))
      continue;
    db[date] = std::strtod(rate.c_str(), NULL);
  }
}

/*
  validates the rate string
  and checks the valid range
*/
static bool isValidRate(std::string& s) {
  std::string number;
  long double x = 0;
  for (size_t i = 0; i < s.size(); i++) {
    if (!std::isdigit(s.at(i)) && !std::isspace(s.at(i))
      && !(s.at(i) == '.') && !(s.at(i) == '-'))
      return false;
    if (!std::isspace(s.at(i))) number += s.at(i);
  }
  std::istringstream limits(number);
  limits >> x;
  if (x < 0) throw std::range_error("not a positive number ==> " + s);
  if (x > 1000) throw std::range_error("too large a number ==> " + s);
  return s = number, !s.empty();
}

/*
  gets the current local time
  year boundaries: birth of btc (2009) and current year
*/
static bool isDateRangeValid(unsigned long long year,
  unsigned long long month, unsigned long long day) {
  time_t now = std::time(NULL);
  std::tm* time = std::localtime(&now);
  if (year < 2009ULL
    || year > static_cast<unsigned long long>(time->tm_year + 1900)
    || month > 12ULL
    || (month <= 6ULL && month % 2ULL == 0ULL && day > 30ULL)
    || (month >= 9ULL && month % 2ULL && day > 30ULL)) return false;
  if (month == 2ULL) {
    if (day > 29ULL) return false;
    if (day == 29ULL)
      return (year % 4ULL == 0ULL && year % 100ULL != 0ULL) || (year % 400ULL == 0ULL);
  }
  return month && day;
}

/*
  checks and cleans the date string
  only digits are accpeted; spaces are eliminated
*/
static bool isDateClean(std::string& s) {
  std::string number;
  for (size_t i = 0; i < s.size(); i++) {
    if (!std::isdigit(s.at(i)) && !std::isspace(s.at(i)))
      return false;
    if (std::isdigit(s.at(i))) number += s.at(i);
  }
  return s = number, !s.empty();
}

/*
  splits the full string date in 3
  year | month | day
  returns true if date is valid
  after the split date strings can just have spaces
  and numbers
*/
static bool isValidDate(std::string const& date) {
  if (std::count(date.begin(), date.end(), '-') != 2)
    return false;
  size_t len = date.find("-");
  std::string year(date.substr(0, len));
  if (date.size() <= year.size()) return false;
  len = year.size() + 1;
  std::string month(date.substr(len, date.substr(len).find("-")));
  if (date.size() <= len + month.size() + 1) return false;
  std::string day(date.substr(len + month.size() + 1));
  if (isDateClean(year) && isDateClean(month) && isDateClean(day))
    return isDateRangeValid(std::strtoull(year.c_str(), NULL, 10),
                            std::strtoull(month.c_str(), NULL, 10),
                            std::strtoull(day.c_str(), NULL, 10));
  return false;
}

/*
  finds the corresponding string date in the container
  if the string date has no equal correspondence, the closest (lower) date is choosen
  converts the rate string to a double and multiplies by the btc DB price
  converts the result back to string to be printed to the stdout
*/
void BitcoinExchange::multiply(std::string const& date, std::string const& rate) {
  std::map<std::string,double>::const_iterator i = db.lower_bound(date);
  if (i != db.begin() && i->first != date) --i;
  long double x = std::strtod(rate.c_str(), NULL) * i->second;
  std::ostringstream result;
  result << x;
  std::cout << date << " => " << rate << " = " << result.str() << std::endl;
}

/*
  receives both db already fetched to the map container
  opens input file and splits the line in half (date & rate)
  performs string and number validations for date and rate
*/
void  BitcoinExchange::dbDebug(const char* input) {
  dbOpen();
  if (db.empty())
    throw std::invalid_argument("database file is empty.");
  std::ifstream inputFile(input, std::ios::in);
  if (!inputFile.is_open())
  {
    std::string err("unable to open file ==> ");
    err += std::string(input);
    throw std::ios_base::failure(err);
  }
  std::string line;
  if (!std::getline(inputFile, line))
    throw std::invalid_argument("input file is empty.");
  while (std::getline(inputFile, line)) {
    try {
      std::string date;
      std::string rate;
      if (line.find("|") != line.npos) {
        date = line.substr(0, line.find("|"));
        rate = line.substr(line.find("|") + 1);
        if (isValidDate(date) && isValidRate(rate)) {
          multiply(date, rate);
          continue ;
        }
      }
      throw std::invalid_argument(std::string("bad input ==> ") + line);
    }
    catch (std::exception const& e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }
}

// returns a reference to the map container (database)
std::map<std::string,double> const& BitcoinExchange::getDB() const { return db; }

// default object constructor
BitcoinExchange::BitcoinExchange() {}

// copy object consctrutor
BitcoinExchange::BitcoinExchange(BitcoinExchange const& other) : db(other.getDB()) {}

// copy assignment operator
BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& other) {
  if (this != &other) {
    db = other.getDB();
  }
  return *this;
}

// object destructor
BitcoinExchange::~BitcoinExchange() {}
