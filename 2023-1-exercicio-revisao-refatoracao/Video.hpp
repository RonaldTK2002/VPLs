#ifndef VIDEO_HPP
#define VIDEO_HPP

#include <string>
#include <iostream>
#include <list>

using namespace std;

class Video {
public:
int ano, filme_duracao, n_temp, total_ep;
string nome, genero, subtipo;
list<int> avaliacoes;

Video(string nome, int ano, string genero, string subtipo, int filme_duracao, int n_temp, int total_ep) : nome(nome), ano(ano), genero(genero), subtipo(subtipo), filme_duracao(filme_duracao),n_temp(n_temp), total_ep(total_ep)
{
}

float get_media_avaliacao() {
    float v = 0;
    for (auto n : avaliacoes)v += n;
    return v/avaliacoes.size();
  }

void avaliar(int nota) {
  avaliacoes.push_back(nota);
  }

void print_info(int id){
  if (subtipo == "Filme") 
  {
    cout << "Filme " << id << ":";
    cout << nome;
    cout << " (" << ano << "), ";
    cout << genero;
    cout << ", " << filme_duracao << " min, ";
    cout << "nota: " << get_media_avaliacao() << std::endl;
  }

  if (subtipo == "Serie")
  {
    cout << "Serie " << id << ":";
    cout << nome;
    cout << " (" << ano << "), ";
    cout << genero << ", ";
    cout << n_temp << " temporadas, ";
    cout << total_ep << " episodios, ";
    cout << "nota: " << get_media_avaliacao() << std::endl;
  }
};
};

#endif
