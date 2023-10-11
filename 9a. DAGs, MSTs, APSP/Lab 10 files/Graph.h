#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <list>
#include <queue>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <climits>
#include <unordered_map>

#include "Vertex.h"

using namespace std;

class Graph {
private:
  vector<Vertex> vertices;
  unordered_map<string,int> map;
public:
  Graph();
  Graph(ifstream&);
  ~Graph();
  void output_graph(const string &);
  void visualizeTree(ofstream & outFS, int n);
  void bfs();
};

#endif /* GRAPH_H_ */