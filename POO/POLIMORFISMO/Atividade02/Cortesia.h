#ifndef CORTESIA_H
#define CORTESIA_H

#include "Ingresso.h"

class Cortesia : public Ingresso
{
public:
	Cortesia(double valor);

	double precoFinal() const override;

	void exibir() const override;
};

#endif // !CORTESIA_H