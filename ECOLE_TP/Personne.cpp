#include "Header.h"


Personne::Personne(string name, int age)
{
    this->nom = name;
    this->age = age;
    joueur = false;

};
Personne::Personne()
{
    this->nom = "inconnu";
    this->age = 0;
    joueur = false;
}
Personne::Personne(Personne& p)
{
    this->nom = p.nom;
    this->age = p.age;
    joueur = p.joueur;
}

// ==================stters
void Personne::setName(string name) { this->nom = name; }
void Personne::setAge(int age) { this->age = age; }

void Personne::setJoueur(bool j)
{
    joueur = j;
}


// =========================getters

string Personne::getName() { return this->nom; }
int Personne::getAge() { return this->age; }

bool Personne::jouer()
{
    return joueur;
}

bool Personne::operator==(Personne med)
{
    if (age == med.age)
    {
        return true;
    }
    return false;
}

bool Personne::operator!=(Personne med)
{
    return !((*this) == med);
}
bool Personne::operator<(Personne med)
{
    if (age < med.age)
    {
        return true;
    }
    return false;
}
bool Personne::operator<=(Personne med)
{
    return (*this) == med || (*this) < med;
}
bool Personne::operator>(Personne med)
{
    return !((*this) <= med);
}
bool Personne::operator>=(Personne med)
{
    return !((*this) < med);
}

string Personne::getData()
{
    return " ";
}

std::ostream& operator<<(std::ostream& F, Personne& p)
{
    return F << p.nom << "   " << p.age << endl;
}
