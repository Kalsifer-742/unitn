package org.example.esame_20230718.view;

import javafx.scene.control.Button;
import javafx.scene.layout.VBox;
import org.example.esame_20230718.controller.MainController;
import org.example.esame_20230718.model.ventilatori.Tipologia;

public class BottoniOrdinamento extends VBox {
    MainController mainController;

    public BottoniOrdinamento(MainController mainController) {
        super();
        this.mainController = mainController;

        draw();
    }

    public void draw() {
        Button orderByTypeButton = new Button("Ordina per Tipo");
        orderByTypeButton.setOnMouseClicked(mouseEvent -> mainController.ordinaVentilatori(((v1, v2) -> {
            int result = v1.getTipologia().compareTo(v2.getTipologia());

            if (result == 0) {
                return Double.compare(v2.getCosto(), v1.getCosto());
            } else {
                return result;
            }
        })));
        Button orderByPriceButton = new Button("Ordina per Prezzo");
        orderByPriceButton.setOnMouseClicked(mouseEvent -> mainController.ordinaVentilatori(((v1, v2) -> {
            int result = Double.compare(v1.getCosto(), v2.getCosto());

            if (result == 0) {
                return v1.getTipologia().compareTo(v2.getTipologia());
            } else {
                return result;
            }
        })));

        super.getChildren().addAll(orderByTypeButton, orderByPriceButton);
    }
}
