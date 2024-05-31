package Model;

import javafx.scene.control.Alert;

/**
 * La classe AlertDisplayer fornisce un metodo statico per visualizzare un avviso di errore.
 */
public class AlertDisplayer {

    /**
     * Visualizza un avviso di errore con il messaggio specificato.
     *
     * @param s il messaggio di errore da visualizzare
     */
    public static void display_ERROR_Alert(String s) {
        Alert err = new Alert(Alert.AlertType.ERROR);
        err.setTitle("ERRORE!");
        err.setHeaderText("ATTENZIONE");
        err.setContentText(s);
        err.show();
    }
}
