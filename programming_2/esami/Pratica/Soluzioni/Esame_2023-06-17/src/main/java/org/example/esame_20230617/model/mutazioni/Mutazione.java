package org.example.esame_20230617.model.mutazioni;

import javafx.scene.paint.Color;
import org.example.esame_20230617.model.InterfacciaMutazione;

public abstract class Mutazione implements InterfacciaMutazione {
    private final Color colore;
    private boolean isAttiva;

    public Mutazione(Color colore) {
        this.colore = colore;
        isAttiva = false;
    }

    @Override
    public boolean isAttiva() {
        return isAttiva;
    }

    public void toggleAttiva() {
        isAttiva = !isAttiva;
    }

    public Color getColore() {
        return colore;
    }
}
