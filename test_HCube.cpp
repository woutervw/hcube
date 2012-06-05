/*
    Project: HCube
    Filename: test_HCube
    Date: 02-06-2012
    Author: Wouter Van Werveke
    Mail: wouter.vanwerveke@student.ua.ac.be

    Purpose: Testing HCube.
*/

#include "HCube.h"

#include <iostream>

int main()
{
    HCube point();
    std::cout << "Created a HCube with dimension " << point.getDimension() << " and sidelength " << point.getSide() << std::endl;
    HCube line(1,1.);
    HCube square(2,1.);
    HCube cube(3,1.);

    cube = line*square;
    cube = square*line;
    point = point*line;
    line = line+line;

    // TODO +=, -= and *= operators as well as product with scalar (e.g. 2*line)

    return 0;
};
