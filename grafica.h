#ifndef GRAFICA_H
#define GRAFICA_H

#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <iostream>

template <class T>
class grafica {
public:
    void cargraf(int, std::ifstream &);

    virtual void punto(T, T) = 0;
    virtual void deleteP(T, T) = 0;
    virtual void vertice(T) = 0;
    virtual void deleteV(T) = 0;
    virtual bool isPunto(T, T) const = 0;
    virtual bool isVertice(T) const = 0;

    virtual std::vector<T> getVert() const = 0;
    virtual std::vector<T> getNB(T) const = 0;

    std::set<T> dfs(T) const;
    std::set<T> bfs(T) const;

private:
    int size;
    bool directed;
};

//Grado de complejidad: O(n^2)
template <class T>
std::set<T> grafica<T>::dfs(T v) const {
    if (!isVertice(v))
        throw std::invalid_argument("Error, no hay vertice exisrente");

    std::set<T> visited;
    std::stack<T> toSearch;
    toSearch.push(v);

    T current;
    while (!toSearch.empty())
    {
        current = toSearch.top();
        toSearch.pop();
        if (visited.find(current) == visited.end())
        {
            std::cout << current << " ";
            visited.insert(current);
            for (auto elem : getNeighbours(current))
                toSearch.push(elem);
        }
    }
    std::cout << std::endl;

    return visited;
}

//Grado de complejidad: O(n^2)
template <class T>
std::set<T> grafica<T>::bfs(T v) const {
    if (!isVertice(v))
        throw std::invalid_argument("Error, no hay vertice exisrente");

    std::set<T> visited;
    std::queue<T> toSearch;
    toSearch.push(v);

    T current;
    while (!toSearch.empty()) {
        current = toSearch.front();
        toSearch.pop();
        if (visited.find(current) == visited.end()){
            std::cout << current << " ";
            visited.insert(current);
            for (auto elem : getNeighbours(current))
                toSearch.push(elem);
        }
    }
    std::cout << std::endl;

    return visited;
}

template <class T>
void grafica<T>::loadGraph(int n, std::ifstream &inputFile) {
    size = n;
    int inicio, fin;

    inputFile >> inicio >> fin;

    while (inicio && fin) {
        inputFile >> inicio >> fin;
        punto(inicio, fin);
    }
}

#endif
