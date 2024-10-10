package org.example.esame_20230617.view;

import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import org.example.esame_20230617.model.mutazioni.Mutazione;

import java.util.LinkedList;

public class MutazioniPossibili extends VBox {
    final LinkedList<Mutazione> mutazioni;

    public MutazioniPossibili(LinkedList<Mutazione> mutazioni) {
        super();
        this.mutazioni = mutazioni;

        draw();
    }

    public void draw() {
        super.getChildren().clear();

        Text info = new Text("Mutazioni possibili");
        HBox vistaMutazioni = new HBox();
        for (Mutazione mutazione : mutazioni) {
            vistaMutazioni.getChildren().add(new VistaMutazione(mutazione));
        }

        super.getChildren().addAll(info, vistaMutazioni);
    }
}
