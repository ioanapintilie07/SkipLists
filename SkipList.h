//
// Created by Expert on 4/29/2020.
//

#ifndef INCERCARE_SKIPLIST_H
#define INCERCARE_SKIPLIST_H

#include "Nod.h"

class SkipList {
    int nivelMaxim;
    float p;
    int nivel;
    Nod *header;
public:
    SkipList(int, float);

    ~SkipList() {
        delete header;
    }

    static Nod *initializareNod(int, int);

    void afisare();

    int randomLevel();

    void inserare(int);

    bool cautare(int element);

    int eliminare(int element);

    Nod *succesor(int element);

    Nod *predecesor(int element);

    void ordine(int x, int y);

};


#endif //INCERCARE_SKIPLIST_H
