#ifndef METHODUNIT_H
#define METHODUNIT_H
#include "Unit.h"
#include <iostream>
#include <string>
#include <vector>

class MethodUnit : public Unit
{
public:
    enum Modifier
    {
        STATIC = 1,
        CONST = 1 << 1,
        VIRTUAL = 1 << 2,
        DEFAULT = 0,
        ABSTRACT = 1 << 3, // Java
        FINAL = 1 << 4, // Java
        INTERNAL = 1 << 5, // C#
    };
public:
    MethodUnit(const std::string& name, const std::string& returnType, Flags flags);
    void add( const std::shared_ptr< Unit >& unit, Flags = Modifier::STATIC);
    std::string compile( unsigned int level = 0 ) const = 0;
protected:
     std::string m_name;
     std::string m_returnType;
     Flags m_flags;
     std::vector< std::shared_ptr< Unit > > m_body;
};

#endif // METHODUNIT_H
