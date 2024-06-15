package org.example.esame_20230617.model.mutazioni.magia;

import org.example.esame_20230617.model.Geraldo;
import org.example.esame_20230617.model.Magia;

public class MutazioneMagiaFuoco extends MutazioneMagia {
    public MutazioneMagiaFuoco() {
        super();
    }

    @Override
    public String toString() {
        return "Magia di Fuoco";
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
