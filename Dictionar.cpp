#include "Dictionar.h"
#include <iostream>
#include "IteratorDictionar.h"

Dictionar::Dictionar() {
    elem = new TElem[8];
    for(int i = 0; i < 8; i++)
        elem[i] = NIL;
    m = 8;
    len = 0;
}

Dictionar::~Dictionar() {
    delete elem;
}

TValoare Dictionar::adauga(TCheie c, TValoare v) {
    int primaLibera = -1;
    TValoare fosta = NULL_TVALOARE;
    for(int i = 0; i < m; i++){
        int j = d(c, i);
        if(elem[j].first == c){
            fosta = elem[j].second;
            elem[j].second = v;
            return fosta;
        }
        if(elem[j] == NIL || elem[j] == STERS){
            primaLibera = j;
            break;
        }
    }
    if (primaLibera != -1) {
        TElem nou{c, v};
        len++;
        elem[primaLibera] = nou;
        return NULL_TVALOARE;
    }
    redim();
    return adauga(c, v); ///reincercare dupa redimensionare
}


//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
TValoare Dictionar::cauta(TCheie c) const {
    for(int i = 0; i < m; i++){
        int j = d(c, i);
        if(elem[j] == NIL)break;
        if(elem[j].first == c)return elem[j].second;
    }
    return NULL_TVALOARE;
}


TValoare Dictionar::sterge(TCheie c) {
    TValoare fosta = NULL_TVALOARE;
    for(int i = 0; i < m; i++){
        int j = d(c, i);
        if(elem[j] == NIL)break;
        if(elem[j].first == c){
            fosta = elem[j].second;
            elem[j] = STERS;
            len--;
        }
    }
    return fosta;
}


int Dictionar::dim() const {
    return len;
}

bool Dictionar::vid() const {
    return len == 0;
}


IteratorDictionar Dictionar::iterator() const {
    return IteratorDictionar(*this);
}

int Dictionar::d(TCheie c, int i) const {
    return (disp(c)+(i+(i*i))/2) % m;
}

int Dictionar::disp(TCheie c) const{
    return abs(c) % m;
}

void Dictionar::redim() {
//    k++;
//    while(!prim(4*k + 3))k++;
    int vechi = m;
    m= 2*m;

    TElem* newElem = new TElem[m];
    for(int i = 0; i < m; i++)newElem[i] = NIL;

    ///redispersare
    for(int i = 0; i < vechi; i++){
        if(elem[i] != NIL && elem[i] != STERS){
            TElem dePus = elem[i];
            for(int ii = 0; ii < m; ii++){
                int j = d(dePus.first, ii);
                if(newElem[j] == NIL){
                    newElem[j] = dePus;
                    break;
                }
            }
        }
    }
    delete elem;
    elem = newElem;
}

bool Dictionar::prim(int n) {
    if(n < 2)return false;
    for(int i = 2; i <= n/2; i++)
        if(n % i == 0)
            return false;
    return true;
}


