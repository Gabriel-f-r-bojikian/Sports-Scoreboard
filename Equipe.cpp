#include <iostream>
#include "Equipe.h"

Equipe::Equipe(std::string nome):name(nome) {}
//Equipe::Equipe() {}

std::string Equipe::getNome() const{
	return name;
}

void Equipe::imprimir() {
	std::cout << "Equipe " << name;
}
