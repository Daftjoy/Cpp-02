/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:27:26 by antmarti          #+#    #+#             */
/*   Updated: 2021/08/10 18:27:27 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <iomanip>
# include <limits>
# include <string>
# include <cstdlib>
# include <cmath>

class Fixed
{
    private:
        int fixed_point;
        static const int fractional_bits = 8;
    
    public:
        Fixed(void);
        ~Fixed();
        //copy constructor
        Fixed(const Fixed& other);
        Fixed(const int fixed_point);
        Fixed(const float fixed_point);
        //Overload assignment operator
        Fixed& operator=(const Fixed& other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat ( void ) const;
        int toInt ( void ) const;
};


std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
        

#endif