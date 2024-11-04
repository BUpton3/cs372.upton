// Still working on this because I've confused myself

#include <iostream>
#include <vector>
#include <list>
using namespace std;
const int MAX = 10;



class AdjNode {
public:
	int vertex;
	AdjNode* next;
	AdjNode(int data) {
		vertex = data;
		next = NULL;
	}
};

template <class T>
class Graph {
    int vertices;
    int adjacency_matrix[MAX][MAX];

public:
    Graph(int vertices)
    {
        this->vertices = vertices;
        memset(adjacency_matrix, 0,
            sizeof(adjacency_matrix));
    }
    void insert(int source, int destination)
    {
        adjacency_matrix[destination - 1][source] = 1;
    }

    bool is_sink(int i)
    {
        for (int j = 0; j < vertices; j++) {
            if (adjacency_matrix[i][j] == 1)
                return false;
            if (adjacency_matrix[j][i] == 0 && j != i)
                return false;
        }
        return true;
    }

    int eliminate()
    {
        int i = 0, j = 0;
        while (i < vertices && j < vertices) {
            if (adjacency_matrix[i][j] == 1)
                i = i + 1;
            else
                j = j + 1;
        }

        if (i > vertices)
            return -1;
        else if (!is_sink(i))
            return -1;
        else
            return i;
    }
};
