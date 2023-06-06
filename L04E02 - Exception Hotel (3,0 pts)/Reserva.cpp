
#include <ctime>
#include <iomanip>
#include "Reserva.hpp"
#include "ReservaExceptions.hpp"

#define DATE_FORMAT "%d/%m/%Y"

time_t hora_maquina = std::time(0);

Reserva::Reserva(struct std::tm data_entrada, struct std::tm data_saida)
{
    time_t hora_entrada = mktime(&data_entrada);
    time_t hora_saida = mktime(&data_saida);

    if (hora_entrada < hora_maquina)
    {
        throw reserva_excp::data_entrada_no_passado(data_entrada);
    }
    else if (hora_entrada > hora_saida)
    {
        throw reserva_excp::data_saida_antecede_entrada(data_entrada, data_saida);
    }
    else if (hora_saida - hora_entrada < DIA_EM_SEGUNDOS)
    {
        throw reserva_excp::periodo_muito_curto(data_entrada, data_saida);
    }
    else
    {
        this->_data_entrada = data_entrada;
        this->_data_saida = data_saida;
    }
}
struct std::tm *Reserva::get_data_entrada()
{
    return &_data_entrada;
}
struct std::tm *Reserva::get_data_saida()
{
    return &_data_saida;
}
int Reserva::comparar(Reserva &other)
{
    bool saida_menor_entrada = mktime(this->get_data_saida()) < mktime(other.get_data_entrada());
    bool entrada_maior_saida = mktime(this->get_data_entrada()) > mktime(other.get_data_saida());

    if (saida_menor_entrada)
        return -1;
    if (entrada_maior_saida)
        return 1;
    else
        return 0;
}
void Reserva::print_info()
{

    std::cout << "\tData entrada " << std::put_time(get_data_entrada(), DATE_FORMAT) << ",Saida: " << std::put_time(get_data_saida(), DATE_FORMAT) << std::endl;

}
