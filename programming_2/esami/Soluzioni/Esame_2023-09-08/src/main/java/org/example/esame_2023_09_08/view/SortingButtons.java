package org.example.esame_2023_09_08.view;

import javafx.scene.control.Button;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import org.example.esame_2023_09_08.controller.MainController;
import org.example.esame_2023_09_08.model.comparators.OrderByNameComparator;
import org.example.esame_2023_09_08.model.comparators.OrderByTypeComparator;
import org.example.esame_2023_09_08.model.comparators.OrderByYearComparator;

public class SortingButtons extends VBox {
    MainController mainController;

    public SortingButtons(MainController mainController) {
        super();
        this.mainController = mainController;

        super.setSpacing(10);
        draw();
    }

    public void draw() {
        Text info = new Text("Ordina per:");
        Button sortByName = new Button("Nome");
        Button sortByYear = new Button("Anno");
        Button sortByType = new Button("Tipo");

        sortByName.setOnMouseClicked(mouseEvent -> mainController.sortTitles(new OrderByNameComparator()));
        sortByYear.setOnMouseClicked(mouseEvent -> mainController.sortTitles(new OrderByYearComparator()));
        sortByType.setOnMouseClicked(mouseEvent -> mainController.sortTitles(new OrderByTypeComparator()));

        super.getChildren().addAll(info, sortByName, sortByYear, sortByType);
    }
}
