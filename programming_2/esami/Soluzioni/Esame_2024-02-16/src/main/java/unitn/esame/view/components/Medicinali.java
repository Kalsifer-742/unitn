package unitn.esame.view.components;

import javafx.scene.layout.VBox;
import javafx.scene.text.Text;
import unitn.esame.controller.MainController;
import unitn.esame.model.medicinali.Medicinale;
import unitn.esame.view.MainView;

import java.util.Iterator;

public class Medicinali extends VBox {
    public Medicinali(MainController mainController) {
        super();
        super.setSpacing(MainView.SPACING);

        Iterator<Medicinale> it = mainController.getMedicinaliIterator();
        int index = 0;
        while (it.hasNext()) {
            Medicinale medicinale = it.next();
            Text medicinaleTesto = new Text(medicinale.toString());
            medicinaleTesto.setOnMouseClicked(mouseEvent -> mainController.setMedicinaleDaComprare(medicinale));

            super.getChildren().add(medicinaleTesto);
            index++;
        }
    }
}
