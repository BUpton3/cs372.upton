// Used for Help: https://www.geeksforgeeks.org/add-and-remove-vertex-in-adjacency-list-representation-of-graph/
// Used for Help: https://www.geeksforgeeks.org/add-and-remove-vertex-in-adjacency-matrix-representation-of-graph/
// Used for Help: https://www.geeksforgeeks.org/add-and-remove-edge-in-adjacency-matrix-representation-of-a-graph/

#include "Graph.hpp"

int main()
{
    cout << "Adjacency Matrix Graph Working" << endl;
    AdjMatGraph<int> matGraph(4);
    matGraph.addEdge(0, 1);
    matGraph.addEdge(0, 2);
    matGraph.addEdge(1, 2);
    matGraph.addEdge(2, 3);
    cout << "\n\nBefore adding Vertex: ";
    matGraph.displayAdjacencyMatrix();
    matGraph.addVertex();
    matGraph.addEdge(4, 1);
    matGraph.addEdge(4, 3);
    cout << "\n\nAfter adding Vertex: ";
    matGraph.displayAdjacencyMatrix();
    matGraph.removeVertex(1);
    cout << "\n\nAfter removing Vertex: ";
    matGraph.displayAdjacencyMatrix();
    matGraph.delEdge(1, 2);
    cout << "\n\nAfter removing Edge: ";
    matGraph.displayAdjacencyMatrix();
    cout << "\n\n\n";

    cout << "Adjacency List Graph Working" << endl;
    AdjListGraph<int> listGraph(5);
    listGraph.addEdge(0, 1);
    listGraph.addEdge(0, 3);
    listGraph.addEdge(0, 4);
    listGraph.addEdge(1, 2);
    listGraph.addEdge(1, 3);
    listGraph.addEdge(3, 2);
    listGraph.addEdge(4, 3);
    listGraph.addEdge(3, 4);
    cout << "\nBefore adding Vertex: " << endl;
    listGraph.printGraph();
    listGraph.addVertex(5, 3, 2);
    cout << "\nAfter adding Vertex: " << endl;
    listGraph.printGraph();
    listGraph.delVertex(4);
    cout << "\nAfter removing Vertex: " << endl;
    listGraph.printGraph();
    cout << "\n\n\n";
  // Everything works!
    return 0;
}
