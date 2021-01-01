#include <string>
#include <vector>
#include <iostream>
#include "Modalidade.h"

Modalidade::Modalidade(std::string nome, std::vector<Equipe>& participantes):nomeModalidade(nome),inscritos(participantes){}
//Modalidade::Modalidade(std::string nome) : nomeModalidade(nome) {}

std::string Modalidade::getNome() const { return nomeModalidade; }

void Modalidade::getEquipes(std::vector<Equipe>& destino) const {
	destino.clear();
	for (int i = 0; i < inscritos.size(); ++i)
		destino.push_back(inscritos[i]);
}

int Modalidade::getQuantidadeDeEquipes() const { return inscritos.size(); }

void Modalidade::setResultado() {
	std::string nome;
	for (int i = 0; i < inscritos.size(); ++i) {
		std::cout << "Informe o nome da equipe " << i + 1 << "a colodada: ";
		std::cin >> nome;
		ordemFinal.push_back(nome);
	}

	competicaoTerminada = true;
}

void Modalidade::getResultado(std::vector<Equipe>& destino) const {
	destino.clear();
	for (int i = 0; i < ordemFinal.size(); ++i)
		destino.push_back(ordemFinal[i]);
}

int Modalidade::getPosicao(Equipe participante) const {
	for (int i = 0; i < ordemFinal.size(); ++i) {
		if (ordemFinal[i].getNome() == participante.getNome())
			return i + 1;
	}
	return -1;
}

void Modalidade::imprimir() const {
	std::cout << "Modalidade: " << nomeModalidade << "\n";
	if (competicaoTerminada) {
		std::cout << "Resultado: \n";
		for (int i = 0; i < ordemFinal.size(); ++i) {
			std::cout << "\t" << i + 1 << "o " << ordemFinal[i].getNome() << "\n";
		}
	}
	else {
		std::cout << "Participantes: \n";
		for (int i = 0; i < inscritos.size(); ++i) {
			std::cout << "\t" << inscritos[i].getNome() << "\n";
		}
	}
}