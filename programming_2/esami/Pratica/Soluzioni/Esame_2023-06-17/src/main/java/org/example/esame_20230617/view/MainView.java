package org.example.esame_20230617.view;

import javafx.geometry.Insets;
import javafx.scene.layout.BorderPane;
import javafx.scene.text.Text;
import org.example.esame_20230617.controller.MainController;
import org.example.esame_20230617.model.mutazioni.Mutazione;
import org.example.esame_20230617.model.mutazioni.combattimento.MutazioneCombattimentoForza;
import org.example.esame_20230617.model.mutazioni.combattimento.MutazioneCombattimentoVelocita;
import org.example.esame_20230617.model.mutazioni.magia.MutazioneMagiaDifesa;
import org.example.esame_20230617.model.mutazioni.magia.MutazioneMagiaFuoco;
import org.example.esame_20230617.model.mutazioni.pozione.MutazionePozioneTolleranza;

import java.util.LinkedList;

public class MainView extends BorderPane {
    private final MainController mainController;
    private final MutazioniAttive mutazioniAttive;
    private final MutazioniPossibili mutazioniPossibili;
    private final Text geraldoInfo;

    public MainView(MainController mainController) {
        super();
        this.mainController = mainController;
        LinkedList<Mutazione> mutazioni = new LinkedList<>();
        mutazioni.add(new MutazioneCombattimentoForza());
        mutazioni.add(new MutazioneCombattimentoVelocita());
        mutazioni.add(new MutazionePozioneTolleranza());
        mutazioni.add(new MutazioneMagiaDifesa());
        mutazioni.add(new MutazioneMagiaFuoco());
        ClickOnMutazioneEventHandler.setMainController(mainController);

        geraldoInfo = new Text(mainController.getGeraldoInfo());
        mutazioniPossibili = new MutazioniPossibili(mutazioni);
        mutazioniAttive = new MutazioniAttive(mutazioni);

        super.setPadding(new Insets(10, 10, 10, 10));
        super.setLeft(geraldoInfo);
        super.setRight(mutazioniAttive);
        super.setBottom(mutazioniPossibili);
    }

    public void aggiornaGeraldoInfo() {
        geraldoInfo.setText(mainController.getGeraldoInfo());
    }

    public void aggiornaMutazioniAttive() {
        mutazioniAttive.draw();
    }

    public void aggiornaMutazioniPossibili() {
        mutazioniPossibili.draw();
    }
}
