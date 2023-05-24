#include "Passageiro.hpp"
#include "Transporte.hpp"
#include "Trem.hpp"
#include <memory>
#include <string>
#include <iostream>




bool Trem::pagar_passagem(std::shared_ptr<Passageiro> passageiro){
    bool tem_vagas = this->
    bool tem_dinheiro = passageiro->get_saldo() > this-> _valor_passagem;
    if(tem_vagas&&tem_dinheiro){
        passageiro->descontar_valor_passagem(this->_valor_passagem)
    }
}