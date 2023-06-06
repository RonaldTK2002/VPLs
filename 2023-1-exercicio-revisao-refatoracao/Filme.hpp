#ifndef FILME_HPP
#define FILME_HPP

#include <string>
#include <iostream>
#include <list>

#include "Video.hpp"

class Filme : public Video
{

private:
    int _duracao;

public:
    Filme(std::string nome, int ano, std::string genero,int duracao);
    ~Filme();
    virtual void print_info() override;
    int get_duracao();
};

#endif