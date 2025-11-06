/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <joandre-@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 14:37:31 by joandre-          #+#    #+#             */
/*   Updated: 2025/11/06 00:16:06 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

// swap() template declarations that work with all native data type arguments
template void swap<long long>(long long& v1, long long& v2);
template void swap<unsigned long long>(unsigned long long& v1, unsigned long long& v2);
template void swap<long double>(long double& v1, long double& v2);
template void swap<std::string>(std::string& v1, std::string& v2);

// min() template declarations that work with all native data type arguments
template long long const& min<long long>(long long const& v1, long long const& v2);
template unsigned long long const& min<unsigned long long>(unsigned long long const& v1, unsigned long long const& v2);
template long double const& min<long double>(long double const& v1, long double const& v2);
template std::string const& min<std::string>(std::string const& v1, std::string const& v2);

// max() template declarations that work with all native data type arguments
template long long const& max<long long>(long long const& v1, long long const& v2);
template unsigned long long const& max<unsigned long long>(unsigned long long const& v1, unsigned long long const& v2);
template long double const& max<long double>(long double const& v1, long double const& v2);
template std::string const& max<std::string>(std::string const& v1, std::string const& v2);
