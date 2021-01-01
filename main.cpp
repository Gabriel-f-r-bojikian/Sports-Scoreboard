#include <iostream>
#include <vector>
#include <string>
#include <map>
#include "Equipe.h"
#include "Modalidade.h"
#include "Tabela.h"
#include "Competicao.h"

using namespace std;

//Criar competicao
Competicao criaCompeticao(vector<Equipe>& equipes, int& numEquipes);
string inputNomeCompeticao();
int inputQuantidadeDeEquipes();
void cadastraEquipes(vector<Equipe>& equipes, int& numEquipes);
string inputNomeEquipe(int numeroDaEquipe);
//Receber modalidades
void recebeModalidades(vector<Equipe>& equipesInscritas, vector<Modalidade>& modalidades, int& numEquipes);
int inputQuantidadeDeModalidades();
void cadastrarModalidades(int numModalidades, vector<Equipe>& equipesInscritas, vector<Modalidade>& modalidades);
string inputNomeDaModalidade(int numeroDaModalidade);
void guardarResultadoModalidade(string nomeModalidade, vector<Equipe>& equipesInscritas, vector<Modalidade>& modalidades);
//Adicionar modalidades em competição
void adicionaModalidadesEmCompeticao(vector<Modalidade> modalidades, Competicao& competicao);

int main() {
	
	int numEquipes;
	vector<Equipe> timesInscritos;
	Competicao competicao = criaCompeticao(timesInscritos, numEquipes);

	vector<Modalidade> modalidades;
	recebeModalidades(timesInscritos, modalidades, numEquipes);

	adicionaModalidadesEmCompeticao(modalidades, competicao);

	competicao.imprimir();

	return 0;
}

//Criar competicao
Competicao criaCompeticao(vector<Equipe>& equipes, int& numEquipes) {
	string nomeCompeticao = inputNomeCompeticao();
	numEquipes = inputQuantidadeDeEquipes();
	cadastraEquipes(equipes, numEquipes);

	Competicao competicao(nomeCompeticao, equipes, numEquipes);
	return competicao;
}

string inputNomeCompeticao() {
	cout << "Informe o nome da competicao: ";
	string nomeCompeticao;
	cin >> nomeCompeticao;
	return nomeCompeticao;
}

int inputQuantidadeDeEquipes() {
	cout << "Informe a quantidade de equipes: ";
	int quantidadeDeEquipes = 0;
	cin >> quantidadeDeEquipes;
	return quantidadeDeEquipes;
}

void cadastraEquipes(vector<Equipe>& equipes, int& numEquipes){
	string nomeEquipe = "";
	for (int numeroDaEquipe = 0; numeroDaEquipe < numEquipes; ++numeroDaEquipe) {
		nomeEquipe = inputNomeEquipe(numeroDaEquipe);
		equipes.push_back(Equipe(nomeEquipe));
	}
}

string inputNomeEquipe(int numeroDaEquipe) {
	cout << "Informe o nome da equipe " << numeroDaEquipe + 1 << ": ";
	string nomeEquipe = "";
	cin >> nomeEquipe;
	return nomeEquipe;
}

//Receber modalidades
void recebeModalidades(vector<Equipe>& equipesInscritas, vector<Modalidade>& modalidades, int& numEquipes) {
	int numModalidades = inputQuantidadeDeModalidades();
	cadastrarModalidades(numModalidades, equipesInscritas, modalidades);
}

int inputQuantidadeDeModalidades() {
	cout << "Informe a quantidade de modalidades: ";
	int numModalidades = 0;
	cin >> numModalidades;
	return numModalidades;
}

void cadastrarModalidades(int numModalidades, vector<Equipe>& equipesInscritas, vector<Modalidade>& modalidades) {
	string nomeModalidade;

	for (int numeroDaModalidade = 0; numeroDaModalidade < numModalidades; ++numeroDaModalidade) {
		nomeModalidade = inputNomeDaModalidade(numeroDaModalidade);
		guardarResultadoModalidade(nomeModalidade, equipesInscritas, modalidades);
	}
}

string inputNomeDaModalidade(int numeroDaModalidade) {
	string nomeModalidade;
	cout << "\nInforme o nome da modalidade " << numeroDaModalidade + 1 << ": ";
	cin >> nomeModalidade;

	return nomeModalidade;
}

void guardarResultadoModalidade(string nomeModalidade, vector<Equipe>& equipesInscritas, vector<Modalidade>& modalidades) {
	Modalidade modalidade(nomeModalidade, equipesInscritas);
	modalidade.setResultado();
	modalidades.push_back(modalidade);
}

//Adicionar modalidades em competição
void adicionaModalidadesEmCompeticao(vector<Modalidade> modalidades, Competicao& competicao) {
	for (int i = 0; i < modalidades.size(); ++i)
		competicao.adicionar(modalidades[i]);
}