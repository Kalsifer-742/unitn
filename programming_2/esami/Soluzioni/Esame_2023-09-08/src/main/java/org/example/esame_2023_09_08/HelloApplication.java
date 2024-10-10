package org.example.esame_2023_09_08;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Scene;
import javafx.stage.Stage;
import org.example.esame_2023_09_08.controller.MainController;
import org.example.esame_2023_09_08.view.MainView;

import java.io.IOException;
import java.util.Date;

public class HelloApplication extends Application {
    @Override
    public void start(Stage stage) throws IOException {
        MainController mainController = new MainController();

        //Because this is an exercise i didn't bother cleaning up the code: checking visibility, class hierarchy ecc...

        Scene scene = new Scene(mainController.getMainView());
        stage.setTitle("StreamThis!");
        stage.setWidth(400);
        stage.setHeight(250);
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}