#include <iostream>
#include <fstream>
#include <vector>
#include "CustomFunctions.h"

int main()
{
    //Open file
    std::string inputfile = "input2D_float.txt";
    std::ifstream data_file;
    std::vector<std::string> data;
    data_file.open(inputfile);

    //Check to see the file was opened correctly
    if(!data_file.is_open()){
        std::cout << "Error openening file: " << inputfile << std::endl;
        return -1;
    }
    else{
        std::cout << "File: " << inputfile << " opened succesfully!" << std::endl;
    }

    //Create variables to write the data into
    std::vector<std::string> x;
    std::vector<std::string> y;

    //Read the data into the variables
    std::string x_val;
    std::string y_val;

    // Read one x,y pair per line and split into lists.
    while (std::getline(data_file, x_val, ',')) {
        if (!std::getline(data_file, y_val)) {
            break;
        }
        x.push_back(x_val);
        y.push_back(y_val);
    }

    //remove the tile from the lists
    x.erase(x.begin());
    y.erase(y.begin());

//Ask the user what function they would like to use
    std::cout << "What function would you like to use? (1: Print Lines, 2: Calculate Magnitudes)" << std::endl;
    int function_choice;
    std::cin >> function_choice;

    if(function_choice ==1){
        std::vector<std::string> A = print_lines(x, y);
    }
    else if(function_choice ==2){
        std::vector<std::string> B = calculate_magnitude(x, y);
    }
    else{
        std::cout << "Not a function choice" << std::endl;
    }

    std::string A = linear_fit(x, y);
    
    data_file.close(); 

    return 0;
}