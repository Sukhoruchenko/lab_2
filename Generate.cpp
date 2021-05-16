#include "Generate.h"

Generate::Generate(const std::shared_ptr<Generate_>& Gener):
    generat(Gener) {}

void Generate::setGener(const std::shared_ptr<Generate_>& Gener)
{
    generat = Gener;
}

std::shared_ptr<Generate_> Generate::getGener()
{
    return generat;
}

std::string Generate::generateProgram()
{
    auto metod = generat->GenerateClassUnit("MyClass", ClassUnit::PUBLIC | ClassUnit::ABSTRACT);
    auto method1 = generat->GenerateMethodUnit( "testFunc1", "void", 0 );
    metod->add(method1, ClassUnit::PUBLIC );
    auto method2 = generat->GenerateMethodUnit( "testFunc2", "void", MethodUnit::STATIC );
    metod->add(method2, ClassUnit::PRIVATE);
    auto method3 = generat->GenerateMethodUnit( "testFunc3", "void", MethodUnit::VIRTUAL | MethodUnit::CONST );
    metod->add(method3, ClassUnit::PUBLIC);
    auto method4 = generat->GenerateMethodUnit( "testFunc4", "void", MethodUnit::STATIC );
    metod->add(method4, ClassUnit::PROTECTED);
    auto method5 = generat->GenerateMethodUnit( "testFunc5", "void", MethodUnit::ABSTRACT | MethodUnit::INTERNAL );
    metod->add(method5, ClassUnit::PRIVATE);
    auto method6 = generat->GenerateMethodUnit( "testFunc6", "void", MethodUnit::FINAL );
    metod->add(method6, ClassUnit::PUBLIC);
    auto g = generat -> GeneratePrintOperatorUnit( R"(Hello,world!\n)" );
    method4->add(g);

    return metod->compile();
}
