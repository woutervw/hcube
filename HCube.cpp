/*
    Project: HCube
    Filename: HCube
    Date: 01-06-2012
    Author: Wouter Van Werveke
    Mail: wouter.vanwerveke@student.ua.ac.be

    Purpose: Implementation of HCube.
*/

#include "HCube.h"
#include "Exceptions.h"

#include <cmath>
#include <cstdlib>

// Constructor
HCube::HCube(const int& N, const double& s) : dimension(N), side(s) {};

// Reduced constructors
HCube::HCube(const int& N) : HCube(N,0.) {};
HCube::HCube(const double& s) : HCube(0,s) {};

// Default constructor
HCube::HCube() : HCube(0,0.) {};

// Destructor
HCube::~HCube() {};

// Set functions
// =============
HCube HCube::setDimension(const int& N)
{
    dimension = N;
    return *this;
};

HCube HCube::setSide(const double& s)
{
    side = s;
    return *this;
};

// Get functions
// =============
int HCube::getDimension()
{
    return dimension;
};

double HCube::getSide()
{
    return side;
};

double HCube::getVolume()
{
    return std::pow(side,dimension);
};

// Sum
const HCube operator+(const HCube& lhs, const HCube& rhs)
{
    try
    {
        if (lhs.dimension != rhs.dimension)
        {
            throw ex::incompatible_objects("Cube dimensions are incompatible for sommation.");
        }
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
        std::exit(1);
    };

    return HCube(lhs.dimension, lhs.side + rhs.side);
};

// Subtraction
const HCube operator-(const HCube& lhs, const HCube& rhs)
{
    try
    {
        if (lhs.dimension != rhs.dimension)
        {
            throw ex::incompatible_objects("Cube dimensions are incompatible for subtraction.");
        }
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
        std::exit(1);
    };

    return HCube(lhs.dimension, lhs.side - rhs.side);
};

// Product  ||  For now this is not very elegant for HCube's with a different
//              dimension (while a square multiplied with a line segment would
//              intuitively produce a bar, the current implementation squeezes
//              that bar back into a cube with only 1 defining length).
const HCube operator*(const HCube& lhs, const HCube& rhs)
{
    int d1 = lhs.dimension;
    int d2 = rhs.dimension;
    double V = std::pow(lhs.side,d1) * std::pow(rhs.side,d2);
    double newside = std::pow(V, 1/(d1+d2));
    return HCube(d1+d2, newside);
};
