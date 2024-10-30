#include <iostream>
#include <vector>
#include <list>
using namespace std;




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
class AdjMatGraph {
	int n;
	int g[10][10];
public:
	AdjMatGraph() {

	}
	AdjMatGraph(int x)
	{
		n = x;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				g[i][j] = 0;
			}
		}
	}
	void displayAdjacencyMatrix()
	{
		for (int i = 0; i < n; ++i) {
			cout << "\n";
			for (int j = 0; j < n; ++j) {
				cout << " " << g[i][j];
			}
		}
	}
	void addEdge(T x, T y)
	{
		if ((x >= n) || (y > n)) {
			cout << "Vertex does not exists!";
		}
		if (x == y) {
			cout << "Same Vertex!";
		}
		else {
			g[y][x] = 1;
			g[x][y] = 1;
		}
	}
	void delEdge(int x, int y)
	{
		if ((x < 0) || (x >= n)) {
			cout << "Vertex" << x
				<< " does not exist!";
		}
		if ((y < 0) || (y >= n)) {
			cout << "Vertex" << y
				<< " does not exist!";
		}
		if (x == y) {
			cout << "Same Vertex!";
		}
		else {
			g[y][x] = 0;
			g[x][y] = 0;
		}
	}
	void addVertex()
	{
		n++;
		int i;
		for (i = 0; i < n; ++i) {
			g[i][n - 1] = 0;
			g[n - 1][i] = 0;
		}
	}
	void removeVertex(int x)
	{
		if (x > n) {
			cout << "\nVertex not present!";
			return;
		}
		else {
			int i;
			while (x < n) {
				for (i = 0; i < n; ++i) {
					g[i][x] = g[i][x + 1];
				}
				for (i = 0; i < n; ++i) {
					g[x][i] = g[x + 1][i];
				}
				x++;
			}
			n--;
		}
	}
};

template <class T>
class AdjListGraph {
private:
	int v;
	AdjNode** graph;
public:
	AdjListGraph() {}
	AdjListGraph(int verticies) {
		v = verticies;
		graph = new AdjNode * [v];
		for (int i = 0; i < v; ++i)
			graph[i] = NULL;
	}
	void addEdge(int source, int destination)
	{
		AdjNode* node = new AdjNode(destination);
		node->next = graph[source];
		graph[source] = node;
	}
	void addVertex(int vk, int source, int destination)
	{
		addEdge(source, vk);
		addEdge(vk, destination);
	}
	void printGraph()
	{
		for (int i = 0; i < v; ++i) {
			cout << i << " ";
			AdjNode* temp = graph[i];
			while (temp != NULL) {
				cout << "-> " << temp->vertex << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}
	void delVertex(int k)
	{
		for (int i = 0; i < v; ++i) {
			AdjNode* temp = graph[i];
			if (i == k) {
				graph[i] = temp->next;
				temp = graph[i];
			}
			while (temp != NULL) {
				if (temp->vertex == k) {
					break;
				}
				AdjNode* prev = temp;
				temp = temp->next;
				if (temp == NULL) {
					continue;
				}
				prev->next = temp->next;
				temp = NULL;
			}
		}
	}
};
