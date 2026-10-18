# Eletrodomestico
- #string m_nome
- #double m_potencia
- +Eletrodomestico(string nome, double potencia)
- +virtual ~Eletrodomestico()
- +virtual double consumoDiario() const
- +virtual void exibir() const
---
# Geladeira : Eletrodomestico
- -double m_fatorUso
- +Geladeira(string nome, double potencia, double fatorUso)
- +~Geladeira() override
- +double consumoDiario() const override
- +void exibir() const override

# Lampada : Eletrodomestico
- -double m_horasAcesa
- +Lampada(string nome, double potencia, double horasAcesa)
- +~Lampada() override
- +double consumoDiario() const override
- +void exibir() const override