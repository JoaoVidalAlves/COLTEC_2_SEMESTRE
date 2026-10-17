#ifndef INGRESSO_H
#define INGRESSO_H

class Ingresso
{
protected:
	double valorBase;

public:
	Ingresso(double valor);

	virtual ~Ingresso() = default;

	virtual double precoFinal() const;

	virtual void exibir() const;
};

#endif