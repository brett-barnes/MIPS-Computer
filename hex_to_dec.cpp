// C++ program to convert hexadecimal to decimal 
using namespace std; 
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <sstream>
#include <fstream>
#include <iomanip>
// Function to convert hexadecimal to decimal 

int hexStringToDecimal(const std::string& hexString) {
    try {
        size_t processedChars = 0;
        return std::stoi(hexString, &processedChars, 16);

        // If you want to check for invalid characters or incomplete conversion,
        // you can use the following code:
        // if (processedChars != hexString.length()) {
        //     throw std::invalid_argument("Invalid hex string");
        // }
    } catch (const std::invalid_argument& e) {
        // Handle the case where the conversion fails
        std::cerr << "Error: " << e.what() << std::endl;
        return 0; // You may choose a different way to handle errors
    }
}
	// code above is contributed by rakeshsahni 


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
int main(int argc, char* argv[]) 
{ 
	string hexNum = "0x1A"; 
	cout << (hexStringToDecimal(hexNum)); 


    std::string str;
    std::ifstream infile(argv[1]);

    std::ofstream color_outfile;
    color_outfile.open(argv[2]);

    if (!infile) { // if file can't be opened, need to let the user know
        std::cerr << "Error: could not open file: " << argv[1] << std::endl;
        exit(1);
    }
        while (getline(infile, str))
        { 
            string ns = "0x" + str;
            int dec = hexStringToDecimal(ns);
            //color_outfile.write((char *)&dec, sizeof(int));
            color_outfile << dec;
            string blank = " ";
            color_outfile.write(blank.c_str(), 1);
        }
    infile.close();

 
	return 0; 
}
