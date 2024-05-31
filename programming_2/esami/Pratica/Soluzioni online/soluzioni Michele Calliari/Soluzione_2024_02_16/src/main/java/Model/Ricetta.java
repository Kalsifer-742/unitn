package Model;

import java.util.Date;

/**
 * La classe Ricetta rappresenta una ricetta medica associata ad una medicina con una data di scadenza.
 * Implementa l'interfaccia ElementoConScadenza.
 */
public class Ricetta implements ElementoConScadenza {
    private Medicina medicina;
    private Date scadenza;

    /**
     * Costruttore della classe Ricetta.
     *
     * @param medicina la medicina associata alla ricetta
     * @param scadenza la data di scadenza della ricetta
     */
    public Ricetta(Medicina medicina, Date scadenza) {
        this.medicina = medicina;
        this.scadenza = scadenza;
    }

    /**
     * Restituisce la medicina associata alla ricetta.
     *
     * @return la medicina associata
     */
    public Medicina getMedicina() {
        return medicina;
    }

    /**
     * Verifica se la ricetta è scaduta rispetto alla data corrente.
     *
     * @return true se la ricetta è scaduta, false altrimenti
     */
    public boolean isScaduto() {
        Date oggi = new Date();
        return oggi.after(scadenza);
    }

    /**
     * Restituisce una stringa che indica se la ricetta è scaduta o la data di scadenza.
     *
     * @return una stringa che indica lo stato di scadenza della ricetta
     */
    public String scad() {
        if (isScaduto())
            return "scaduta";
        else
            return "valida fino al: " + scadenza;
    }

    /**
     * Restituisce una rappresentazione in formato stringa della ricetta, inclusi il nome della medicina
     * e lo stato di scadenza.
     *
     * @return una stringa che rappresenta la ricetta
     */
    public String toString() {
        return "Ricetta per: " + medicina.getNome() + "\n" +
                scad();
    }
}
