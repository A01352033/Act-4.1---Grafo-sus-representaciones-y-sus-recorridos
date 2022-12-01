#ifndef LISTA_H
#define LISTA_H

#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <iostream>
#include <fstream>
#include "grafica.h"

template <class T>
class lista: public grafica<T>
{
public:
    lista(bool dir = false);
    ~lista();
    std::vector<T> getVert() const;
    std::vector<T> getNB(T) const;

    void punto(T, T);
    void deleteP(T, T);
    void vertice(T);
    void deleteV(T);
    bool isPunto(T, T) const;
    bool isVertice(T) const;

    template <class U>
    friend std::ostream &operator<<(std::ostream &, lista<U> &);
    
private:
    int size;
    bool directed;
    std::set<T> vertices;
    std::map<T, std::set<T>> puntos;
};
#endif
