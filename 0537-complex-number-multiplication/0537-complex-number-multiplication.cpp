#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    string complexNumberMultiply(string num1, string num2) {
        // Parse the complex numbers to get real and imaginary parts
        int a, b, c, d;
        sscanf(num1.c_str(), "%d+%di", &a, &b);
        sscanf(num2.c_str(), "%d+%di", &c, &d);

        // Calculate the real and imaginary parts of the result
        int realPart = a * c - b * d;
        int imaginaryPart = a * d + b * c;

        // Format the result as a string in the form "real+imaginaryi"
        return to_string(realPart) + "+" + to_string(imaginaryPart) + "i";
    }
};
