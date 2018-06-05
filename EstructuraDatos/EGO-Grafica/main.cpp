#include <iostream>
#include <cstdlib>
#include "Graph.h"

using namespace std;

int main () {
    Graph grafica;


    grafica.addVertex ("a");


    grafica.addVertex ("b");

    grafica.addVertex ("c");

    grafica.addVertex ("d");

    grafica.addEdge ("a","b");

    grafica.addEdge ("b","c");

    grafica.addEdge ("c","d");

    grafica.addEdge ("d","a");

    grafica.Fluery ();
    return 0;

}
