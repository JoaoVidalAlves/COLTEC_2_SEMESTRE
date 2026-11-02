#ifndef TEMPERATURA_H
#define TEMPERATURA_H

#include <iostream>

class Temperatura {
private:
    double celsius;

public:
    Temperatura(double celsius);

    double getCelsius() const;

    // (a) soma e subtração: devolvem uma nova Temperatura
    Temperatura operator+(const Temperatura& outra) const;
    Temperatura operator-(const Temperatura& outra) const;

    // (b) comparações
    bool operator<(const Temperatura& outra) const;
    bool operator==(const Temperatura& outra) const;
};

// (c) função livre: cout << t
std::ostream& operator<<(std::ostream& os, const Temperatura& t);

#endif
