package org.example.esame_20230718.controller;

import javafx.scene.control.Alert;
import org.example.esame_20230718.model.SoloVentilatori;
import org.example.esame_20230718.model.ventilatori.Ventilatore;
import org.example.esame_20230718.model.ventilatori.eccezioni.CapitaleNonSufficienteException;
import org.example.esame_20230718.view.MainView;

import java.util.Comparator;
import java.util.LinkedList;

public class MainController {
    SoloVentilatori soloVentilatori;
    MainView mainView;

    public MainController() {
        soloVentilatori = new SoloVentilatori();
        mainView = new MainView(this);
    }

    public MainView getMainView() {
        return mainView;
    }

    public String getUserInfo() {
        return soloVentilatori.getUserInfo();
    }

    public LinkedList<Ventilatore> getVentilatori() {
        return soloVentilatori.getVentilatori();
    }

    public boolean isAbbonato(Ventilatore ventilatore) {
        return soloVentilatori.isAbbonato(ventilatore);
    }

    public boolean puoPagare(Ventilatore ventilatore) {
        return soloVentilatori.puoPagare(ventilatore);
    }

    public void aggiungiAbbonamento(Ventilatore ventilatore) {
        soloVentilatori.aggiungiAbbonamento(ventilatore);
        mainView.aggiornaCatalogoVentilatori();
        mainView.aggiornaInfo();
    }

    public void ordinaVentilatori(Comparator<Ventilatore> comparator) {
        soloVentilatori.ordinaVentilatori(comparator);
        mainView.aggiornaCatalogoVentilatori();
    }

    public void aggiungiFondi(double fondi) {
        soloVentilatori.aggiungiFondi(fondi);
        mainView.aggiornaInfo();
    }

    public void avanzaMese() {
        try {
            soloVentilatori.avanzaMese();
        } catch (CapitaleNonSufficienteException e) {
            new Alert(Alert.AlertType.WARNING, e.getMessage()).show();
        } finally {
            mainView.aggiornaCatalogoVentilatori();
        }
        mainView.aggiornaInfo();
    }
}
