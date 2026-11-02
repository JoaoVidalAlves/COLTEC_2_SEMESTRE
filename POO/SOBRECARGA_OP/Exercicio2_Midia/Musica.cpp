#include "Musica.h"

Musica::Musica(const std::string& titulo, int duracao)
    : Midia(titulo), duracao(duracao) {}

int Musica::duracaoMinutos() const {
    return duracao;
}

std::string Musica::tipo() const {
    return "Musica";
}
