package unitn.esame.view.components;

import javafx.scene.layout.HBox;
import javafx.scene.text.Text;
import unitn.esame.controller.MainController;
import unitn.esame.model.medicinali.Medicinale;
import unitn.esame.view.MainView;

public class Footer extends HBox {
    MainController mainController;
    Text soldi;

    public Footer (MainController mainController) {
        super();
        super.setSpacing(MainView.SPACING);
        this. mainController = mainController;

        soldi = new Text();
        Text dataOdierna = new Text("Data odierna: " + mainController.getDataCorrente());

        super.getChildren().addAll(soldi, dataOdierna);

        updateSoldi();
    }

    public void updateSoldi() {
        this.soldi.setText("$ totali: " + mainController.getSoldiUtente());
    }
}
