# Motor
- -string combustivel
- -int cilindrada
- +Motor(string combustivel, int cilindrada)
- +void exibir() const
---
# Veiculo
- #string placa
- #int anoFabricacao
- -Motor motor
- +Veiculo(string placa, int anoFabricacao, string combustivel, int cilindrada)
- +void exibir() const
- +double valorLicenciamento() const
---
# Automovel : Veiculo
- -int portas
- +Automovel(string placa, int anoFabricacao, string combustivel, int cilindrada, int portas)
- +void exibir() const
- +double valorLicenciamento() const

# Caminhao : Veiculo
- -double capacidadeCarga
- +Caminhao(string placa, int anoFabricacao, string combustivel, int cilindrada, double capacidadeCarga)
- +void exibir() const
- +double valorLicenciamento() const
