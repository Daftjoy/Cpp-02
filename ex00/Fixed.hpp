#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
    private:
        int fixed_point;
        static const int fractional_bits = 8;
    
    public:
        Fixed(int fixed_point = 0);
        ~Fixed();
        //copy constructor
        Fixed(const Fixed& other);
        //Overload assignment operator
        Fixed& operator=(const Fixed& other);
        int getRawBits( void ) const;
        int void setRawBits( int const raw );
}

#endif