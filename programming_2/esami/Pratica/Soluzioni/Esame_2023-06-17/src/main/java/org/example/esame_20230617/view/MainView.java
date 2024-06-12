package org.example.esame_20230617.view;

import javafx.scene.layout.BorderPane;
import javafx.scene.text.Text;
import org.example.esame_20230617.controller.MainController;

public class MainView extends BorderPane {
    public MainView(MainController mainController) {
        super();

        Text geraldoInfo = new Text(mainController.getGeraldoInfo());

        super.setLeft(geraldoInfo);
    }
}
