#include "Trem.hpp"
#include "Passageiro.hpp"
#include "Metro.hpp"
#include <memory>
#include <iostream>
#include <iomanip>

Metro::Metro(int cap, float valor_passagem) : Trem::Trem(cap, valor_passagem) {}
Metro::~Metro()
{
    std::cout << "Destrutor Metro\n";
}
bool Metro::pagar_passagem(std::shared_ptr<Passageiro> passageiro)
{
    bool tem_vagas = (this->_capacidade) > (this->_passageiros.size());
    bool tem_dinheiro = (passageiro->get_saldo()) > (this->_valor_passagem)+0.40;
    if (tem_vagas && tem_dinheiro)
    {
        passageiro->descontar_valor_passagem(this->_valor_passagem + 0.40);
        return true;
    }
    else if (!tem_dinheiro)
    {
        std::cout << "Saldo insuficiente:\n"
                  << "\tnome: " << passageiro->get_nome() << "\n\tsaldo: R$ " << std::fixed << std::setprecision(2) << passageiro->get_saldo() << std::endl;
        return false;
    }
    else
        return false;
}
void Metro::desembarcar()
{

    int numero_desembarcados = 0;
    while (!_passageiros.empty())
    {
        _passageiros.pop_back();
        numero_desembarcados++;
    }
    std::cout << numero_desembarcados << " passageiros desembarcaram do metro\n";
}