#include "Generation.h"

GenerateCPlusPlus::GenerateCPlusPlus() {}

GenerateCPlusPlus::~GenerateCPlusPlus() {}

std::shared_ptr<ClassUnit>GenerateCPlusPlus::GenerateClassUnit(const std::string name, unsigned int modifier)
{
    return std::make_shared<CPlusPlusClassUnit >(name, ClassUnit::DEFAULT);
}

std::shared_ptr<MethodUnit>GenerateCPlusPlus::GenerateMethodUnit(const std::string name, const std::string returnType, unsigned int Flags)
{
    return std::make_shared<CPlusPlusMethodUnit >(name, returnType, Flags);
}

std::shared_ptr<PrintOperatorUnit>GenerateCPlusPlus::GeneratePrintOperatorUnit(const std::string text)
{
    return std::make_shared<CPlusPlusPrintOperatorUnit >(text);
}

GenerateJava::GenerateJava() {}

GenerateJava::~GenerateJava() {}

std::shared_ptr<ClassUnit> GenerateJava::GenerateClassUnit(std::string name, unsigned int modifier)
{
    return std::make_shared< JavaClassUnit >(name, modifier);
}

std::shared_ptr<MethodUnit> GenerateJava::GenerateMethodUnit(std::string name, std::string returnType, unsigned int flags)
{
    return std::make_shared< JavaMethodUnit >(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> GenerateJava::GeneratePrintOperatorUnit(std::string text)
{
    return std::make_shared< JavaPrintOperatorUnit >(text);
}

GenerateCSharp::GenerateCSharp() {}

GenerateCSharp::~GenerateCSharp() {}

std::shared_ptr<ClassUnit> GenerateCSharp::GenerateClassUnit(std::string name, unsigned int modifier)
{
    return std::make_shared< CSharpClassUnit >(name, modifier);
}

std::shared_ptr<MethodUnit> GenerateCSharp::GenerateMethodUnit(std::string name, std::string returnType, unsigned int flags)
{
    return std::make_shared< CSharpMethodUnit >(name, returnType, flags);
}

std::shared_ptr<PrintOperatorUnit> GenerateCSharp::GeneratePrintOperatorUnit(std::string text)
{
    return std::make_shared< CSharpPrintOperatorUnit >(text);
}
