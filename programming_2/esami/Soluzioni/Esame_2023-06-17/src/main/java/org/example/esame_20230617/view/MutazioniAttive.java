package org.example.esame_20230617.view;

import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import org.example.esame_20230617.model.mutazioni.Mutazione;

import java.util.LinkedList;

public class MutazioniAttive extends VBox {
    final LinkedList<Mutazione> mutazioni;

    public MutazioniAttive(LinkedList<Mutazione> mutazioni) {
        super();
        this.mutazioni = mutazioni;

        draw();
    }

    public void draw() {
        super.getChildren().clear();

        Text info = new Text("Mutazioni");
        super.getChildren().add(info);
        for (Mutazione mutazione : mutazioni) {
            if (mutazione.isAttiva()) { //&& !(mutazione instanceof MutazioneMagia)
                Text tmp = new Text(mutazione.toString());
                tmp.setFill(mutazione.getColore());
                super.getChildren().add(tmp);
            }
        }
    }
}
