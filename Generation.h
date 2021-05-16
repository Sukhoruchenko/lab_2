#ifndef GENERATION_H
#define GENERATION_H
#include "ClassUnit.h"
#include "Unit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"
#include "CPlusPlus.h"
#include "Java.h"
#include "CSharp.h"

class Generate_
{
public:

    virtual std::shared_ptr<ClassUnit>GenerateClassUnit(const std::string name, unsigned int modifier = ClassUnit::DEFAULT) = 0;
    virtual std::shared_ptr<MethodUnit>GenerateMethodUnit(const std::string name, const std::string returnType, unsigned int Flags = MethodUnit::DEFAULT) = 0;
    virtual  std::shared_ptr<PrintOperatorUnit>GeneratePrintOperatorUnit(const std::string text) = 0;
    virtual ~Generate_() {};
};

class GenerateCPlusPlus : public Generate_
{
public:
    explicit GenerateCPlusPlus();
    ~GenerateCPlusPlus();

    std::shared_ptr<ClassUnit>GenerateClassUnit(const std::string name, unsigned int modifier = ClassUnit::DEFAULT);
    std::shared_ptr<MethodUnit>GenerateMethodUnit(const std::string name, const std::string returnType, unsigned int Flags = MethodUnit::DEFAULT);
    std::shared_ptr<PrintOperatorUnit>GeneratePrintOperatorUnit(const std::string text);
};

class GenerateJava : public Generate_
{
public:
    explicit GenerateJava();
    ~GenerateJava();

    std::shared_ptr<ClassUnit> GenerateClassUnit(const std::string name, unsigned int modifier = ClassUnit::DEFAULT);
    std::shared_ptr<MethodUnit> GenerateMethodUnit(const std::string name, const std::string returnType, unsigned int flags = MethodUnit::DEFAULT);
    std::shared_ptr<PrintOperatorUnit> GeneratePrintOperatorUnit(const std::string text);
};

class GenerateCSharp : public Generate_
{
public:
    explicit GenerateCSharp();
    ~GenerateCSharp();

    std::shared_ptr<ClassUnit> GenerateClassUnit(const std::string name, unsigned int modifier = ClassUnit::DEFAULT);
    std::shared_ptr<MethodUnit> GenerateMethodUnit(const std::string name, const std::string returnType, unsigned int flags = MethodUnit::DEFAULT);
    std::shared_ptr<PrintOperatorUnit> GeneratePrintOperatorUnit(const std::string text);
};

#endif // GENERATION_H
