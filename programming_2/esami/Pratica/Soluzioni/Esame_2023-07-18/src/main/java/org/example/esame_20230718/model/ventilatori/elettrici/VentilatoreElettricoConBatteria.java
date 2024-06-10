package org.example.esame_20230718.model.ventilatori.elettrici;

import org.example.esame_20230718.model.ventilatori.VentilatoreElettrico;
import org.example.esame_20230718.model.ventilatori.Tipologia;

public class VentilatoreElettricoConBatteria extends VentilatoreElettrico {
    public VentilatoreElettricoConBatteria(String marca, Tipologia tipologia) {
        super(marca, tipologia, "Batteria");
    }
}
