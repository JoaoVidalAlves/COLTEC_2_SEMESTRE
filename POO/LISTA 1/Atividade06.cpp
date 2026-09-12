#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Produto
{
private:
	string m_nome;
	float m_preco;
	int m_estoque;

public:
	Produto(string nome, float preco, int estoque)
	{
		m_nome = nome;

		if (preco <= 0)
		{
			cout << "Preco invalido para " << nome << ", definindo como 0.01" << '\n';
			m_preco = 0.01f;
		}
		else
		{
			m_preco = preco;
		}

		if (estoque < 0)
		{
			cout << "Estoque invalido para " << nome << ", definindo como 0" << '\n';
			m_estoque = 0;
		}
		else
		{
			m_estoque = estoque;
		}
	}

	void setPreco(float preco)
	{
		if (preco <= 0)
		{
			cout << "Preco invalido" << '\n';
		}
		else
		{
			m_preco = preco;
		}
	}

	void setEstoque(int estoque)
	{
		if (estoque < 0)
		{
			cout << "Estoque invalido" << '\n';
		}
		else
		{
			m_estoque = estoque;
		}
	}

	void vender(int quantidade)
	{
		if (quantidade > m_estoque)
		{
			cout << "Estoque insuficiente para vender " << quantidade << " unidades de " << m_nome << '\n';
		}
		else
		{
			m_estoque -= quantidade;
			cout << "Vendidas " << quantidade << " unidades de " << m_nome << '\n';
		}
	}

	void repor(int quantidade)
	{
		if (quantidade <= 0)
		{
			cout << "Quantidade de reposicao invalida" << '\n';
		}
		else
		{
			m_estoque += quantidade;
			cout << "Repostas " << quantidade << " unidades de " << m_nome << '\n';
		}
	}

	float valorEmEstoque()
	{
		return m_preco * m_estoque;
	}

	string getNome()
	{
		return m_nome;
	}
};

void maisValioso(Produto& a, Produto& b)
{
	if (a.valorEmEstoque() > b.valorEmEstoque())
	{
		cout << a.getNome() << " tem o maior valor em estoque" << '\n';
	}
	else if (b.valorEmEstoque() > a.valorEmEstoque())
	{
		cout << b.getNome() << " tem o maior valor em estoque" << '\n';
	}
	else
	{
		cout << a.getNome() << " e " << b.getNome() << " tem o mesmo valor em estoque" << '\n';
	}
}

int main()
{
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	Produto produto1("Teclado", 150.0f, 20);
	Produto produto2("Mouse", 80.0f, 30);

	cout << "Valor em estoque - " << produto1.getNome() << ": " << produto1.valorEmEstoque() << '\n';
	cout << "Valor em estoque - " << produto2.getNome() << ": " << produto2.valorEmEstoque() << '\n';
	cout << '\n';

	produto1.vender(5);
	produto1.vender(100);
	produto2.repor(10);
	produto2.repor(-5);
	cout << '\n';

	cout << "Valor em estoque - " << produto1.getNome() << ": " << produto1.valorEmEstoque() << '\n';
	cout << "Valor em estoque - " << produto2.getNome() << ": " << produto2.valorEmEstoque() << '\n';
	cout << '\n';

	maisValioso(produto1, produto2);

	return 0;
}
