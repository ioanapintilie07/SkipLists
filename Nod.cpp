//
// Created by Expert on 4/29/2020.
//

#include "Nod.h"
#include <bits/stdc++.h>

Nod::Nod(int val, int niv) {
    valoare = val;
    urm = new Nod *[niv + 1];
    memset(urm, 0, sizeof(Nod *) * (niv + 1));
}

Nod::~Nod() {
    valoare = -1;
    delete urm;
}

int Nod::getValoare() {
    return valoare;
}
