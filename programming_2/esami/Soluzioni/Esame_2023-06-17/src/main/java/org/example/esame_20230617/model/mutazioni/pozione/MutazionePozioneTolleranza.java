package org.example.esame_20230617.model.mutazioni.pozione;

import org.example.esame_20230617.model.Geraldo;

public class MutazionePozioneTolleranza extends MutazionePozione {
    public MutazionePozioneTolleranza() {
        super();
    }

    @Override
    public String toString() {
        return "Tolleranza";
    }

    @Override
    public void applica(Geraldo geraldo) {
        geraldo.tolleranza += 2;
        toggleAttiva();
    }

    @Override
    public void rimuovi(Geraldo geraldo) {
        geraldo.tolleranza -= 2;
        toggleAttiva();
    }
}
