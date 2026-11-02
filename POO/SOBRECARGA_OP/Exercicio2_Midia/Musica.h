#ifndef MUSICA_H
#define MUSICA_H

#include "Midia.h"

class Musica : public Midia {
private:
    int duracao;

public:
    Musica(const std::string& titulo, int duracao);

    int duracaoMinutos() const override;
    std::string tipo() const override;
};

#endif
