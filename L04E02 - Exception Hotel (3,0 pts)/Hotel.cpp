#include <ctime>
#include "Hotel.hpp"

Quarto *Hotel::get_quarto_pelo_n(int n_quarto)
{
    for (int i = 0; i < _quartos.size(); i++)
    {
        if (n_quarto == _quartos[i]->get_n_quarto())
        {
            return _quartos[i];
        }
        else
            continue;
    }
    throw hotel_excp::quarto_nao_criado(n_quarto);
}
void Hotel::adiciona_reserva(int n_quarto, struct std::tm data_entrada, struct std::tm data_saida)
{
    if (n_quarto > 5 || n_quarto < 0)
    {
        throw hotel_excp::quarto_nao_existe(n_quarto);
    }
    int i = 0;
    for (i; i < _quartos.size(); i++)
    {
        if (n_quarto == _quartos[i]->get_n_quarto())
        {
            _quartos[i]->adiciona_reserva(data_entrada, data_saida);
            return;
        }
        else
            continue;
    }
    _quartos.insert(_quartos.begin() + i, new Quarto(n_quarto));
    _quartos[i]->adiciona_reserva(data_entrada, data_saida);
}
void Hotel::remove_reserva(int n_quarto, struct std::tm data_entrada)
{
    if (n_quarto > 5 || n_quarto < 0)
    {
        throw hotel_excp::quarto_nao_existe(n_quarto);
    }
    for (int i = 0; i < _quartos.size(); i++)
    {
        if (n_quarto == _quartos[i]->get_n_quarto())
        {
            _quartos[i]->remove_reserva(data_entrada);
        }
        else
            continue;
    }
}
void Hotel::print_info()
{
    for (auto quarto : _quartos)
    {
        quarto->print_info();
    }
}