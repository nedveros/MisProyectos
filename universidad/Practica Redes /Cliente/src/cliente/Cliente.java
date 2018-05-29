package cliente;

import java.io.*;
import java.net.*;

/**
 *
 * @author joseton
 */
public class Cliente {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws Exception {
        
        //Se crea el flujo de entrada
        BufferedReader entradaDesdeUsuario=
                new BufferedReader(new InputStreamReader(System.in));
        
        //Se crea el socket del cliente
        DatagramSocket socketCliente= new DatagramSocket();
        
        //Traduce el nombre de host a una dirección IP, en este caso sera el localhost
        //para probarlo en el mismo pc
        InetAddress direccionIP=InetAddress.getByName("localhost");
        
        byte[] datosEnvio=new byte[1024];
        byte[] datosRecepcion=new byte[1024];
        
        //Entrada del usuario para meter la dirección IP o el dominio a traducir
        String direccion=entradaDesdeUsuario.readLine();
        datosEnvio=direccion.getBytes();
        
        //Creaación del datagrama con los datos a enviar
        DatagramPacket paqueteEnvio=
                new DatagramPacket(datosEnvio, datosEnvio.length,direccionIP,9876);
        
        //Envia el datagrama al servidor correspondiente
        socketCliente.send(paqueteEnvio);
        
        //Creación del datagrama de los datos que recibirá del servidor
        DatagramPacket paqueteRecepcion=
                new DatagramPacket(datosRecepcion,datosRecepcion.length);
        
        //Lee el datagrama que proviene del servidor
        socketCliente.receive(paqueteRecepcion);
        
        //Se extrae el contenido del datagrama 
        String nuevaDireccion=
                new String(paqueteRecepcion.getData());
        
        System.out.println("Del servidor: "+nuevaDireccion);
        
        //Cierre del socket cliente
        socketCliente.close();
    }
    
}
