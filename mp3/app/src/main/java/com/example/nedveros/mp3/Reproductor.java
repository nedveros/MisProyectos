package com.example.nedveros.mp3;

import android.content.Intent;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.media.MediaMetadataRetriever;
import android.media.MediaPlayer;
import android.net.Uri;
import android.os.Handler;
import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.MotionEvent;
import android.view.View;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.SeekBar;
import android.widget.TextView;
import java.io.File;
import java.util.ArrayList;
import java.util.concurrent.TimeUnit;

/**
 * clase reproductor implementa los botones de la consola del mp3 y las funciones para reproducir el audio
 */
public class Reproductor extends AppCompatActivity implements View.OnClickListener {
    static MediaPlayer mp3;
    ArrayList<File> canciones;
    SeekBar barra;
    int position;
    ImageButton play, next, prev;
    Uri u,y;
    String artist;
    TextView txtFinal,txtCurrent;
    private final Handler handler = new Handler();
    private double startTime = 0;
    private double finalTime = 0;
    ImageView album_art;
    TextView album, artistText, title;
    MediaMetadataRetriever metaRetriver;
    byte[] art;


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.capa_reproductor);
        empezar();



    }



    @Override
    public void onClick(View v) {
        int id = v.getId();
        switch (id) {
            case R.id.play:
                if (mp3.isPlaying()) {
                    mp3.pause();
                    play.setImageResource(R.drawable.play);
                } else {
                    mp3.start();
                    play.setImageResource(R.drawable.pause);
                    actualizatiempo();
                }
                break;
            case R.id.next:
                next();
                fincancion();
                break;
            case R.id.prev:
                previous();
                fincancion();
                break;

        }
    }

    /**
     * @brief funcion de carga del programa
     */
    public void empezar() {

        album_art = (ImageView) findViewById(R.id.album_art);
        album = (TextView) findViewById(R.id.Album);
        artistText = (TextView) findViewById(R.id.artist_name);
        title = (TextView) findViewById(R.id.title);
        play = (ImageButton) findViewById(R.id.play);
        prev = (ImageButton) findViewById(R.id.prev);
        next = (ImageButton) findViewById(R.id.next);
        barra = (SeekBar) findViewById(R.id.seekBar);
        txtFinal = (TextView) findViewById(R.id.txtFinalTime);
        txtCurrent = (TextView) findViewById(R.id.txtCurrentTime);

        play.setOnClickListener(this);
        prev.setOnClickListener(this);
        next.setOnClickListener(this);

        if (mp3 != null) {
            mp3.stop();
            mp3.release();
        }

        Intent i = getIntent();
        Bundle b = i.getExtras();
        canciones = (ArrayList) b.getParcelableArrayList("songlist");
        position = b.getInt("pos", 0);
        artist = b.getString("pos");

        u = Uri.parse(canciones.get(position).toString());
        y = Uri.parse(canciones.get(position).toString());
        mp3 = MediaPlayer.create(getApplicationContext(), u);
        if (mp3.isPlaying()) {
            mp3.stop();
            mp3.release();
        } else {
            mp3.start();
        }

        finalTime = mp3.getDuration();
        time();
        actualizatiempo();
        barra.setMax(mp3.getDuration());
        barra.setOnTouchListener(new View.OnTouchListener() {
            @Override
            public boolean onTouch(View v, MotionEvent event) {
                actualizabarra(v);
                return false;
            }
        });
        String nombre = mp3.toString();
        metadatos( recortar(y.toString()));
        fincancion();

    }
    /**
     *@brief conseguir los datos de cada archivo mp3
     */
    public void metadatos(String nombre ){
        metaRetriver = new MediaMetadataRetriever();
        metaRetriver.setDataSource(String.valueOf(y));
        try {
            art = metaRetriver.getEmbeddedPicture();
            Bitmap songImage = BitmapFactory
                    .decodeByteArray(art, 0, art.length);
            album_art.setImageBitmap(songImage);
            album.setText(metaRetriver
                    .extractMetadata(MediaMetadataRetriever.METADATA_KEY_ALBUM));
            artistText.setText(metaRetriver
                    .extractMetadata(MediaMetadataRetriever.METADATA_KEY_ARTIST));
            title.setText(metaRetriver
                    .extractMetadata(MediaMetadataRetriever.METADATA_KEY_TITLE));
        } catch (Exception e) {
            album_art.setImageDrawable(getResources().getDrawable(R.drawable.album));
            album.setText("Album Desconocido");
            artistText.setText("Artista Desconocido");

            title.setText(nombre);

        }
    }
    /**
     *
     * funcion para cambiar con la barra el tiempo
     */
    private void actualizabarra(View v){
        if(mp3.isPlaying()){
            SeekBar sb = (SeekBar)v;
            mp3.seekTo(sb.getProgress());
        }
    }
    /**
     * @brief actualizar el tiempo
     */
    public void actualizatiempo() {
        barra.setProgress(mp3.getCurrentPosition());
        startTime = mp3.getCurrentPosition();
        if(TimeUnit.MILLISECONDS.toSeconds((long) startTime) -
                TimeUnit.MINUTES.toSeconds(TimeUnit.MILLISECONDS.
                        toMinutes((long) startTime))<10){
            txtCurrent.setText(String.format("%d:"+0+"%d",
                    TimeUnit.MILLISECONDS.toMinutes((long) startTime),
                    TimeUnit.MILLISECONDS.toSeconds((long) startTime) -
                            TimeUnit.MINUTES.toSeconds(TimeUnit.MILLISECONDS.
                                    toMinutes((long) startTime)))
            );
        }
        else{
            txtCurrent.setText(String.format("%d:%d",
                    TimeUnit.MILLISECONDS.toMinutes((long) startTime),
                    TimeUnit.MILLISECONDS.toSeconds((long) startTime) -
                            TimeUnit.MINUTES.toSeconds(TimeUnit.MILLISECONDS.
                                    toMinutes((long) startTime)))
            );
        }

        if (mp3.isPlaying()) {
            Runnable notification = new Runnable() {
                public void run() {
                    actualizatiempo();
                }
            };
            handler.postDelayed(notification,1000);
        }
        else{
            mp3.pause();
        }

    }
    /**
     * @brief funcion de tiempo para la barra
     */
    public void time(){
        if(TimeUnit.MILLISECONDS.toSeconds((long) finalTime) -
                TimeUnit.MINUTES.toSeconds(TimeUnit.MILLISECONDS.toMinutes((long)
                        finalTime))< 10){
            txtFinal.setText(String.format("%d:"+0+"%d",
                    TimeUnit.MILLISECONDS.toMinutes((long) finalTime),
                    TimeUnit.MILLISECONDS.toSeconds((long) finalTime) -
                            TimeUnit.MINUTES.toSeconds(TimeUnit.MILLISECONDS.toMinutes((long)
                                    finalTime)))
            );
        }
        else{
            txtFinal.setText(String.format("%d:%d",
                    TimeUnit.MILLISECONDS.toMinutes((long) finalTime),
                    TimeUnit.MILLISECONDS.toSeconds((long) finalTime) -
                            TimeUnit.MINUTES.toSeconds(TimeUnit.MILLISECONDS.toMinutes((long)
                                    finalTime)))
            );
        }
    }
    /**
     * @brief carga la cancion siguiente
     */
    public void next(){
        mp3.stop();
        mp3.release();
        position = (position+1)% canciones.size();
        u = Uri.parse(canciones.get((position)).toString());
        y = Uri.parse(canciones.get(position).toString());
        mp3 = MediaPlayer.create(getApplicationContext(),u);
        mp3.start();
        finalTime = mp3.getDuration();
        time();
        barra.setMax(mp3.getDuration());
        metadatos(recortar(y.toString()));
        barra.setProgress(0);
        actualizatiempo();
    }
    /**
     * carga la cancion anterior de la lista
     */
    public void previous(){
        mp3.stop();
        mp3.release();
        position = (position-1<0)? canciones.size()-1: position-1;
        u = Uri.parse(canciones.get((position)).toString());
        y = Uri.parse(canciones.get(position).toString());
        mp3 = MediaPlayer.create(getApplicationContext(),u);
        mp3.start();
        finalTime = mp3.getDuration();
        time();
        barra.setMax(mp3.getDuration());
        metadatos(recortar(y.toString()));
        barra.setProgress(0);
        actualizatiempo();
    }
    /**
     * @brief cuando termina la lista empieza de nuevo
     */
    public void fincancion(){
        mp3.setOnCompletionListener(new MediaPlayer.OnCompletionListener() {
            @Override
            public void onCompletion(MediaPlayer mp) {
                next();
                fincancion();
            }

        });

    }

    /*
    *
    * @brief funcion para recortar la ruta y quedarnos con el nombre de la cancion para los casos en los que no tenga metadatos
    *
    *
    * */
    public String recortar (String a){




        String[] numerosComoArray = a.split("/");
        String[] numerosComoArray2=numerosComoArray[numerosComoArray.length-1].split(".mp3");



        return numerosComoArray2[numerosComoArray2.length-1];

    }

}



