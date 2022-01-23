#pragma once
class Professeur : public Personne
{
private:
	std::string filiere;
public:

	Professeur(std::string nom, int age, string filiere);
	Professeur(Professeur&);

	// constructeur qui donne a l'utilisateur d'entrer les donnes de prof
	Professeur();
	~Professeur();

	// methode virtual qui retourne les donnes de prof  sous form de string
	string getData();
	friend std::ostream& operator<<(std::ostream& Stream, Professeur& p);
};

