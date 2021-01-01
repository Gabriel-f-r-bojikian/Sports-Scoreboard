#include "Competicao.h"

const std::map<int, int> Competicao::pontuacaoEmFuncaoDaColocacao = {
	{0, 13},
	{1, 10},
	{2, 8},
	{3, 7},
	{4, 5},
	{5, 4},
	{6, 3},
	{7, 2},
	{8, 1}
};

Competicao::Competicao(std::string nome, std::vector<Equipe>& equipes, int maximoDeModalidades) : nome(nome), inscritos(equipes), maxParticipantes(maximoDeModalidades) {
	Tabela tabelaAux(equipes);
	tabelaDePontos = tabelaAux;
}

std::string Competicao::getNome() { return nome; }

std::vector<Equipe>& Competicao::getEquipes() { return inscritos; }

int Competicao::getQuantidadeDeEquipes() { return inscritos.size(); }

bool Competicao::adicionar(Modalidade& m) {
	if (modalidades.size() < maxParticipantes) {
		modalidades.push_back(m);
		return true;
	}
	else
		return false;
}

std::vector<Modalidade> Competicao::getModalidades() { return modalidades; }

int Competicao::getQuantidadeDeModalidades() { return modalidades.size(); }

Tabela& Competicao::getTabela() {
	
	std::vector<Equipe> times;
	for (int i = 0; i < modalidades.size(); ++i) {
		modalidades[i].getResultado(times);
		for (int j = 0; j < times.size(); ++j)
			tabelaDePontos.pontuar(times[j], pontuacaoEmFuncaoDaColocacao.at(j));
	}

	return tabelaDePontos; 
}

void Competicao::imprimir() {
	std::cout << "\n" << nome << "\n";
	getTabela().imprimir();
}