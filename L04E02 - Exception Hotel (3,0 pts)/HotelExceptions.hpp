#include <stdexcept>
#include <ctime>

namespace hotel_excp
{
    class quarto_nao_existe : std::exception
    {
    private:
        int _n_quarto;

    public:
        quarto_nao_existe(int n_quarto) : _n_quarto(n_quarto) {}
        const char *what() const throw()
        {
            return "Numero do quarto informado nao pertence a colecao";
        }
        int get_n_quarto()
        {
            return _n_quarto;
        }
    };

    class quarto_nao_criado : std::exception
    {
    private:
        int _n_quarto;

    public:
        quarto_nao_criado(int n_quarto) : _n_quarto(n_quarto) {}
        const char *what() const throw()
        {
            return "Quarto ainda nao foi adicionado a lista";
        }
        int get_n_quarto()
        {
            return _n_quarto;
        }
    };
}