#ifndef VIDEO_HPP
#define VIDEO_HPP

#include <string>
#include <iostream>
#include <list>

class Video
{

private:
  static int _prox_id;
  int _ano, _id;
  std::string _nome, _genero;
  std::list<int> _avaliacoes;

public:
  Video(std::string nome, int ano, std::string genero);
  virtual ~Video();
  int get_id();
  int get_ano();
  std::string get_nome();
  std::string get_genero();
  float get_media_avaliacao();
  void avaliar(int nota);
  virtual void print_info() = 0;
};

#endif