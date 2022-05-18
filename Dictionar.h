#pragma once


#define NULL_TVALOARE -1
typedef int TCheie;
typedef int TValoare;

class IteratorDictionar;

#include <utility>
#include <climits>

typedef std::pair<TCheie,TValoare> TElem;
const TElem STERS{ INT_MAX , INT_MAX };
const TElem NIL{INT_MAX-1, INT_MAX-1};

class Dictionar {
	friend class IteratorDictionar;

	private:
    int len; //nr de elemente adaugate
    int m; // nr de locatii
	TElem* elem; ///vectorul de elemente
    int d(TCheie c, int i) const; ///functia de dispersie asociata
    int disp(TCheie c) const; ///functia de dispersie uzuala

    bool prim(int);
    void redim();
    int k = 1;

	public:

	// constructorul implicit al dictionarului
	Dictionar();

	// adauga o pereche (cheie, valoare) in dictionar	
	//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
	// daca nu exista cheia, adauga perechea si returneaza null: NULL_TVALOARE
	TValoare adauga(TCheie c, TValoare v);

	//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null: NULL_TVALOARE
	TValoare cauta(TCheie c) const;

	//sterge o cheie si returneaza valoarea asociata (daca exista) sau null: NULL_TVALOARE
	TValoare sterge(TCheie c);

	//returneaza numarul de perechi (cheie, valoare) din dictionar 
	int dim() const;

	//verifica daca dictionarul e vid 
	bool vid() const;

	// se returneaza iterator pe dictionar
	IteratorDictionar iterator() const;


	// destructorul dictionarului	
	~Dictionar();

};


