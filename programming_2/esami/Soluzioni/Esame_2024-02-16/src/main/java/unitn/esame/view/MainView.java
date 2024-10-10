package unitn.esame.view;

import javafx.scene.layout.BorderPane;
import unitn.esame.controller.MainController;
import unitn.esame.model.medicinali.Medicinale;
import unitn.esame.view.components.Compra;
import unitn.esame.view.components.Footer;
import unitn.esame.view.components.Medicinali;
import unitn.esame.view.components.Ricette;

public class MainView extends BorderPane {
    public static int SPACING = 10;
    Medicinali medicinali;
    Ricette ricette;
    Compra compra;
    Footer footer;

    public MainView(MainController mainController) {
        super();

        medicinali = new Medicinali(mainController);
        ricette = new Ricette(mainController);
        compra = new Compra(mainController);
        footer = new Footer(mainController);

        super.setLeft(medicinali);
        super.setRight(ricette);
        super.setCenter(compra);
        super.setBottom(footer);
    }

    public void clearCompra() {
        compra.clear();
    }

    public void clearRicette() {
        ricette.clear();
    }

    public void setMedicinaleDaComprare(Medicinale medicinale) {
        compra.setMedicinale(medicinale);
    }

    public void updateFooter() {
        footer.updateSoldi();
    }
}
