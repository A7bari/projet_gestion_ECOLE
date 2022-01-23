#pragma once
class Ecole;
class EquipeFoot
{
private:
	string nom;
	bool gardien;
	Joueur** listeJoueur;
	int nbr_joueur;
	Ecole* monEcole;

public:
	EquipeFoot(string nom, Ecole* monEcole);
	~EquipeFoot();

	void ajouterJoueur(Joueur* j); // ajouter un joueur deja cree.
	void ajouterJoueur(); // ajouter joueur selon son indice dans l'ecole
						  // demande a l'utilisateur d'entrer les donnees de joueur

	void suprimeJoueur(int indice); //supp selon indice 
	void suprimeJoueur(Joueur* j);  // supp selon adress memoire.

	void afficherMembers();

	void menu(); // menu de gestion d'equipe

	friend ostream& operator<<(ostream& stream, EquipeFoot& e);
};

