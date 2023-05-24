#ifndef TREM_HPP
#define TREM_HPP
#include "Transporte.hpp"
#include <memory>
#include <list>

class Trem : public Transporte
{
protected:
    std::list<std::shared_ptr<Passageiro>> _passageiros;

public:
    Trem(int capacidade, float valor_passagem);
    virtual ~Trem();
    virtual bool pagar_passagem(std::shared_ptr<Passageiro> passageiro) override;
    virtual void mover() override;
    virtual void embarcar(std::shared_ptr<Passageiro> passageiro) override;
    virtual void desembarcar() override;
};
#endif