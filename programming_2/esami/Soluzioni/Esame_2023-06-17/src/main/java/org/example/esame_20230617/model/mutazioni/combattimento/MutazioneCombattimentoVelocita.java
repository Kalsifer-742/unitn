package org.example.esame_20230617.model.mutazioni.combattimento;

import org.example.esame_20230617.model.Geraldo;

public class MutazioneCombattimentoVelocita extends MutazioneCombattimento {
    public MutazioneCombattimentoVelocita() {
        super();
    }

    @Override
    public String toString() {
        return "Velocità";
    }

    @Override
    public void applica(Geraldo geraldo) {
        geraldo.velocita += 2;
        toggleAttiva();
    }

    @Override
    public void rimuovi(Geraldo geraldo) {
        geraldo.velocita -= 2;
        toggleAttiva();
    }
}
