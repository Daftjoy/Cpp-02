#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <iomanip>
# include <limits>
# include <string>
# include <cstdlib>

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
        //Overload assignment operator
        Fixed& operator=(const Fixed& other);
        int getRawBits( void ) const;
        void setRawBits( int const raw );
};

#endif