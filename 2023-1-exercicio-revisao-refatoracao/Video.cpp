#include "Video.hpp"
#include <string>

Video::Video(std::string nome, int ano, std::string genero) : _nome(nome), _ano(ano), _genero(genero) {}

float Video::get_media_avaliacao()
{
    float total_avaliacoes = 0;

    for (auto avaliacao : _avaliacoes)
        total_avaliacoes += avaliacao;

    float media_avaliacoes = total_avaliacoes / _avaliacoes.size();

    return media_avaliacoes;
}

void Video::avaliar(int nota)
{
    _avaliacoes.push_back(nota);
}
