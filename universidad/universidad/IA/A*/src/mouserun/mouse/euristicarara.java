/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mouserun.mouse;

/**
 *
 * @author nedveros
 */
//public class euristicarara {
//}
/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Random;
import java.util.Stack;
import mouserun.game.Mouse;
import mouserun.game.Cheese;
import mouserun.game.Grid;

/**
 *
 * @author mdiazm97
 */
public class euristicarara extends Mouse {

    int contador = 0;
    String numCadena;

    private ArrayList<Integer> posibles;    // Lista que almacena los posibles movimientos accesibles desde una casilla.

    private Stack<Integer> pilaMovimientos;

    private Map<Long, ArrayList<Integer>> visitados;

    private Integer ultimo;

    private boolean deshacerPila;

    private Stack<Integer> caminoAlQueso;

    private int quesoActual;

    private Map<Long, Nodo> casillasVisitadas;

    private boolean[] encontrados;

    private boolean reiniciado = false;

    public euristicarara() {
        super("euristicarara");
        this.posibles = new ArrayList<>();
        this.pilaMovimientos = new Stack<>();
        this.visitados = new HashMap<Long, ArrayList<Integer>>();
        this.ultimo = 0;
        this.deshacerPila = false;

        // Atributos para el algoritmo A*
        this.caminoAlQueso = new Stack<>();
        this.quesoActual = 0;
        this.casillasVisitadas = new HashMap<>();
        this.encontrados = new boolean[5];
        for (int i = 0; i < encontrados.length; i++) {
            encontrados[i] = false;
        }

    }

    @Override
    public int move(Grid currentGrid, Cheese[] cheese) {

        if (currentGrid.getX() == cheese[quesoActual].getX() && currentGrid.getY() == cheese[quesoActual].getY()) {
            encontrados[quesoActual] = true;
            quesoActual++;

        }

        if (!caminoAlQueso.empty()) {
            return caminoAlQueso.pop();
        }

        Nodo nodoActual = new Nodo(currentGrid);
        Long objetivo = dispersar(cheese[quesoActual].getX(), cheese[quesoActual].getY());

        if (quesoActual - 1 > 0 && !reiniciado) {
            if (caminoAlQueso.empty() == true && !visitados.containsKey(objetivo) && encontrados[quesoActual - 1] == true) {
                restart();
                System.out.println("REINICIANDO");
                reiniciado = true;
            }
        }

        Nodo nodoObjetivo = new Nodo(cheese[quesoActual].getX(), cheese[quesoActual].getY());

        System.out.println("Objetivo: " + nodoObjetivo.getX() + " y " + nodoObjetivo.getY());

        if (caminoAlQueso.empty()) {

            if (!visitados.containsKey(objetivo)) {
                return explorar(currentGrid, cheese);
            } else {
                reiniciado = false;
                calcularCamino(nodoActual, nodoObjetivo);
            }
        }

        return 0;
    }

    @Override
    public void respawned() {
        restart();
    }

    @Override
    public void newCheese() {

    }

    private int explorar(Grid currentGrid, Cheese[] cheese) {
        todasDirecciones(currentGrid);
        Long clave = dispersar(currentGrid);
        ArrayList<Integer> grid = visitados.get(clave);
        if (deshacerPila == true && grid.size() == 0) {
            int aux = deshacer();
            return aux;
        } else if (grid != null && grid.size() != 0) {
            deshacerPila = false;
        }
        if (grid == null) { // Si la casilla no existe, se introduce en la estructura junto con las posibles rutas accesibles

            incExploredGrids(); // Incrementamos las casillas visitadas.
            int mv = tomarDecision();
            visitados.put(clave, new ArrayList<Integer>(posibles));
            casillasVisitadas.put(clave, new Nodo(currentGrid));
            if (mv == 0) {
                // Implementar código para deshacer la pila.
                deshacerPila = true;
                return deshacer();
            }

            ultimo = opuesta(mv);
            pilaMovimientos.push(ultimo);

            return mv;

        } else {
            posibles.clear();
            posibles = new ArrayList<Integer>(grid);

            if (posibles.isEmpty()) {
                deshacerPila = true;
                return deshacer();
            }

            int mv = tomarDecision();
            if (mv == 0) {
                deshacerPila = true;
                return deshacer();
            }

            visitados.remove(clave);
            visitados.put(clave, new ArrayList<Integer>(posibles));
            ultimo = opuesta(mv);
            pilaMovimientos.push(ultimo);

            return mv;

        }
    }

    private void todasDirecciones(Grid currentGrid) {
        posibles.clear();
        if (currentGrid.canGoUp()) {
            posibles.add(Mouse.UP);
        }
        if (currentGrid.canGoDown()) {
            posibles.add(Mouse.DOWN);
        }
        if (currentGrid.canGoLeft()) {
            posibles.add(Mouse.LEFT);
        }
        if (currentGrid.canGoRight()) {
            posibles.add(Mouse.RIGHT);
        }
    }

    private Long dispersar(Grid currentGrid) {
        Long clave;

        clave = (long) currentGrid.getX() * 123 + currentGrid.getY() * 345;

        return clave;
    }

    private int tomarDecision() {
        Random random = new Random();

        posibles.remove(new Integer(ultimo));

        if (posibles.isEmpty()) {
            deshacerPila = true;
            return 0;
        } else if (posibles.size() == 1) {
            int aux = posibles.get(0);
            posibles.clear();

            return aux;
        }

        int pos = random.nextInt(posibles.size());

        Integer aux = posibles.get(pos);
        posibles.remove(new Integer(aux));

        return aux;

    }

    private int opuesta(int movimiento) {
        switch (movimiento) {
            case Mouse.UP:
                return Mouse.DOWN;
            case Mouse.DOWN:
                return Mouse.UP;
            case Mouse.LEFT:
                return Mouse.RIGHT;
            case Mouse.RIGHT:
                return Mouse.LEFT;
            default:
                return 0;
        }
    }

    private int deshacer() {
        if (pilaMovimientos.empty()) {
            deshacerPila = false;
            return 0;
        }

        int aux = pilaMovimientos.pop();

        ultimo = 0;
        return aux;
    }

    public class Nodo {

        private int x;
        private int y;

        private boolean left;
        private boolean right;
        private boolean up;
        private boolean down;

        public Nodo(int x, int y, boolean left, boolean right, boolean up, boolean down) {
            this.x = x;
            this.y = y;
            this.left = left;
            this.right = right;
            this.up = up;
            this.down = down;
        }

        public Nodo(int x, int y) {
            this.x = x;
            this.y = y;
        }

        public Nodo(Grid grid) {
            this.x = grid.getX();
            this.y = grid.getY();

            this.left = grid.canGoLeft();
            this.right = grid.canGoRight();
            this.up = grid.canGoUp();
            this.down = grid.canGoDown();
        }

        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        public boolean casillaIzquierda() {
            return left;
        }

        public boolean casillaDerecha() {
            return right;
        }

        public boolean casillaArriba() {
            return up;
        }

        public boolean casillaAbajo() {
            return down;
        }

        @Override
        public int hashCode() {
            return x * 123 + y * 345;
        }

        @Override
        public boolean equals(Object obj) {
            if (this == obj) {
                return true;
            }
            if (!(obj instanceof Nodo)) {
                return false;
            }
            Nodo node = (Nodo) obj;
            return x == node.x && y == node.y;
        }
    }

    private Long dispersar(int x, int y) {
        Long clave;

        clave = (long) x * 123 + y * 345;

        return clave;
    }

    private void calcularCamino(Nodo actual, Nodo objetivo) {
        if (actual == objetivo) {
            return;
        }

        Map<Long, Par<Nodo, Nodo>> explorados = new HashMap<>();

        aEstrella(actual, objetivo, explorados);
        Long dispersion = dispersar(objetivo.getX(), objetivo.getY());

        Par<Nodo, Nodo> par = explorados.get(dispersion);
        caminoAlQueso.push(direccion(par.second, par.first));

        explorados.remove(dispersion);

        while (par.first != actual) {
            dispersion = dispersar(par.second.getX(), par.second.getY());
            par = explorados.get(dispersion);
            int aux = direccion(par.second, par.first);
            caminoAlQueso.push(aux);
        }

    }

    private int euristica(Nodo actual, Nodo objetivo) {

        if (actual.casillaArriba()) {

            if (actual.getY() + 1 <= objetivo.getY()) {
                return (Math.abs(actual.getX() + (Math.abs(actual.getY() + 1))));
            }

        }

        if (actual.casillaAbajo()) {

            if (actual.getY() - 1 <= objetivo.getY()) {
                return (Math.abs(actual.getX() + (Math.abs(actual.getY() - 1))));
            }

        }

        if (actual.casillaDerecha()) {

            if (actual.getX() + 1 <= objetivo.getX()) {
                return (Math.abs(actual.getX() + 1 + (Math.abs(actual.getY()))));
            }

        }

        if (actual.casillaIzquierda()) {

            if (actual.getX() - 1 <= objetivo.getX()) {
                return (Math.abs(actual.getX() - 1 + (Math.abs(actual.getY()))));
            }

        }

        return (Math.abs(actual.getX() + (Math.abs(actual.getY() + 1))));

        // return (Math.abs(actual.getX() - objetivo.getX())) + (Math.abs(actual.getY() - objetivo.getY()));
    }

//    
//     private int euristica(Nodo actual, Nodo objetivo) {
//        
//        
//        if (actual.casillaArriba()){
//        
//        if (actual.getY()+1 <= objetivo.getY())
//            
//               numCadena = "Arriba";
//            int numEntero = Integer.parseInt(numCadena);
//            numEntero= numEntero + contador;
//            contador++;
//            return (numEntero);
//            
//        }
//        
//              if (actual.casillaAbajo()){
//           numCadena = "Abajo";
//            int numEntero = Integer.parseInt(numCadena);
//            numEntero= numEntero + contador;
//            contador++;
//            return (numEntero);
//        }
//        
//        
//            if (actual.casillaDerecha()){
//        
//        if (actual.getX()+1 <= objetivo.getX())
//            
//             numCadena = "Derecha";
//            int numEntero = Integer.parseInt(numCadena);
//            numEntero= numEntero + contador;
//            contador++;
//            return (numEntero);
//            
//            
//        }
//            
//            
//         if (actual.casillaIzquierda()){
//        numCadena = "Izquierda";
//        int numEntero = Integer.parseInt(numCadena);
//            numEntero= numEntero + contador;
//            contador++;
//            return (numEntero);
//            
//        }
//        
//            
//            
//            
//            
//            
//            return contador+contador+2;
//            
//        
//       // return (Math.abs(actual.getX() - objetivo.getX())) + (Math.abs(actual.getY() - objetivo.getY()));
//    }
//    
//    
//    
//    
//    
//    
//    
//    
//    
//    
//    
//    
//    
//    
//    
//    
//    
//    
    private void aEstrella(Nodo actual, Nodo objetivo, Map<Long, Par<Nodo, Nodo>> mapa) {
        ArrayList<Par<Integer, Nodo>> abiertos = new ArrayList<>();
        Map<Long, Par<Integer, Nodo>> cerrados = new HashMap<>();
        Long dispersion;

        Par<Integer, Nodo> par = new Par(0, actual);
        abiertos.add(par);

        while (!abiertos.isEmpty()) {
            int distMin = 10000;

            int i = 0; // Para recorrer la lista.
            int cont = 0; // Para contener al nodo más prometedor de la lista.

            while (i < abiertos.size()) {
                Par<Integer, Nodo> parC = abiertos.get(i);
                if (parC.second == objetivo) {
                    cont = i;
                    break;
                }

                int coste = parC.first + euristica(parC.second, objetivo);
                if (coste < distMin) {
                    distMin = coste;
                    cont = i;
                }
                i++;
            }

            Par<Integer, Nodo> tmp = abiertos.get(cont);
            abiertos.remove(tmp);
            cerrados.put(dispersar(tmp.second.getX(), tmp.second.getY()), tmp);
            int nivel = 1 + tmp.first;

            if (tmp.second.casillaIzquierda()) {
                dispersion = dispersar(tmp.second.getX() - 1, tmp.second.getY());

                if (visitados.containsKey(dispersion)) { // Si la casilla ha sido visitada
                    Nodo nodoActual = casillasVisitadas.get(dispersion); // Se obtiene la casilla
                    Par<Integer, Nodo> insert = new Par<>(nivel, nodoActual);
                    if (!cerrados.containsKey(dispersion)) { // Si la e.d. de cerrados no la tiene: 
                        abiertos.add(insert); // Se inserta en la lista de abiertos y en la estructura de explorados.
                        mapa.put(dispersion, new Par(nodoActual, tmp.second));
                    }
                }
            }

            if (tmp.second.casillaDerecha()) {
                dispersion = dispersar(tmp.second.getX() + 1, tmp.second.getY());

                if (visitados.containsKey(dispersion)) { // Si la casilla ha sido visitada
                    Nodo nodoActual = casillasVisitadas.get(dispersion); // Se obtiene la casilla
                    Par<Integer, Nodo> insert = new Par<>(nivel, nodoActual);
                    if (!cerrados.containsKey(dispersion)) { // Si la e.d. de cerrados no la tiene: 
                        abiertos.add(insert); // Se inserta en la lista de abiertos y en la estructura de explorados.
                        mapa.put(dispersion, new Par(nodoActual, tmp.second));
                    }
                }
            }

            if (tmp.second.casillaArriba()) {
                dispersion = dispersar(tmp.second.getX(), tmp.second.getY() + 1);

                if (visitados.containsKey(dispersion)) { // Si la casilla ha sido visitada
                    Nodo nodoActual = casillasVisitadas.get(dispersion); // Se obtiene la casilla
                    Par<Integer, Nodo> insert = new Par<>(nivel, nodoActual);
                    if (!cerrados.containsKey(dispersion)) { // Si la e.d. de cerrados no la tiene: 
                        abiertos.add(insert); // Se inserta en la lista de abiertos y en la estructura de explorados.
                        mapa.put(dispersion, new Par(nodoActual, tmp.second));
                    }
                }
            }

            if (tmp.second.casillaAbajo()) {
                dispersion = dispersar(tmp.second.getX(), tmp.second.getY() - 1);

                if (visitados.containsKey(dispersion)) { // Si la casilla ha sido visitada
                    Nodo nodoActual = casillasVisitadas.get(dispersion); // Se obtiene la casilla
                    Par<Integer, Nodo> insert = new Par<>(nivel, nodoActual);
                    if (!cerrados.containsKey(dispersion)) { // Si la e.d. de cerrados no la tiene: 
                        abiertos.add(insert); // Se inserta en la lista de abiertos y en la estructura de explorados.
                        mapa.put(dispersion, new Par(nodoActual, tmp.second));
                    }
                }
            }
        }

    }

    public class Par<A, B> {

        public A first;
        public B second;

        public Par(A first, B second) {
            this.first = first;
            this.second = second;
        }
    }

//    private int direccion(Nodo actual, Nodo destino) {
//        if (actual == new Nodo(destino.getX() - 1, destino.getY())) { // Está a la izquierda 
//            return Mouse.RIGHT;
//        }
//        if (actual == new Nodo(destino.getX() + 1, destino.getY())) { // Está a la derecha
//            return Mouse.LEFT;
//        }
//        if (actual == new Nodo(destino.getX(), destino.getY() + 1)) { // Está arriba
//            return Mouse.DOWN;
//        }
//        if (actual == new Nodo(destino.getX(), destino.getY() - 1)) { // Está debajo
//            return Mouse.UP;
//        }
//        return 0;
//    }
    private int direccion(Nodo actual, Nodo destino) {
        if (actual.getX() == destino.getX() - 1) { // Está a la izquierda 
            return Mouse.RIGHT;
        }
        if (actual.getX() == destino.getX() + 1) { // Está a la derecha
            return Mouse.LEFT;
        }
        if (actual.getY() == destino.getY() + 1) { // Está arriba
            return Mouse.DOWN;
        }
        if (actual.getY() == destino.getY() - 1) { // Está abajo
            return Mouse.UP;
        }
        return 0;
    }

    public void restart() {
        this.posibles.clear();
        this.pilaMovimientos.clear();
        this.visitados.clear();
        this.ultimo = 0;
        this.deshacerPila = false;

        // Atributos para el algoritmo A*
        this.caminoAlQueso.clear();
        this.casillasVisitadas.clear();

    }
}
