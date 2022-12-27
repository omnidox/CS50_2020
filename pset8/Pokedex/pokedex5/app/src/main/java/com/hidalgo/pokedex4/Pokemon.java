package com.hidalgo.pokedex4;

import android.content.Context;
import android.content.SharedPreferences;
import android.util.Log;

public class Pokemon {
    private String name;
    private String url;


    Pokemon(String name, String url) {

        this.name = name;
        this.url = url;
    }

    public String getName() {
        return name;
    }

    public String getUrl() {
        return url;
    }
}
