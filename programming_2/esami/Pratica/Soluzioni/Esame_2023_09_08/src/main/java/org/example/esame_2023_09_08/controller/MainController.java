package org.example.esame_2023_09_08.controller;

import javafx.scene.control.Alert;
import org.example.esame_2023_09_08.model.StreamingPlatform;
import org.example.esame_2023_09_08.model.TitleListExceptions.TitleListEndReachedException;
import org.example.esame_2023_09_08.model.TitleListExceptions.TitleListStartReachedException;
import org.example.esame_2023_09_08.model.Titolo;
import org.example.esame_2023_09_08.view.MainView;

import java.util.Comparator;
import java.util.LinkedList;

public class MainController {
    StreamingPlatform streamingPlatform;
    MainView mainView;
    Titolo selectedTitle;

    public MainController() {
        streamingPlatform = new StreamingPlatform();
        mainView = new MainView(this);
        selectedTitle = null;
    }

    public MainView getMainView() {
        return mainView;
    }

    public LinkedList<Titolo> getTitlesToShow() {
        return streamingPlatform.getTitlesToShow();
    }

    public void next() {
        try {
            streamingPlatform.next();
        } catch (TitleListEndReachedException e) {
            new Alert(Alert.AlertType.WARNING, e.getMessage()).show();
        }
        mainView.updateTitlesView();
    }

    public void prev() {
        try {
            streamingPlatform.prev();
        } catch (TitleListStartReachedException e) {
            new Alert(Alert.AlertType.WARNING, e.getMessage()).show();
        }
        mainView.updateTitlesView();
    }

    public void setSelectedTitle(Titolo selectedTitle) {
        this.selectedTitle = selectedTitle;
        mainView.updateTitleInfo();
    }

    public Titolo getSelectedTitle() {
        return selectedTitle;
    }

    public void sortTitles(Comparator<Titolo> comparator) {
        streamingPlatform.sortTitles(comparator);
        mainView.updateTitlesView();
    }
}
