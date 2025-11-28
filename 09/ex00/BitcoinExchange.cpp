/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 13:07:26 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/28 01:02:06 by joandre-         ###   ########.fr       */
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
    throw std::ios_base::failure(err.c_str());
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
  if (x < 0) throw std::range_error("not a positive number.");
  if (x > 1000) throw std::range_error("too large of a number.");
  return s = number, s.size();
}

/*
  gets the current local time
  year boundaries: birth of btc (2009) and current year
*/
static bool validDateRange(unsigned long long year,
  unsigned long long month, unsigned long long day) {
  time_t now = std::time(NULL);
  std::tm* time = std::localtime(&now);
  if (year < 2009ULL
    || year > static_cast<unsigned long long>(time->tm_year + 1900)
    || month > 12ULL
    || (month <= 6 && month % 2 == 0 && day > 30)
    || (month >= 9 && month % 2 && day > 30)) return false;
  if (month == 2) {
    if (day > 29) return false;
    if (day == 29)
      return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  }
  return month && day;
}

/*
  validates the date format if every char is a digit/space
  eliminates spaces from the string argument if format is valid
*/
static bool isValidDate(std::string& s) {
  std::string number;
  for (size_t i = 0; i < s.size(); i++) {
    if (!std::isdigit(s.at(i)) && !std::isspace(s.at(i)))
      return false;
    if (std::isdigit(s.at(i))) number += s.at(i);
  }
  return s = number, s.size();
}

/*
  splits the full string date in 3
  year | month | day
  returns true if date is valid
*/
static bool validateDate(std::string const& date) {
  size_t len = date.find("-");
  if (len == date.npos) return false;
  std::string year(date.substr(0, len));
  if (date.size() > year.size()
    && date.substr(year.size() + 1).find("-") != date.npos) {
    std::string month(date.substr(year.size() + 1,
    date.substr(year.size() + 1).find("-")));
    if (date.size() > year.size() + month.size() + 2) {
      std::string day(date.substr(year.size() + month.size() + 2));
      if (isValidDate(year) && isValidDate(month) && isValidDate(day))
        return validDateRange(std::strtoull(year.c_str(), NULL, 10),
          std::strtoull(month.c_str(), NULL, 10),
          std::strtoull(day.c_str(), NULL, 10));
    }
  }
  return false;
}

/*
  finds the corresponding date in the container
  multiply its values to the stdout
*/
void BitcoinExchange::multiply(std::string const& date, std::string const& rate) {
  std::map<std::string,double>::const_iterator i = db.lower_bound(date);
  long double x = std::strtod(rate.c_str(), NULL) * i->second;
  std::ostringstream result;
  result << x;
  std::cout << date << " => " << rate << " = " << result.str() << std::endl;
}

/*
  receives both db already fetched to container
  opens input file and splits each line into date and rate
  performs string and number validations and outputs accordingly
*/
void  BitcoinExchange::dbDebug(const char* input) {
  dbOpen();
  std::ifstream inputFile(input, std::ios::in);
  if (!inputFile.is_open())
  {
    std::string err("unable to open file ==> ");
    err += std::string(input);
    throw std::ios_base::failure(err.c_str());
  }
  std::string line;
  std::getline(inputFile, line);
  while (std::getline(inputFile, line)) {
    try {
      std::string date;
      std::string rate;
      if (line.find("|") != line.npos) {
        date = line.substr(0, line.find("|"));
        rate = line.substr(line.find("|") + 1);
        if (validateDate(date) && isValidRate(rate)) {
          multiply(date, rate);
          continue ;
        }
      }
      throw std::invalid_argument(std::string(std::string("bad input ==> ")
        + line).c_str());
    }
    catch (std::exception const& e) {
      std::cout << "Error: " << e.what() << std::endl;
    }
  }
}

std::map<std::string,double> const& BitcoinExchange::getDB() const { return db; }

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const& other) : db(other.getDB()) {}

BitcoinExchange& BitcoinExchange::operator=(BitcoinExchange const& other) {
  if (this != &other) {
    db = other.getDB();
  }
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}
