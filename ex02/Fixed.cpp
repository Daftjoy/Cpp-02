/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antmarti <antmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 18:27:22 by antmarti          #+#    #+#             */
/*   Updated: 2022/07/05 20:11:32 by antmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void)
{
    std::cout << "Default constructor called" << std::endl;
    this->fixed_point = 0;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
    std::cout << "Copy constructor called" << std::endl;
    this->fixed_point = other.getRawBits();
}

Fixed::Fixed(const int fixed_point)
{
    std::cout << "Int constructor called" << std::endl;
    this->fixed_point = fixed_point << this->fractional_bits;
}

Fixed::Fixed(const float fixed_point)
{
    std::cout << "Float constructor called" << std::endl;
    this->fixed_point =(int)(roundf(fixed_point * (1 << this->fractional_bits)));
}

Fixed& Fixed::operator=(Fixed const &other)
{
    std::cout << "Assignation operator called" << std::endl;
    this->setRawBits(other.getRawBits());
    return *this;
}

bool Fixed::operator>(Fixed const &other) const
{
    return(this->getRawBits() >  other.getRawBits());
}

bool Fixed::operator<(Fixed const &other) const
{
    return(this->getRawBits() <  other.getRawBits());
}

bool Fixed::operator>=(Fixed const &other) const
{
    return(this->getRawBits() >=  other.getRawBits());
}

bool Fixed::operator<=(Fixed const &other) const
{
    return(this->getRawBits() <=  other.getRawBits());
}

bool Fixed::operator==(Fixed const &other) const
{
    return(this->getRawBits() ==  other.getRawBits());
}

bool Fixed::operator!=(Fixed const &other) const
{
    return(this->getRawBits() !=  other.getRawBits());
}

Fixed Fixed::operator+(Fixed const &other)
{
    Fixed fix;
    fix.setRawBits(this->getRawBits() + other.getRawBits());
    return(fix);
}

Fixed Fixed::operator-(Fixed const &other)
{
    Fixed fix;
    fix.setRawBits(this->getRawBits() - other.getRawBits());
    return(fix);
}

Fixed Fixed::operator*(Fixed const &other)
{
    Fixed fix;
    fix.setRawBits((this->getRawBits() * other.getRawBits()) >> this->fractional_bits);
    return(fix);
}

Fixed Fixed::operator/(Fixed const &other)
{
    Fixed fix;
    fix.setRawBits((this->getRawBits() << this->fractional_bits) / other.getRawBits());
    return(fix);
}

Fixed &Fixed::operator++(void)
{
    this->fixed_point++;
    return(*this);
}

Fixed Fixed::operator++(int)
{
    Fixed fix(*this);
    operator++();
    return(fix);
}

Fixed &Fixed::operator--(void)
{
    this->fixed_point--;
    return(*this);
}

Fixed Fixed::operator--(int)
{
    Fixed fix(*this);
    operator--();
    return(fix);
}

int Fixed::getRawBits(void) const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->fixed_point);
}

void Fixed::setRawBits(int const raw)
{
    this->fixed_point = raw;
}

float Fixed::toFloat (void) const
{
    return ((float)this->fixed_point / (float) (1 << this->fractional_bits));
}

int Fixed::toInt (void) const
{
    return (int) (this->fixed_point / (int) (1 << this->fractional_bits));
}




Fixed &Fixed::min( Fixed &first, Fixed &second)
{
	if (first > second)
		return (second);
	return (first);
}


Fixed const &Fixed::min( Fixed const &first, Fixed const &second)
{
	if (first > second)
		return (second);
	return (first);
}


Fixed& Fixed::max(Fixed& first, Fixed& second)
{
    if (first > second)
        return (first);   
    return (second);
}

Fixed const &Fixed::max( Fixed const &first, Fixed const &second)
{
	if (first > second)
        return (first);   
    return (second);
}
 
 
std::ostream& operator<<(std::ostream& os, const Fixed& fixed)
{
    os << fixed.toFloat();
    return os;
}
