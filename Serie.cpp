#include "Serie.hpp" 
#include <string>
  

Serie::Serie(std::string nome, int ano, std::string genero,int num_temporadas, int total_episodios):Video(nome,ano,genero),
_num_temporadas(num_temporadas),_total_episodios(total_episodios){}
 
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