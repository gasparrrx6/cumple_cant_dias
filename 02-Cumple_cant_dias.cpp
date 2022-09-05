#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct info {
  int edades;
  int annos;
  string dias;
};

struct cantDias {
  string dia;
  int cant;
};

class diasCumple {
private:
  string nombre;
  int edadActual;
  int annoNacimiento;
  int primerDia;
  vector<info> contenido;

public:
  diasCumple(string nombre, int edadActual, int annoNacimiento, int primerDia);
  void setEdades();
  void setAnnos();
  void setDias();
  vector<info> getDatos();
  vector<cantDias> getCantDias(diasCumple persona);
};

diasCumple::diasCumple(string nombre, int edadActual, int annoNacimiento,
                       int primerDia) {
  this->nombre = nombre;
  this->edadActual = edadActual;
  this->annoNacimiento = annoNacimiento;
  this->primerDia = primerDia - 1;
  contenido.resize(edadActual + 1);
}

void diasCumple::setEdades() {
  for (int i = 0; i <= edadActual; i++) {
    contenido[i].edades = i;
  }
}
void diasCumple::setAnnos() {
  for (int i = 0; i <= edadActual; i++) {
    contenido[i].annos = i + annoNacimiento;
  }
}

vector<string> diasSemana = {"domingo", "lunes",   "martes", "miercoles",
                             "jueves",  "viernes", "sabado"};

void diasCumple::setDias() {
  int countDias = primerDia;
  int general = 0;
  for (int i = 0; i <= edadActual; i++) {
    if (contenido[i].annos % 4 == 0) {
      if (countDias == 6) {
        contenido[i].dias = diasSemana[0];
        countDias = 0;
      } else {
        countDias++;
        contenido[i].dias = diasSemana[countDias];
      }
    } else {
      contenido[i].dias = diasSemana[countDias];
    }
    countDias++;
    if (countDias > 6) {
      countDias = 0;
    }
  }
}

vector<info> diasCumple::getDatos() { return contenido; }

vector<cantDias> diasCumple::getCantDias(diasCumple persona) {
  vector<cantDias> contDias(7);
  for (int i = 0; i <= 6; i++) {
    contDias[i].cant = 0;
    contDias[i].dia = diasSemana[i];
  }

  for (int i = 1; i <= edadActual; i++) {
    for (int j = 0; j <= 6; j++) {
      if (persona.getDatos()[i].dias == contDias[j].dia) {
        contDias[j].cant++;
      }
    }
  }

  return contDias;
}

int main() {
  string nombre;
  int edadActual;
  int annoNacimiento;
  int primerDia;
  cout << "Ingrese nombre\n";
  cin >> nombre;
  cout << "Ingrese edad\n";
  cin >> edadActual;
  cout << "Ingrese anno de nacimiento\n";
  cin >> annoNacimiento;
  cout << "Ingrese dia de la semana que nacio en nro (empezando del dom que "
          "es 1)\n";
  cin >> primerDia;
  diasCumple persona(nombre, edadActual, annoNacimiento, primerDia);

  persona.setEdades();
  persona.setAnnos();
  persona.setDias();

  cout << endl;

  for (int i = 0; i <= edadActual; i++) {
    if (persona.getDatos()[i].edades == 0) {
      cout << nombre << " nacio un " << persona.getDatos()[i].dias << " en el "
           << persona.getDatos()[i].annos << endl;
    } else {
      cout << nombre << " cumplio " << persona.getDatos()[i].edades
           << " el dia " << persona.getDatos()[i].dias << " en el "
           << persona.getDatos()[i].annos << endl;
    }
  }

  cout << endl;

  for (int i = 0; i <= 6; i++) {
    cout << nombre << " cumplio " << persona.getCantDias(persona)[i].cant
         << " veces el dia " << persona.getCantDias(persona)[i].dia << endl;
  }
}
