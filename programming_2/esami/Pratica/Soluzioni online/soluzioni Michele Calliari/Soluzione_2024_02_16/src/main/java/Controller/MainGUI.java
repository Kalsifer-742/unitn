package Controller;

import Model.Farmacia;
import Model.Ricetta;
import View.BottomPane;
import View.BottoniPane;
import View.CentralPane;
import View.MedicinePane;
import javafx.scene.layout.AnchorPane;

/**
 * La classe MainGUI rappresenta l'interfaccia grafica principale della farmacia,
 * estendendo la classe AnchorPane di JavaFX.
 */
public class MainGUI extends AnchorPane {
    private Farmacia farmacia;
    private MedicinePane medicinePane;
    private BottomPane bottomPane;
    private BottoniPane bottoniPane;

    /**
     * Costruttore della classe MainGUI.
     * Inizializza la farmacia e i pannelli dell'interfaccia grafica, e li aggiunge all'AnchorPane.
     */
    public MainGUI() {
        super();
        farmacia = new Farmacia();
        medicinePane = new MedicinePane(farmacia);
        bottomPane = new BottomPane();
        bottoniPane = new BottoniPane(this);

        getChildren().addAll(medicinePane, bottomPane, bottoniPane);

        AnchorPane.setLeftAnchor(medicinePane, 0.0);
        AnchorPane.setTopAnchor(medicinePane, 0.0);

        AnchorPane.setLeftAnchor(bottomPane, 0.0);
        AnchorPane.setBottomAnchor(bottomPane, 0.0);

        AnchorPane.setRightAnchor(bottoniPane, 0.0);
        AnchorPane.setTopAnchor(bottoniPane, 0.0);
    }

    /**
     * Restituisce il pannello inferiore che mostra il saldo e la data odierna.
     *
     * @return il pannello inferiore
     */
    public BottomPane getBottomPane() {
        return bottomPane;
    }

    /**
     * Restituisce l'istanza della farmacia.
     *
     * @return l'istanza della farmacia
     */
    public Farmacia getFarmacia() {
        return farmacia;
    }

    /**
     * Imposta e mostra il pannello centrale con le informazioni della ricetta selezionata.
     *
     * @param r la ricetta selezionata
     */
    public void setCentro(Ricetta r) {
        if (getChildren().get(getChildren().size() - 1) instanceof CentralPane) {
            getChildren().remove(getChildren().size() - 1);
        }
        CentralPane cp = new CentralPane(r, this);
        getChildren().add(cp);
        AnchorPane.setLeftAnchor(cp, 260.0);
        AnchorPane.setTopAnchor(cp, 200.0);
    }
}
