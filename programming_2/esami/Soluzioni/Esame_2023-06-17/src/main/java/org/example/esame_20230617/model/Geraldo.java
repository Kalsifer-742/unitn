package org.example.esame_20230617.model;

import org.example.esame_20230617.model.mutazioni.Mutazione;

import java.util.LinkedList;

public class Geraldo {
    public final int livello;
    public int forza;
    public int velocita;
    public int tolleranza;
    public final LinkedList<Magia> magie;

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

    public void applicaMutazione(Mutazione mutazione) {
        mutazione.applica(this);
    }

    public void rimuoviMutazione(Mutazione mutazione) {
        mutazione.rimuovi(this);
    }
}