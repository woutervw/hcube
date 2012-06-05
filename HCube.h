/*
    Project: HCube
    Filename: HCube
    Date: 01-06-2012
    Author: Wouter Van Werveke
    Mail: wouter.vanwerveke@student.ua.ac.be

    Purpose: Definition of cubes in N-dimensions.
*/

#ifndef _HCUBE_H_
#define _HCUBE_H_

class HCube
{
    public:
        // Constructor
        HCube(const int&, const double&);
        // Reduced constructor
        HCube(const int&);
        // Default constructor
        HCube();
        // Destructor
        ~HCube();

        // Set functions
        HCube setDimension(const int&);
        HCube setSide(const double&);

        // Get functions
        int getDimension();
        double getSide();
        double getVolume();

        // Sum
        friend const HCube operator+(const HCube&, const HCube&);
        // Subtraction
        friend const HCube operator-(const HCube&, const HCube&);
        // Product
        friend const HCube operator*(const HCube&, const HCube&);

    private:
        int dimension;
        double side;
};

#endif
