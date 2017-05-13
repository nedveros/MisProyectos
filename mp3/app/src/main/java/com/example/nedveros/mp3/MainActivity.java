package com.example.nedveros.mp3;

import android.Manifest;
import android.content.Intent;
import android.os.Environment;
import android.support.v4.app.ActivityCompat;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.ListView;

import java.io.File;
import java.util.ArrayList;

/*
* @author David Baudet Moreno
* @alias Nedveros
*
* @brief clase encargada de cargar las canciones en una listview para mostarlas en la capa activity_main
*
* */




public class MainActivity extends AppCompatActivity {
    ListView Lista;
    String[] artistas;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        ActivityCompat.requestPermissions(MainActivity.this, new String[]{Manifest.permission.READ_EXTERNAL_STORAGE}, 1);
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Lista = (ListView) findViewById(R.id.lvPlaylist);

        final ArrayList<File> canciones = Buscacanciones(Environment.getExternalStorageDirectory());


        artistas = new String[canciones.size()];

        for (int i = 0; i < canciones.size(); i++) {

            artistas[i] = recortar(canciones.get(i).getName().toString());
        }

        ArrayAdapter<String> adp = new ArrayAdapter<String>(getApplicationContext(), R.layout.capa_canciones, R.id.text, artistas);
        Lista.setAdapter(adp);
        Lista.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position, long id) {
                startActivity(new Intent(getApplicationContext(), Reproductor.class).putExtra("pos", position).putExtra("songlist",
                        canciones));
            }
        });
    }




    /*
    * @brief funcion para buscar canciones recursivamente
    *
    * @pre tener en el androidManifest los permisos de lectura en el dispositivo de memoria
    * @post devuelve un array con las canciones encontradas
    * */



    public ArrayList<File> Buscacanciones(File root) {
        ArrayList<File> al = new ArrayList<File>();
        File[] cancion = root.listFiles();
        for (File singleFile : cancion) {
            if (singleFile.isDirectory() && !singleFile.isHidden()) {
                al.addAll(Buscacanciones(singleFile));
                // al.add(singleFile);
            } else {
                if (singleFile.getName().endsWith(".mp3")) {
                    al.add(singleFile);

                }
            }

        }
        return al;
    }

/*
* @brief se le pasa una cadena y se le quita la ruta hasta el archivo y el punto mp3 para dejar solo la cancion
*
*
*
* */
    public String recortar (String a){




        String[] numerosComoArray = a.split("/");
        String[] numerosComoArray2=numerosComoArray[numerosComoArray.length-1].split(".mp3");





        return numerosComoArray2[numerosComoArray2.length-1];

    }

}


