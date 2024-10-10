package org.example.esame_20230718.view;

import javafx.scene.layout.HBox;
import javafx.scene.paint.Color;
import javafx.scene.shape.Circle;
import javafx.scene.text.Text;
import org.example.esame_20230718.controller.MainController;
import org.example.esame_20230718.model.ventilatori.Ventilatore;

public class VistaVentilatore extends HBox {
    MainController mainController;
    Ventilatore ventilatore;

    public VistaVentilatore(MainController mainController, Ventilatore ventilatore) {
        super();
        this.mainController = mainController;
        this.ventilatore = ventilatore;

        draw();
    }

    public void draw() {
        super.getChildren().clear();
        Circle icon = new Circle(20);
        icon.setStrokeWidth(5);

        Color fillColor = mainController.isAbbonato(ventilatore) ? Color.RED : Color.BLUE;
        Color borderColor = mainController.puoPagare(ventilatore) ? Color.BLACK : Color.GRAY;

        icon.setFill(fillColor);
        icon.setStroke(borderColor);
        Text info = new Text(ventilatore.toString());

        super.getChildren().addAll(icon, info);
    }
}
