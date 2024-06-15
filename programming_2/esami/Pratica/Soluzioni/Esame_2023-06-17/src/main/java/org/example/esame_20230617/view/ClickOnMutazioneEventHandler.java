package org.example.esame_20230617.view;

import javafx.event.EventHandler;
import javafx.scene.input.MouseEvent;
import org.example.esame_20230617.controller.MainController;
import org.example.esame_20230617.model.mutazioni.Mutazione;

public class ClickOnMutazioneEventHandler implements EventHandler<MouseEvent> {
    private static MainController mainController;
    private final Mutazione mutazione;

    public ClickOnMutazioneEventHandler(Mutazione mutazione) {
        this.mutazione = mutazione;
    }

    public static void setMainController(MainController mainController) {
        ClickOnMutazioneEventHandler.mainController = mainController;
    }

    @Override
    public void handle(MouseEvent mouseEvent) {
        if (!mutazione.isAttiva()) {
            mainController.applicaMutazione(mutazione);
        } else {
            mainController.rimuoviMutazione(mutazione);
        }
    }
}
