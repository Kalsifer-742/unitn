package View;

import Controller.MainGUI;
import Model.Farmacia;
import Model.Ricetta;
import javafx.scene.Node;
import javafx.scene.control.Button;
import javafx.scene.layout.VBox;
import java.util.ArrayList;

/**
 * La classe BottoniPane rappresenta un pannello che contiene bottoni per ogni ricetta disponibile in farmacia,
 * estendendo la classe VBox di JavaFX.
 */
public class BottoniPane extends VBox {
    private MainGUI mg;

    /**
     * Costruttore della classe BottoniPane.
     *
     * @param mg l'istanza del controller MainGUI
     */
    public BottoniPane(MainGUI mg) {
        super();
        this.mg = mg;
        Farmacia farmacia = mg.getFarmacia();
        creaBottoni(farmacia);
    }

    /**
     * Crea i bottoni per ogni ricetta disponibile in farmacia.
     *
     * @param farmacia l'istanza della farmacia da cui ottenere le ricette
     */
    private void creaBottoni(Farmacia farmacia) {
        ArrayList<Ricetta> ricette = farmacia.getRicette();
        for (Ricetta r : ricette) {
            Button b = new Button(r.toString());
            if (r.isScaduto()) {
                b.setDisable(true);
            } else {
                attivaBottone(b, r);
            }
            getChildren().add(b);
        }
        setSpacing(10);
    }

    /**
     * Attiva il bottone associato a una ricetta, impostando l'azione da eseguire quando viene cliccato.
     *
     * @param b il bottone da attivare
     * @param r la ricetta associata al bottone
     */
    private void attivaBottone(Button b, Ricetta r) {
        b.setOnAction(event -> {
            abilitaAltri();
            b.setDisable(true);
            b.setText(b.getText() + "\n(selezionata)");
            mg.setCentro(r);
        });
    }

    /**
     * Abilita tutti gli altri bottoni disabilitati, tranne quelli con ricette scadute,
     * e rimuove il testo "(selezionata)" dai bottoni precedentemente selezionati.
     */
    private void abilitaAltri() {
        for (Node n : getChildren()) {
            if (n instanceof Button b) {
                if (!b.getText().contains("scaduta") && b.isDisabled()) {
                    b.setDisable(false);
                    b.setText(b.getText().replace("\n(selezionata)", ""));
                }
            }
        }
    }
}
