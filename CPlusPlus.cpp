#include "CPlusPlus.h"

CPlusPlusClassUnit::CPlusPlusClassUnit(const std::string& name, Flags modifier) :
    ClassUnit(name, modifier) {}

CPlusPlusClassUnit::~CPlusPlusClassUnit() {}

std::string CPlusPlusClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level) + "class " + m_name + " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
    {
        if (m_fields[i].empty())
            continue;

        result += ACCESS_MODIFIERS[i] + ":\n";
        for (const auto& f : m_fields[i])
        {
            if (f)
            result += f->compile(level + 1);
        }
        result += "\n";
    }

    result += generateShift(level) + "};\n";

    return result;
}

CPlusPlusMethodUnit::CPlusPlusMethodUnit(const std::string& name, const std::string& returnType, Flags flags) :
   MethodUnit(name, returnType, flags) {}

CPlusPlusMethodUnit::~CPlusPlusMethodUnit() {}

std::string CPlusPlusMethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    if (m_flags & STATIC)
    {
        result += "static ";
    }
    else if (m_flags & VIRTUAL)
    {
        result += "virtual ";
    }

    result += m_returnType + " ";
    result += m_name + "()";

    if (m_flags & CONST)
    {
        result += " const";
    }

    result += " {\n";

    for (const auto& b : m_body)
    {
        if (b)
        result += b->compile(level + 1);
    }

    result += generateShift(level) + "}\n";

    return result;
}

CPlusPlusPrintOperatorUnit::CPlusPlusPrintOperatorUnit(const std::string& text) :
    PrintOperatorUnit(text) {}

CPlusPlusPrintOperatorUnit::~CPlusPlusPrintOperatorUnit() {}

std::string CPlusPlusPrintOperatorUnit::compile(unsigned int level) const
{
    return generateShift(level) + "printf( \"" + m_text + "\" );\n";
}
