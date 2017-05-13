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
 * 
 * @author migueldiazmedina
 * 
 */
public class M17D03 extends Mouse {

    private ArrayList<Integer> posibles;    // Lista que almacena los posibles movimientos accesibles desde una casilla.

    private Stack<Integer> pilaMovimientos;

    private Map<Long, ArrayList<Integer>> visitados;

    private Integer ultimo;

    private boolean deshacerPila;

    private Stack<Integer> queso2;

    private Stack<Integer> queso3;

    private Stack<Integer> queso4;

    private Stack<Integer> queso5;

    private int quesoActual;

    private boolean quesoEncontrado;

    public M17D03() {
        super("M17D03");
        this.posibles = new ArrayList<>();
        this.pilaMovimientos = new Stack<>();
        this.visitados = new HashMap<Long, ArrayList<Integer>>();
        this.ultimo = 0;
        this.deshacerPila = false;
        this.quesoActual = 0;
        this.quesoEncontrado = false;
        this.queso2 = new Stack<>();
        this.queso3 = new Stack<>();
        this.queso4 = new Stack<>();
        this.queso5 = new Stack<>();
    }

    @Override
    public int move(Grid currentGrid, Cheese[] cheese) {
        if (currentGrid.getX() == cheese[quesoActual].getX() && currentGrid.getY() == cheese[quesoActual].getY()) {
            System.out.println("Se ha encontrado el queso " + quesoActual);
            quesoActual++;

            visitados.clear();
            pilaMovimientos.clear();
            if (compruebaCamino(quesoActual) == true) {
                System.out.println("Hay camino para el queso" + quesoActual);
                quesoEncontrado = true;
            } else {

                System.out.println("No hay camino para el queso" + quesoActual);
                quesoEncontrado = false;
            }
        }

        if (quesoEncontrado == true) {
            //pilaMovimientos.pop();
            if (quesoActual == 1) {
                if (queso2.empty()) {
                    System.out.println("Pila " + 2 + " vacia");
                }
                System.out.println("Deshaciendo pila "+2);
                return queso2.pop();
            }

            if (quesoActual == 2) {
                if (queso3.empty()) {
                    System.out.println("Pila " + 3 + " vacia");
                }
                System.out.println("Deshaciendo pila "+3);
                return queso3.pop();
            }

            if (quesoActual == 3) {
                if (queso4.empty()) {
                    System.out.println("Pila " + 4 + " vacia");
                }
                System.out.println("Deshaciendo pila "+4);
                return queso4.pop();
            }

            if (quesoActual == 4) {
                if (queso5.empty()) {
                    System.out.println("Pila " + 5 + " vacia");
                }
                System.out.println("Deshaciendo pila "+5);
                return queso5.pop();
            }

        }
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

            int aux = compruebaQuesos(currentGrid, cheese);
            if (aux != -1) {
                caminoPila(aux, opuesta(mv));
            }
            llenaPilas(opuesta(mv));
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

            int aux = compruebaQuesos(currentGrid, cheese);
            if (aux != -1) {
                caminoPila(aux, opuesta(mv));
            }
            llenaPilas(opuesta(mv));
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

    private int compruebaQuesos(Grid currentGrid, Cheese[] cheese) {
        if (currentGrid.getX() == cheese[1].getX() && currentGrid.getY() == cheese[1].getY()) {
            return 1;
        }
        if (currentGrid.getX() == cheese[2].getX() && currentGrid.getY() == cheese[2].getY()) {
            return 2;
        }
        if (currentGrid.getX() == cheese[3].getX() && currentGrid.getY() == cheese[3].getY()) {
            return 3;
        }
        if (currentGrid.getX() == cheese[4].getX() && currentGrid.getY() == cheese[4].getY()) {
            return 4;
        }
        return -1;
    }

    private void caminoPila(int i, int mv) {
        if (i == 1) {
            queso2.push(mv);
        }
        if (i == 2) {
            queso3.push(mv);
        }
        if (i == 3) {
            queso4.push(mv);
        }
        if (i == 4) {
            queso5.push(mv);
        }

    }

    private boolean compruebaCamino(int queso) {
        if (queso == 1) {
            return !queso2.empty();
        }
        if (queso == 2) {
            return !queso3.empty();
        }
        if (queso == 3) {
            return !queso4.empty();
        }
        if (queso == 4) {
            return !queso5.empty();
        }
        return false;
    }

    public void llenaPilas(int mv) {
        if (!queso2.empty()) {
            queso2.push(mv);
        }
        if (!queso3.empty()) {
            queso3.push(mv);
        }
        if (!queso4.empty()) {
            queso4.push(mv);
        }
        if (!queso5.empty()) {
            queso5.push(mv);
        }
    }
}
