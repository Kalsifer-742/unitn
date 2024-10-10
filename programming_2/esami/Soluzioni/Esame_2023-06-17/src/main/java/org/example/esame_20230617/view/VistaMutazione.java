package org.example.esame_20230617.view;

import javafx.geometry.Insets;
import javafx.scene.layout.*;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import org.example.esame_20230617.model.mutazioni.Mutazione;

public class VistaMutazione extends StackPane {
    public VistaMutazione(Mutazione mutazione) {
        super();

        super.setBackground(new Background(new BackgroundFill(mutazione.getColore(), null, null)));
        super.setBorder(new Border(new BorderStroke(Color.BLACK, BorderStrokeStyle.SOLID, null, null)));

        Text info;
        if(!mutazione.isAttiva()) {
            info = new Text("+ " + mutazione);
        } else {
            info = new Text("- " + mutazione);
        }
        StackPane.setMargin(info, new Insets(5, 5, 5, 5));

        super.setOnMouseClicked(new ClickOnMutazioneEventHandler(mutazione));

        super.getChildren().add(info);
    }
}
