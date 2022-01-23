#pragma once
class Ecole
{
private:
	string nom,adresse;
	Etudiant** listeEtudiant;
	Professeur** listeProfesseur;
	EquipeFoot** listeEquipe;

	int tailleListeEtudiants, 
		tailleListeProfs,
		tailleListeEquipe , 
		nbr_prof , 
		nbr_etud,
		nbr_equipes;

public:
	Ecole(string, string);
	~Ecole();

	// getters
	int getMbEtud();			// nbr d'etudiants dans la liste
	int getMbProf();			// nbr des profs dans la liste 
	Etudiant* getEtud(int indice);	// adresse M d'etudiant a-partir de son indice dans la liste
	Professeur* getProf(int indice); // adresse M du prof a-partir de son indice dans la liste

	// initialise le tableau , 
	//(supp tous les elements et mettre nbr des elements a 0 )
	void initialise_etud_liste();
	void initialise_prof_liste();

	// extension des tableaux
	void etendreTabEtudiants(int);
	void etendreTabProfesseurs(int);
	void etendreTabEquipe(int);

	// ajouter etudiant et prof
	void ajouter_etud();		 // on donne a l'utilisateur d'entrer les donnees 
	void ajouterProfesseur();	// on donne a l'utilisateur d'entrer les donnees 
	void ajouter_etud(Etudiant*);   // a-partir d'une adresse mem
	void ajouterProfesseur(Professeur*);

	// supprimer etudiant ou prof selon l'indice 
	void supprimeEtudiant(int);
	//
	void supprimeProfesseur(int indice);

	//initialiser 10 personne dans chaque liste (prof et etud )
	void initialiser();

	//afficher les listes 
	void afficher_etud_list();
	void afficherProfesseurs();

	// menu de gestion d'ecole 
	void menu();

	// gerer les equipes
	void creerEquipe();
	void supprimeEquipe(int indice); // supp equipe selon indice 
	void afficherEquipes();
	void afficherEquipe(int indice); // afficher l'equipe de l'indice entrer 
	void modifierEquipe(int indice); // modifier l'equipe de l'indice entrer 
	void afficherEtudJoueurs();		  // afficher tous les etudiant joueurs 
	void afficherEtud_NON_Joueurs();  // afficher tous les etudiant NON joueurs

	//gestion les equipes 
	// affiche le menu de gestion d'equipes
	void gererChampionat();

	friend ostream& operator<<(ostream& stream, Ecole* ecole);
};

