#include <iostream>
#include <fstream>
#include <vector>

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

    //Read the data line by line
    //std::string line;
    //while (std::getline(data_file,line)){
    //    data.push_back(line);
    //}
    
    //Output to the terminal
    //std::cout << "The data in the file is: "<< std::endl;
    //for(auto dataVal: data){
      //  std::cout << dataVal << std::endl;
    //}

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

    //Output to the terminal
    std::cout << "The data in x is: "<< std::endl;
    for(auto dataVal: x){
        std::cout << dataVal << std::endl;
    }

    std::cout << "The data in y is: "<< std::endl;
    for(auto dataVal: y){
        std::cout << dataVal << std::endl;
    }

    data_file.close(); 

    return 0;
}