#ifndef MIDIA_H
#define MIDIA_H

#include <iostream>
#include <string>

class Midia {
protected:
    std::string titulo;

public:
    Midia(const std::string& titulo);
    virtual ~Midia();  // destrutor virtual: necessário para deletar via Midia*

    virtual int duracaoMinutos() const = 0;
    virtual std::string tipo() const = 0;

    virtual void imprimir(std::ostream& os) const;
};

// função livre que delega para o método imprimir
std::ostream& operator<<(std::ostream& os, const Midia& m);

#endif
