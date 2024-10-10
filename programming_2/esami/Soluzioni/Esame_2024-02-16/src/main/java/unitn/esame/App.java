package unitn.esame;

import javafx.application.Application;
import javafx.scene.Scene;
import javafx.stage.Stage;
import unitn.esame.controller.MainController;

public class App extends Application {
    @Override
    public void start(Stage stage) {
        MainController mainController = new MainController();

        Scene scene = new Scene(mainController.getMainView());
        stage.setTitle("Farmacia");
        stage.setWidth(750);
        stage.setHeight(500);
        stage.setScene(scene);
        stage.show();
    }

    public static void main(String[] args) {
        launch();
    }
}