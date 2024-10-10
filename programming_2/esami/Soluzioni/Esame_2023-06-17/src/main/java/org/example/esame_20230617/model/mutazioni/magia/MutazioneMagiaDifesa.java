package org.example.esame_20230617.model.mutazioni.magia;

import org.example.esame_20230617.model.Geraldo;
import org.example.esame_20230617.model.Magia;

public class MutazioneMagiaDifesa extends MutazioneMagia {
    public MutazioneMagiaDifesa() {
        super();
    }

    @Override
    public String toString() {
        return "Magia di Difesa";
    }

    @Override
    public void applica(Geraldo geraldo) {
        geraldo.magie.add(new Magia(this.toString()));
        toggleAttiva();
    }

    @Override
    public void rimuovi(Geraldo geraldo) {
        geraldo.magie.remove(new Magia(this.toString()));
        toggleAttiva();
    }
}
