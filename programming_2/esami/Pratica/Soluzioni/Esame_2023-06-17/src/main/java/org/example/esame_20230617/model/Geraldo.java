package org.example.esame_20230617.model;

import java.util.LinkedList;

public class Geraldo {
    int livello;
    int forza;
    int velocita;
    int tolleranza;
    LinkedList<Magia> magie;

    public Geraldo() {
        livello = 0;
        forza = 10;
        velocita = 10;
        tolleranza = 2;
        magie = new LinkedList<>();
    }

    @Override
    public String toString() {
        String magieToString = "";
        for (Magia magia : magie) {
            magieToString += magia + "\n";
        }

        return "Lvl: " + livello + "\n" +
                "Str: " + forza + "\n" +
                "Vel: " + velocita + "\n" +
                "\n" +
                "Tol: " + tolleranza + "\n" +
                "\n" +
                "Spells:" + "\n" +
                magieToString;
    }
}
