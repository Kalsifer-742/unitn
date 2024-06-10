package org.example.esame_20230718.model.ventilatori;

import org.example.esame_20230718.model.ventilatori.elettrici.VentilatoreElettricoConBatteria;
import org.example.esame_20230718.model.ventilatori.elettrici.VentilatoreElettricoConPresa;

public abstract class Ventilatore {
    private final String marca;
    private double costo = 10;
    private final Tipologia tipologia;
    private final String alimentazione;

    public Ventilatore(String marca, Tipologia tipologia, String alimentazione) {
        this.marca = marca;
        this.tipologia = tipologia;
        this.alimentazione = alimentazione;

        costo = calcolaCosto();
    }
    
    private double calcolaCosto() {
        costo += tipologia.getCosto();

        if (this instanceof VentilatoreMeccanico) {
            return costo * 1;
        } else if (this instanceof VentilatoreElettricoConPresa) {
            return costo * 2;
        } else if (this instanceof VentilatoreElettricoConBatteria) {
            return costo * 3;
        } else {
            return 0;
        }
    }

    public double getCosto() {
        return costo;
    }

    public Tipologia getTipologia() {
        return tipologia;
    }

    @Override
    public String toString() {
        return marca + "\n" +
                "Tipo: " + tipologia + " Alimentazione: " + alimentazione + "\n" +
                "Costo: " + costo;
    }
}
