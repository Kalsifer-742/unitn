package org.example.esame_2023_09_08.view;

import javafx.scene.control.Button;
import javafx.scene.layout.Background;
import javafx.scene.layout.BackgroundFill;
import javafx.scene.layout.HBox;
import javafx.scene.layout.StackPane;
import javafx.scene.paint.Color;
import javafx.scene.text.Text;
import org.example.esame_2023_09_08.controller.MainController;
import org.example.esame_2023_09_08.model.Titolo;
import org.example.esame_2023_09_08.model.titoli.Anime;
import org.example.esame_2023_09_08.model.titoli.Film;
import org.example.esame_2023_09_08.model.titoli.SerieTV;

import java.util.LinkedList;

public class TitlesView extends HBox {
    MainController mainController;

    public TitlesView(MainController mainController) {
        super();
        this.mainController = mainController;

        draw();
    }

    class TitleView extends StackPane {
        Titolo titolo;
        MainController mainController;

        public TitleView(Titolo titolo){
            super();
            this.titolo = titolo;

            draw();
        }

        public void draw() {
            Text nome = new Text(titolo.getNome() + " (" + titolo.getAnno() + ")");

            super.setBackground(new Background(new BackgroundFill(getColor(), null, null)));
            super.setMaxSize(130, 40);
            super.getChildren().add(nome);
        }

        public Color getColor() {
            if (titolo instanceof Film) {
                return Color.CYAN;
            } else if (titolo instanceof Anime) {
                return Color.SALMON;
            } else if (titolo instanceof SerieTV) {
                return Color.MAGENTA;
            } else {
                return Color.BLACK;
            }
        }
    }

    public void draw() {
        super.getChildren().clear();

        Button prev = new Button("<");
        prev.setOnMouseClicked(mouseEvent -> mainController.prev());
        Button next = new Button(">");
        next.setOnMouseClicked(mouseEvent -> mainController.next());

        LinkedList<Titolo> titlesToShow = mainController.getTitlesToShow();
        super.getChildren().add(prev);
        for (Titolo titolo : titlesToShow) {
            TitleView tmp = new TitleView(titolo);
            tmp.setOnMouseClicked(mouseEvent -> mainController.setSelectedTitle(titolo));
            super.getChildren().add(tmp);
        }
        super.getChildren().add(next);
    }
}
