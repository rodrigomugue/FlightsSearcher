/*
* Rodrigo Mu�oz Guerrero
* A00572858
* 29/11/2020
*/
#ifndef HASH_H_
#define HASH_H_

//Librerias que se utilizaran
#include <string>
#include <sstream>
#include <fstream>

/*
*La estructura de Hash se utiliza para poder referirse a un valor de cualquier tipo,
*teniendo una clave para mismo. Un ejemplo simple de esto puede ser un diccionario;
*Se busca una clave o en este caso palabra y se espera que tenga un significado de la
*misma, ligado espec�ficamente con esa palabra.
*/

using namespace std;

//Se crea la clase template de Hash donde se tendran las funciones
//para crear y manipular la estructura de Hash
template <class Key, class Value>
class Hash {
private:
    unsigned int num;
    unsigned int size;
    Key *keys;
    Key val0;
    Value *values;
    int indexOf(const Key) const;
public:
    Hash(unsigned int, Key);
    Value get(const Key);
    bool put(Key, Value);
    void clear();
};

/*
*Constructor de la estructura Hash
*Se inicializan las variables de tama�o, valor inicial
*y se crean los arrays de las llaves y los valores.
*O(n) porque al crear los arrays se va �ndice por �ndice
*inicianizandolos en sus valores iniciales determinados
*/
template <class Key, class Value>
Hash<Key, Value>::Hash(unsigned int sze, Key init) {
	size = sze;
	keys = new Key[size];
	val0 = init;
	for (unsigned int i = 0; i < size; i++)
		keys[i] = init;
	values = new Value[size];
	for (int i = 0; i  < sze; i++)
        values[i] = "0";
}

/*
*Funci�n que regresa el �ndice del array de llaves en el que se
*encuentra un valor ingresado
*O(1) porque se asegur� que haya el mismo n�mero de valores que de
*�ndices de los arrays
*/
template <class Key, class Value>
int Hash<Key, Value>::indexOf(const Key k) const {
	unsigned int i, start;
	start = i = k;
	do {
		if (keys[i] == k) {
			return i;
		}
		i = (i + 1) % size;
	}
	while (start != i);
	return -1;
}

/*
*Funcion que coloca en los arrays de las claves y los valores, la clave y el valor ingresados
*haciendo la uni�n de los mismos con el mismo �ndice en los dos arrays.
* Complejidad O(1) ya que son definiciones directas y no hay ciclos.
*/
template <class Key, class Value>
bool Hash<Key, Value>::put(Key k, Value v){
    if (keys[k] == val0) {
        keys[k] = k;
        values[k] = v;
        return true;
    }
}

/*
*Regresa el valor de la llave ingresada
*Compllejidad O(1) ya que es una consulta directa porque se asegur�
*que no hubieran m�s elementos que �ndices en los arrays
*/
template <class Key, class Value>
Value Hash<Key, Value>::get(const Key k) {
    int pos;
    pos = indexOf(k);
	if (pos != -1) {
		return values[k];
	}
	return 0;
}

//Funci�n que borra toda la tabla de Hash
//O(1) porque se borran los arrays directamente con una funci�n ya integrada
template <class Key, class Value>
void Hash<Key, Value>::clear() {
	delete [] keys;
	delete [] values;
}

#endif
