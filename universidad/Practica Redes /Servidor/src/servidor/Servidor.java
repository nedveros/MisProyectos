package servidor;

import java.io.*;
import java.net.*;

/**
 *
 * @author joseton
 */
public class Servidor {
    
    static String DNS(String envio){
        
        File archivo = null;
        FileReader fr = null;
        BufferedReader br = null;

        String auxiliar=new String(""); //String auxiliar para comparar con la dirección IP o dominio que nos pase el cliente

        //Variables necesarias para el flujo del fichero

        try {
            // Apertura del fichero y creacion de BufferedReader para poder
            // hacer una lectura comoda (disponer del metodo readLine()).
            archivo = new File ("/home/joseton/NetBeansProjects/DNS");
            fr = new FileReader (archivo);
            br = new BufferedReader(fr);

            // Lectura del fichero
            String linea=new String("");
            while((linea=br.readLine())!=null){

                //Extraigo la subcadena del primer campo (dirección IP)
                auxiliar=linea.substring(0,linea.indexOf(';'));

                //Comparamos si coincide con la dirección que nos han pasado
                if(envio.equals(auxiliar)){
                    return linea.substring(linea.indexOf(';')+1,linea.length()-1);
                }

                //Extraigo la subcadena del segundo campo (dominio)
                auxiliar=linea.substring(linea.indexOf(';')+1,linea.length()-1);

                //Comparamos si coincide con la dirección que nos han pasado
                if(envio.equals(auxiliar)){
                    return linea.substring(0,linea.indexOf(';'));
                }
            }
        }

        catch(Exception e){
        e.printStackTrace();
        }finally{
            // En el finally cerramos el fichero, para asegurarnos
            // que se cierra tanto si todo va bien como si salta
            // una excepcion.
            try{                   
               if( null != fr ){  
                  fr.close();    
               }                 
            }catch (Exception e2){
               e2.printStackTrace();
            }
        }
        
        return "La dirección no se encuentra en la base de datos";
        
    }

    /**
     * Programa principal
     */
    public static void main(String[] args) throws Exception{
            
            //Creación del socket servidor en el puerto 9876
            DatagramSocket socketServidor= new DatagramSocket(9876);
            
            byte[] datosRecepcion= new byte[1024];
            byte[] datosEnvio=new byte[1024];
            
            while(true) //Bucle infinito
            {   
                //Creación del datagrama de los datos que recibirá del cliente
                DatagramPacket paqueteRecepcion = new DatagramPacket(datosRecepcion,datosRecepcion.length);
                
                //Recibo el datagrama del cliente
                socketServidor.receive(paqueteRecepcion);
                
                //Paso el contenido a una cadena de caracteres y le doy un tamaño adecuado para comparar
                String direccion= new String(paqueteRecepcion.getData(),0,paqueteRecepcion.getLength(),"UTF-8");
                
                //Dirección IP del remitente
                InetAddress DireccionIP= paqueteRecepcion.getAddress();
                
                //Puerto del remitente
                int puerto= paqueteRecepcion.getPort();
                
                //String que contendrá la traducción
                String cambioDireccion=new String("");
                
                //Traducción dirección
                cambioDireccion=DNS(direccion);
                
                System.out.println( "Dirección recibida " +direccion+ " que corresponde a " +cambioDireccion);
                
                datosEnvio=cambioDireccion.getBytes();
                
                //Creación de datagrama de los datos que recibirá el cliente
                DatagramPacket paqueteEnvio= 
                        new DatagramPacket(datosEnvio, datosEnvio.length,DireccionIP,puerto);
                
                //Enviamos el datagrama
                socketServidor.send(paqueteEnvio);
                
            }
    }
    
}
