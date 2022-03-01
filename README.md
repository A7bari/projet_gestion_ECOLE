# projet_getsion_ECOLE

## Description

Un projet - Gestion d'Ecole et Gestion des équipes de football composee des classes suivante :
- ## la classe « Personne »
  ### **Les attributs**

  ```cpp
    std::string nom;
	int age;
	bool joueur;
  ```
  ### **Les méthodes**

  ```cpp
  // setters
    void setName(std::string name);
	void setAge(int age);
	void setJoueur(bool j);
	//  getters
	std::string getName();
	int getAge();
	bool jouer();

	virtual string getData(); // methode virtual qui retourne les donnees de la personne sous form d'une string
  ```
  ***
- ## la classe « Etudiant »

   `La classe Etudiant herite de la classe Personne`
  ### **Les attributs**

  ```cpp
    std::string cne, filiere;
	int matricule;
	static int  matricule_compt; // compteur sur les matricules crees
  ```
  ### **Les méthodes**

  ```cpp
  // methode virtual qui retourne les donnes de l'etudiant sous form de string
	string getData();
  ```
  ***
- ## la classe « Professeur »

  `La classe Professeur herite de la classe Personne`
  ### **Les attributs**

  ```cpp
    std::string filiere;
  ```
  ### **Les méthodes**

  ```cpp
  // methode virtual qui retourne les donnes de prof  sous form de string
	string getData();
  ```
  ***
- ## la classe « Ecole »

  définie par les caractéristiques suivantes :
  ### **Contraintes**
  - La classe Ecole possède un `nom` et une `adresse` .
  - Elle possède 2 tableaux dynamiques : `listeEtudiants` et `listeProfesseurs`.
  - Ces tableaux sauvegardent les références (`adresses mémoires`) des étudiants et des professeurs de l'école.
  - Les deux tableaux dynamiques ( `listeEtudiants et listeProfesseurs` ) sont créés initialement avec une taille de 10 çases chacun. 
  - Cette taille doit être **étendue automatiquement de 5 cases** supplémentaires à chaque fois que le tableau saturé. 
  - Pour manipuler ces deux tableaux, on dispose des attributs :

      `taillelisteEtudiants, taillelisteProfs, nbEtudiants et nbProfesseurs.`

  - Extension des tableaux « *listeEtudiants* » et « *listeProfesseurs* » sera réalisée par les méthodes « `etendreTabEtudiants(int)` » et « `etendreTabProfesseurs(int)` ».
  - Le constructeur reçoit seulement deux paramètres qui sont le nom de l'école et son adresse. 
  - La classe Ecole possède la méthode « `ajouterEtudiant()` » qui ne reçoit pas de paramètres et qui demande à l'utilisateur les informations nécessaires pour créer un étudiant. L'étudiant créé sera inséré dans le tableau *listeEtudiants*.
  - Chaque étudiant dans l'école possède un identifiant unique interne à l'école appelé « `matricule` ».
  - La classe Ecole possède également la méthode « `ajouterProfesseur` » qui ne reçoit pas de paramètres et qui demande à l'utilisateur les informations nécessaires pour créer un  professeur. Le professeur créé sera inséré dans le tableau *listeProfesseurs*.  
  - Elle possède également une version surchargée de chacunedes méthodes précédentes. Elles reçoivent en paramètres un objet de type Etudiant et Professeur respectivement.
  - Le service « `supprimerEtudiant` » reçoit en paramètre l'indice de l'étudiant à supprimer dans le tableau listeEtudiants. Cette méthode effectue un **décalage vers la gauche de toutes les cases qui viennent après la case contenant l'élément supprimé**. Idem pour la suppression d'un professeur à travers la méthode « `supprimerPrefesseur` ». 
  - Elle possėde la méthode « `initialiser` » qui remplit le tableau ListeEtudiants de 10 étudiants et remplit le tableau ListeProfesseurs de 10 professeurs. 
  - La méthode « `afficherEtudiants` » affiche les étudiants inscrits à l'école. 
  - La méthode « `afficherProfesseurs`» affiche les professeurs affiliés à l'école. 
  - La méthode « `menu` » propose ces différents services à l'utilisateur.
  - L'opérateur `<<` pour afficher toutes les données de l'école. 

  ### **Les attributs**

  ```cpp
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
  ```

  ### **Les méthodes**

  ```cpp
  // getters
	int getMbEtud();			// nbr d'etudiants dans la liste
	int getMbProf();			// nbr des profs dans la liste 
	Etudiant* getEtud(int indice);	// adresse M d'etudiant a-partir de son indice dans la liste
	Professeur* getProf(int indice); // adresse M du prof a-partir de son indice dans la liste

	// initialise le tableau , 
	void initialise_etud_liste(); //(supp tous les elements et mettre nbr des elements a 0 )
	void initialise_prof_liste();

	// extension des tableaux
	void etendreTabEtudiants(int);
	void etendreTabProfesseurs(int);
	void etendreTabEquipe(int);

	// ajouter etudiant et prof
	void ajouter_etud(); // on donne a l'utilisateur d'entrer les donnees 
	void ajouterProfesseur();	// on donne a l'utilisateur d'entrer les donnees 
	void ajouter_etud(Etudiant*);   // a-partir d'une adresse memoire
	void ajouterProfesseur(Professeur*);

	// supprimer etudiant ou prof selon l'indice 
	void supprimeEtudiant(int);
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

	// affiche le menu de gestion d'equipes
	void gererChampionat();
  ```

  ***
- ## la classe « Joueur »

  ### **Contraintes**

  - Un joueur a un `numéro de maillot`
  - Un joueur a un `poste` dans l'équipe qui peut être : **attaquant, défenseur, milieu ou gardien**.
  - Un joueur peut être un professeur ou un étudiant.
  - Un joueur ne peut être affilié qu'à une seule `équipe`.
  - Un joueur a le droit de quitter une équipe
  - Un joueur n'a pas le droit d'intégrer une équipe, c'est l'équipe qui peut l'ajouter et à condition que ce joueur soit libre et ne soit pas engagé avec une autre équipe.
  - Développez l'opérateur << qui affiche les informations du joueur
  ### **Les attributs**

  -  `int numMaillot`
  -  `string post`
	-  `Personne* etre` : pointeur sur la personne qui va etre un joueur 
	-  `EquipeFoot* equipe` : l'equipe de joueur 

  ### **Les méthodes**

```cpp
    string getPost(); // retourner le poste de joueur 
	bool aEquipe();  // est-ce-que ce joueur est libre et ne soit pas engagé avec une autre équipe ? 
	void setEquipe(EquipeFoot* equipe); // integrer une equipe
	void quiterEquipe();    // quiter l'equipe
```

  ***
- ## la classe « EquipeFoot »

  ### **Contraintes**
  
  - Une équipe a un nom et elle est composée de 6 joueurs. L'équipe ne peut avoir qu'un seul gardien. 
  -bElle possède la méthode « `ajouterJoueur` ». Attention : **l'équipe ne dépasse pas 6 joueurs**.
  - Elle possède la méthode « `supprimerJoueur` ». 
  - La méthode « `afficherMembres` » affiche les informations des 6 membres de l'équipe.
  - La classe Equipe est munie de la méthode « menu » qui affiche les services possibles de cette classe.
  -  Développez l'opérateur << qui affiche les informations de 
  
  ### **Les attributs**
  
  - string `nom`
  - bool `gardien`
  - Joueur** `listeJoueur`
  - int `nbr_joueur`
  - Ecole* `monEcole`

  ### **Les méthodes**

```cpp
    void ajouterJoueur(Joueur* j); // ajouter un joueur deja cree.
	void ajouterJoueur(); // ajouter joueur selon son indice dans l'ecole
						  //et demander a l'utilisateur d'entrer les donnees de joueur
	void suprimeJoueur(int indice); //supp selon indice 
	void suprimeJoueur(Joueur* j);  // supp selon adress memoire.
	void afficherMembers();
	void menu(); // menu de gestion d'equipe  
```

