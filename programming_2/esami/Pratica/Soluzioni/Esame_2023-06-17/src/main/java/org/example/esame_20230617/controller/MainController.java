package org.example.esame_20230617.controller;

import org.example.esame_20230617.model.Geraldo;
import org.example.esame_20230617.model.mutazioni.Mutazione;
import org.example.esame_20230617.view.MainView;

public class MainController {
    private final Geraldo geraldo;
    private final MainView mainView;

    public MainController() {
        geraldo = new Geraldo();
        mainView = new MainView(this);
    }

    public MainView getMainView() {
        return mainView;
    }

    public String getGeraldoInfo() {
        return geraldo.toString();
    }

    public void applicaMutazione(Mutazione mutazione) {
        geraldo.applicaMutazione(mutazione);
        mainView.aggiornaGeraldoInfo();
        mainView.aggiornaMutazioniAttive();
        mainView.aggiornaMutazioniPossibili();
    }

    public void rimuoviMutazione(Mutazione mutazione) {
        geraldo.rimuoviMutazione(mutazione);
        mainView.aggiornaGeraldoInfo();
        mainView.aggiornaMutazioniAttive();
        mainView.aggiornaMutazioniPossibili();
    }
}
