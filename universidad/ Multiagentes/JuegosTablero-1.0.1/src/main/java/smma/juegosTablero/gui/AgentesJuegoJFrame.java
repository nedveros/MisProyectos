/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package smma.juegosTablero.gui;

import jade.core.AID;
import java.util.Iterator;
import java.util.List;
import juegosTablero.Vocabulario.NombreServicio;
import smma.juegosTablero.agentes.AgenteCentralJuego;

/**
 *
 * @author pedroj
 */
public class AgentesJuegoJFrame extends javax.swing.JFrame {
    private final AgenteCentralJuego agente;

    /**
     * Creates new form AgentesJuegoJFrame
     */
    public AgentesJuegoJFrame(AgenteCentralJuego agente) {
        initComponents();
        
        this.agente = agente;
        this.setTitle("Agentes localizados por: " + agente.getLocalName());
        this.setVisible(false);
    }

    public void addAgente(List listaAgentes, NombreServicio servicio) {
        this.setVisible(true);
        Iterator it;
        AID agente;
        
        switch ( servicio ) {
            case GRUPO_JUEGOS:
                centralJuegos.setText(null);
                it = listaAgentes.iterator();
                while ( it.hasNext() ) {
                    agente = (AID) it.next();
                    centralJuegos.append(agente.getLocalName() + "\n");
                }
                break;
            case JUEGO_BARCOS:
                juegoBarcos.setText(null);
                it = listaAgentes.iterator();
                while ( it.hasNext() ) {
                    agente = (AID) it.next();
                    juegoBarcos.append(agente.getLocalName() + "\n");
                }
                break;
            case JUEGO_CONECTA_4:
                juegoConecta4.setText(null);
                it = listaAgentes.iterator();
                while ( it.hasNext() ) {
                    agente = (AID) it.next();
                    juegoConecta4.append(agente.getLocalName() + "\n");
                }
                break;
            case JUEGO_DOMINO:
                juegoDomino.setText(null);
                it = listaAgentes.iterator();
                while ( it.hasNext() ) {
                    agente = (AID) it.next();
                    juegoDomino.append(agente.getLocalName() + "\n");
                }
                break;
        }
    } 
    
    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jLabel1 = new javax.swing.JLabel();
        jLabel2 = new javax.swing.JLabel();
        jLabel3 = new javax.swing.JLabel();
        jLabel4 = new javax.swing.JLabel();
        jScrollPane2 = new javax.swing.JScrollPane();
        centralJuegos = new javax.swing.JTextArea();
        jScrollPane4 = new javax.swing.JScrollPane();
        juegoBarcos = new javax.swing.JTextArea();
        jScrollPane5 = new javax.swing.JScrollPane();
        juegoConecta4 = new javax.swing.JTextArea();
        jScrollPane6 = new javax.swing.JScrollPane();
        juegoDomino = new javax.swing.JTextArea();

        setDefaultCloseOperation(javax.swing.WindowConstants.DO_NOTHING_ON_CLOSE);
        setResizable(false);
        addWindowListener(new java.awt.event.WindowAdapter() {
            public void windowClosing(java.awt.event.WindowEvent evt) {
                formWindowClosing(evt);
            }
        });

        jLabel1.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jLabel1.setText("Grupo Juegos");

        jLabel2.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jLabel2.setText("Juego Barcos");

        jLabel3.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jLabel3.setText("Juego Conecta 4");

        jLabel4.setFont(new java.awt.Font("Arial", 1, 14)); // NOI18N
        jLabel4.setText("Juego Dominó");

        centralJuegos.setEditable(false);
        centralJuegos.setColumns(20);
        centralJuegos.setFont(new java.awt.Font("Courier New", 0, 14)); // NOI18N
        centralJuegos.setRows(5);
        jScrollPane2.setViewportView(centralJuegos);

        juegoBarcos.setEditable(false);
        juegoBarcos.setColumns(20);
        juegoBarcos.setFont(new java.awt.Font("Courier New", 0, 14)); // NOI18N
        juegoBarcos.setRows(5);
        jScrollPane4.setViewportView(juegoBarcos);

        juegoConecta4.setEditable(false);
        juegoConecta4.setColumns(20);
        juegoConecta4.setFont(new java.awt.Font("Courier New", 0, 14)); // NOI18N
        juegoConecta4.setRows(5);
        jScrollPane5.setViewportView(juegoConecta4);

        juegoDomino.setEditable(false);
        juegoDomino.setColumns(20);
        juegoDomino.setFont(new java.awt.Font("Courier New", 0, 14)); // NOI18N
        juegoDomino.setRows(5);
        jScrollPane6.setViewportView(juegoDomino);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap()
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 173, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel1))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane4, javax.swing.GroupLayout.PREFERRED_SIZE, 173, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel2))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane5, javax.swing.GroupLayout.PREFERRED_SIZE, 172, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jLabel3))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jLabel4)
                    .addComponent(jScrollPane6, javax.swing.GroupLayout.PREFERRED_SIZE, 172, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addContainerGap(11, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jLabel1)
                    .addComponent(jLabel2)
                    .addComponent(jLabel3)
                    .addComponent(jLabel4))
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
                    .addComponent(jScrollPane2, javax.swing.GroupLayout.PREFERRED_SIZE, 600, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jScrollPane4, javax.swing.GroupLayout.PREFERRED_SIZE, 600, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jScrollPane5, javax.swing.GroupLayout.PREFERRED_SIZE, 600, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jScrollPane6, javax.swing.GroupLayout.PREFERRED_SIZE, 600, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap())
        );

        pack();
        setLocationRelativeTo(null);
    }// </editor-fold>//GEN-END:initComponents

    private void formWindowClosing(java.awt.event.WindowEvent evt) {//GEN-FIRST:event_formWindowClosing
        // TODO add your handling code here:
        setVisible(false);
    }//GEN-LAST:event_formWindowClosing

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JTextArea centralJuegos;
    private javax.swing.JLabel jLabel1;
    private javax.swing.JLabel jLabel2;
    private javax.swing.JLabel jLabel3;
    private javax.swing.JLabel jLabel4;
    private javax.swing.JScrollPane jScrollPane2;
    private javax.swing.JScrollPane jScrollPane4;
    private javax.swing.JScrollPane jScrollPane5;
    private javax.swing.JScrollPane jScrollPane6;
    private javax.swing.JTextArea juegoBarcos;
    private javax.swing.JTextArea juegoConecta4;
    private javax.swing.JTextArea juegoDomino;
    // End of variables declaration//GEN-END:variables
}
