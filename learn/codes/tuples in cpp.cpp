#include <iostream>
#include <tuple>

int main() {
    std::tuple<int, int, std::string> student {1, 2, "Forhad"};

    // extract bojects from a tuple
    auto [id, roll, name] = student;
    std::cout << "id: " << id << ", roll: " << roll << ", name: " << name << std::endl;

    // get ith item from a tuple
    std::cout << "roll: " << std::get<1>(student) << std::endl;

    // create tuple using make_tuple()
    auto anotherTuple = std::make_tuple(2, 10, "Rasel");

    // extract bojects from a tuple
    auto [anotherId, anotherRoll, anotherName] = anotherTuple;
    std::cout << "id: " << anotherId << ", roll: " << anotherRoll << ", name: " << anotherName << std::endl;

    // get ith item from a tuple
    std::cout << "roll: " << std::get<1>(anotherTuple) << std::endl;
    
    return 0;
}

// id: 1, roll: 2, name: Forhad
// roll: 2
// id: 2, roll: 10, name: Rasel
// roll: 10
