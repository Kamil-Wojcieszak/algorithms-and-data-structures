#include <iostream>
#include "Graph/Graph.h"
#include "Prim/Prim.h"
#include "Kruskal/Kruskal.h"
#include "Djikstra/Dijkstra.h"
#include "Ford-Bellman/BellmanFord.h"
#include "Ford-Fulkerson/FordFulkerson.h"
#include "Tests/Tests.h"

Graph graph;


void displayMenu(string info) {
}

void menu() {
	char opt;
	int startingVertex,endVertex;
	string fileName;
	do {
		cout << endl;
		cout << "Minimum Spanning Tree;" << endl;
		cout << "1.Wczytaj menu z pliku " << endl;
		cout << "2.Wczytaj sp z pliku " << endl;
		cout << "3.Wygeneruj graf losowo" << endl;
		cout << "4.Wyswietl" << endl;
		cout << "5.Algorytm Prima" << endl;
		cout << "6.Algorytm Kruskala" << endl;
		cout << "7.Algorytm Dijkstry" << endl;
		cout << "8. Algorytm Bellmana Forda" << endl;
		cout << "9. Algorytm Forda Fulkersona" << endl;
		cout << "10. Wczytyaj flow" << endl;
		cout << "0.Powrot do menu" << endl;
		cout << "Podaj opcje:";
		cin >> opt;
		switch (opt) {
			case '1': {
				cout << " Podaj nazwe zbioru:";
				cin >> fileName;
				graph.loadFromFileMst(fileName);
				graph.print();
				break;
			}
			case '2': {
				cout << " Podaj nazwe zbioru:";
				cin >> fileName;
				startingVertex = graph.loadFromSP(fileName);
				graph.print();
				break;
			}
			case '3': {
				int vertices;
				int edgesDensity;
				cout << " Podaj ilosc wezlow ";
				cin >> vertices;
				cout << " Podaj gestosc wypelnienia (liczba calkowita) ";
				cin >> edgesDensity;
				graph.generateUndirectedGraph(vertices, edgesDensity);
				break;
			}

			case '4': {
				graph.print();
				break;
			}
			case '5': {
				Prim prim(graph);
				cout << "Prim lista" << endl;
				prim.primAdjacencyList();
				cout << "Prim macierz" << endl;
				prim.primAdjacencyMatrix();
				break;
			}
			case '6': {
				Kruskal kruskal(graph);
				cout << "Kruskal lista" << endl;
				kruskal.kruskalAdjacencyList();
				cout << "Kruskal macierz" << endl;
				kruskal.kruskalAdjacencyMatrix();
				break;
			}
			case '7': {
				Dijkstra dijkstra(graph);
				cout << "Dijkstra lista" << endl;
				dijkstra.dijkstraAdjacencyList(startingVertex);
				cout << "Dijkstra macierz" << endl;
				dijkstra.dijkstraAdjacencyMatrix(startingVertex);
				break;
			}
			case '8': {
				BellmanFord bellmanFord(graph);
				cout << "BellmanFord lista" << endl;
				bellmanFord.bellmanFordAdjacencyList(startingVertex);
				cout << "BellmanFord macierz" << endl;
				bellmanFord.bellmanFordAdjacencyMatrix(startingVertex);
				break;
			}
			case '9': {
				FordFulkerson fordFulkerson(graph);
				cout << "FordFulkerson BFS" << endl;
				fordFulkerson.fordFulkersonBFSAdjacencyMatrix(startingVertex,endVertex);
				cout << "FordFulkerson DFS" << endl;
				fordFulkerson.fordFulkersonDFSAdjacencyMatrix(startingVertex,endVertex);
				break;
			}
			case '10': {
				cout << " Podaj nazwe zbioru:";
				cin >> fileName;
				int *SandT;
				SandT = graph.loadFromFloat(fileName);
				startingVertex = SandT[0];
				endVertex = SandT[1];
				graph.print();
				break;
			}
		}
	} while (opt != 0);
}

int main() {
	menu();


}


