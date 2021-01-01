#include <string>
#include <vector>

#ifndef EQUIPE_H
#define EQUIPE_H


class Equipe
{
public:
	Equipe(std::string nome);
	
	std::string getNome() const;
	void imprimir();

private:
	std::string name;
};

#endif // !EQUIPE_H