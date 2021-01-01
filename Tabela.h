#include <iostream>
#include <vector>
#include <map>
#include <string>
#include"Equipe.h"

#ifndef TABELA_H
#define TABELA_H

class Tabela
{
public:
	Tabela(const std::vector<Equipe>& participantes);
	Tabela();

	void pontuar(Equipe& participante, int pontos);
	int getPontos(Equipe& participante);
	int getPosicao(Equipe& participante);
	int getPosicao(std::string nomeParticipante);
	void imprimir();

private:
	std::map<std::string, int> tabelaPontos;
};

#endif // !TABELA_H