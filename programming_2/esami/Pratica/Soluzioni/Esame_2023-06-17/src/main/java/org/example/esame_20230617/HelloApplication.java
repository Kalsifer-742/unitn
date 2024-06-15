package org.example.esame_20230617;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import org.example.esame_20230617.controller.MainController;

public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) {
        MainController mainController = new MainController();

        Scene scene = new Scene(mainController.getMainView());
        stage.setTitle("Enrico Dalla Croce");
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}