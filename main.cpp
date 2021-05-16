#include <iostream>
#include <memory>
#include "Generate.h"
#include "Generation.h"

using std::cout;

int main()
{
    cout << "generator CPlusPlus:" << std::endl;
    cout << std::endl;
    Generate Cplus(std::make_shared<GenerateCPlusPlus>());
    cout << Cplus.generateProgram() << std::endl;

    cout << "generator Java:" << std::endl;
    cout << std::endl;
    Generate Java(std::make_shared<GenerateJava>());
    cout << Java.generateProgram() << std::endl;

    cout << "generator CSharp:" << std::endl;
    cout << std::endl;
    Generate CSharp(std::make_shared<GenerateCSharp>());
    cout << CSharp.generateProgram() << std::endl;

    return 0;
}


