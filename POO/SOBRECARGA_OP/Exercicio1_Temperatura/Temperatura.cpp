#include "Temperatura.h"
#include <cmath>
#include <iomanip>

Temperatura::Temperatura(double celsius) : celsius(celsius) {}

double Temperatura::getCelsius() const {
    return celsius;
}

Temperatura Temperatura::operator+(const Temperatura& outra) const {
    return Temperatura(celsius + outra.celsius);
}

Temperatura Temperatura::operator-(const Temperatura& outra) const {
    return Temperatura(celsius - outra.celsius);
}

bool Temperatura::operator<(const Temperatura& outra) const {
    return celsius < outra.celsius;
}

bool Temperatura::operator==(const Temperatura& outra) const {
    // tolerância pequena, pois comparar double com == direto é arriscado
    return std::fabs(celsius - outra.celsius) < 1e-9;
}

std::ostream& operator<<(std::ostream& os, const Temperatura& t) {
    // guarda a formatação atual do stream para restaurar depois
    std::ios_base::fmtflags flags = os.flags();
    std::streamsize precisao = os.precision();

    os << std::fixed << std::setprecision(1) << t.getCelsius() << " C";

    os.flags(flags);
    os.precision(precisao);
    return os;
}
