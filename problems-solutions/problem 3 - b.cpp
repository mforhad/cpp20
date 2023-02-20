#include <iostream>

struct FunctionParameter {};

struct TestClass{
    void function(FunctionParameter&)            {std::cout<<"a";}
    void function(FunctionParameter&&)           {std::cout<<"b";}
    void function(FunctionParameter&)    const   {std::cout<<"c";}
    void function(FunctionParameter&&)   const   {std::cout<<"d";}
    void function(const FunctionParameter&)      {std::cout<<"e";}
    void function(const FunctionParameter&&)     {std::cout<<"f";}
    void function(const FunctionParameter&) const {std::cout<<"g";}
    void function(const FunctionParameter&&) const {std::cout<<"h";}
};

int main() {
    FunctionParameter fptcObj{};
    const FunctionParameter& cfptcObj = fptcObj;

    TestClass tcObj{};
    const TestClass& ctcObj = tcObj;

    tcObj.function(cfptcObj);
    ctcObj.function(std::move(fptcObj));
    tcObj.function(fptcObj);
    ctcObj.function(cfptcObj);
    ctcObj.function(FunctionParameter{});
    tcObj.function(std::move(cfptcObj));

    return 0;
}