#ifndef CSHARP_H
#define CSHARP_H
#include "ClassUnit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"

class CSharpClassUnit : public ClassUnit
{
public:
    explicit CSharpClassUnit(const std::string& name, Flags modifier = ClassUnit::PUBLIC);
    ~CSharpClassUnit();
    std::string compile(unsigned int level = 0) const;
};

class CSharpMethodUnit : public MethodUnit
{
public:
    explicit CSharpMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    ~CSharpMethodUnit();
    std::string compile(unsigned int level = 0) const;
};

class CSharpPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit CSharpPrintOperatorUnit(const std::string& text);
    ~CSharpPrintOperatorUnit();
    std::string compile(unsigned int level = 0) const;
};

#endif // CSHARP_H
