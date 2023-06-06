#include <stdexcept>
#include <ctime>

namespace reserva_excp
{

    class data_entrada_no_passado : std::exception
    {
    private:
        std::tm _data_entrada={};

    public:
        data_entrada_no_passado(struct std::tm data_entrada) : _data_entrada(data_entrada) {}
        const char *what() const throw()
        {
            return "Data de entrada esta no passado";
        }
        struct std::tm *get_data_entrada()
        {
            return &_data_entrada;
        }
    };
    class data_saida_antecede_entrada : std::exception
    {
    private:
        struct std::tm _data_entrada= {};
        struct std::tm _data_saida= {};

    public:
        data_saida_antecede_entrada(struct std::tm data_entrada, struct std::tm data_saida) : _data_entrada(data_entrada), _data_saida(data_saida) {}
        const char *what() const throw()
        {
            return "Data saida nao pode ser menor que a data entrada";
        }
        struct std::tm *get_data_entrada()
        {
            return &_data_entrada;
        }
        struct std::tm *get_data_saida()
        {
            return &_data_saida;
        }
    };
    class periodo_muito_curto : std::exception
    {
    private:
        struct std::tm _data_entrada={};
        struct std::tm _data_saida= {};

    public:
        periodo_muito_curto(struct std::tm data_entrada, struct std::tm data_saida) : _data_entrada(data_entrada), _data_saida(data_saida) {}
        const char *what() const throw()
        {
            return "Reserva deve ter duracao minima de 1 dia";
        }
        struct std::tm *get_data_entrada()
        {
            return &_data_entrada;
        }
        struct std::tm *get_data_saida()
        {
            return &_data_saida;
        }
    };

}