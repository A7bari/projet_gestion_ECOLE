#include "Header.h"

EquipeFoot::EquipeFoot(string nom, Ecole* monEcole): nom(nom), monEcole(monEcole)
{
	listeJoueur = new Joueur * [6];
	gardien = false;
	nbr_joueur = 0;
}

EquipeFoot::~EquipeFoot()
{
	for (int i = 0; i < nbr_joueur; i++)
	{
		listeJoueur[i]->quiterEquipe();
		delete listeJoueur[i];
	}
	delete []listeJoueur;
}

void EquipeFoot::ajouterJoueur()
{
	string choix;
	int num,npost, indice;
	Personne* p;

	cout << "le joueur est un etudiant ou un prof ? (e/p)  : ";
	getline(cin, choix);

	if (choix == "e")
	{
		cout << "entrer l'indice de l'etudiant a ajouter"<< " (entre : 0-"<<monEcole->getMbEtud() -1 <<") : ";
		cin >> indice;
		cin.ignore();
		p = monEcole->getEtud(indice);
	}
	else
	{
		cout << "entrer l'indice de prof a ajouter" << " (entre : 0-" << monEcole->getMbProf()-1 << ") : ";
		cin >> indice;
		cin.ignore();
		p = monEcole->getProf(indice);
	}

	if ( p != nullptr) {
		string post[5] = {"attaquant","defenseur","milieu","gardient"};

		cout << "entrer le numero du poste du joueur \n (";
		for (int i = 0; i < 4; i++)
		{
			cout << i << "- " << post[i]<< "  ";
		}
		cout << ") : ";

		cin >> npost;
		cin.ignore(10000, '\n');

		cout << "entrer le numero de maillot du joueur : ";
		cin >> num;
		cin.ignore(10000, '\n');

		Joueur* j = new Joueur(p, post[npost], num);
		ajouterJoueur(j);
	}
	else
	{
		cout << "ERR ajouterJoueur --- indice invalide \n";
	}


}

void EquipeFoot::ajouterJoueur(Joueur* j)
{
	if (nbr_joueur < 6 && !j->aEquipe())     //il faux que ce joueur soit libre 
	{
		// si le joueur est un gardient en verifier s'il y a deja un gardient dans l'equipe
		if (j->getPost() == "gardien")
		{
			if (gardien)
			{
				cout << "echec d'ajouter ---equipe a deja un gardien ! \n";
			}
			else
			{
				listeJoueur[nbr_joueur++] = j;
				j->setEquipe(this);
				gardien = true;
				cout << "ajouter avec secces !! \n";
			}
		}
		else
		{
			listeJoueur[nbr_joueur++] = j;
			j->setEquipe(this);
			cout << "ajouter avec secces !! \n";
		}
	}
	else 
	{
		cout << "echec d'ajouter ---equipe saturee \n";
	}
}

void EquipeFoot::suprimeJoueur(int indice)
{
	if (indice < 0 || indice >= nbr_joueur) // assure que ce indice est existe
	{
		cout << "echec a suprime ---indice erreur !! \n";
	}
	else
	{
		listeJoueur[indice]->setEquipe(nullptr);
		nbr_joueur--;
		for (int i = indice; i < nbr_joueur; i++)
		{
			listeJoueur[i] = listeJoueur[i + 1];
		}
		cout << "supprimee avec succes !!\n ";

	}
}
void EquipeFoot::suprimeJoueur(Joueur* j)
{
	// on cherche l'indice de cette adresse dans la liste des joueurs si il existe
	
	for (int i = 0; i < nbr_joueur; i++)
	{
		if (listeJoueur[i] == j)
		{
			suprimeJoueur(i);
			break;
		}
	}
}

void EquipeFoot::afficherMembers()
{
	cout << "\n members d'equipe " << nom << " ===================================================================================\n";
	for (int i = 0; i < nbr_joueur; i++)
	{
		cout << *listeJoueur[i];

	}
	cout << "==========================================================================================================\n\n";
}

void EquipeFoot::menu()
{
	int choix = -1, indice;
	do
	{
		cout << "		menu de gestion d'equipe "<< this->nom <<" : ----------------------------\n"
			<< "			1--> ajouter un joueur. \n"
			<< "			2--> suprimer un joueur.\n"
			<< "			3--> afficher la liste des joueurs. \n"
			<< "			4--> quitter.\n";
		cin >> choix;
		cin.clear();
		cin.ignore(10000, '\n');

		switch (choix)
		{
		case 1:
			ajouterJoueur();
			break;
		case 2:
			cout << " entrer l'indice a supprimer : ";
			cin >> indice;
			cin.clear();
			cin.ignore(10000, '\n');
			this->suprimeJoueur(indice);
			break;

		case 3:
			cout << *this;
			break;
		}

	} while (choix != 4);
}

ostream& operator<<(ostream& stream, EquipeFoot& e)
{
	stream <<  e.nom << " =========================================================================================\n";
	for (int i = 0; i < e.nbr_joueur; i++)
	{
		stream << *e.listeJoueur[i];

	}
	stream << "==========================================================================================================\n\n";
	return stream;
}
