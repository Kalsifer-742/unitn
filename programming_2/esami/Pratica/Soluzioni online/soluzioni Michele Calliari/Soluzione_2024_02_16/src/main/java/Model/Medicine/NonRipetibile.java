package Model.Medicine;

import java.util.Date;

/**
 * La classe NonRipetibile rappresenta una medicina con ricetta non ripetibile,
 * che estende la classe ConRicetta.
 */
public class NonRipetibile extends ConRicetta {

    /**
     * Costruttore della classe NonRipetibile.
     *
     * @param nome     il nome della medicina
     * @param costo    il costo base della medicina
     * @param scadenza la data di scadenza della medicina
     */
    public NonRipetibile(String nome, int costo, Date scadenza) {
        super(nome, costo, scadenza);
    }

    /**
     * Calcola lo sconto applicabile alla medicina non ripetibile.
     * Imposta uno sconto fisso di 10 unità.
     */
    @Override
    public void calcolaSconto() {
        setSconto(10);
    }

    /**
     * Restituisce una rappresentazione in formato stringa della medicina non ripetibile,
     * inclusi il nome, il costo base, il prezzo scontato, lo stato di scadenza e la dicitura "Non Ripetibile".
     *
     * @return una stringa che rappresenta la medicina non ripetibile
     */
    @Override
    public String toString() {
        return super.toString() + "Non Ripetibile";
    }
}
