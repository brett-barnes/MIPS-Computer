// C++ code to convert the given RGB
// color code to Hex color code
 
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
#include <iomanip>

using namespace std;
 
// function to convert decimal to hexadecimal
string decToHexa(int n)
{
    // char array to store hexadecimal number
    char hexaDeciNum[2];
 
    // counter for hexadecimal number array
    int i = 0;
    while (n != 0) {
 
        // temporary variable to store remainder
        int temp = 0;
 
        // storing remainder in temp variable.
        temp = n % 16;
 
        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }
 
        n = n / 16;
    }
 
    string hexCode = "";
    if (i == 2) {
        hexCode.push_back(hexaDeciNum[0]);
        hexCode.push_back(hexaDeciNum[1]);
    }
    else if (i == 1) {
        hexCode = "0";
        hexCode.push_back(hexaDeciNum[0]);
    }
    else if (i == 0)
        hexCode = "00";
 
    // Return the equivalent
    // hexadecimal color code
    return hexCode;
}
 
// Function to convert the
// RGB code to Hex color code
string convertRGBtoHex(int R, int G, int B)
{
    if ((R >= 0 && R <= 255)
        && (G >= 0 && G <= 255)
        && (B >= 0 && B <= 255)) {
 
        string hexCode = "#";
        hexCode += decToHexa(R);
        hexCode += decToHexa(G);
        hexCode += decToHexa(B);
 
        return hexCode;
    }
 
    // The hex color code doesn't exist
    else
        return "-1";
}
 
 std::string rgbToHex(int red, int green, int blue) {
    // Ensure that the RGB values are within the valid range (0-255)
    red = std::min(255, std::max(0, red));
    green = std::min(255, std::max(0, green));
    blue = std::min(255, std::max(0, blue));

    // Convert RGB to hex
    std::stringstream hexStream;
    hexStream << std::setfill('0') << std::setw(2) << std::hex << red;
    hexStream << std::setfill('0') << std::setw(2) << std::hex << green;
    hexStream << std::setfill('0') << std::setw(2) << std::hex << blue;

    return hexStream.str();
}


 std::vector<std::string> split(const std::string &s, const std::string &split_on) {
    std::vector<std::string> split_terms;
    int cur_pos = 0;
    while(cur_pos >= 0) {
        int new_pos = s.find_first_not_of(split_on, cur_pos);
        cur_pos = s.find_first_of(split_on, new_pos);
        if(new_pos == -1 && cur_pos == -1) break; //This line is new
        split_terms.push_back(s.substr(new_pos,cur_pos-new_pos));
    }
    return split_terms;
}



const std::string WHITESPACE = " \n\r\t\f\v";

// Driver program to test above function
int main(int argc, char* argv[])
{
    std::string str;
    std::ifstream infile(argv[1]);

    std::ofstream color_outfile;
    color_outfile.open(argv[argc - 1]);




    if (!infile) { // if file can't be opened, need to let the user know
        std::cerr << "Error: could not open file: " << argv[1] << std::endl;
        exit(1);
    }
        while (getline(infile, str))
        { 
            std::vector<std::string> terms = split(str, WHITESPACE+",()");

            string hex = rgbToHex(stoi(terms[0]),stoi(terms[1]),stoi(terms[2]));
            color_outfile << hex;
            //color_outfile.write(hex.c_str(), 7);
            //cout << "RGB: " << terms[0] << terms[1] << terms[2] << ", Hex: " << hex;
            string blank = "\n";
            color_outfile.write(blank.c_str(), 1);
        }
 
    return 0;
}