#include <stdexcept>
#include <ctime>

namespace quarto_excp
{
    class reserva_nao_encontrada : std::exception
    {
    private:
        int _n_quarto;
        std::tm _data_inicio = {};

    public:
        reserva_nao_encontrada(int n_quarto, std::tm data_inicio) : _n_quarto(n_quarto), _data_inicio(data_inicio) {}
        const char *what() const throw()
        {
            return "Reserva nao encontrada";
        }
        int get_n_quarto()
        {
            return _n_quarto;
        }
        struct std::tm *get_data_entrada()
        {
            return &_data_inicio;
        }
    };
    class reserva_indisponivel : std::exception
    {
    private:
        std::tm _data_inicio = {};
        std::tm _data_saida = {};

    public:
        reserva_indisponivel(struct std::tm data_inicio, struct std::tm data_saida) : _data_inicio(data_inicio), _data_saida(data_saida) {}
        const char *what() const throw()
        {
            return "Existe uma reserva em alguns dos dias do periodo";
        }
        struct std::tm *get_data_entrada()
        {
            return &_data_inicio;
        }
        struct std::tm *get_data_saida()

        {
            return &_data_saida;
        }
    };
}