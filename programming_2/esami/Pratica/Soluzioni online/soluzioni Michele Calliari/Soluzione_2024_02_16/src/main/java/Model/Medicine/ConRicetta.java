package Model.Medicine;

import Model.Medicina;

import java.util.Date;

/**
 * La classe astratta ConRicetta rappresenta una medicina che richiede una ricetta,
 * estendendo la classe Medicina. Gestisce lo sconto applicabile alla medicina.
 */
public abstract class ConRicetta extends Medicina {
    private int sconto;

    /**
     * Costruttore della classe ConRicetta.
     *
     * @param nome     il nome della medicina
     * @param costo    il costo base della medicina
     * @param scadenza la data di scadenza della medicina
     */
    public ConRicetta(String nome, int costo, Date scadenza) {
        super(nome, costo, scadenza);
        sconto = 0;
        calcolaSconto();
        applicaSconto();
    }

    /**
     * Metodo astratto per calcolare lo sconto applicabile alla medicina.
     * Questo metodo deve essere implementato dalle classi concrete.
     */
    public abstract void calcolaSconto();

    /**
     * Imposta il valore dello sconto.
     *
     * @param sconto il valore dello sconto da applicare
     */
    public void setSconto(int sconto) {
        this.sconto = sconto;
    }

    /**
     * Applica lo sconto al prezzo della medicina, aggiornando il prezzo scontato.
     */
    private void applicaSconto() {
        setPrezzoScontato(getCosto() - sconto);
    }

    /**
     * Restituisce una rappresentazione in formato stringa della medicina con ricetta,
     * inclusi il nome, il costo base, il prezzo scontato e lo stato di scadenza.
     *
     * @return una stringa che rappresenta la medicina con ricetta
     */
    @Override
    public String toString() {
        return super.toString() + "\nCon Ricetta: ";
    }
}
