#ifndef GENERATE_H
#define GENERATE_H
#include "Generation.h"

class Generate
{
private:
    std::shared_ptr<Generate_> generat;
public:
    explicit Generate(const std::shared_ptr<Generate_>& Gener);
    ~Generate() {};
    void setGener(const std::shared_ptr<Generate_>& Gener);
    std::shared_ptr<Generate_> getGener();
    std::string generateProgram();
};

#endif // GENERATE_H

