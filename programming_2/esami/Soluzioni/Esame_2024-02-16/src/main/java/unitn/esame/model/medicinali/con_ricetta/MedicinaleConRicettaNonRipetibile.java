package unitn.esame.model.medicinali.con_ricetta;

import java.util.Date;

public class MedicinaleConRicettaNonRipetibile extends MedicinaleConRicetta {
    public MedicinaleConRicettaNonRipetibile(String nome, float costo, Date dataDiScadenza) {
        super(nome, costo, dataDiScadenza);
        float sconto = 5;
        super.prezzoScontato = costo - sconto;
    }

    @Override
    public String toString() {
        return super.toString() + "Non ripetibile";
    }
}
