#include <stdexcept>
#include "IteratorDictionar.h"
#include "Dictionar.h"

using namespace std;

IteratorDictionar::IteratorDictionar(const Dictionar& d) : dict(d){
	index = 0;
    deplasare();
}


void IteratorDictionar::prim() {
	index = 0;
    deplasare();
}


void IteratorDictionar::urmator() {
    if(!valid())throw std::runtime_error("");
    index++;
    if(index == dict.m)return;
    deplasare();
}


TElem IteratorDictionar::element() const{
    return dict.elem[index];
}


bool IteratorDictionar::valid() const {
    return dict.dim() > 0 && index < dict.m;
}

void IteratorDictionar::deplasare() {
    while(dict.elem[index] == NIL || dict.elem[index] == STERS && index < dict.m )index++;
}

