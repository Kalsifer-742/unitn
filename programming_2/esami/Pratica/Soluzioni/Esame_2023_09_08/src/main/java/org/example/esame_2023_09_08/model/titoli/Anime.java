package org.example.esame_2023_09_08.model.titoli;

import org.example.esame_2023_09_08.model.Titolo;

public class Anime extends Titolo {
    String linguaSottotitoli;

    public Anime(String nome, int annoDiPubblicazione, String lingua, String linguaSottotitoli, double prezzoBase) {
        super(nome, annoDiPubblicazione, lingua, prezzoBase);
        this.linguaSottotitoli = linguaSottotitoli;
    }

    public Anime(String nome, int annoDiPubblicazione, String lingua, double prezzoBase) {
        super(nome, annoDiPubblicazione, lingua, prezzoBase);
        this.linguaSottotitoli = null;
    }

    @Override
    public String toString() {
        return "Titolo: " + nome + "\n" +
                "Anno: " + annoDiPubblicazione + "\n" +
                "Lingua: " + lingua + "\n" +
                (linguaSottotitoli != null ? ("Sottotitoli: " + linguaSottotitoli + "\n") : "") +
                "Prezzo base: " + prezzoBase + "$";
    }
}
