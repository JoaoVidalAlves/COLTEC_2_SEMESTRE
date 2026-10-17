#ifndef INTEIRA_H
#define INTEIRA_H

#include "Ingresso.h"

class Inteira : public Ingresso
{
public:
	Inteira(double valor);

	double precoFinal() const override;

	void exibir() const override;
};

#endif // !INTEIRA_H