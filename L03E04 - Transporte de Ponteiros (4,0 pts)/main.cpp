#include "Passageiro.hpp"
#include "Trem.hpp"
#include "Metro.hpp"
#include "Onibus.hpp"
#include "Transporte.hpp"
#include <iostream>
#include <memory>
#include <string>
#include <iomanip>
#include <list>

int main()
{
    std::list<std::shared_ptr<Passageiro>> l_passageiro;
    std::unique_ptr<Trem> trem;
    std::unique_ptr<Metro> metro;
    std::unique_ptr<Onibus> onibus;
    std::string comando;
    while (std::cin >> comando)
    {
        if (comando == "add")
        {

            std::string nome;
            int idade;
            float saldo_passagem;
            std::cin >> nome >> idade >> saldo_passagem;
            std::shared_ptr<Passageiro> passageiro(new Passageiro(nome, idade, saldo_passagem));
            l_passageiro.push_back(passageiro);
        }
        else if (comando == "trem")
        {
            int capacidade;
            float valor_passagem;
            std::cin >> capacidade >> valor_passagem;
            trem.reset(new Trem(capacidade, valor_passagem));
            for (std::list<std::shared_ptr<Passageiro>>::iterator it = l_passageiro.begin(); it != l_passageiro.end(); it++)
            {
                trem->embarcar(*it);
            }
            trem->mover();
            trem->desembarcar();
        }
        else if (comando == "metro")
        {
            int capacidade;
            float valor_passagem;
            std::cin >> capacidade >> valor_passagem;

            metro.reset(new Metro(capacidade, valor_passagem));
            for (std::list<std::shared_ptr<Passageiro>>::iterator it = l_passageiro.begin(); it != l_passageiro.end(); it++)
            {
                metro->embarcar(*it);
            }
            metro->mover();
            metro->desembarcar();
        }
        else if (comando == "onibus")
        {
            int capacidade;
            float valor_passagem;
            std::cin >> capacidade >> valor_passagem;
            onibus.reset(new Onibus(capacidade, valor_passagem));
            for (std::list<std::shared_ptr<Passageiro>>::iterator it = l_passageiro.begin(); it != l_passageiro.end(); it++)
            {
                onibus->embarcar(*it);
            }
            onibus->mover();
            onibus->desembarcar();
        }
    }
}