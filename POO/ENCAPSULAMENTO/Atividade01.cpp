#include <iostream>

using namespace std;

class Produto
{
public:
    void Inicializar(string nome, float preco)
    {
        if(preco < 0)
        {
            cout << "Preço Invalido!" << endl;
            precoPrivadoProduto = 0;
        } 
        else 
        {
            precoPrivadoProduto = preco;
        } 
        nomePrivadoProduto = nome;
    }

    //ATRIBUIR
    void setNomeProduto(string nome)
    {
        nomePrivadoProduto = nome;
    }

    //OBTER
    string getNomeProduto()
    {
        return nomePrivadoProduto;
    }

    //ATRIBUIR
    void setPrecoProduto(float preco)
    {
        if(preco < 0)
        {
            cout << "Preço Invalido!" << endl;
        } 
        else 
        {
            precoPrivadoProduto = preco;
        } 
    }

    //OBTER 
    float getPrecoProduto()
    {
        return precoPrivadoProduto;
    }

private:
    string nomePrivadoProduto;
    float precoPrivadoProduto;
};

int main()
{
    Produto produto1, produto2;

    produto1.Inicializar("Arroz", -20);
    cout << produto1.getNomeProduto() << endl;
    cout << produto1.getPrecoProduto() << endl;
    
    produto2.Inicializar("Feijão", 20);
    cout << produto2.getNomeProduto() << endl;
    cout << produto2.getPrecoProduto() << endl;

    return 0;
}