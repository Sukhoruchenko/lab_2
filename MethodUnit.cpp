#include "MethodUnit.h"

MethodUnit::MethodUnit(const std::string& name, const std::string& returnType, Flags flags) :
    m_name( name ), m_returnType( returnType ), m_flags( flags ) {}


void MethodUnit::add(const std::shared_ptr< Unit > & unit, Flags)
{
    m_body.push_back(unit);
}
