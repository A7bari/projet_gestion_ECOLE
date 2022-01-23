#include "Header.h"

Professeur::Professeur(std::string nom, int age, string filiere) : Personne(nom,age)
{

	this->filiere = filiere;
}

Professeur::Professeur(Professeur& prof)
{
	this->nom = prof.nom;
	this->age = prof.age;
	this->filiere = prof.filiere;
}

// constructeur qui donne a l'utilisateur d'entrer les donnes de prof
Professeur::Professeur()
{
	cout << " entrer le nom de professeur : ";
	getline(cin, this->nom);

	cout << " entrer specialite : ";
	getline(cin, this->filiere);

	cout << " entrer age : ";
	cin >> this->age;
	cin.ignore(256,'\n');
	cout << endl;
}

Professeur::~Professeur()
{
}

string Professeur::getData()
{
	return "prof " + nom + "  |  age : " + to_string(age) + "  |  filiere : " + filiere;
}



std::ostream& operator<<(std::ostream& Stream, Professeur& p)
{
	return Stream  <<"prof : "<<  p.nom << endl
		<< "	|  age : " << p.age << endl
		<< "	|  specialite : " << p.filiere << endl
		<< "	 ----------------------------------- \n";
}