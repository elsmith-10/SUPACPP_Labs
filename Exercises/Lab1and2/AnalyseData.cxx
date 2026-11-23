#include <iostream>
#include <fstream>
#include <vector>
#include "CustomFunction.h"

//Create recursive loop for question 
int Recursive_loop(std::vector<std::string> x,std::vector<std::string> y){
    std::cout<<"What action would you like? (0: None, 1: Print Lines, 2: Calculate Magnitudes, 3: Linear Fit, 4: xpowery)"<<std::endl;
    int User_choice;
    std::cin>>User_choice;

    if(User_choice==1){
        print_lines(x,y);
    }
    if(User_choice==2){
        calculate_magnitude(x,y);
    }
    if(User_choice==3){
        linear_fit(x,y);
    }
     if(User_choice==4){
        xpowery(x,y);
    }
     if(User_choice>=5){
        std::cout<<"Invalid number choice."<<std::endl;
    }

    //breaks loop
    if (User_choice==0){
        return 0;
    }

    return Recursive_loop(x,y);
}

int main(){
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

    Recursive_loop(x,y);

    return 0;
}
