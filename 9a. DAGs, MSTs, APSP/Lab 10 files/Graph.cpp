#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <unordered_map>
#include "Graph.h"
#include "Vertex.h"

using namespace std;

Graph::Graph(){}

Graph::~Graph(){}

Graph::Graph(ifstream &inFS)
{
    int N, M, i, j, k, cost = 0;
    string currLabel;
    pair<int, int> currPair;

    inFS >> N;
    inFS >> M;

    for (i = 0; i < N; ++i){
        inFS >> currLabel;
        vertices.push_back(Vertex());
        vertices.at(i).label = currLabel;

    }
    
    for (i = 0; i < M; ++i)
    {
        inFS >> currLabel;
        for (j = 0; j < N; ++j)
        {
            if (vertices.at(j).label == currLabel)
            {
                break;
            }
        }
        
        inFS >> currLabel;
        for (k = 0; k < N; ++k)
        {
            if (vertices.at(k).label == currLabel)
            {
                break;
            }
        }
        
        inFS >> cost;

        currPair = pair<int, int>(k, cost);
        vertices.at(j).neighbors.push_back(currPair);

    }
}

void Graph::bfs()
{
    queue<Vertex> vts;
    Vertex u, v;
    list<pair<int, int>>::iterator itr;

    for(unsigned i = 0; i < vertices.size(); ++i)
    {
        vertices.at(i).color = "WHITE";
        vertices.at(i).distance = INT_MAX;
        vertices.at(i).prev = 0;
    }

    vertices.at(0).color = "GRAY";
    vertices.at(0).distance = 0;
    vertices.at(0).prev = 0;

    vts.push(vertices.at(0)); //vertices.at(0) = Q,s, Q = queue s = ??

    while (vts.empty() != true)
    {
        u = vts.front(); // dequeue Q
        vts.pop(); 

        itr = u.neighbors.begin(); //each adjacent v
        while (itr != u.neighbors.end()){ //itr = v
            if(vertices.at(itr->first).color == "WHITE")
            {                                               //color[v] = WHITE then
                vertices.at(itr->first).color = "GRAY";    //color[v] = GRAY, discovered
                vertices.at(itr->first).distance = u.distance + itr->second; //d[v] = d[u] + 1
                vertices.at(itr->first).prev = &u; //p[v] = u
                vts.push(vertices.at(itr->first)); //enqueue Q,
            }
            itr++;
        }

        u.color = "BLACK";
    }
}


void Graph::output_graph(const string &outputFilename)
{
 ofstream outFS(outputFilename.c_str());
    if(!outFS.is_open())
    {
        cout<<"Error"<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,0);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());   
}

void Graph::visualizeTree(ofstream & outFS, int n)
{
    
    if(vertices[n].color == "BLACK")
        return;
    vertices[n].color = "BLACK";
    outFS << vertices[n].label << "[label=\"" << vertices[n].label << ", " << vertices[n].distance << "\"];" << endl; 
    for(list<pair<int,int>>::const_iterator it = vertices[n].neighbors.begin(); it != vertices[n].neighbors.end(); it++)
    {
        outFS<< vertices[n].label <<" -> " << vertices[(*it).first].label <<";"<<endl;
        visualizeTree(outFS,(*it).first);
    }
}