/*
 * polinomios.cpp
 *
 */

#include <iostream>
#include <string>
#include <stdio.h>
#include "Timer.h"
#include <vector>

using namespace std;

typedef vector<int> polinomio;

using namespace std;

/**
 * @brief operaciones de apoyo al código posterior...
 */

int max(int x, int y){
	return x>y?x:y;
}

int min(int x, int y){
	return x<y?x:y;
}

/**
 * @brief Muestra un polinomio por pantalla...
 */
void muestra(const polinomio& p){
	if(p.size()>0){
		for(int i=p.size()-1; i>0; i--)
			cout<<p[i]<<"x"<<i<<" ";
		cout<<p[0];
	}
	cout<< endl;
}

/**
 * @brief Función SumaPolinomios que suma dos polinomios...
 */
polinomio sp(const polinomio& p1, const polinomio& p2){

	int n=min(p1.size(), p2.size());
	int i;
	polinomio resul;
	/**<Acumulamos el resultado de la suma de cada uno en resul*/
	for(i=0;i<n;i++){
		resul.push_back(p1[i] + p2[i]);
	}
	/**Si los grados no son iguales, acumulamos en resul el valor de los coeficientes no comprobados del mayor...*/
	if(p1.size()>p2.size()){
		resul.insert(resul.end(), p1.begin()+n, p1.end());
	} else if(p1.size()<p2.size()){
		resul.insert(resul.end(), p2.begin()+n, p2.end());
	}

	return resul;
}

/**
 * @brief Funcion RestaPolinomios que resta dos polinomios...
 */
polinomio rp(const polinomio& p1,const polinomio& p2){

	unsigned int n=min(p1.size(), p2.size()); /**<Obtenemos el menor grado de los polinomios...*/
	unsigned int i;
	polinomio resul;

	for(i=0;i<n;i++){	/**<Y acumulamos el resultado de la resta de cada uno en resul*/
		resul.push_back(p1[i] - p2[i]);
	}

	/**Si los grados no son iguales, acumulamos en resul el valor de los coeficientes no comprobados del mayor...*/
	if(p1.size()>p2.size()){
		resul.insert(resul.end(), p1.begin()+n, p1.end());
	} else if(p1.size()<p2.size()){
		resul.insert(resul.end(), p2.begin()+n, p2.end());
		for(i=n; i<resul.size(); i++)	/**<Si el sustraendo es el de mayor grado, cambiamos de signo los coeficientes...*/
			resul[i]=-resul[i];
	}

	return resul;
}

/**
 * @brief Multiplicación Clásica de dos polinomios cualquiera.
 */
polinomio multPoliClasico(const polinomio& p1, const polinomio& p2){
	polinomio res;
	int n=p1.size(), m=p2.size();
	res.resize(n+m-1, 0);

	for (int i=0;i<n;i++){
		for (int j=0;j<m;j++){
			res[i+j]+=(p1[i]*p2[j]);
		}
	}
	return res;
}

/**
 * @brief Multiplicación de dos polinomios de igual grado basado en Divide y Vencerás.
 */
polinomio multPoli(const polinomio& p1, const polinomio& p2){
	int n=max(p1.size(), p2.size());
	polinomio aux, auxx;
	if(n<=2){		/**<Si el polinomio es lo suficientemente pequeño, llamamos al algoritmo clásico...*/
		return multPoliClasico(p1,p2);
	}
	else{ 			/**<Si no, aplicamos divide y vencerás.*/
		/**Partimos cada polinomio en dos más pequeños*/
		int s=(n/2);
		polinomio x;
		x.insert(x.end(),p1.begin(), p1.begin()+s);
		polinomio w;
		w.insert(w.end(),p1.begin()+s, p1.end());
		polinomio z;
		z.insert(z.end(),p2.begin(), p2.begin()+s);
		polinomio y;
		y.insert(y.end(),p2.begin()+s, p2.end());

		aux.clear();aux=sp(w,x);
		auxx.clear();auxx=sp(y,z);
		/**Creamos polinomios auxiliares para reducir las llamadas al algoritmo clásico
		(wz+xy)=(w+x)(y+z)-wy-xz*/
		polinomio r(multPoli(aux, auxx)),
				  p(multPoli(w,y)),
				  q(multPoli(x,z));
		polinomio o;

		aux.clear();aux=rp(r,p);
		o=rp(aux,q);

		/**Agrupamos de nuevo los polinomios en uno solo
		cuadrando las posiciones donde debe quedar cada coeficiente
		insertando ceros por la izda a los polinomios intermedios obtenidos
		p1*p2= 102s(wy) + 10s(wz+xy) + xz
		          (p)   +    (o)     + (q)   */

		for(int i=0; i<2*s; i++){
			p.insert(p.begin(),0); //insertamos 2s posiciones iniciales con 0
			if(i%2==0)
				o.insert(o.begin(),0); //insertamos s posiciones iniciales con 0
		}

		aux.clear();aux=sp(o,q);
		auxx.clear();auxx=sp(p,aux);
		return auxx;
	}

}



int main(){
    Timer t;
	polinomio x,y;
	x.push_back(-5);
	x.push_back(-7);
	x.push_back(3);
	x.push_back(2);
	x.push_back(-5);
	x.push_back(-7);
	//x.push_back(3);

	y.push_back(6);
	y.push_back(1);
	y.push_back(-8);
	y.push_back(3);
	y.push_back(6);
	y.push_back(1);
    y.push_back(-8);

	polinomio d, clas;

    t.start();
	d= multPoli(y,x);
    t.stop();
    cout << "El tiempo de ejecucion es de " ;
    cout  << t.getElapsedTimeInMilliSec() << " ms" << endl;
 	cout<<"Algoritmo DyV:  \n";muestra(d);

	t.start();
	clas=multPoliClasico(y,x);
    t.stop();
	cout << "El tiempo de ejecucion es de " ;
    cout  << t.getElapsedTimeInMilliSec() << " ms" << endl;
	cout<<"Algoritmo Clas:  \n";muestra(clas);


}



