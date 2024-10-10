package org.example.esame_2023_09_08.model;

public class Titolo {
    protected String nome;
    protected int annoDiPubblicazione;
    protected String lingua;
    protected double prezzoBase;

    public Titolo(String nome, int annoDiPubblicazione, String lingua, double prezzoBase) {
        this.nome = nome;
        this.annoDiPubblicazione = annoDiPubblicazione;
        this.lingua = lingua;
        this.prezzoBase = prezzoBase;
    }

    public String getNome() {
        return nome;
    }

    public int getAnnoDiPubblicazione() {
        return annoDiPubblicazione;
    }

    public double getPrezzo() {
        if (annoDiPubblicazione < 2015) {
            return (prezzoBase - prezzoBase * 0.10);
        }
        return prezzoBase;
    }

    public String getAnno() {
        return "'" + String.valueOf(annoDiPubblicazione).substring(2);
    }

    @Override
    public String toString() {
        return "Titolo: " + nome + "\n" +
                "Anno: " + annoDiPubblicazione + "\n" +
                "Lingua: " + lingua + "\n" +
                "Prezzo base: " + prezzoBase + "$";
    }
}
