package com.hidalgo.pokedex4;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Context;
import android.content.SharedPreferences;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.Button;
import android.widget.ImageView;
import android.widget.TextView;

import com.android.volley.Request;
import com.android.volley.RequestQueue;
import com.android.volley.Response;
import com.android.volley.VolleyError;
import com.android.volley.toolbox.JsonObjectRequest;
import com.android.volley.toolbox.Volley;

import org.json.JSONArray;
import org.json.JSONException;
import org.json.JSONObject;
import org.w3c.dom.Text;

import java.io.IOException;
import java.net.URL;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class PokemonActivity extends AppCompatActivity {

    private ImageView poke_img;
    private TextView nameTextView;
    private TextView numberTextView;
    private TextView type1TextView;
    private TextView type2TextView;
    private TextView catch_release_stat;
    private TextView poke_desc;
    private String url;
    private RequestQueue requestQueue;
    public static String pname;
    public String pic_entries;
    public static String desc_url;
    public static String url3;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_pokemon);


        SharedPreferences prefs = getPreferences(Context.MODE_PRIVATE);
        requestQueue = Volley.newRequestQueue(getApplicationContext());
        url = getIntent().getStringExtra("url");

        nameTextView = findViewById(R.id.pokemon_name);
        numberTextView = findViewById(R.id.pokemon_number);
        type1TextView = findViewById(R.id.pokemon_type1);
        type2TextView = findViewById(R.id.pokemon_type2);
        catch_release_stat = findViewById((R.id.catch_release));
        poke_img = findViewById(R.id.poke_pic);
        poke_desc = findViewById(R.id.poke_desc);


        load();
        Log.d("urltest3",String.valueOf(pname));

    }

    public void load(){
        type1TextView.setText("");
        type2TextView.setText("");
        SharedPreferences prefs = getPreferences(Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = prefs.edit();


        JsonObjectRequest request = new JsonObjectRequest(Request.Method.GET, url, null, new Response.Listener<JSONObject>() {
            @Override
            public void onResponse(JSONObject response) {

                try {
                    pname = response.getString(("name"));
                    nameTextView.setText(pname.substring(0,1).toUpperCase() + pname.substring(1));
                    numberTextView.setText(String.format("#%03d", response.getInt("id")));

                    String check = prefs.getString(pname, null);


                    if (null == check){
                        editor.putString(pname, "Catch");
                        editor.apply();
                        catch_release_stat.setText(prefs.getString(pname,"fail"));
                        Log.d("test4","ifnull");
                    }
                    else {
                        catch_release_stat.setText(prefs.getString(pname, "fail2"));
                        Log.d("test4","nonull");
                    }

                    pic_entries = response.getJSONObject("sprites").getString("front_default");
                    desc_url = response.getJSONObject("species").getString("url");
                    url3 = desc_url;


                    editor.putString(pname+"desc",desc_url);
                    editor.apply();
                    String saved_desc_url = prefs.getString(pname+"desc","fail_desc");


                    JSONArray typeEntries = response.getJSONArray("types");
                    for (int i = 0; i < typeEntries.length(); i++){
                       JSONObject typeEntry = typeEntries.getJSONObject(i);
                       int slot = typeEntry.getInt("slot");
                       String type = typeEntry.getJSONObject("type").getString("name");

                       if(slot == 1){
                           type1TextView.setText(type);
                       }
                       else if (slot == 2) {
                           type2TextView.setText(type);
                       }
                   }

                    new DownloadSpriteTask().execute(pic_entries);
                    load2();

                    Log.d("TTest5", String.valueOf(pic_entries));





                } catch (JSONException e) {
                    Log.e("cs50", "Pokemon Json error", e);
                }
                Log.d("testurltest",String.valueOf(desc_url));


            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Log.e("cs50", "Pokemon details error");
            }
        });

        requestQueue.add(request);

        Log.d("urltest53",String.valueOf(desc_url));

    }

    private class DownloadSpriteTask extends AsyncTask<String, Void, Bitmap> {
        @Override
        protected Bitmap doInBackground(String... strings) {
            try {
                URL url = new URL(strings[0]);
                return BitmapFactory.decodeStream(url.openStream());
            }
            catch (IOException e) {
                Log.e("cs50", "Download sprite error", e);
                return null;
            }
        }

        @Override
        protected void onPostExecute(Bitmap bitmap) {
            Log.d("TTest4", "TTest4");
            poke_img.setImageBitmap(bitmap);
        }
    }

    public void load2(){

        Log.d("omgtest1",url3);
        JsonObjectRequest request2 = new JsonObjectRequest(Request.Method.GET, url3, null, new Response.Listener<JSONObject>() {
            @Override
            public void onResponse(JSONObject response) {

                try {

                    JSONArray flavor_texts = response.getJSONArray("flavor_text_entries");
                    for (int i = 0; i < flavor_texts.length(); i++){

                        JSONObject flavor_text = flavor_texts.getJSONObject(i);

                        JSONObject language = flavor_text.getJSONObject("language");


                        if(language.getString("name").equals("en") ) {
                            String flavor = flavor_text.getString("flavor_text");
                            poke_desc.setText(flavor);
                            Log.d("flavor",flavor);
                            break;

                        }

                    }





                } catch (JSONException e) {
                    Log.e("cs50", "Pokemon Json error2", e);
                }



            }
        }, new Response.ErrorListener() {
            @Override
            public void onErrorResponse(VolleyError error) {
                Log.e("cs50", "Pokemon details error2");
            }
        });


        requestQueue.add(request2);



    }






    public void toggleCatch(View view) {

        SharedPreferences prefs = getPreferences(Context.MODE_PRIVATE);
        SharedPreferences.Editor editor = prefs.edit();

        Button button = (Button)findViewById(R.id.catch_release);




        String check2 = prefs.getString(pname,"fail5");
        Log.d("Test2", check2 );
        if (!check2.equals("Release")) {
            editor.putString(pname, "Release");
            editor.apply();
            button.setText(prefs.getString(pname, "fail4"));
            Log.d("Test2", check2);
        }
        else{
            editor.putString(pname,"Catch");
            editor.apply();
            button.setText(prefs.getString(pname, "fail5"));
            Log.d("Test2", "else" );
        }
    }


}