#include "Filme.h"

Filme::Filme(const std::string& titulo, int duracao, const std::string& diretor)
    : Midia(titulo), duracao(duracao), diretor(diretor) {}

int Filme::duracaoMinutos() const {
    return duracao;
}

std::string Filme::tipo() const {
    return "Filme";
}

void Filme::imprimir(std::ostream& os) const {
    Midia::imprimir(os);              // reaproveita a impressão da base
    os << " | Diretor: " << diretor;
}
