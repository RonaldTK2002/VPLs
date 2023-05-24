#ifndef ONIBUS_HPP
#define ONIBUS_HPP
#include "Transporte.hpp"
#include <list>
#include "Passageiro.hpp"

class Onibus: public Transporte{
    protected:
    std::list<std::shared_ptr<Passageiro>> _passageiros;
    public:
    Onibus(int cap, float passagem);
    virtual ~Onibus();
    virtual bool pagar_passagem(std::shared_ptr<Passageiro> passageiro) override;
    virtual void mover() override;
    virtual void embarcar(std::shared_ptr<Passageiro> passageiro) override;
    virtual void desembarcar() override;

};
#endif