#include "Passageiro.hpp"
#include "Transporte.hpp"
#include "Trem.hpp"
#include <memory>
#include <string>
#include <iostream>
#include <iomanip>

Trem::Trem(int capacidade, float valor_passagem) : Transporte::Transporte(capacidade, valor_passagem) {}

Trem::~Trem()
{
    std::cout << "Destrutor Trem\n";
}

bool Trem::pagar_passagem(std::shared_ptr<Passageiro> passageiro)
{
    bool tem_vagas = (this->_capacidade) >= (this->_passageiros.size());
    bool tem_dinheiro = (passageiro->get_saldo()) >= (this->_valor_passagem);
    if (tem_vagas && tem_dinheiro)
    {
        passageiro->descontar_valor_passagem(this->_valor_passagem);
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
void Trem::mover()
{
    float porcentagem_ocupacao = (_passageiros.size() / float(_capacidade)) * 100;
    std::cout << "Deslocando com " << std::fixed << std::setprecision(0) << porcentagem_ocupacao << "% da capacidade\n";
}
void Trem::embarcar(std::shared_ptr<Passageiro> passageiro)
{

    if (pagar_passagem(passageiro))
        _passageiros.push_back(passageiro);
}
void Trem::desembarcar()
{
    int numero_desembarcados = 0;
    while (!_passageiros.empty())
    {
        _passageiros.pop_back();
        numero_desembarcados++;
    }
    std::cout << numero_desembarcados << " passageiros desembarcaram do trem\n";
}
