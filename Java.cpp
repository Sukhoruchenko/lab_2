#include "Java.h"

JavaClassUnit::JavaClassUnit(const std::string& name, Flags modifier) :
    ClassUnit(name, modifier) {}

JavaClassUnit::~JavaClassUnit() {}

std::string JavaClassUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);


    if (m_modifier & PRIVATE)
        result += "private ";
    else if (m_modifier & PROTECTED)
        result += "protected ";
    else
        result += "public ";

    if (m_modifier & ABSTRACT)
        result += "abstract ";
    else if (m_modifier & FINAL)
        result += "final ";

    result += "class " + m_name + " ";

    result += " {\n";

    for (size_t i = 0; i < ACCESS_MODIFIERS.size(); ++i)
    {
        if (m_fields[i].empty())
            continue;

        for (const auto& f : m_fields[i])
        {
            if (f)
            result += generateShift(level + 1) + ACCESS_MODIFIERS[i] + " " + f->compile(level);//
        }
        result += "\n";
    }

    result += generateShift(level) + "};\n";

    return result;
}

JavaMethodUnit::JavaMethodUnit(const std::string& name, const std::string& returnType, Flags flags) :
    MethodUnit(name, returnType, flags) {}

JavaMethodUnit::~JavaMethodUnit() {}

std::string JavaMethodUnit::compile(unsigned int level) const
{
    std::string result = generateShift(level);

    // Методы abstract не могут быть static или final

    if (m_flags & STATIC)
        result += "static ";
    else if (m_flags & ABSTRACT)
        result += "abstract ";
    else if (m_flags & FINAL)
        result += "final ";

    result += m_returnType + " ";
    result += m_name + "()";
    result += " {\n";

    for (const auto& b : m_body)
    {
        if (b)
        result += b->compile(level + 1);
    }

    result += generateShift(level) + "}\n";

    return result;
}

JavaPrintOperatorUnit::JavaPrintOperatorUnit(const std::string& text) :
    PrintOperatorUnit(text) {}

JavaPrintOperatorUnit::~JavaPrintOperatorUnit() {}

std::string JavaPrintOperatorUnit::compile(unsigned int level) const
{
    return generateShift(level) + "System.out.println( \"" + m_text + "\" );\n";
}

