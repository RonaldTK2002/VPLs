#include <ctime>
#include "Quarto.hpp"
#include "Reserva.hpp"
#include <vector>

void Quarto::adiciona_reserva(struct std::tm data_entrada, struct std::tm data_saida)
{

    for (int i = 0; i < _reservas.size(); i++)
    {
        bool menor = mktime(&data_entrada) < mktime(_reservas[i]->get_data_entrada());
        bool igual = mktime(&data_entrada) == mktime(_reservas[i]->get_data_entrada());

        if (menor)
        {
            _reservas.insert(_reservas.begin() + i - 1, new Reserva(data_entrada, data_saida));
        }
        else if (igual)
        {
            throw quarto_excp::reserva_indisponivel(data_entrada, data_saida);
        }
        else
            continue;
    }
}
void Quarto::remove_reserva(struct std::tm data_inicio)
{
    for (int i = 0; i < _reservas.size(); i++)
    {
        bool igual = mktime(&data_inicio) == mktime(_reservas[i]->get_data_entrada());
        if (igual)
        {
            _reservas.erase(_reservas.begin() + i);
            return;
        }
    }
    throw quarto_excp::reserva_nao_encontrada(this->get_n_quarto(), data_inicio);
}
void Quarto::print_info()
{

    std::cout << "Quarto " << this->get_n_quarto() << " ---------" << std::endl;
    for (auto reserva : _reservas)
    {
        reserva->print_info();
    }
    std::cout << "------------------" << std::endl;
}
