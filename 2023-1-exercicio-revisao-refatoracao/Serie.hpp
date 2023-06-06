 #ifndef SERIE_HPP
#define SERIE_HPP

#include <string>
#include <iostream>
#include <list>

#include "Video.hpp"

class Serie: public Video{

    private:

    int _num_temporadas,_total_episodios;
    
    public:

    Serie(std::string nome, int ano, std::string genero,int num_temporadas, int total_episodios);
    ~Serie();
    virtual void print_info() override;
    int get_num_temp();
    int get_total_ep();

};

#endif