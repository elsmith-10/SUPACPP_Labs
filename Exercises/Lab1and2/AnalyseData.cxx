#include <iostream>
#include <fstream>
#include <vector>
#include "CustomFunctions.h"

//Main function for the choices selection
void choice_function(const std::vector<std::string>& x, const std::vector<std::string>& y)
{
    std::cout << "What function would you like to use? (1: Print Lines, 2: Calculate Magnitudes, 3: Linear Fit, 4: x to power y)" << std::endl;
    int function_choice;
    std::cin >> function_choice;

    if(function_choice == 1){
        std::vector<std::string> A = print_lines(x, y);
    }
    else if(function_choice == 2){
        std::vector<std::string> B = calculate_magnitude(x, y);
    }
    else if(function_choice == 3){
        std::string C = linear_fit(x, y);
    }
    else if(function_choice == 4){
        std::vector<std::string> D = xpowery(x, y);
    }
    else{
        std::cout << "Not a function choice" << std::endl;
    }
}

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

    //after splitting data, run through choice and actions
    choice_function(x,y);

    //Ask user if they would like to choose another function or end

    std::cout << "Do you want to perform another action? (1: Yes, 0: No)" << std::endl;
    int user_decision;
    std::cin>>user_decision;

    if(user_decision==1){
        choice_function(x, y);
    }
    else if(user_decision==0){
        std::cout<<"End actions"<<std::endl;
    }
    else{
            std::cout << "Not an action choice" << std::endl;
        }

    data_file.close(); 

    return 0;
}