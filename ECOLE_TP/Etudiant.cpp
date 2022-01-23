#include "Header.h"

// initialiser le compteur des matricules 
int Etudiant::matricule_compt = 0;

Etudiant::Etudiant(std::string nom, int age, std::string cne, string filiere) : Personne(nom , age)
{

	this->cne = cne;
	this->filiere = filiere;
	this->matricule = ++matricule_compt;

}

// constructeur qui donne a l'utilisateur d'entrer les donnes d'etudiant
Etudiant::Etudiant()
{
	cout << " entrer le nom d'etudiant : ";
	getline(cin, this->nom);

	cout << " entrer age : ";
	cin >> this->age;
	cin.ignore(256, '\n');

	cout << " entrer CNE : ";
	getline(cin, this->cne);

	cout << " entrer filiere : ";
	getline(cin, this->filiere);
	cout << endl;

	this->matricule = ++matricule_compt;
}

Etudiant::Etudiant(Etudiant& etud)
{
	this->nom = etud.nom;
	this->age = etud.age;
	this->cne = etud.cne;
	this->filiere = etud.filiere;
	this->matricule = etud.matricule;

}

Etudiant::~Etudiant()
{

}


// retourne les donnes de l'etudiant sous form de string
string Etudiant::getData()
{
	 return "etudiant : " + nom + "  | matricule : " + to_string(matricule) + "  |  age : " + to_string(age) + "  |  cne : " + cne + "  |  filiere : " + filiere;
}




std::ostream& operator<<(std::ostream& F, Etudiant& p)
{
	return F <<"|  "<<  p.nom <<endl
		<< "     |  matricule : " << p.matricule << endl
		<< "     |  age : " << p.age << endl
		<< "     |  cne : " << p.cne << endl
		<< "     |  filiere : " << p.filiere << endl
		<< "     ------------------------------------\n";
}

