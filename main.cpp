
/* 
Nombre: main.cpp
Autor: Manuel Villalpando - Diego Vega
 */

#include "matriz.cpp"
#include "lista.cpp"

int main(int argc, char *argv[])
{
    listagrafica<char> graph(true);
    graph.vertice('A');
    graph.vertice('B');
    graph.vertice('C');
    graph.vertice('D');
    graph.vertice('E');
    graph.punto('A', 'B');
    graph.punto('A', 'C');
    graph.punto('B', 'C');
    graph.punto('B', 'D');
    graph.punto('C', 'D');
    graph.punto('C', 'E');
    graph.punto('D', 'E');
    graph.dfs('B');
    std::cout << std::endl;
    graph.bfs('B');
    std::cout << std::endl;
    std::cout << graph;
    return 0;
}
