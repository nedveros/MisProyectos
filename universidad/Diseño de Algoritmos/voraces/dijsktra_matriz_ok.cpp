void dijkstra (int origen,int destino, int d[] ){
int marca[n], predecesores[n];
int   i, last, x;

   // inicializacion
   for (i = 1; i<vertices; i++){
      d[i] = infinito;
      marca[i] = 0;
      predecesores[i] := -1
   }

   d[origen] = 0; 		//inicializamos la distancia
   marca[origen] = 1; 		//marcas vertice origen comocomo visitado
   last = origen;
   while (!marca[destino]){	    //mientras no se haya llegado al destino
      for (i = 1; i<vertices; i++){ 	//recorremos todos los vertices
        if (!marca[i]) 			//si no ha sido marcado
          // si la d[i] mayor que el peso ponderado, fíjate que vector d[], inicialmente vale infinito
	      if (d[i] > d[last] + peso[last][i]){ 	// si la d[i] mayor que el peso ponderado, fíjate que vector d[], inicialmente vale infinito
	         d[i] = d[last] + peso[last][i]; //actualizamos vector distancias
	         predecesores[i] = last; 		//guardamos vertice visitado
	      }
      }
      x = menor_valor(marca, d); 		//vertice no marcado con menor distancia
      marca[x] = 1; 			//marcamos
      last = x; 				//actualizamos el ultimo vertice
   }
}
==========================================
int menor_valor(int marca[], int d[]){
 int  i, verticeMenor;
 float  menor;

   menor = infinito;
   for (i = 1; i<vertices; i++)
   {
      if (!marca[i])
         if (menor > d[i]){
            menor = d[i];
            verticeMenor = i;
         }
   end;
   menor_valor= verticeMenor;	//retornamos
}

