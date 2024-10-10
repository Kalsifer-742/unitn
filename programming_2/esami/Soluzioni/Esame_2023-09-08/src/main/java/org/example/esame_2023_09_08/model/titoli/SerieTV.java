package org.example.esame_2023_09_08.model.titoli;

import org.example.esame_2023_09_08.model.Titolo;

public class SerieTV extends Titolo {
    int numeroStagioni;
    int numeroStagioniAcquistate;

    public SerieTV(String nome, int annoDiPubblicazione, String lingua, int numeroStagioni, double prezzoBase) {
        super(nome, annoDiPubblicazione, lingua, prezzoBase);
        this.numeroStagioni = numeroStagioni;
        numeroStagioniAcquistate = 0;
    }

    public int getNumeroStagioni() {
        return numeroStagioni;
    }

    public void setNumeroStagioniAcquistate(int numeroStagioniAcquistate) {
        this.numeroStagioniAcquistate = numeroStagioniAcquistate;
    }

    @Override
    public double getPrezzo() {
        double prezzo = (super.getPrezzo() * numeroStagioni);

        if (numeroStagioniAcquistate == numeroStagioni) {
            prezzo -= prezzo * 0.5;
        } else if (numeroStagioniAcquistate > 1) {
            prezzo -= prezzo * 0.25;
        }

        return prezzo;
    }
}
