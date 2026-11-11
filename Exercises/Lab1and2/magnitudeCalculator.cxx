#include <iostream>
#include <cmath>

int main()
{
    //Ask user for input
    std::cout << "Please submit two numbers to calculate the magnitude" << std::endl;
    
    //Define variables
    float x;
    float y;

    //Gain user input for variables
    std::cin >> x;
    std::cin >> y;

    //Calculate magnitude
    float mag = sqrt((x*x)+(y*y));

    //Print output to terminal
    std::cout << "The magnitude of "<< x << " and " << y << "is: "<< mag << std::endl;

    return 0;
}