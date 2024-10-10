package org.example.esame_2023_09_08.view;

import javafx.geometry.Pos;
import javafx.scene.control.Alert;
import javafx.scene.control.Button;
import javafx.scene.layout.HBox;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import org.example.esame_2023_09_08.controller.MainController;
import org.example.esame_2023_09_08.model.Titolo;
import org.example.esame_2023_09_08.model.titoli.SerieTV;

public class TitleInfo extends VBox {
    MainController mainController;
    Button buyButton;

    public TitleInfo(MainController mainController) {
        super();
        this.mainController = mainController;
        buyButton = new Button();

        draw();
    }

    public void draw() {
        super.getChildren().clear();
        super.setAlignment(Pos.CENTER);

        if (mainController.getSelectedTitle() == null){
            return;
        }

        Titolo selectedTitle = mainController.getSelectedTitle();

        Text description = new Text(selectedTitle.toString());
        super.getChildren().add(description);

        if (selectedTitle instanceof SerieTV) {
            SerieTV selectedTVSerie = ((SerieTV) selectedTitle);

            HBox seasonsButtons = new HBox();
            seasonsButtons.setAlignment(Pos.CENTER);
            for (int i = 0; i < selectedTVSerie.getNumeroStagioni(); i++) {
                Button button = new Button("S" + i);
                int finalI = i;
                button.setOnMouseClicked(mouseEvent -> {
                    button.setDisable(true);
                    selectedTVSerie.setNumeroStagioniAcquistate(finalI + 1);
                    updatePrice(selectedTVSerie);
                });
                seasonsButtons.getChildren().add(button);
            }
            super.getChildren().add(seasonsButtons);
        }

        updatePrice(selectedTitle);
        buyButton.setOnMouseClicked(mouseEvent -> new Alert(Alert.AlertType.ERROR, "ERRORE: connessione non presente").show());
        super.getChildren().add(buyButton);
    }

    private void updatePrice(Titolo selectedTitle) {
        buyButton.setText("Acquista: " + selectedTitle.getPrezzo());
    }

    public void clear() {
        super.getChildren().clear();
    }
}
