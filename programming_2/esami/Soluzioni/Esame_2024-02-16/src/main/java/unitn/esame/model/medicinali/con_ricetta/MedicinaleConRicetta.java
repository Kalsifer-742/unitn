package unitn.esame.model.medicinali.con_ricetta;

import unitn.esame.model.medicinali.Medicinale;

import java.util.Date;

public abstract class MedicinaleConRicetta extends Medicinale {
    public MedicinaleConRicetta(String nome, float costo, Date dataDiScadenza) {
        super(nome, costo, dataDiScadenza);
    }

    @Override
    public String toString() {
        return super.toString() + "Con ricetta: ";
    }
}
