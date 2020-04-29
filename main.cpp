#include <iostream>
#include <fstream>
#include "SkipList.h"
#include "Nod.h"
#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("intrare.in");
    srand((unsigned) time(nullptr));
    int nivelMaxim, nrInstructiuni, i, instructiune, x, y;
    float p;
    Nod *succ, *pred;
    cin >> nivelMaxim >> p;
    SkipList lst(nivelMaxim, p);
    fin >> nrInstructiuni;
    for (i = 0; i < nrInstructiuni; ++i) {
        fin >> instructiune;
        if (instructiune == 1) {
            fin >> x;
            cout << "A fost inserata valoarea " << x << ".\n";
            lst.inserare(x);
        } else if (instructiune == 2) {
            fin >> x;
            int nrAparitii = lst.eliminare(x);
            cout << "Au fost eliminate toate cele " << nrAparitii << " aparitii ale lui " << x << ".\n";
        } else if (instructiune == 3) {
            fin >> x;
            if (lst.cautare(x)) std::cout << x << " se gaseste in lista.\n";
            else cout << x << " nu se gaseste in lista.\n";
        } else if (instructiune == 4) {
            fin >> x;
            succ = lst.succesor(x);
            if (succ == nullptr) std::cout << "-1\n";
            else cout << "Succesorul lui " << x << " este " << succ->getValoare() << ".\n";
        } else if (instructiune == 5) {
            fin >> x;
            fin >> x;
            pred = lst.predecesor(x);
            if (pred == nullptr) std::cout << "-1\n";
            else cout << "Predecesorul lui " << x << " este " << pred->getValoare() << ".\n";
        } else if (instructiune == 6) {
            fin >> x >> y;
            cout << "\n";
            lst.ordine(x, y);
            cout << "\n";
        }
    }
    fin.close();
}
