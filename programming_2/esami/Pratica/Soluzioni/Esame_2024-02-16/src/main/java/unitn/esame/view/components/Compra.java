package unitn.esame.view.components;

import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import unitn.esame.controller.MainController;
import unitn.esame.model.medicinali.Medicinale;

public class Compra extends VBox {
    Medicinale medicinale;
    Text testoMedicinale;

    public Compra(MainController mainController) {
        super();
        super.setAlignment(Pos.CENTER);

        testoMedicinale = new Text();
        Button buttonCompra = new Button("Compra");
        buttonCompra.setOnMouseClicked(mouseEvent -> {
            if (medicinale != null) {
                mainController.compraMedicinale(medicinale);
            }
        });

        super.getChildren().addAll(testoMedicinale, buttonCompra);

        clear();
    }

    public void clear() {
        testoMedicinale.setText("");
    }

    public void setMedicinale(Medicinale medicinale) {
        this.medicinale = medicinale;
        testoMedicinale.setText(medicinale.toString());
    }
}
