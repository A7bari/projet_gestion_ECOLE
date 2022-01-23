#include "Header.h"



Joueur::Joueur(Personne* etre, string post, int m) :
	etre(etre),
	post(post),
	numMaillot(m)	
{
	equipe = nullptr;
	//la personne devient un joueur
	etre->setJoueur(true);
}

Joueur::~Joueur()
{
}

string Joueur::getPost()
{
	return this->post;
}

bool Joueur::aEquipe()
{
	return this->equipe != nullptr;
}

void Joueur::setEquipe(EquipeFoot* equipe)
{
	this->equipe = equipe;
}
void Joueur::quiterEquipe()
{
	this->equipe->suprimeJoueur(this);
	equipe = nullptr;
}

ostream& operator<<(ostream& stream, Joueur& j)
{
	return stream << "\n       ---------------------------------------------------------------------------------------------------\n"
		<<"       | "<< j.etre->getData() << "\n       | post : " << j.post << "\n       | num : " << j.numMaillot
		<<"\n       ---------------------------------------------------------------------------------------------------"<< endl;
}
