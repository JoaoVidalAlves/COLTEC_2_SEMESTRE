#ifndef MEIA_H
#define MEIA_H

#include "Ingresso.h"

class Meia : public Ingresso
{
public:
	Meia(double valor);

	double precoFinal() const override;

	void exibir() const override;
};

#endif
