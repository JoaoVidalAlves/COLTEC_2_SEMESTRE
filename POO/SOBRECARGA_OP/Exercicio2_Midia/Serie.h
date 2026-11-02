#ifndef SERIE_H
#define SERIE_H

#include "Midia.h"

class Serie : public Midia {
private:
    int duracaoEpisodio;
    int qtdEpisodios;

public:
    Serie(const std::string& titulo, int duracaoEpisodio, int qtdEpisodios);

    int duracaoMinutos() const override;  // duração total do conjunto
    std::string tipo() const override;
};

#endif
