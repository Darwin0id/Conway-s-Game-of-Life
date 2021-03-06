#pragma once
#include <sstream>
#include <string>
#include <vector>

class racunalnaIgra
{
private:
	//BITNE VARIJABLE
	int velicinaRedaka;
	int velicinaStupaca;
	char zivaStanica = 'x';
	char mrtvaStanica = '.';

	//VEKTOR STVARAJUĈIH STANICA
	std::vector<std::vector<char>> matrica;
public:
	//ZADANE POSTAVKE
	racunalnaIgra();
	racunalnaIgra(char zivaStanica, char mrtvaStanica);
	racunalnaIgra& operator=(const racunalnaIgra&) = delete;

	//GLAVNA KARAKTERSITIKA POKRETANJA IGRE
	std::string pokreniIgru(int velicinaRedaka, int velicinaStupaca);
	std::string vratiPlocu(std::vector<std::vector<char>> const &mat);
	bool vratiRandomBroj();
	std::string azurirajIgru();
	int brojSusjeda(int i, int j);
};

