/*
*Rodrigo Muñoz Guerrero
*A00572858
*29/11/2020
*/

//Librerias que se utilizarán en el main
#include <bits/stdc++.h>
#include <iostream>
#include <queue>
#include <tuple>
#include <unordered_map>
#include <fstream>
#include <string>
#include <sstream>
//Archivos tipo header que se utilizaran en el main
#include "program.h"
#include "hash.h"

using namespace std;

/*
*Función que coloca en las listas de llaves y valores del Hash los valores
*que se le dan en el main.
*O(n) porque hace lo mismo para el número de elementos totales de los vectores.
*/
void createh(vector<int> vectork, vector<string> vectorv, int size, Hash<int, string> &hash){
    for (int m = 0; m<size ; m++){
        hash.put(vectork[m], vectorv[m]);
    }
}

//Esta función imprime los países opciones para las consultas
//O(n) ya que va aumentando la variable i conforme se imprimen los países
void printcountries(){
    int i = 0;
    cout << i++ << "   THAILAND\n" << i++ << "   MEXICO\n" << i++ << "   USA\n" << i++ << "   BRAZIL\n" << i++ <<
    "   ENGLAND\n" << i++ << "   GERMANY\n" << i++ << "   SOUTH AFRICA\n" << i++ << "   INDIA\n" <<
    i++ << "   RUSSIA\n" << i++ << "   TAIWAN\n" << i++ << "  CASOS PRUEBA\n";
}

int main()
{
    //Se crea un objeto de tipo Query para hacer las búsquedas
    Query query1;

    int respuesta = 1, q = 1;

    //Se inicializa el tamaño de los vectores para el Hash
    int sze = 10;

    //Se inicializa la matriz donde se tendran los grafos
    int flights[30][4];

    //Se define el nombre del archivo de donde se sacaran
    //los nodos y aristas de los grafos
    string archivo = "archivo.txt", line;

    //Se lee el archivo de texto
    ifstream lee(archivo);
    if (lee.is_open()){
        unsigned j = 0;
        while (getline(lee,line)){
            stringstream aux;
            aux << line;
            string source, destination, cost, duration;
            aux >> source >> destination >> cost >> duration;
            int a = stoi(source);
            int b = stoi(destination);
            int c = stoi(cost);
            int d = stoi(duration);
            flights[j][0] = a;
            flights[j][1] = b;
            flights[j][2] = c;
            flights[j][3] = d;
            j++;
            }
        lee.close();
    }

    //Se crean dos objetos de tipo Hash, uno para los grafos y otro para pruebas
    Hash<int, string> hash(sze, -1);
    Hash<int, string> pruebas(5, -1);

    //Se crean los vectores de llaves y valores para el Hash
    vector<string> Values;
    vector<int> Keys;

    //Se les da valores a los vectores de llaves y valores
    for (int n = 0; n<10 ; n++){
        Keys.push_back(n);
    }
    Values.push_back("THAILAND");
    Values.push_back("MEXICO");
    Values.push_back("USA");
    Values.push_back("BRAZIL");
    Values.push_back("ENGLAND");
    Values.push_back("GERMANY");
    Values.push_back("SOUTH AFRICA");
    Values.push_back("INDIA");
    Values.push_back("RUSSIA");
    Values.push_back("TAIWAN");

    //Se crea el Hash
    createh(Keys, Values, sze, hash);

    //Se inicializan las variables del origen y destino
    int sourceCity, destCity;

    ofstream fileout("Queries.txt");

    //Se crea un ciclo mientras para poder hacer múltiples consultas
    while (respuesta==1){
        printcountries();
        cout << "FROM WHERE TO WHERE WOULD YOU LIKE TO MAKE A QUERY OF?\n(TYPE THE NUMBER CODE FOR EACH COUNTRY)\nSOURCE: ";
        cin >> sourceCity;
        if (sourceCity==10){
            string prueba1 = "IIPA", prueba2 = "HEFEWEIZEN", prueba3 = "MILK STOUT";
            pruebas.put(0,"IIPA");
            pruebas.put(1,"DIPA");
            pruebas.put(2,"HEFEWEIZEN");
            pruebas.put(3,"MILK STOUT");
            pruebas.put(4,"BOCK");

            cout << "test 1 " << ((!prueba1.compare(pruebas.get(0).c_str())) ? "success\n" : "fail\n");
            cout << "test 2 " << ((!prueba2.compare(pruebas.get(2).c_str())) ? "success\n" : "fail\n");
            cout << "test 3 " << ((!prueba3.compare(pruebas.get(3).c_str())) ? "success\n" : "fail\n");
            respuesta = 2;
            continue;
        }
        cout << "DESTINATION: ";
        cin >> destCity;
        if (fileout.is_open()){
        stringstream countries;
        countries << "FROM: " << hash.get(sourceCity) << "\nTO: " << hash.get(destCity) << endl;
        string countr = countries.str();
        cout << countr << endl;
        fileout << "Query " << q << "\n" << countr;
        q++;
        string cheapest = query1.findCheapestPrice(flights, sourceCity, destCity);
        string quickest = query1.findQuickestPath(flights, sourceCity, destCity);
        cout << cheapest << "\n" << quickest << endl;
        fileout << cheapest << quickest << endl;
        }
        cout << "WOULD YOU LIKE TO DO ANOTHER QUERY?\n 1)YES 2)NO" << endl;
        cin >> respuesta;
        if (respuesta==1)
            continue;
        else
            break;
    }
    fileout.close();
    hash.clear();
    pruebas.clear();
    return 0;
}
