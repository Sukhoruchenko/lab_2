#include "ClassUnit.h"

ClassUnit::ClassUnit(const std::string& name, Flags modifier) :
    m_name( name ),
    m_modifier(modifier)
    {
        m_fields.resize( ACCESS_MODIFIERS.size() );
    }

void ClassUnit::add(const std::shared_ptr< Unit > & unit, Flags flags)
{
    int accessModifier = PRIVATE;

    if (flags < ACCESS_MODIFIERS.size())
    {
        accessModifier = flags;
    }

    m_fields[accessModifier].push_back(unit);
}

const std::vector< std::string > ClassUnit::ACCESS_MODIFIERS = { "public","protected", "private" };
