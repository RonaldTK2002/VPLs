#include "Passageiro.hpp"
#include <string>

Passageiro::Passageiro(std::string nome, int idade, float saldo_passagem) : _nome(nome), _idade(idade), _saldo_passagem(saldo_passagem) {}
Passageiro::~Passageiro() {}
void Passageiro::descontar_valor_passagem(float valor_passagem)
{
    this->_saldo_passagem -= valor_passagem;
}
float Passageiro::get_saldo(){
    return this->get_saldo();
}
