#ifndef JAVA_H
#define JAVA_H
#include "ClassUnit.h"
#include "MethodUnit.h"
#include "PrintOperatorUnit.h"

class JavaClassUnit : public ClassUnit
{
public:
    explicit JavaClassUnit(const std::string& name, Flags modifier = ClassUnit::DEFAULT);
    ~JavaClassUnit();
    std::string compile(unsigned int level = 0) const;
};

class JavaMethodUnit : public MethodUnit
{
public:
    explicit JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    ~JavaMethodUnit();
    std::string compile(unsigned int level = 0) const;
};

class JavaPrintOperatorUnit : public PrintOperatorUnit
{
public:
    explicit JavaPrintOperatorUnit(const std::string& text);
    ~JavaPrintOperatorUnit();
    std::string compile(unsigned int level = 0) const;
};

#endif // JAVA_H
