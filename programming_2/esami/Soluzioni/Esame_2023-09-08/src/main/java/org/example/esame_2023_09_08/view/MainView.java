package org.example.esame_2023_09_08.view;

import javafx.geometry.Pos;
import javafx.scene.Group;
import javafx.scene.control.Button;
import javafx.scene.layout.BorderPane;
import javafx.scene.layout.HBox;
import org.example.esame_2023_09_08.controller.MainController;

public class MainView extends BorderPane {
    MainController mainController;
    TitlesView titlesView;
    TitleInfo titleInfo;

    public MainView(MainController mainController) {
        this.mainController = mainController;

        titlesView = new TitlesView(mainController);
        titleInfo = new TitleInfo(mainController);
        Button clearButton = new Button("Clear");
        clearButton.setOnMouseClicked(mouseEvent -> titleInfo.clear());
        SortingButtons sortingButtons = new SortingButtons(mainController);

        titlesView.setAlignment(Pos.CENTER);
        super.setTop(titlesView);
        super.setCenter(titleInfo);
        super.setLeft(clearButton);
        super.setRight(sortingButtons);
    }

    public void updateTitlesView() {
        titlesView.draw();
    }

    public void updateTitleInfo() {
        titleInfo.draw();
    }
}
