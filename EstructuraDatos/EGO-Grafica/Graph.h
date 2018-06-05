//
// Created by Eduardo Gonzalez Olea on 5/22/18.
//

#ifndef EGO_GRAFICA_GRAPH_H
#define EGO_GRAFICA_GRAPH_H


#include <iostream>
#include "LinkedList.h"

class Graph {
public:

    Graph() : edges(0) {}

    /**
     * @brief Creates and adds a node with the
     * label pass by parameter.
     * @param label the name of the node.
     */
    void addVertex(std::string label);

    /**
     * @brief Add an edge from vertex v1 to v2.
     * @param v1 vertex the edge will connect.
     * @param v2 vertex the edge will connect.
     * @thrwos NoVertexInTheGraph if there is no
     * one vertex with the label v1 or v2.
     */
    void addEdge(std::string v1, std::string v2);

    /**
     * @brief Removes a edge from this graph.
     * @param v1 the label of the vertex.
     * @param v2 the label of the vertex.
     * @thrwos NoVertexInTheGraph if there is no
     * one vertex with the label v1 or v2.
     * @throws NoEdgeInTheGraph if there is no
     * a edge that between v1 and v2.
     */
    void removeEdge(std::string v1, std::string v2);

    /**
     * @brief Removes a vertex from this graph.
     * @param label the label of the vertex to be removed.
     * @throw NoVertexInTheGraphException if there is no one
     * vertex with that label.
     */
    void removeVertex(std::string label);

    /**
    * @brief Checks if the specified vertex is in this graph.
    * @param label label of the vertex to check.
    * @retrun True if the vertex is in the graph, false otherwise.
    */
    bool searchVertex(std::string label);

    /**
    * @brief Checks if there is an edge betwen the vertex v1 and v2.
    * @param v1 label of the vertex to check.
    * @param v2 label of the vertex to check.
    * @return True if the edge is in the graph, false otherwise.
    * @throw NoVertexInTheGraph if v1 or v2 are not in the graph.
    */
    bool searchEdge(std::string v1, std::string v2);

    /**
     * @brief Return the list of vertices.
     * @return The list of verteices.
     */
    LinkedList<std::string> listOfVertices();

    /**
     * @brief Retrun the number of vertices in this graph.
     * @return The number of vertices in this graph.
     */
    int numberOfVertices();

    /**
     * @brief Return the number of edges in this graph.
     * @return The number of edges in this graph.
     */
    int numberOfEdges();

    /**
     * @brief Return the degree of the specified vertex.
     * @param label label of the vertex to get the degree;
     * @return The degree of the specified vertex;
     */
    int degree(std::string label);

    std::string Fluery();
    void printEulerTour();
    void printEulerUtil(std::string u);
    bool isValidNextEdge(std::string u, std::string v);
    int  DFSCount(int v, bool visited[]);


    /**
     * @brief Insertion operator overload.
     * @param out the ostream to insert the graph.
     * @param graph to be inserted.
     */
    friend std::ostream & operator<<(std::ostream & out, const Graph & graph);

    class NoVertexInTheGraphException : Exception {
    public:
        NoVertexInTheGraphException(std::string label);
    };

    class NoEdgeInTheGraphException : Exception {
    public:
        NoEdgeInTheGraphException(std::string v1, std::string v2);
    };

    class DuplicatedEdgeException : Exception {
    public:
        DuplicatedEdgeException();
    };

    class SelfLoopException : Exception {
    public:
        SelfLoopException();
    };

private:

    struct Vertex {

        Vertex() {};

        Vertex(std::string _label);

        bool operator==(const Vertex & v) const;

        std::string label;

        LinkedList<Vertex*> edges;
    };

    LinkedList<Vertex> vertices;
    int edges;
};

#endif //EGO_GRAFICA_GRAPH_H
