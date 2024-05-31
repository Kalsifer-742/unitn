package Model;

/**
 * L'interfaccia ElementoConScadenza rappresenta un elemento che ha una data di scadenza.
 */
public interface ElementoConScadenza {
    /**
     * Verifica se l'elemento è scaduto rispetto alla data corrente.
     *
     * @return true se l'elemento è scaduto, false altrimenti
     */
    boolean isScaduto();

    /**
     * Restituisce una stringa che indica se l'elemento è scaduto o la data di scadenza.
     *
     * @return una stringa che indica lo stato di scadenza dell'elemento
     */
    String scad();
}
