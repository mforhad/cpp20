#include <iostream>
#include <string>

int main() {
    // Create a string
    std::string str{"This is a string to test the std::string, std::string_view and std::substr"};
    std::cout << str << std::endl;

    // Create a substring starting from 10th character with a length of 20 characters
    // It copies the substring into a new memory location with a O(n) complexity
    std::string subStr = str.substr(10, 20);
    std::cout << subStr << std::endl;

    // Create a string view from the original string
    // It creates a pointer to the existing stirng with a O(1) complexity
    std::string_view strView{str};
    std::cout << strView << std::endl;

    // Create a substring from the string view pointer
    // It also creates another pointer to the substring with a O(1) complexity
    std::string_view subStrView = strView.substr(10, 20);
    std::cout << subStrView << std::endl;

    // remove substring before a given position
    // Complexity: O(1)
    strView.remove_prefix(10);
    std::cout << strView << std::endl;

    return 0;
}


// ############# Output ##########
// This is a string to test the std::string, std::string_view and std::substr
// string to test the s
// This is a string to test the std::string, std::string_view and std::substr
// string to test the s
// string to test the std::string, std::string_view and std::substr
