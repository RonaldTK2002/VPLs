
#ifndef STREAMING_HPP
#define STREAMING_HPP

#include "Video.hpp"

#include <string>
#include <vector>

class Streaming
{

private:
  std::vector<Video *> _catalogo;

public:
  void cadastrar_conteudo(Video *conteudo);
  void avaliacao(int id, int nota);
  void print_catalogo();
};

#endif;