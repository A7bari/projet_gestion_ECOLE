#include "Header.h"

Ecole::Ecole(string nom, string adresse)
{
	this->nom = nom;
	this->adresse = adresse;
	this->listeEtudiant = new Etudiant*[10];
	this->listeProfesseur = new Professeur*[10];
	this->listeEquipe = new EquipeFoot * [10];
	this->tailleListeEtudiants = this->tailleListeProfs = this->tailleListeEquipe = 10;
	nbr_etud = nbr_prof =nbr_equipes = 0;
	
}
Ecole::~Ecole()
{
	for (int i = 0; i < this->tailleListeProfs; i++)
	{
		delete listeProfesseur[i];
	}
	for (int i = 0; i < this->tailleListeEtudiants; i++)
	{
		delete listeEtudiant[i];
	}
	for (int i = 0; i < nbr_equipes; i++)
	{
		delete listeEquipe[i];
	}
	delete[]listeEquipe;
	delete []listeEtudiant;
	delete []listeProfesseur;
}
int Ecole::getMbEtud()
{
	return nbr_etud;
}
int Ecole::getMbProf()
{
	return nbr_prof;
}
Etudiant* Ecole::getEtud(int indice)
{
	if (indice >= 0 && indice < nbr_etud)
	{

	return listeEtudiant[indice];

	}
	return nullptr;
}
Professeur* Ecole::getProf(int indice)
{
	if (indice >= 0 && indice < nbr_prof)
	{

		return listeProfesseur[indice];

	}
	return nullptr;
}

void Ecole::initialise_prof_liste() 
{
	for (int i = 0; i < this->tailleListeProfs; i++)
	{
		delete listeProfesseur[i];
		listeProfesseur[i] = nullptr;
	}
	nbr_prof = 0;
}
void Ecole::initialise_etud_liste()
{
	for (int i = 0; i < this->tailleListeEtudiants; i++)
	{
		delete listeEtudiant[i];
		listeEtudiant[i] = nullptr;
	}
	nbr_etud = 0;
}
void Ecole::etendreTabEtudiants(int t)
{
	Etudiant** newtab = new Etudiant*[tailleListeEtudiants + t];

	for (int i = 0; i < nbr_etud; i++)
	{
		newtab[i] = listeEtudiant[i];
	}
	delete []listeEtudiant;
	listeEtudiant = newtab;
	tailleListeEtudiants += t;
}
void Ecole::etendreTabProfesseurs(int t)
{
	Professeur** newtab = new Professeur * [tailleListeProfs + t];

	for (int i = 0; i < nbr_etud; i++)
	{
		newtab[i] = listeProfesseur[i];
	}
	delete[]listeProfesseur;
	listeProfesseur = newtab;
	tailleListeProfs += t;
}
void Ecole::etendreTabEquipe(int t)
{
	EquipeFoot** newtab = new EquipeFoot * [tailleListeEquipe + t];

	for (int i = 0; i < nbr_equipes; i++)
	{
		newtab[i] = listeEquipe[i];
	}
	delete[]listeEquipe;
	listeEquipe = newtab;
	tailleListeEquipe += t;
}
void Ecole::ajouter_etud()
{

		if (tailleListeEtudiants == nbr_etud)
		{
			etendreTabEtudiants(5);
		}
		cout << "saisir les information de l'etudiant numero : " << nbr_etud + 1 << endl;
		listeEtudiant[nbr_etud++] = new Etudiant();
	
}
void Ecole::ajouterProfesseur()
{
	if (tailleListeProfs == nbr_prof)
	{
		etendreTabProfesseurs(5);
	}
	cout << "saisir les information de professeur numero : " << nbr_prof + 1 << endl;
	listeProfesseur[nbr_prof++] = new Professeur();

}
void Ecole::ajouter_etud(Etudiant* etud)
{
	if (tailleListeEtudiants == nbr_etud)
	{
		etendreTabEtudiants(5);
	}

	listeEtudiant[nbr_etud++] = etud;

}
void Ecole::ajouterProfesseur(Professeur* prof)
{
	if (tailleListeProfs == nbr_prof)
	{
		etendreTabProfesseurs(5);
	}

	listeProfesseur[nbr_prof++] = prof;
}
void Ecole::supprimeEtudiant(int indice)
{
	if (indice >= nbr_etud  || indice < 0)
	{
		cout << " l'indice entrer n'existe pas \n";
	}
	else
	{
		
		delete listeEtudiant[indice];
		nbr_etud--;
		for (indice; indice < nbr_etud ; indice++)
		{
			listeEtudiant[indice] = listeEtudiant[indice + 1];
		}

	}
}
void Ecole::supprimeProfesseur(int indice)
{
	if (indice >= nbr_prof || indice < 0)
	{
		cout << " l'indice entrer n'existe pas \n";
	}
	else
	{

		delete listeProfesseur[indice];
		nbr_prof--;
		for (indice; indice < nbr_prof; indice++)
		{
			listeProfesseur[indice] = listeProfesseur[indice + 1];
		}

	}
}

void Ecole::initialiser()
{

	string nom[10] = {"mohammed", "ahmed", "ayoub","meryem","asmae","ali","ismail","fatima","younes","ilyas"};

	for (int i = 0; i < 10; i++)
	{
		this->ajouter_etud(new Etudiant(nom[i], 22, "n" + to_string(2432322 * i), "G. Info"));
		this->ajouterProfesseur(new Professeur(nom[i], 40 + i, "G. Informatique"));
		
	}

}
void Ecole::afficher_etud_list()
{
	for (int  i = 0; i < nbr_etud; i++)
	{
		cout <<" "<<i + 1 << " --" << *listeEtudiant[i];
	}
	cout << endl;
}
void Ecole::afficherProfesseurs()
{
	for (int i = 0; i < nbr_prof; i++)
	{
		cout <<"  "<< i + 1 << " --" << *listeProfesseur[i];
	}
	cout << endl;
}

void Ecole::menu()
{
	int choix = -1;
	do
	{
		cout << "\n	menu de gestion d'ecole : ----------------------------- \n"
			<< "			 1 --> ajouter un etudiant. \n"
			<< "			 2 --> ajouter un professeur.\n"
			<< "			 3 --> supprimer un etudiant. \n"
			<< "			 4 --> supprimer un professeur. \n"
			<< "			 5 --> afficher la liste des etudiants. \n"
			<< "			 6 --> afficher la liste des professeurs. \n"
			<< "			 7 --> gestion des equipes. \n"
			<< "			 8 --> quitter \n";
		cin >> choix;
		cin.clear();
		cin.ignore(10000, '\n');

		int indice = -1;

		switch (choix)
		{
		case 1:
			ajouter_etud();
			break;
		case 2:
			ajouterProfesseur();
			break;
		case 3 :
			
			cout << " entrer l'indice d'etudiant a supprime : ";
			cin >> indice;
			cin.clear();
			cin.ignore(256, '\n');
			supprimeEtudiant(indice);
			break;

		case 4:
			
			cout << " entrer l'indice de prof a supprime : ";
			cin >> indice;
			cin.clear();
			cin.ignore(256, '\n');
			supprimeProfesseur(indice);
			break;
		case 5:
			afficher_etud_list();
			break;

		case 6:
			afficherProfesseurs();
			break;
		case 7:
			gererChampionat();
			break;
		
		}


	} while (choix != 8);
}

void Ecole::creerEquipe()
{
	cout << " entrer le nom de nouvelle equipe : ";
	string nom;
	getline(cin, nom);
	listeEquipe[nbr_equipes++] = new EquipeFoot(nom,this);
	cout << "succes de creation d'equipe\n";
	// apres la creation de l'equipe on appelle la methode menu
	// si l'etulisateur veut la gerer
	listeEquipe[nbr_equipes - 1]->menu();

}
void Ecole::supprimeEquipe(int indice)
{
	if (indice >= nbr_equipes || indice < 0)
	{
		cout << "erreur a supp equipe --- indice entrer invalable\n";
	}
	else
	{
		
		for (int i = indice; i < nbr_equipes; i++)
		{
			listeEquipe[i] = listeEquipe[i + 1];
		}
		nbr_equipes--;
	}
}

void Ecole::afficherEquipes()
{
	for (int i = 0; i < nbr_equipes; i++)
	{
		cout << i << "-- " << *listeEquipe[i];
	}
}
void Ecole::afficherEquipe(int indice)
{
	if (indice >= nbr_equipes || indice < 0)
	{
		cout << "erreur a afficher equipe --- indice entrer invalable\n";
	}
	else
	{
		cout << *listeEquipe[indice];
	}

}
void Ecole::modifierEquipe(int indice)
{
	if (indice >= nbr_equipes || indice < 0)
	{
		cout << "erreur a modifier equipe --- indice entrer invalable\n";
	}
	else
	{

		listeEquipe[indice]->menu();
	}
}

void Ecole::afficherEtudJoueurs()
{
	for (int i = 0; i < nbr_etud; i++)
	{
		if (listeEtudiant[i]->jouer())
		{
			cout << *listeEtudiant[i];
		}
	}
}
void Ecole::afficherEtud_NON_Joueurs()
{
	for (int i = 0; i < nbr_etud; i++)
	{
		if (!listeEtudiant[i]->jouer())
		{
			cout << *listeEtudiant[i];
		}
	}
}

void Ecole::gererChampionat()
{
	int choix = -1, indice;
	do
	{
		cout << "\n	menu de gestion des equipes : -----------------------------------\n"
			<< "			1 --> creer une equipe. \n"
			<< "			2 --> supprimer une equipe. \n"
			<< "			3 --> afficher une equipe. \n"
			<< "			4 --> afficher la liste des equipes. \n"
			<< "			5 --> modifier une equipe. \n"
			<< "			6 --> afficher les etudiants de l'ecole affilies aux differents equipes. \n"
			<< "			7 --> afficher les etudiants qui m'aiment pas jouer au football. \n"
			<< "			8 --> quitter. <retour au menu d'ecole>\n";
		cin >> choix;
		cin.ignore(100000, '\n');

		switch (choix)
		{
		case 1:
			creerEquipe();
			break;
		case 2:
			cout << "entrer l'indice d'equipe a supprime : ";
			cin >> indice;
			cin.ignore(100000, '\n');

			supprimeEquipe(indice);
			break;

		case 3:
			cout << "entrer l'indice d'equipe a supprime : ";
			
			cin >> indice;
			cin.ignore(100000, '\n');
			afficherEquipe(indice);
			break;

		case 4:
			afficherEquipes();
			break;

		case 5:
			cout << "entrer l'indice d'equipe a modifier : ";
			int indice;
			cin >> indice;
			cin.ignore(100000, '\n');

			modifierEquipe(indice);
			break;

		case 6:
			afficherEtudJoueurs();
			break;

		case 7:
			afficherEtud_NON_Joueurs();
			break;

		}


	} while (choix != 8);
}

ostream& operator<<(ostream& stream, Ecole* ecole)
{
	stream << " Ecole " << ecole->nom << " adresse : " << ecole->adresse << endl << endl
		<< "lites des etudiants : ----------------------------\n\n";
	for (int i = 0; i < ecole->nbr_etud; i++)
	{
		stream << i + 1 << " --" << *ecole->listeEtudiant[i];
	}
	stream << "\n\nlites des profs : --------------------------\n\n";
	for (int i = 0; i < ecole->nbr_prof; i++)
	{
		stream << i + 1 << " --" << *ecole->listeProfesseur[i];
	}
	stream << endl;


	return stream;
}
