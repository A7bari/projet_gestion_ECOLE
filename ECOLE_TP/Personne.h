#pragma once

class Personne
{
protected:
	std::string nom;
	int age;
	bool joueur;

public:
	Personne(std::string name, int age);
	Personne();
	Personne(Personne& p);


	void setName(std::string name);
	void setAge(int age);
	void setJoueur(bool j);

	std::string getName();
	int getAge();
	bool jouer();


	bool operator==(Personne med);

	bool operator!=(Personne med);
	bool operator<(Personne med);
	bool operator<=(Personne med);
	bool operator>(Personne med);
	bool operator>=(Personne med);

	// methode virtual qui retourne les donnees de la personne sous form d'une string
	virtual string getData();


	friend std::ostream& operator<<(std::ostream& F, Personne& p);
};

