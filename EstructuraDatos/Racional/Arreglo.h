//
// Created by Eduardo Gonzalez Olea on 3/2/18.
//

#ifndef RACIONAL_ARREGLO_H
#define RACIONAL_ARREGLO_H

#include "Racional.h"

template  <typename tipo>
    /**
     * \brief Plantilla de clase que genera un objeto tipo Arreglo.
     *
     */
class Arreglo;
template <typename tipo>
std::ostream & operator<< (std::ostream & o, const Arreglo <tipo> &v);

template <typename tipo>
std::istream & operator>> (std::istream & o,  Arreglo <tipo> &v);

template <typename tipo>
class Arreglo {

    /** \brief  sobrecarga de operador << para imprimir un objeto tipo Arreglo
     *
     * \param ostream o donde se almacenara la cadena
     * \param Arreglo v arreglo a imprimir
     * \return devuelve una variable de tipo ostream
     *
     */
    friend std::ostream & operator<< <>(std::ostream & o, const Arreglo <tipo> &v);
    /** \brief  sobrecarga de operador >> para capturar una objeto tipo Arreglo
    *
    * \param istream entrada en la cual se almacena las entradas de la matriz
    * \param Areglo v Arreglo a capturar
    * \return devuelve una variable de tipo istream
    *
    */

    friend std::istream & operator>> <>(std::istream & o, Arreglo <tipo> &v);

public:
    /**
    * \brief constructor  de la clase Arreglo al cual le mandas la dimensi&oacute;n del arreglo, pero por default es 10.
    *
    */
    Arreglo(int _dim =10):dim (_dim),entrada(CreaArreglo())
    {

    }
    /**
    * \brief Destructor de la clase Arreglo
    */
    ~Arreglo();

    /**
    * \brief Constructor de copias de la clase Arreglo
    * \param const Arreglo &p una referencia constante de tipo Arreglo la cual se copiara
    */
    Arreglo(const Arreglo &p);
    /**
    * \brief Sobrecarga del operador [] para accesar a un elemento en particular del Arreglo.
    * \param int indice El indice al cual se quiere acceder
    * \pre que el indice no sea negativo, ni mayor que la dimensi&oacute;n
    * \exception  Excepcion si no se cumple la precondici&oacute;n
    */
    tipo &operator[](int indice) ;
    /**
   * \brief Sobrecarga del operador [] para accesar a un elemento en particular del Arreglo(R value).
   * \param int indice El indice al cual se quiere acceder
   * \pre que el indice no sea negativo, ni mayor que la dimensi&oacute;n
   * \exception  Excepcion si no se cumple la precondici&oacute;n
   */
    const tipo &operator[](int indice) const;
    /**
      * \brief funci&oacute;n que ordena un arreglo de forma ascendente.
      */
    void OrdenarAscendente();
    /**
  * \brief funci&oacute;n que ordena un arreglo de forma descendente.
  */
    void OrdenarDescendente();

private:
    /** \brief Funci&oacute;n para crear un arreglo
     *
     * \return un arreglo de tipo tipo
     *
     */
    tipo *CreaArreglo();
    int dim;
    tipo *entrada;
    /** \brief Funci&oacute;n para liberar memoria de un arreglo
    */
    void LiberaArreglo();
    /** \brief Funci&oacute;n que devuelve la dimensi&oacute;n de un arreglo.
     * \return la dimensi&oacute;n del Arreglo
        */
    int ObtenerCapacidad();
};


template <typename tipo>
tipo* Arreglo<tipo>::CreaArreglo ()
{

    return new tipo[dim]; //bad_alloc

}

template<typename tipo>
void Arreglo<tipo>::LiberaArreglo () {
    delete [] entrada;
    entrada = NULL;
}

template<typename tipo>
const tipo &Arreglo<tipo>::operator[] (int indice) const {
    if(indice<0  ||  indice > dim )throw Excepcion("Indice fuera de rango");
    return entrada[indice];
}

template<typename tipo>
tipo &Arreglo<tipo>::operator[] (int indice) {
    if(indice<0  ||  indice > dim )throw Excepcion("Indice fuera de rango");
    return entrada[indice];
}

template<typename tipo>
Arreglo<tipo>::~Arreglo () {
    LiberaArreglo ();
}

template<typename tipo>
Arreglo<tipo>::Arreglo (const Arreglo &p) {
    if(this == &p) return *this;

    LiberaArreglo();

    dim = p.ObtenerCapacidad ();


    if(dim !=0) {


        entrada = CreaArreglo ();

        for ( int i = 0 ; i < p.ObtenerCapacidad () ; ++i ) {
            entrada[ i ] = p.entrada[ i ];
        }

    }
    return *this;
}

template<typename tipo>
int Arreglo<tipo>::ObtenerCapacidad () {
    return dim;
}


template<typename tipo>
std::istream &operator>> (std::istream &o ,  Arreglo<tipo> &v) {

    for(int i = 0 ; i < v.dim ; ++i){
        std::ostringstream mensajeCaptura;
        mensajeCaptura << "\nIngrese el componente [" << i+1 <<"]: \n";
        CapturaDato(mensajeCaptura.str().c_str(), v.entrada[i]);

    }
    return o;
}
template<typename tipo>
std::ostream &operator<< (std::ostream &o , const Arreglo<tipo> &v) {
    for(int i = 0 ; i < v.dim ; ++i){
        o << "[ " << v.entrada[i]<<" ]"<<std::endl;
    }

    return o;
}


template<typename tipo>
void Arreglo<tipo>::OrdenarAscendente () {
    tipo aux;
    for(int i = 0 ; i < dim ; i++)
        for(int j = 0 ; j < dim - 1 ; j++)
            if(entrada[j] > entrada[j+1]){
                aux = entrada[j];
                entrada[j] = entrada[j+1];
                entrada[j+1] = aux;
            }
}

template<typename tipo>
void Arreglo<tipo>::OrdenarDescendente () {
    tipo aux;
    for(int i = 0 ; i < dim ; i++)
        for(int j = 0 ; j < dim - 1 ; j++)
            if(entrada[j] < entrada[j+1]){
                aux = entrada[j];
                entrada[j] = entrada[j+1];
                entrada[j+1] = aux;
            }
}

#endif //RACIONAL_ARREGLO_H
