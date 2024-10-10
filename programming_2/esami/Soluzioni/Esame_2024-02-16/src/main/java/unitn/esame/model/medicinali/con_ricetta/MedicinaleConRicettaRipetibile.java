package unitn.esame.model.medicinali.con_ricetta;

import java.util.Date;

public class MedicinaleConRicettaRipetibile extends MedicinaleConRicetta {
    protected final int numeroMaxRipetizioni;

    public MedicinaleConRicettaRipetibile(String nome, float costo, Date dataDiScadenza, int numeroRipetizioni) {
        super(nome, costo, dataDiScadenza);
        float sconto = 5;
        super.prezzoScontato = costo - sconto;

        this.numeroMaxRipetizioni = numeroRipetizioni;
    }

    public int getNumeroMaxRipetizioni() {
        return numeroMaxRipetizioni;
    }

    @Override
    public String toString() {
        return super.toString() + "Ripetibile fino a " + numeroMaxRipetizioni + " volte";
    }
}
