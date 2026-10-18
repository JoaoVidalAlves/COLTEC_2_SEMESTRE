#include "Motor.h"
#include <iostream>

Motor::Motor(const std::string& combustivel, int cilindrada)
    : combustivel(combustivel), cilindrada(cilindrada) {}

void Motor::exibir() const 
{
    std::cout << "Motor: " << combustivel << ", " << cilindrada << " cc" << std::endl;
}
