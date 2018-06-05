//
// Created by Eduardo Gonzalez Olea on 5/22/18.
//

#include "Graph.h"
#include "Pila.h"
#include "Cola.h"
using namespace std;

void Graph::addVertex(std::string label) {
    Vertex vertex;
    vertex.label = label;
    vertices.append(vertex);
}

void Graph::addEdge(std::string v1, std::string v2) {
    int index1 = vertices.getIndexOf(v1);
    int index2 = vertices.getIndexOf(v2);

    if(index1 == -1 || index2 == -1) throw NoVertexInTheGraphException(v1 + " or " + v2);
    if(index1 == index2) throw SelfLoopException();

    Vertex & vertex1 = vertices[index1];
    Vertex & vertex2 = vertices[index2];

    if(vertex1.edges.search(&vertex2)) throw DuplicatedEdgeException();

    vertex1.edges.append(&vertex2);
    vertex2.edges.append(&vertex1);
    edges++;
}

void Graph::removeEdge(std::string v1, std::string v2) {
    int index = vertices.getIndexOf(v1);
    if(index < 0) throw NoVertexInTheGraphException(v1);
    if(vertices.getIndexOf(v2) < 0) throw NoVertexInTheGraphException(v2);

    Vertex & vertex1 = vertices[index];
    Vertex * vertex2 = NULL;
    LinkedList<Graph::Vertex*>::Iterator itr;

    int i = 0;
    for(itr = vertex1.edges.begin(); itr != vertex1.edges.end(); itr++) {
        if((*itr)->label.compare(v2) == 0) {
            vertex2 = *itr;
            break;
        }
        i++;
    }

    if(vertex2 == NULL) throw NoEdgeInTheGraphException(v1,v2);

    vertex1.edges.remove(i);
    vertex2->edges.remove(vertex2->edges.getIndexOf(&vertex1));
    edges--;
}

void Graph::removeVertex(std::string label) {
    int index = vertices.getIndexOf(label);
    if(index < 0) throw NoVertexInTheGraphException(label);

    Vertex & v = vertices[index];
    LinkedList<Vertex*>::Iterator itr;

    edges -= v.edges.getSize();

    for(itr = v.edges.begin(); itr != v.edges.end(); itr++) {
        (*itr)->edges.remove((*itr)->edges.getIndexOf(&v));
    }

    vertices.remove(index);
}

bool Graph::searchVertex(std::string label) {
    return vertices.search(label);
}

bool Graph::searchEdge(std::string v1, std::string v2) {
    int index = vertices.getIndexOf(v1);
    if(index < 0) throw NoVertexInTheGraphException(v1);
    if(vertices.getIndexOf(v2) < 0) throw NoVertexInTheGraphException(v1);

    Vertex v = vertices[index];
    LinkedList<Vertex*>::Iterator itr;

    for(itr = v.edges.begin(); itr != v.edges.end(); itr++) {
        if((*itr)->label.compare(v2) == 0) {
            return true;
        }
    }
    return false;
}

LinkedList<std::string> Graph::listOfVertices() {
    LinkedList<std::string> list;
    LinkedList<Vertex>::Iterator itr;

    for(itr = vertices.begin(); itr != vertices.end(); itr++) {
        list.append((*itr).label);
    }

    return list;
}

int Graph::numberOfVertices() {
    return vertices.getSize();
}

int Graph::numberOfEdges() {
    return edges;
}

int Graph::degree(std::string label) {
    int index = vertices.getIndexOf(label);
    if(index < 0) throw NoVertexInTheGraphException(label);

    return vertices[index].edges.getSize();
}

std::ostream & operator<<(std::ostream & out, const Graph & graph) {
    LinkedList<Graph::Vertex>::ConstIterator itr;
    LinkedList<Graph::Vertex*>::ConstIterator itr2;

    for(itr = graph.vertices.begin(); itr != graph.vertices.end(); itr++) {
        out << (*itr).label << " :  ";
        for(itr2 = (*itr).edges.begin(); itr2 != (*itr).edges.end(); itr2++) {
            out << (*itr2)->label << ", ";
        }
        out << "\b\b \n";
    }

    return out;
}

std::string Graph::Fluery () {
    class LinkedList<Graph::Vertex>::Iterator itr;

    for(itr = vertices.begin(); itr != vertices.end(); itr++) {
        if(degree((*itr).label) % 2 == 1) throw "NoEulerTrail";
    }

    Graph::Vertex * vp = &(vertices[0]);
    Graph::Vertex * vc = vp;

    Pila<std::string> pila_aristas;
    Cola<std::string> cola_aristas;

    LinkedList<Graph::Vertex*>::Iterator nextEdge;

    while(!vp->edges.empty()) {
        for(nextEdge = vp->edges.begin(); nextEdge != vp->edges.end(); nextEdge++) {
            if(degree((*nextEdge)->label) > 1) {
                pila_aristas.AgregarElemento(vp->label + " - " + (*nextEdge)->label);
                removeEdge(vp->label, (*nextEdge)->label);
                vp = *nextEdge;
                break;
            }
        }
        if(degree(vc->label) == 1) {
            cola_aristas.AgregarElemento (vc->label + " - " + vc->edges[0]->label);
            removeEdge(vp->label, vp->edges[0]->label);
            vc = vp->edges[0];
        }
    }

    std::string eulerianTrail = "";

    while(!cola_aristas.EstaVacia ()) {
        eulerianTrail += cola_aristas.EliminarElemento () + ", ";
    }

    while(!pila_aristas.EstaVacia ()) {
        eulerianTrail += pila_aristas.EliminarElemento () + ", ";
    }

    eulerianTrail = eulerianTrail.substr(0,eulerianTrail.size()-3);

    return eulerianTrail;
}

void Graph::printEulerTour()
{
    // Find a vertex with odd degree
    int u = 0;
    for (int i = 0; i < numberOfVertices (); i++)
        if (vertices.getSize() & 1)
        {   u = i; break;  }

    // Print tour starting from oddv
    printEulerUtil(to_string(u));
    cout << endl;
}

// Print Euler tour starting from vertex u
void Graph::printEulerUtil(string u)
{
    // Recur for all the vertices adjacent to this vertex
    //LinkedList<int>::iterator i;
    for (int i = 0; i < numberOfVertices (); i++)
    {

        // If edge u-v is not removed and it's a a valid next edge
        if (v != -1 && isValidNextEdge(u, v))
        {
            cout << u << "-" << v << "  ";
            removeEdge (u, v);
            printEulerUtil(v);
        }
    }
}

// The function to check if edge u-v can be considered as next edge in
// Euler Tout
bool Graph::isValidNextEdge(string u, string v)
{
    // The edge u-v is valid in one of the following two cases:

    // 1) If v is the only adjacent vertex of u
    int count = 0;  // To store count of adjacent vertices
    //list<int>::iterator i;
    for (int i = 0; i < numberOfVertices (); i++)
        if (*i != -1)
            count++;
    if (count == 1)
        return true;


    // 2) If there are multiple adjacents, then u-v is not a bridge
    // Do following steps to check if u-v is a bridge

    // 2.a) count of vertices reachable from u
    bool visited[numberOfVertices ()];
    memset(visited, false, numberOfVertices ());
    int count1 = DFSCount(u, visited);

    // 2.b) Remove edge (u, v) and after removing the edge, count
    // vertices reachable from u
    removeEdge (u, v);
    memset(visited, false, numberOfVertices ());
    int count2 = DFSCount(u, visited);

    // 2.c) Add the edge back to the graph
    addEdge(u, v);

    // 2.d) If count1 is greater, then edge (u, v) is a bridge
    return (count1 > count2)? false: true;
}
int Graph::DFSCount(int v, bool visited[])
{
    // Mark the current node as visited
    visited[v] = true;
    int count = 1;

    // Recur for all vertices adjacent to this vertex
    //list<int>::iterator i;
    for (int i = 0; i < numberOfVertices (); i++)
        if (*i != -1 && !visited[*i])
            count += DFSCount(*i, visited);

    return count;
}

Graph::Vertex::Vertex(std::string _label) {
    label = _label;
}

bool Graph::Vertex::operator==(const Vertex & v) const {
    return label.compare(v.label) == 0;
}

Graph::NoVertexInTheGraphException::NoVertexInTheGraphException(std::string label) {
    message = "There is no vertex " + label + " in this graph";
}

Graph::NoEdgeInTheGraphException::NoEdgeInTheGraphException(std::string v1, std::string v2) {
    message = "There is no edge from vertex " + v1 + " to " + v2;
}

Graph::DuplicatedEdgeException::DuplicatedEdgeException() {
    message = "Duplicated edge are disallowed";
}

Graph::SelfLoopException::SelfLoopException() {
    message = "Self-loop are disallowed";
}
