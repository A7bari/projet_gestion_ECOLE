#pragma once
class EquipeFoot;

class Joueur
{
private:
	int numMaillot;
	string post;
	Personne* etre;     // pointeur sur la personne qui va etre un joueur 
	EquipeFoot* equipe; // l'equipe de joueur 

public:
	Joueur(Personne* etre, string post, int m);
	~Joueur();

	string getPost(); // retourner le poste de joueur 
	bool aEquipe();  // est-ce-qu'il est affilie a une equipe 

	void setEquipe(EquipeFoot* equipe); // integrer une equipe
	void quiterEquipe();    // quiter l'equipe


	friend ostream& operator<<(ostream& stream, Joueur& j);

};

