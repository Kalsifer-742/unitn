package View;

import Model.Farmacia;
import Model.Medicina;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;

import java.util.ArrayList;

/**
 * La classe MedicinePane rappresenta un pannello che mostra le informazioni di tutte le medicine
 * disponibili in una farmacia, estendendo la classe VBox di JavaFX.
 */
public class MedicinePane extends VBox {

    /**
     * Costruttore della classe MedicinePane.
     *
     * @param farmacia l'istanza della farmacia da cui ottenere le medicine
     */
    public MedicinePane(Farmacia farmacia) {
        super();
        creaPane(farmacia);
    }

    /**
     * Crea il pannello aggiungendo un testo per ogni medicina disponibile in farmacia.
     *
     * @param farmacia l'istanza della farmacia da cui ottenere le medicine
     */
    private void creaPane(Farmacia farmacia) {
        getChildren().clear();
        ArrayList<Medicina> medicine = farmacia.getMedicine();
        for (Medicina med : medicine) {
            getChildren().add(new Text(med.toString()));
        }
        setSpacing(10);
    }
}
