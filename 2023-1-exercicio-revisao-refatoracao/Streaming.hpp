
#include <string>
#include <vector>

#include "Video.hpp"


class Streaming { 

private:
std::vector<Video*> catalogo;

public:
  


void cadastrar_filme(Video *v)
{
  catalogo.push_back(v);
}

void cadastrar_serie(Video *v)
{
  catalogo.push_back(v);
}

void avaliacao(int id, int nota) {
  catalogo[id - 1]->avaliar(nota);
  }


void print_catalogo()
{
  if (catalogo.size()==0)
    cout << "Sem video cadastrado!" << endl;
  else {
    cout << "Catalogo Streaming:";
    cout << endl;
    int i = 0;;
    for (vector<Video*>::iterator it = catalogo.begin(); it != catalogo.end(); it++) {
      (*it)->print_info(i + 1);
      i++;
    }
  }
}
};
