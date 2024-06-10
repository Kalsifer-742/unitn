package org.example.esame_20230718.view;

import javafx.scene.layout.VBox;
import org.example.esame_20230718.controller.MainController;
import org.example.esame_20230718.model.ventilatori.Ventilatore;

public class CatalogoVentilatori extends VBox {
    MainController mainController;

    public CatalogoVentilatori(MainController mainController) {
        super();
        this.mainController = mainController;

        draw();
    }

    public void draw() {
        super.getChildren().clear();

        for (Ventilatore ventilatore : mainController.getVentilatori()) {
            VistaVentilatore tmp = new VistaVentilatore(mainController, ventilatore);
            tmp.setOnMouseClicked(mouseEvent -> mainController.aggiungiAbbonamento(ventilatore));
            super.getChildren().add(tmp);
        }
    }
}
