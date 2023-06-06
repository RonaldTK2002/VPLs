#include "Streaming.hpp"

void Streaming::avaliacao(int id, int nota)
{
    for (int i = 0; i < this->_catalogo.size(); i++)
    {
        if (_catalogo[i]->get_id() == id)
        {
            _catalogo[i]->avaliar(nota);
            return;
        }
    }

    // Se não encontrar o id:
    std::cout << "Id não encontrado" << std::endl;
}

void Streaming::cadastrar_conteudo(Video *conteudo)
{
    _catalogo.push_back(conteudo);
}

void Streaming::print_catalogo()
{
    if (_catalogo.size() == 0)
        std::cout << "Sem video cadastrado!" << std::endl;

    else
    {
        std::cout << "Catalogo Streaming:" << std::endl;

        for (auto conteudo : _catalogo)
        {
            conteudo->print_info();
        }
    }
}