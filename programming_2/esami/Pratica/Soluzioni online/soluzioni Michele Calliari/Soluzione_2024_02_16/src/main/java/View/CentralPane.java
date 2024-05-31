package View;

import Controller.MainGUI;
import Model.*;
import Model.Medicine.ConRicetta;
import Model.Medicine.Ripetibile;
import javafx.geometry.Pos;
import javafx.scene.control.Button;
import javafx.scene.layout.VBox;
import javafx.scene.text.Text;

/**
 * La classe CentralPane rappresenta un pannello centrale che mostra le informazioni di una medicina
 * e permette di acquistare la medicina, estendendo la classe VBox di JavaFX.
 */
public class CentralPane extends VBox {
    private Text testo;
    private Ricetta ricetta;

    /**
     * Costruttore della classe CentralPane.
     *
     * @param ricetta l'istanza della ricetta da visualizzare e gestire
     * @param mg l'istanza del controller MainGUI
     */
    public CentralPane(Ricetta ricetta, MainGUI mg) {
        super();
        this.ricetta = ricetta;
        Medicina medicina = ricetta.getMedicina();
        testo = new Text(medicina.toString());
        Button bottone = new Button("Compra");
        setBottoneAction(bottone, mg);
        getChildren().addAll(testo, bottone);
        setAlignment(Pos.CENTER);
    }

    /**
     * Imposta l'azione del bottone per l'acquisto della medicina.
     *
     * @param bottone il bottone da impostare
     * @param mg l'istanza del controller MainGUI
     */
    private void setBottoneAction(Button bottone, MainGUI mg) {
        bottone.setOnAction(event -> {
            Medicina medicina = ricetta.getMedicina();
            if (medicina.getCosto() > mg.getBottomPane().getSoldi()) {
                AlertDisplayer.display_ERROR_Alert("Soldi insufficienti");
            } else if (medicina.isScaduto()) {
                AlertDisplayer.display_ERROR_Alert("Medicina scaduta");
            } else if (medicina instanceof ConRicetta && !mg.getFarmacia().getRicette().contains(ricetta)) {
                AlertDisplayer.display_ERROR_Alert("Non disponi la ricetta di questa medicina");
            } else if (medicina instanceof Ripetibile r && r.getRipetizioni() == 0) {
                AlertDisplayer.display_ERROR_Alert("Hai finito le ripetizioni per questa medicina");
            } else {
                mg.getBottomPane().aggiornaSoldi(-medicina.getCosto());
                if (medicina instanceof Ripetibile r) {
                    r.decrementaRipetizioni();
                }
                testo.setText(medicina.toString());
            }
        });
    }
}
