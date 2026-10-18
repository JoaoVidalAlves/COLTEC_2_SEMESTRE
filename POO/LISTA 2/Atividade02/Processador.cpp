#include <iostream>
#include <string>

class Processador
{
private:
	std::string m_modelo;
	double m_frequencia;

public:
	Processador(std::string modelo, double frequencia)
		:	m_modelo(modelo), m_frequencia(frequencia < 0.1f ? 0.1 : frequencia) 
	{
		if (frequencia < 0.1f)
			std::cout << "Frequencia minima 0.1 GHz" << std::endl;
	}

	void Exibir() const
	{
		std::cout << "Processador: " << m_modelo << std::endl;
		std::cout << "Frequencia: " << m_frequencia << " GHz" << std::endl;
	}
};

class Computador
{
private:
	std::string m_fabricante;
	int m_memoriaRAM;

public:
	Processador processador;

	Computador(std::string modelo, double frequencia, std::string fabricante, int memoriaRAM)
		: processador(modelo, frequencia), m_fabricante(fabricante), m_memoriaRAM(memoriaRAM < 1 ? 1 : memoriaRAM)
	{
		if (memoriaRAM < 1)
			std::cout << "Tamanho minimo de ram = 1" << std::endl;
	}

	void Ficha() const
	{
		std::cout << "Fabricante: " << m_fabricante << std::endl;
		std::cout << "Memoria ram: " << m_memoriaRAM << " GB" << std::endl;
		processador.Exibir();
	}
};

int main()
{
	Computador PC1("RYZEN 5 7535HS", 3.3f, "ACER", 8);
	Computador PC2("RYZEN 7 5700U", 2.3f, "ACER", 16);

	PC1.Ficha();
	std::cout << std::endl;
	PC2.Ficha();

	return 0;
}