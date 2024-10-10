package org.example.esame_20230617.model.mutazioni.combattimento;

import org.example.esame_20230617.model.Geraldo;

public class MutazioneCombattimentoForza extends MutazioneCombattimento {
    public MutazioneCombattimentoForza() {
        super();
    }

    @Override
    public String toString() {
        return "Forza";
    }

    @Override
    public void applica(Geraldo geraldo) {
        geraldo.forza += 2;
        toggleAttiva();
    }

    @Override
    public void rimuovi(Geraldo geraldo) {
        geraldo.forza -= 2;
        toggleAttiva();
    }
}
