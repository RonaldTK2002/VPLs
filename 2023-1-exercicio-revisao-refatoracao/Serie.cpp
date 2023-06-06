#include "Serie.hpp"
#include "Video.hpp"

#include <string>
#include <iostream>

Serie::Serie(std::string nome, int ano, std::string genero, int num_temporadas, int total_episodios) : 
Video(nome, ano, genero), _num_temporadas(num_temporadas), _total_episodios(total_episodios) {}

Serie::~Serie(){}

int Serie::get_num_temp()
{
  return this->_num_temporadas;
}
int Serie::get_total_ep()
{
  return this->_total_episodios;
}
void Serie::print_info()
{

  std::cout << "Serie " << this->get_id() << ":" << this->get_nome()
            << " (" << this->get_ano() << "), "
            << this->get_genero() << ", "
            << this->get_num_temp() << " temporadas, "
            << get_total_ep() << " episodios, "
            << "nota: " << get_media_avaliacao() << std::endl;
}