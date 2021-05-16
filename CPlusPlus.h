#ifndef CPLUSPLUS_H
#define CPLUSPLUS_H
#include "ClassUnit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"

class CPlusPlusClassUnit : public ClassUnit
{
public:
    explicit CPlusPlusClassUnit(const std::string& name, Flags modifier = ClassUnit::DEFAULT);
    ~CPlusPlusClassUnit();
    std::string compile(unsigned int level = 0) const;
};

class CPlusPlusMethodUnit : public MethodUnit
{
public:
    explicit CPlusPlusMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    ~CPlusPlusMethodUnit();
    std::string compile(unsigned int level = 0) const;
};

class CPlusPlusPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit CPlusPlusPrintOperatorUnit(const std::string& text);
    ~CPlusPlusPrintOperatorUnit();
    std::string compile(unsigned int level = 0) const;
};

#endif // CPLUSPLUS_H
