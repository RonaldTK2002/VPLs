#include "Streaming.hpp"
#include "Filme.hpp"
#include "Serie.hpp"

#include <iostream>
#include <list>
#include <string>
#include <vector>

int main()

{
    Streaming streaming;
    std::string acao;
    

    while (std::cin >> acao)
    {
        Video *conteudo;
        

        if (acao == "Filme")

        {
            std::string nome, genero;
            int ano,duracao;
            std::cin >> genero >> ano>> duracao;
            getline(std::cin, nome);

            conteudo = new Filme(nome, ano, genero, duracao);

            if (duracao >= 50)

                streaming.cadastrar_conteudo(conteudo);
            else
                std::cout << "A duracao deve ser de no mínimo 50 min" << std::endl;
        }
        if (acao == "Serie")
        {

            std::string nome, genero;
            int ano,numero_temp, total_ep;
            std::cin >> genero >> ano>> numero_temp >> total_ep;
            getline(std::cin, nome);

            conteudo = new Serie(nome, ano, genero, numero_temp, total_ep);

            if (total_ep >= 2)
                streaming.cadastrar_conteudo(conteudo);
            else
                std::cout << "A série deve ter pelo menos 2 episódios" << std::endl;
        }

        if (acao == "Nota")
        {
            int id, nota;
            std::cin >> id >> nota;

            if (nota <= 10 && nota >= 0)
                streaming.avaliacao(id, nota);

            else
                std::cout << "A nota deve estar entre 0 e 10" << std::endl;
        }
    }

    streaming.print_catalogo();

    return 0;
}
