package unitn.esame.view.components;

import javafx.scene.control.Button;
import javafx.scene.layout.VBox;
import unitn.esame.controller.MainController;
import unitn.esame.model.Ricetta;
import unitn.esame.view.MainView;

import java.util.Iterator;

public class Ricette extends VBox {
    MainController mainController;

    public Ricette(MainController mainController) {
        super();
        super.setSpacing(MainView.SPACING);

        this.mainController = mainController;

        clear();
    }

    public void clear() {
        super.getChildren().clear();
        Iterator<Ricetta> it = mainController.getRicetteIterator();
        while (it.hasNext()) {
            Ricetta ricetta = it.next();
            Button button = new Button(ricetta.toString());
            button.setOnMouseClicked(mouseEvent -> {
                button.setDisable(true);
                button.setText(button.getText() + "\n(selezionata)");
                mainController.setRicettaSelezionata(ricetta);
            });

            if (ricetta.isScaduta()) {
                button.setDisable(true);
            }

            super.getChildren().add(button);
        }
    }
}
