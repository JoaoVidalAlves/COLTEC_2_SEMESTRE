#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

class Account
{
private:
	float m_saldo;

public:

	Account(float valor)
	{
		if (valor < 0)
			cout << "Valor Invalido" << '\n';
			m_saldo = 0;
		else
			m_saldo = valor;
	}

	void creditar(float valor)
	{
		if (valor < 1)
			cout << "Valor minimo: R$ 1.00" << '\n';
		else
			m_saldo += valor;
	}

	void debitar(float valor)
	{
		if (valor < 1)
			cout << "Valor minimo: R$ 1.00" << '\n';
		else if (m_saldo >= valor)
			m_saldo -= valor;
		else
			cout << "Saldo insuficiente." << '\n';
	}

	float getSaldo() const
	{
		return m_saldo;
	}
};

int main() {
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	Account conta1(100.0f), conta2(-50.0f);

	cout << "Saldo inicial conta1: " << conta1.getSaldo() << endl;
	cout << "Saldo inicial conta2: " << conta2.getSaldo() << endl;

	cout << "\n--- Testando creditar ---" << endl;
	conta1.creditar(50.0f);
	cout << "Saldo conta1 apos creditar 50: " << conta1.getSaldo() << endl;

	conta2.creditar(200.0f);
	cout << "Saldo conta2 apos creditar 200: " << conta2.getSaldo() << endl;

	conta1.creditar(-10.0f);
	cout << "Saldo conta1 apos tentativa de credito negativo: " << conta1.getSaldo() << endl;

	cout << "\n--- Testando debitar ---" << endl;
	conta1.debitar(30.0f);
	cout << "Saldo conta1 apos debitar 30: " << conta1.getSaldo() << endl;

	conta2.debitar(500.0f);
	cout << "Saldo conta2 apos tentativa de debito invalido: " << conta2.getSaldo() << endl;

	conta1.debitar(-5.0f);
	cout << "Saldo conta1 apos tentativa de debito negativo: " << conta1.getSaldo() << endl;

	cout << "\n--- Saldos finais ---" << endl;
	cout << "Saldo final conta1: " << conta1.getSaldo() << endl;
	cout << "Saldo final conta2: " << conta2.getSaldo() << endl;

	return 0;
}