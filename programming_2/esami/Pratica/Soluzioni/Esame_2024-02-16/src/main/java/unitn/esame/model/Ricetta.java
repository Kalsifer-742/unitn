package unitn.esame.model;

import unitn.esame.model.medicinali.Scadenza;

import java.util.Date;

public class Ricetta implements Scadenza {
    private final String nomeMedicina;
    private final Date dataDiScandeza;
    private int numeroUsi;

    public Ricetta(String nomeMedicina, Date dataDiScandeza) {
        this.nomeMedicina = nomeMedicina;
        this.dataDiScandeza = dataDiScandeza;
    }

    public String getNomeMedicina() {
        return nomeMedicina;
    }

    public int getNumeroUsi() {
        return numeroUsi;
    }

    public void updateNumeroUsi() {
        numeroUsi += 1;
    }

    @Override
    public String toString() {
        return "Ricetta per: " + nomeMedicina + "\n" + (isScaduta() ? "scaduta" : "valida fino al" + dataDiScandeza);
    }

    @Override
    public boolean isScaduta() {
        return dataDiScandeza.before(new Date());
    }
}
