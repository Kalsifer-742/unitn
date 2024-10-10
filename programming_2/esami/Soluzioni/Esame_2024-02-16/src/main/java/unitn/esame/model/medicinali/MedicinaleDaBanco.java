package unitn.esame.model.medicinali;

import java.util.Date;

public class MedicinaleDaBanco extends Medicinale {
    public MedicinaleDaBanco(String nome, float costo, Date dataDiScadenza) {
        super(nome, costo, dataDiScadenza);

        super.prezzoScontato = costo;
    }

    @Override
    public String toString() {
        return super.toString() + "Medicinale da banco";
    }
}
