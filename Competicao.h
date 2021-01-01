#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"

#ifndef COMPETICAO_H
#define COMPETICAO_H

class Competicao
{
public:
	Competicao(std::string nome, std::vector<Equipe>& equipes, int maximoDeModalidades);
	Competicao();

	std::string getNome();
	std::vector<Equipe>& getEquipes();
	int getQuantidadeDeEquipes();

	bool adicionar(Modalidade& m);
	std::vector<Modalidade> getModalidades();
	int getQuantidadeDeModalidades();

	Tabela& getTabela();

	void imprimir();

private:
	std::string nome;
	std::vector<Equipe>& inscritos;
	int maxParticipantes;

	std::vector<Modalidade> modalidades;
	Tabela tabelaDePontos;

	static const std::map<int, int> pontuacaoEmFuncaoDaColocacao;
};

#endif // !COMPETICAO_H