#include "Serie.h"

Serie::Serie(const std::string& titulo, int duracaoEpisodio, int qtdEpisodios)
    : Midia(titulo), duracaoEpisodio(duracaoEpisodio), qtdEpisodios(qtdEpisodios) {}

int Serie::duracaoMinutos() const {
    return duracaoEpisodio * qtdEpisodios;
}

std::string Serie::tipo() const {
    return "Serie";
}
