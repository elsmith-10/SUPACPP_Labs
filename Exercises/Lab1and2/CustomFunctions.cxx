#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
 
//Create overload print functions
std::vector<std::string> print(std::vector<std::string> A){
for(int i = 0; i < A.size(); i++){
        std::cout << A[i] << std::endl;
return A;        
}
}
float print(float A){
    std::cout << A << std::endl;
return A;
}
int print(int A){
    std::cout << A << std::endl;
return A;
}
std::string print(std::string A){
    std::cout << A << std::endl;
return A;
}

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

    //Print magnitudes to terminal
    print("The magnitudes of the x and y values are: ");
    print(mag);
}

//Function for straight line fitting 
std::string linear_fit(std::vector<std::string> x, std::vector<std::string> y){
    //Make variables for m and c
    float m;
    float c;

    //Set initial values for the sums of the parameters for least squares
    float sum_x = 0;
    float sum_y = 0;
    float sum_xy = 0;
    float sum_x_sqrd = 0;
    int N = x.size();

    //Calculate parametrs of sum of least squares
    for (int i=0; i<x.size(); i++){
        float x_val = std::stof(x[i]);
        float y_val = std::stof(y[i]);
        float x_sqrd = x_val * x_val;

        sum_x += x_val;
        sum_y += y_val;
        sum_xy += x_val * y_val;
        sum_x_sqrd += x_sqrd;
    } 
    
    //Calculate m and c
    m = ((N*sum_xy)-(sum_x*sum_y))/((N*sum_x_sqrd)-(sum_x*sum_x));
    c = ((sum_x_sqrd*sum_y)-(sum_xy*sum_x))/((N*sum_x_sqrd)-(sum_x*sum_x));

    //print to terminal
    print("The straight line fit is: y = " + std::to_string(m) + "x + " + std::to_string(c));

    //Create file with the straight line fit
    std::string filename = "linear_fit.txt";
    std::ofstream outputfile;
    outputfile.open(filename);

    //Append file with straight line fit
    outputfile << "y = " << m << "x + " << c << std::endl;

    outputfile.close();

    return filename;
}
