/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:27:26 by antmarti          #+#    #+#             */
/*   Updated: 2022/06/30 21:29:57 by antmarti         ###   ########.fr       */
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
        
        //copy constructors
        Fixed(const Fixed& other);
        Fixed(const int fixed_point);
        Fixed(const float fixed_point);
        
        //Overload assignment operators
        Fixed& operator=(const Fixed& other);
        
        //Comparison operators
        bool operator>(const Fixed&  other) const;
        bool operator<(const Fixed&  other) const;
        bool operator>=(const Fixed&  other) const;
        bool operator<=(const Fixed&  other) const;
        bool operator==(const Fixed&  other) const;
        bool operator!=(const Fixed&  other) const;
        
        //Arithmetic operators
        Fixed operator+(const Fixed& other);
        Fixed operator-(const Fixed& other);
        Fixed operator*(const Fixed& other);
        Fixed operator/(const Fixed& other);

        Fixed &operator++(void);
        Fixed operator++(int);        
        Fixed &operator--(void);
        Fixed operator--(int);
        
        int getRawBits( void ) const;
        void setRawBits( int const raw );
        float toFloat ( void ) const;
        int toInt ( void ) const;
        
        static Fixed &min(Fixed &a, Fixed &b);
        static Fixed const &min(Fixed const &a, Fixed const &b);

       
};
std::ostream& operator<<(std::ostream& os, const Fixed& fixed);
Fixed &min(Fixed &a, Fixed &b);


        

#endif