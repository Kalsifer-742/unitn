package View;

import javafx.scene.layout.HBox;
import javafx.scene.text.Text;
import java.util.Date;

/**
 * La classe BottomPane rappresenta un pannello inferiore che mostra il saldo corrente
 * e la data odierna, estendendo la classe HBox di JavaFX.
 */
public class BottomPane extends HBox {
    private int soldi;
    private Text soldiText;
    private Text data;

    /**
     * Costruttore della classe BottomPane.
     * Inizializza il saldo a 30 e imposta i testi per il saldo e la data odierna.
     */
    public BottomPane() {
        super();
        soldi = 30;
        data = new Text();
        soldiText = new Text();
        aggiornaSoldi(0);

        getChildren().addAll(soldiText, data);
    }

    /**
     * Restituisce il saldo corrente.
     *
     * @return il saldo corrente
     */
    public int getSoldi() {
        return soldi;
    }

    /**
     * Aggiorna il saldo aggiungendo la somma specificata e aggiorna i testi per il saldo
     * e la data odierna.
     *
     * @param somma la somma da aggiungere al saldo corrente
     */
    public void aggiornaSoldi(int somma) {
        soldi += somma;
        Date d = new Date();
        soldiText.setText("$ totali: " + soldi);
        data.setText("Data Odierna: " + d);
        setSpacing(10);
    }
}
