//
// Created by Expert on 4/29/2020.
//

#ifndef INCERCARE_NOD_H
#define INCERCARE_NOD_H


class Nod {
    int valoare;
    Nod **urm;
public:
    Nod(int, int);

    ~Nod();

    int getValoare();

    friend class SkipList;
};


#endif //INCERCARE_NOD_H
