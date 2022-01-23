#pragma once

class Etudiant : public Personne
{
private:
	
	std::string cne, filiere;
	int matricule;
public:
	static int  matricule_compt; // compteur sur les matricules crees 

public:
	

	Etudiant(std::string nom, int age, std::string cne, string filiere);
	Etudiant(Etudiant& etud);
	
	// constructeur qui donne a l'utilisateur d'entrer les donnes d'etudiant
	Etudiant();
	~Etudiant();

	// methode virtual qui retourne les donnes de l'etudiant sous form de string
	string getData();


	friend std::ostream& operator<<(std::ostream& F, Etudiant& p);
};


