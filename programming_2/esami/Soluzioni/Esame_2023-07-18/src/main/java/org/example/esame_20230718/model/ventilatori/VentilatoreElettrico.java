package org.example.esame_20230718.model.ventilatori;

public abstract class VentilatoreElettrico extends Ventilatore {
    public VentilatoreElettrico(String marca, Tipologia tipologia, String alimentazione) {
        super(marca, tipologia, alimentazione);
    }
}
