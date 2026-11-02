#ifndef FILME_H
#define FILME_H

#include "Midia.h"

class Filme : public Midia {
private:
    int duracao;
    std::string diretor;

public:
    Filme(const std::string& titulo, int duracao, const std::string& diretor);

    int duracaoMinutos() const override;
    std::string tipo() const override;
    void imprimir(std::ostream& os) const override;  // acrescenta o diretor
};

#endif
