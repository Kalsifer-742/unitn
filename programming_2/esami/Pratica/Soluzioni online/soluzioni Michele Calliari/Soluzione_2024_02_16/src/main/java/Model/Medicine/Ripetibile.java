package Model.Medicine;

import Model.Medicine.ConRicetta;

import java.util.Date;

/**
 * La classe Ripetibile rappresenta una medicina con ricetta ripetibile,
 * che estende la classe ConRicetta.
 */
public class Ripetibile extends ConRicetta {
    private int ripetizioni;

    /**
     * Costruttore della classe Ripetibile.
     *
     * @param nome       il nome della medicina
     * @param costo      il costo base della medicina
     * @param scadenza   la data di scadenza della medicina
     * @param ripetizioni il numero di volte in cui la ricetta può essere ripetuta
     */
    public Ripetibile(String nome, int costo, Date scadenza, int ripetizioni) {
        super(nome, costo, scadenza);
        this.ripetizioni = ripetizioni;
    }

    /**
     * Restituisce il numero di ripetizioni rimanenti per la ricetta.
     *
     * @return il numero di ripetizioni rimanenti
     */
    public int getRipetizioni() {
        return ripetizioni;
    }

    /**
     * Decrementa il numero di ripetizioni rimanenti di uno.
     */
    public void decrementaRipetizioni() {
        ripetizioni--;
    }

    /**
     * Calcola lo sconto applicabile alla medicina ripetibile.
     * Imposta uno sconto fisso di 5 unità.
     */
    @Override
    public void calcolaSconto() {
        setSconto(5);
    }

    /**
     * Restituisce una rappresentazione in formato stringa della medicina ripetibile,
     * inclusi il nome, il costo base, il prezzo scontato, lo stato di scadenza e il numero di ripetizioni rimanenti.
     *
     * @return una stringa che rappresenta la medicina ripetibile
     */
    @Override
    public String toString() {
        return super.toString() + "Ripetibile fino a " + ripetizioni + " volte";
    }
}
