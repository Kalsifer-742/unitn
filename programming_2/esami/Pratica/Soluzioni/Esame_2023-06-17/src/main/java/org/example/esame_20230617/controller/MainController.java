package org.example.esame_20230617.controller;

import org.example.esame_20230617.model.Geraldo;
import org.example.esame_20230617.view.MainView;

public class MainController {
    Geraldo geraldo;
    MainView mainView;

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
}
