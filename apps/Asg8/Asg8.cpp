// Used for Help: https://www.geeksforgeeks.org/number-sink-nodes-graph/

#include <iostream>
#include "graph.hpp"
int main()
{
    int number_of_vertices = 6, number_of_edges = 5;
    Graph<int> g(number_of_vertices);
    g.insert(1, 6);
    g.insert(2, 3);
    g.insert(4, 3);
    g.insert(5, 3);
    int vertex = g.eliminate();

    if (vertex >= 0)
        cout << "Sink found at vertex " << (vertex + 1)
        << endl;
    else
        cout << "No Sink" << endl;

    return 0;
}
