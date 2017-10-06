#include <iostream>
#include <sstream>
#include "Complejo.h"
using namespace std;


string Complejo::imprimir(){

    stringstream sss ;
    sss <<  real << " + " << imag<<"i" ;;
    return sss.str();
}
