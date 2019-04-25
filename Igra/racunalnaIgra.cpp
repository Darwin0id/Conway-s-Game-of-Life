#include "racunalnaIgra.h"
#include <time.h>
#include <random>
#include <chrono>

racunalnaIgra::racunalnaIgra()
{
	srand(time(NULL));
	this->velicinaRedaka = 8;
	this->velicinaStupaca = 8;
}

std::string racunalnaIgra::pokreniIgru(int velicinaRedaka, int velicinaStupaca)
{
		this->velicinaRedaka = velicinaRedaka;
		this->velicinaStupaca = velicinaStupaca;
		
		for (int i = 0; i < velicinaRedaka; i++)
		{
			std::vector<char> pomocniV;
			for (int j = 0; j < velicinaStupaca; j++) 
			{
				pomocniV.push_back((vratiRandomBroj() == 1) ? (this->zivaStanica) : (this->mrtvaStanica));
			}
			this->matrica.push_back(pomocniV);
		}

		return vratiPlocu(matrica);
}

std::string racunalnaIgra::vratiPlocu(std::vector<std::vector<char>> const &mat)
{
	std::stringstream bacva;
	
	for (std::vector<char> redak : mat) {
		for (char vrijednost : redak) {
			bacva << vrijednost << " ";
		}
		bacva << '\n';
	}

	return bacva.str();
}

bool racunalnaIgra::vratiRandomBroj()
{
	auto funkcija1 = []() -> int {return rand() & 1;};
	auto funkcija2 = [&]() -> bool {return (funkcija1() | funkcija1());};

	return 1 - (funkcija2());
}

std::string racunalnaIgra::azurirajIgru()
{
	std::stringstream bacva;

	for (int i = 0; i < this->matrica.size(); i++)
	{
		for (int j = 0; j < this->matrica[i].size(); j++)
		{

			int brojac = brojSusjeda(i, j);

			if ((this->matrica[i][j] == this->zivaStanica) && (brojac < 2))
			{
				this->matrica[i][j] = this->mrtvaStanica;
			} 
			
			if ((this->matrica[i][j] == this->zivaStanica) && (brojac > 3)) {
				this->matrica[i][j] = this->mrtvaStanica;
			} 
			
			if ((this->matrica[i][j] == this->zivaStanica) && (brojac == 2 || brojac == 3)) {
				this->matrica[i][j] = this->zivaStanica;
			}

			if ((this->matrica[i][j] == this->mrtvaStanica) && (brojac == 3)) {
				this->matrica[i][j] = this->zivaStanica;
			}

			bacva << this->matrica[i][j] << " ";			
			}
		bacva << '\n';
	}



	return bacva.str();
}

int racunalnaIgra::brojSusjeda(int i, int j)
{
	int brojac = 0;

		if (i != (matrica.size()-1))
		{
			if (this->matrica[i+1][j] == this->zivaStanica)
			{
			brojac += 1;
			}
		}

		if (i != (matrica.size() - 1) && j != (matrica.size()-1))
		{
			if (this->matrica[i+1][j+1] == this->zivaStanica)
			{
				brojac++;
			}
		}

		if (j != (matrica.size() - 1))
		{
			if (this->matrica[i][j+1] == this->zivaStanica)
			{
				brojac++;
			}
		}

		if ((i != 0) && (j != (matrica.size() - 1)))
		{
			if (this->matrica[i-1][j+1] == this->zivaStanica)
			{
				brojac++;
			}
		}

		if ((i != 0))
		{
			if (this->matrica[i-1][j] == this->zivaStanica)
			{
				brojac++;
			}
		}

		if ((i != 0) && (j != 0))
		{
			if (this->matrica[i-1][j-1] == this->zivaStanica)
			{
				brojac++;
			}
		}

		if ((j != 0))
		{
			if (this->matrica[i][j-1] == this->zivaStanica)
			{
				brojac++;
			}
		}

		if (i != (matrica.size() - 1) && (j != 0))
		{
			if (this->matrica[i+1][j-1] == this->zivaStanica)
			{
				brojac++;
			}
		}

	
	return brojac;
}


