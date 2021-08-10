/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:27:31 by antmarti          #+#    #+#             */
/*   Updated: 2021/08/10 19:29:44 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( Fixed( 5.05f ) / Fixed( 2 ) );
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    if (a < b)
        std::cout << "a is smaller than b" << std::endl;
    else
        std::cout << "b is smaller than a" << std::endl;
    
    //std::cout << ++a << std::endl;
    //std::cout << a++ << std::endl;
    //std::cout << a << std::endl;
    //std::cout << b << std::endl;
    //std::cout << Fixed::max( a, b ) << std::endl;
    return 0;
}