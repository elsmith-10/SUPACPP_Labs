#include <iostream>
#include <cmath>

int main()
{
    //Define components of the 2D vector x and y
    float x = 7.5;
    float y = 3.5;

    //Print the values to the terminal
    std::cout << "The values of x and y are: " << x << "and " << y << std::endl;

    //Calculate the magnitude
    float mag = sqrt((x*x)+(y*y));

    //Print magnitude to the terminal
    std::cout << "The magnitude of x and y is: "<< mag << std::endl;

    return 0;
}