package org.example.esame_20230718.view;

import javafx.scene.control.Button;
import javafx.scene.layout.VBox;
import org.example.esame_20230718.controller.MainController;

public class BottoniDebug extends VBox {
    MainController mainController;

    public BottoniDebug(MainController mainController) {
        super();
        this.mainController = mainController;

        draw();
    }

    public void draw() {
        Button bottoneProssimoMese = new Button("Prox Mese");
        bottoneProssimoMese.setOnMouseClicked(mouseEvent -> mainController.avanzaMese());
        Button bottoneAggiungiFondi = new Button("+ 100 Fondi");
        bottoneAggiungiFondi.setOnMouseClicked(mouseEvent -> mainController.aggiungiFondi(100));

        super.getChildren().addAll(bottoneProssimoMese, bottoneAggiungiFondi);
    }
}
