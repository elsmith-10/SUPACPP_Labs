#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

//Create overload print functions
void print(std::vector<std::string> A){
for(int i = 0; i < A.size(); i++){
        std::cout << A[i] << std::endl;        
}
}
void print(float A){
    std::cout << A << std::endl;
}
void print(int A){
    std::cout << A << std::endl;
}
void print(std::string A){
    std::cout << A << std::endl;
}

    //Function for printing lines
    void print_lines(std::vector<std::string> x, std::vector<std::string> y){

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

    //create a file to save the lines
    std::string filename = "print_lines.txt";
    std::ofstream outputfile;
    outputfile.open(filename);

    //Append file with x and y values
    for(int i = 0; i < N; i++){
        outputfile << x[i] << ", " << y[i]   << std::endl;
    }

    outputfile.close();
}

//Function for calculating magnitudes of x and y
void calculate_magnitude(std::vector<std::string> x, std::vector<std::string> y){
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

    //Create a file for magnitudes
    std::string filename = "magnitude.txt";
    std::ofstream outputfile;
    outputfile.open(filename);

    //Append file with magnitudes
    for(int i = 0; i < mag.size(); i++){
        outputfile << mag[i] << std::endl;    
}
    outputfile.close();
}

//Function for linear fitting function
void linear_fit(std::vector<std::string> x, std::vector<std::string> y){
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
        sum_xy += (x_val * y_val);
        sum_x_sqrd += x_sqrd;
    } 
    
    //Calculate m and c
    m = ((N*sum_xy)-(sum_x*sum_y))/((N*sum_x_sqrd)-(sum_x*sum_x));
    c = ((sum_x_sqrd*sum_y)-(sum_xy*sum_x))/((N*sum_x_sqrd)-(sum_x*sum_x));

    //Open and split errors file into x and y errors
    //Open file
    std::string inputfile = "error2D_float.txt";
    std::ifstream data_file;
    std::vector<std::string> data;
    data_file.open(inputfile);

    //Create variables to write the data into
    std::vector<std::string> x_error;
    std::vector<std::string> y_error;

    //Read the data into the variables
    std::string x_err_val;
    std::string y_err_val;

    // Read one x,y pair per line and split into lists.
    while (std::getline(data_file, x_err_val, ',')) {
        if (!std::getline(data_file, y_err_val)) {
            break;
        }
        x_error.push_back(x_err_val);
        y_error.push_back(y_err_val);
    }

    //remove the tile from the lists
    x_error.erase(x_error.begin());
    y_error.erase(y_error.begin());

    data_file.close();

    //Create vectors for the parameters of chi squared
    std::vector<std::string> observed = y;
    std::vector<std::string> expected;
    std::vector<std::string> error = y_error;

    //Calculate expected values from the straight line fit
    for(int i = 0; i < x.size(); i++){
        float expected_val = m*std::stof(x[i]) + c;
        expected.push_back(std::to_string(expected_val));
    }

    //Calculate the chi squared value
    float chi_squared = 0;
    for(int i = 0; i < observed.size(); i++){
        float obs = std::stof(observed[i]);
        float exp = std::stof(expected[i]);
        float err = std::stof(error[i]);
        chi_squared += ((obs - exp) * (obs - exp)) / (err * err);
    }

    //print to terminal
    print("The straight line fit is: y = " + std::to_string(m) + "x + " + std::to_string(c));
    print("The chi-squared value is: " + std::to_string(chi_squared));

    //Create file with the straight line fit
    std::string filename = "linear_fit.txt";
    std::ofstream outputfile;
    outputfile.open(filename);

    //Append file with straight line fit
    outputfile << "y = " << m << "x + " << c << std::endl;
    outputfile << "Chi-squared value: " << chi_squared << std::endl;

    outputfile.close();
}

//Function for recursive method for xpowery
float power(float x, int y){
     if (y == 0){
          return 1;
        }
     else if (y > 0){
           return x * power(x, y - 1);
        }
    else{
        return 1 / power(x, -y);
        }
    }

    //function for calculating xpowery 
void xpowery(std::vector<std::string>x,std::vector<std::string>y){
    std::vector<std::string> result_list;
    //loop through the x and y values and calculate x to the power of y
    for (int i = 0; i < x.size(); i++){
        float x_val = std::stof(x[i]);
        int y_val = std::stoi(y[i]);
        float result = power(x_val, y_val);
        std::cout << x_val << " to power of " << y_val << " is: " << result << std::endl;
        result_list.push_back(std::to_string(result));
    }

    //Create a file for x to power y
    std::string filename = "xpowery.txt";
    std::ofstream outputfile;
    outputfile.open(filename);

    //Append file with x to power y
    for(int i = 0; i < result_list.size(); i++){
        outputfile << result_list[i] << std::endl;     
}
    outputfile.close();
}