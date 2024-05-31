package Model;

import java.util.Date;

/**
 * La classe astratta Medicina rappresenta una medicina con un nome, un costo, una data di scadenza e un prezzo scontato.
 * Implementa l'interfaccia ElementoConScadenza.
 */
public abstract class Medicina implements ElementoConScadenza{
    private String nome;
    private int costo;
    private Date scadenza;
    private int prezzoScontato;

    /**
     * Costruttore della classe Medicina.
     *
     * @param nome    il nome della medicina
     * @param costo   il costo base della medicina
     * @param scadenza la data di scadenza della medicina
     */
    public Medicina(String nome, int costo, Date scadenza) {
        this.nome = nome;
        this.costo = costo;
        this.scadenza = scadenza;
        prezzoScontato = costo;
    }

    /**
     * Restituisce il nome della medicina.
     *
     * @return il nome della medicina
     */
    public String getNome() {
        return nome;
    }

    /**
     * Imposta il prezzo scontato della medicina.
     *
     * @param prezzoScontato il prezzo scontato della medicina
     */
    public void setPrezzoScontato(int prezzoScontato) {
        this.prezzoScontato = prezzoScontato;
    }

    /**
     * Restituisce il costo base della medicina.
     *
     * @return il costo base della medicina
     */
    public int getCosto() {
        return costo;
    }

    /**
     * Verifica se la medicina è scaduta rispetto alla data corrente.
     *
     * @return true se la medicina è scaduta, false altrimenti
     */
    public boolean isScaduto() {
        Date oggi = new Date();
        return oggi.after(scadenza);
    }

    /**
     * Restituisce una stringa che indica se la medicina è scaduta o la data di scadenza.
     *
     * @return una stringa che indica lo stato di scadenza della medicina
     */
    public String scad(){
        if(isScaduto())
            return "scaduta";
        else
            return "scadenza: " + scadenza;
    }

    /**
     * Restituisce una rappresentazione in formato stringa della medicina, inclusi il nome, il costo base,
     * il prezzo scontato e lo stato di scadenza.
     *
     * @return una stringa che rappresenta la medicina
     */
    public String toString(){
        return  nome + "\n" +
                "costo base: " + costo + "$, Scontato a " + prezzoScontato + "$\n" +
                scad();
    }
}
