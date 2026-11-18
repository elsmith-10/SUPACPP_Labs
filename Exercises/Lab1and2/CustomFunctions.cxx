#include <iostream>
#include <vector>
#include <cmath>
 
//Function for printing lines to the terminal
std::vector<std::string> print_lines(std::vector<std::string> x, std::vector<std::string> y){
    //Question to terminal user about number of lines to print and max
    std::cout << "How many lines would you like printing? (max: " << x.size() << ")" << std::endl;
    
    //Create variable for user input
    int N;
    std::cin >> N;

    //Check to see if the user input is valid
    if(N > x.size()){
        std::cout << "The number of lines is too large, therefore the first 5 lines will be printed:" << std::endl;
        N = 5;
    }
    else{ std::cout << "The first " << N << " lines of the data are: " << std::endl;
    }
    
    //Print the x and y values together to terminal for value N
    for(int i = 0; i < N; i++){
         std::cout << x[i] << ", " << y[i] << std::endl;
    }
}

//Function for calculating the magnitudes of x and y
std::vector<std::string> calculate_magnitude(std::vector<std::string> x, std::vector<std::string> y){
    //Make vector to write the magnitudes into
    std::vector<std::string> mag;

    //Calculate the magnitudes of x and y
    for(int i = 0; i < x.size(); i++){
        float magnitude = sqrt((std::stof(x[i])*std::stof(x[i]))+(std::stof(y[i])*std::stof(y[i])));
        mag.push_back(std::to_string(magnitude));
    }

    //Print magnitudes to terminal for N specified
    std::cout << "The magnitudes of x and y are: " << std::endl;
    for(int i = 0; i < mag.size(); i++){
        std::cout << mag[i] << std::endl;
    }
}