/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package mouserun.mouse;

import mouserun.game.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Stack;
import java.util.Random;

/**
 *
 * @author migueldiazmedina
 */
public class Raton extends Mouse {

    private ArrayList<Integer> posibles;    // Lista que almacena los posibles movimientos accesibles desde una casilla.

    private Stack<Integer> pilaMovimientos;

    private Map<Long, ArrayList<Integer>> visitados;

    private Integer ultimo;

    private boolean deshacerPila;

    private Stack<Integer> pilaGeneral;

    public Raton() {
        super("Raton");
        this.posibles = new ArrayList<>();
        this.pilaMovimientos = new Stack<>();
        this.visitados = new HashMap<Long, ArrayList<Integer>>();
        this.ultimo = 0;
        this.deshacerPila = false;
    }

    @Override
    public int move(Grid currentGrid, Cheese[] cheese) {
        
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
            if (mv == 0) {
                // Implementar código para deshacer la pila.
                deshacerPila = true;
                return deshacer();
            }

            ultimo = opuesta(mv);
            pilaMovimientos.push(ultimo);

            pilaGeneral.push(ultimo);
           
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

            pilaGeneral.push(ultimo);
            return mv;

        }

    }

    @Override
    public void respawned() {

    }

    @Override
    public void newCheese() {

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

    
}
