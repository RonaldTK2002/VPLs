#include "Video.hpp"
#include <string>

int Video::_prox_id = 1;

Video::Video(std::string nome, int ano, std::string genero) : _nome(nome), _ano(ano), _genero(genero), _id(_prox_id)
{
    _prox_id++;
}

Video::~Video() {}

int Video::get_id()
{
    return this->_id;
}

int Video::get_ano()
{
    return this->_ano;
}

std::string Video::get_nome()
{
    return this->_nome;
}

std::string Video::get_genero()
{
    return this->_genero;
}

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