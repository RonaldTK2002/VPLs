#ifndef PASSAGEIRO_HPP
#define PASSAGEIRO_HPP

#include <string>

class Passageiro
{
private:
    std::string _nome;
    int _idade;
    float _saldo_passagem;

public:
    Passageiro(std::string nome, int idade, float saldo_passagem);
    ~Passageiro();
    void descontar_valor_passagem(float valor_passagem);
    float get_saldo();
};

#endif