#include "Midia.h"

Midia::Midia(const std::string& titulo) : titulo(titulo) {}

Midia::~Midia() {}

void Midia::imprimir(std::ostream& os) const {
    os << titulo << " | " << tipo() << " | " << duracaoMinutos() << " min";
}

std::ostream& operator<<(std::ostream& os, const Midia& m) {
    m.imprimir(os);
    return os;
}
