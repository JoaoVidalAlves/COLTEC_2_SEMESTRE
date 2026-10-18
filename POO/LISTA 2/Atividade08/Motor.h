#ifndef MOTOR_H
#define MOTOR_H

#include <string>

class Motor 
{
private:
    std::string combustivel;
    int cilindrada;

public:
    Motor(const std::string& combustivel, int cilindrada);
    void exibir() const;
};

#endif
