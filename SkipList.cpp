//
// Created by Expert on 4/29/2020.
//

#include "SkipList.h"
#include <iostream>
#include <bits/stdc++.h>

SkipList::SkipList(int nivmax, float P) {
    nivelMaxim = nivmax;
    p = P;
    header = new Nod(-1, nivmax);
    nivel = 0;
}

Nod *SkipList::initializareNod(int val, int niv) {
    Nod *n = new Nod(val, niv);
    return n;
}

void SkipList::afisare() {
    for (int i = 0; i <= nivel; i++) {
        Nod *afis = header->urm[i];
        while (afis != nullptr) {
            std::cout << afis->valoare << " ";
            afis = afis->urm[i];
        }
        std::cout << "\n";
    }
}

int SkipList::randomLevel() {
    float raport = (float) rand() / RAND_MAX;
    int niv = 0;
    while (raport < p && niv < nivelMaxim) {
        niv++;
        raport = (float) rand() / RAND_MAX;
    }
    return niv;
}

void SkipList::inserare(int valoare) {
    Nod *nodCurent = header, *aux[nivelMaxim + 1];
    memset(aux, 0, sizeof(Nod *) * (nivelMaxim + 1));
    for (int i = nivel; i >= 0; --i) {
        while (nodCurent->urm[i] != nullptr && nodCurent->urm[i]->valoare < valoare)
            nodCurent = nodCurent->urm[i];
        aux[i] = nodCurent;
    }
    nodCurent = nodCurent->urm[0];
    if (nodCurent == nullptr || nodCurent->valoare != valoare) {
        int nivelNou = randomLevel();
        if (nivelNou > nivel) {
            for (int i = nivel + 1; i < nivelNou + 1; ++i)
                aux[i] = header;
            nivel = nivelNou;
        }
        Nod *nou = initializareNod(valoare, nivelNou);
        for (int i = 0; i <= nivelNou; ++i) {
            nou->urm[i] = aux[i]->urm[i];
            aux[i]->urm[i] = nou;
        }
    }
}

bool SkipList::cautare(int element) {
    Nod *nodCurent = header;
    int i;
    for (i = nivel; i >= 0; --i)
        while (nodCurent->urm[i] != nullptr && nodCurent->urm[i]->valoare < element)
            nodCurent = nodCurent->urm[i];
    nodCurent = nodCurent->urm[0];
    return nodCurent != nullptr && nodCurent->valoare == element;
}

int SkipList::eliminare(int element) {
    Nod *nodCurent = header, *aux[nivelMaxim + 1];
    memset(aux, 0, sizeof(Nod *) * (nivelMaxim + 1));
    int i, nrAparitii = 0;
    for (i = nivel; i >= 0; --i) {
        while (nodCurent->urm[i] != nullptr && nodCurent->urm[i]->valoare < element)
            nodCurent = nodCurent->urm[i];
        aux[i] = nodCurent;
    }
    nodCurent = nodCurent->urm[0];
    if (nodCurent != nullptr && nodCurent->valoare == element) {
        for (i = 0; i <= nivel; ++i) {
            if (aux[i]->urm[i] != nodCurent)
                break;
            else {
                aux[i]->urm[i] = nodCurent->urm[i];
                nrAparitii++;
            }
        }
        while (nivel != 0 && header->urm[nivel] == nullptr)
            nivel--;
    }
    return nrAparitii;
}

Nod *SkipList::predecesor(int element) {
    Nod *nodCurent = header;
    if (element < nodCurent->valoare)
        return nullptr;
    int i;
    for (i = nivel; i >= 0; --i)
        while (nodCurent->urm[i] != nullptr && nodCurent->urm[i]->valoare <= element)
            nodCurent = nodCurent->urm[i];
    return nodCurent;
}

Nod *SkipList::succesor(int element) {
    Nod *nodCurent = header;
    int i;
    for (i = nivel; i >= 0; --i)
        while (nodCurent->urm[i] != nullptr && nodCurent->urm[i]->valoare <= element)
            nodCurent = nodCurent->urm[i];
    if (nodCurent == nullptr || nodCurent->valoare == element)
        return nodCurent;
    nodCurent = nodCurent->urm[0];
    return nodCurent;
}

void SkipList::ordine(int x, int y) {
    Nod *nodCurent = succesor(x);
    if (nodCurent->valoare == x)
        nodCurent = nodCurent->urm[0];
    while (nodCurent->urm[0] != nullptr && nodCurent->valoare < y) {
        std::cout << nodCurent->valoare << " ";
        nodCurent = nodCurent->urm[0];
    }
}