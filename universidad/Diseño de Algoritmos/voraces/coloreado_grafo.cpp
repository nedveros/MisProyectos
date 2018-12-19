#include <iostream>
#define n 5

using namespace std;

void ColorearGrafo(int aristas[][n+1], int Nvertices){
int i,j; // i recorre los vertices del grafo, j los vertices del 1 al i *)
int color; // recorre los colores del 1 al n
bool VerticeMarcado; // sirve para marcar el vertice i como coloreado
int Colores[n+1]={0,0,0,0,0,0}; // almacena la solucion del problema

for (i=1; i<=Nvertices; i++){
        //por cada nuevo vertice comenzamos inicializando el color
    color=0;
    do{
        VerticeMarcado=true;
        color++;
        for (j=1; j<i; j++){
                //si estan adyacentes y el color ya fue usado lo desmarcamos
                //para que pruebe con el siguiente color
            //cout << i << "," << j << ": " << color << endl;
            if (aristas[i][j]== 1 && Colores[j]==color){
                VerticeMarcado=false;
            }
        }
    }while (!VerticeMarcado);  //!=true
    Colores[i]=color;
}
for (int i=1; i<=Nvertices; i++){
        cout << "Nodo: " << i << " Color: " << Colores[i] << endl;
}
}

int main()
{
    int Nvertices=n;
  /*  int aristas[n+1][n+1]= {{-1,-1,-1,-1,-1,-1},
                     {-1, 0, 1, 1, 1, 0},
                     {-1, 1, 0, 1, 0, 1},
                     {-1, 1, 1, 0, 1, 1},
                     {-1, 1, 0, 1, 0, 1},
                     {-1, 0, 1, 1, 1, 0}
                    };
*/

  int aristas[n+1][n+1]= {{-1,-1,-1,-1,-1,-1},
                          {-1, 0, 1, 1, 1, 0},
                          {-1, 1, 0, 1, 1, 0},
                          {-1, 0, 1, 0, 1, 0},
                          {-1, 1, 1, 1, 0, 1},
                          {-1, 1, 1, 1, 1, 0}
                    };

    ColorearGrafo(aristas, Nvertices);

    return 0;
}
