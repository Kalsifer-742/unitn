package Model.Medicine;

import Model.Medicina;

import java.util.Date;

/**
 * La classe Banco rappresenta una medicina che può essere acquistata senza ricetta,
 * estendendo la classe Medicina.
 */
public class Banco extends Medicina {

    /**
     * Costruttore della classe Banco.
     *
     * @param nome     il nome della medicina
     * @param costo    il costo base della medicina
     * @param scadenza la data di scadenza della medicina
     */
    public Banco(String nome, int costo, Date scadenza) {
        super(nome, costo, scadenza);
    }

    /**
     * Restituisce una rappresentazione in formato stringa della medicina da banco,
     * inclusi il nome, il costo base, il prezzo scontato e lo stato di scadenza.
     *
     * @return una stringa che rappresenta la medicina da banco
     */
    @Override
    public String toString() {
        return super.toString() + "\nMedicinale da banco";
    }
}
