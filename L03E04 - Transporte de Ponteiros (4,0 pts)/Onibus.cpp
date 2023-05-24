#include "Onibus.hpp"
#include "Transporte.hpp"
#include "Passageiro.hpp"
#include <memory>
#include <iostream>
#include <iomanip>

Onibus::Onibus(int cap, float valor_passagem) : Transporte::Transporte(cap, valor_passagem) {}
Onibus::~Onibus()
{
    std::cout << "Destrutor Onibus\n";
}
bool Onibus::pagar_passagem(std::shared_ptr<Passageiro> passageiro)
{

    bool gratuidade = passageiro->get_idade() >= 65;
    bool tem_vagas = (this->_capacidade) > (this->_passageiros.size());
    bool tem_dinheiro = (passageiro->get_saldo()) >= (this->_valor_passagem);
    if (tem_vagas && tem_dinheiro && !gratuidade)
    {
        passageiro->descontar_valor_passagem(this->_valor_passagem);
        return true;
    }
    else if (tem_vagas && gratuidade)
    {
        std::cout << "Passagem gratuita:\n\tnome: " << passageiro->get_nome() << std::endl
                  << "\tidade: " << passageiro->get_idade() << std::endl
                  << "\tsaldo: R$ " << std::fixed << std::setprecision(2) << passageiro->get_saldo() << std::endl;
        return true;
    }
    else if (!tem_dinheiro && !gratuidade)
    {
        std::cout << "Saldo insuficiente:\n"
                  << "\tnome: " << passageiro->get_nome() << std::endl
                  << "\tsaldo: R$ " << std::fixed << std::setprecision(2) << passageiro->get_saldo() << std::endl;
        return false;
    }
    else
        return false;
}
void Onibus::mover()
{

    float porcentagem_ocupacao = (_passageiros.size() / float(_capacidade)) * 100;
    std::cout << "Onibus deslocando com " << std::fixed << std::setprecision(0) << porcentagem_ocupacao << "% da capacidade\n";
}
void Onibus::embarcar(std::shared_ptr<Passageiro> passageiro)
{
    if (pagar_passagem(passageiro)&&_capacidade > _passageiros.size())
        _passageiros.push_back(passageiro);
}
void Onibus::desembarcar()
{
    int numero_desembarcados = 0;
    while (!_passageiros.empty())
    {
        _passageiros.pop_back();
        numero_desembarcados++;
    }
    std::cout << numero_desembarcados << " passageiros desembarcaram do onibus\n";
}

