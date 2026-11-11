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
    std::string line;
    while (std::getline(data_file,line)){
        data.push_back(line);
    }
    
    //Output to the terminal
    std::cout << "The data in the file is: "<< std::endl;
    for(auto dataVal: data){
        std::cout << dataVal << std::endl;
    }

    data_file.close(); 

    return 0;
}