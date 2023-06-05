#ifndef FILME_HPP
#define FILME_HPP

#include <string>
#include <iostream>
#include <list>

#include "Video.hpp"

class Filme : public Video
{

private:
    int duracao;

public:
    virtual void print_info() override;
};

#endif