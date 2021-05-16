#ifndef PRINTOPERATORUNIT_H
#define PRINTOPERATORUNIT_H
#include "Unit.h"
#include <iostream>

class PrintOperatorUnit : public Unit
{
public:
    explicit PrintOperatorUnit( const std::string& text );
    std::string compile( unsigned int level = 0 ) const = 0;
protected:
    std::string m_text;
};

#endif // PRINTOPERATORUNIT_H
