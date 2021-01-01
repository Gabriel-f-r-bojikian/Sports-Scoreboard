#include <vector>
#include <string>
#include "Equipe.h"

#ifndef MODALIDADE_H
#define MODALIDADE_H

class Modalidade
{
public:
	Modalidade(std::string nome, std::vector<Equipe>& participantes);
	//Modalidade(std::string nome);

	std::string getNome() const;
	void getEquipes(std::vector<Equipe>& destino) const;
	int getQuantidadeDeEquipes() const;
	void setResultado();
	void getResultado(std::vector<Equipe>& destino) const;
	int getPosicao(Equipe participante) const;

	void imprimir() const;

private:
	std::string nomeModalidade;
	std::vector<Equipe>& inscritos;
	std::vector<Equipe> ordemFinal; //Vetor com a coloca��o dos times ao fim da competi��o. A posi��o 0 � do 1�, 1 � do 2� e assim por diante
	bool competicaoTerminada = false;
};


#endif // !MODALIDADE_H