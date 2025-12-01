/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/20 00:27:11 by joandre-          #+#    #+#             */
/*   Updated: 2025/12/01 17:54:53 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdexcept>
#include <map>
#include <ctime>
#include <algorithm>

#define DB_FILE "data.csv"

class BitcoinExchange {
  private:
    std::map<std::string, double> db;
    void dbOpen();
    void multiply(std::string const&, std::string const&);
  public:
    void dbDebug(const char* input);
    std::map<std::string,double> const& getDB() const;
    BitcoinExchange();
    BitcoinExchange(BitcoinExchange const&);
    BitcoinExchange& operator=(BitcoinExchange const&);
    ~BitcoinExchange();
};

#endif
