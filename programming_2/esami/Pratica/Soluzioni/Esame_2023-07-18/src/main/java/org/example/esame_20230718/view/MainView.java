package org.example.esame_20230718.view;

import javafx.scene.layout.BorderPane;
import javafx.scene.text.Text;
import org.example.esame_20230718.controller.MainController;

public class MainView extends BorderPane {
    MainController mainController;
    CatalogoVentilatori catalogoVentilatori;
    Text info;

    public MainView(MainController mainController) {
        super();
        this.mainController = mainController;

        info = new Text(mainController.getUserInfo());
        catalogoVentilatori = new CatalogoVentilatori(mainController);
        BottoniOrdinamento bottoniOrdinamento = new BottoniOrdinamento(mainController);
        BottoniDebug bottoniDebug = new BottoniDebug(mainController);

        super.setTop(info);
        super.setCenter(catalogoVentilatori);
        super.setRight(bottoniOrdinamento);
        super.setLeft(bottoniDebug);
    }

    public void aggiornaCatalogoVentilatori() {
        catalogoVentilatori.draw();
    }

    public void aggiornaInfo() {
        info.setText(mainController.getUserInfo());
    }
}
