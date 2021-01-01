#include "Tabela.h"

Tabela::Tabela(const std::vector<Equipe>& participantes) {
	for (int i = 0; i < participantes.size(); ++i)
		tabelaPontos[participantes[i].getNome()] = 0;
}

Tabela::Tabela() {}

void Tabela::pontuar(Equipe& participante, int pontos) {
	if (tabelaPontos.count(participante.getNome()) != 0)
		tabelaPontos[participante.getNome()] += pontos;
}

int Tabela::getPontos(Equipe& participante) {
	if (tabelaPontos.count(participante.getNome()) != 0)
		return tabelaPontos[participante.getNome()];
}

int Tabela::getPosicao(Equipe& participante) {
	int posicao = 1;
	for (auto item : tabelaPontos) {
		if (item.second > tabelaPontos[participante.getNome()])
			posicao++;
	}

	return posicao;
}

int Tabela::getPosicao(std::string nomeParticipante) {
	int posicao = 1;
	for (auto item : tabelaPontos) {
		if (item.second > tabelaPontos[nomeParticipante])
			posicao++;
	}

	return posicao;
}

void Tabela::imprimir() {
	for (auto item : tabelaPontos)
		std::cout << "\t" << item.first << " - " << item.second << " pontos (" << getPosicao(item.first) << "o)\n";
}