#include <string>
using namespace std;

class Complejo{

public:
  float real;
  float imag;

  Complejo();
  Complejo(float);
  Complejo(float,float);

  string imprimir();
  
  Complejo operator+ (Complejo);
  Complejo operator- (Complejo);
  Complejo operator- ();
  //Para ++a;
  Complejo operator++ ();
  //Para a++;
  Complejo operator++ (int);

};
