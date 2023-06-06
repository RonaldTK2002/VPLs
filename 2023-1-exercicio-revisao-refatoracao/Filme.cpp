#include "Filme.hpp"
#include "Video.hpp"

#include <string>
#include <iostream>

Filme::Filme(std::string nome, int ano, std::string genero, int duracao) : Video(nome, ano, genero), _duracao(duracao) {}

Filme::~Filme(){}
int Filme::get_duracao()
{
  return this->_duracao;
}

void Filme::print_info()
{
  std::cout << "Filme " << this->get_id() << ":" << this->get_nome()
            << " (" << this->get_ano() << "), " << this->get_genero() << ", "
            << this->get_duracao() << " min, "
            << "nota: " << get_media_avaliacao() << std::endl;
}