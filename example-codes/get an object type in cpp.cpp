#include <iostream>
#include <memory>
#include <boost/type_index.hpp>

using namespace std;
using namespace boost::typeindex;

int main() {
    auto var1 = {20, 30};
    auto var2 {make_unique<int>()};

    cout<<"Type of var1 = " << type_id_with_cvr<decltype(var1)>().pretty_name() << endl;
    cout<<"Type of var2 = " << type_id_with_cvr<decltype(var2)>().pretty_name() << endl;
    
    return 0;
}


// ########## Output ############
// Type of var1 = std::initializer_list<int>
// Type of var2 = std::unique_ptr<int, std::default_delete<int> >
