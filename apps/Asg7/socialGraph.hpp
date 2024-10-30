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
class socialGraph {
private:
	int v;
	AdjNode** graph;
public:
	socialGraph() {}
	socialGraph(int verticies) {
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
		for (int i = 1; i < v; ++i) {
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
