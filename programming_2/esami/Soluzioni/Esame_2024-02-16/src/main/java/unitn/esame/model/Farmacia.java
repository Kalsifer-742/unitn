package unitn.esame.model;

import unitn.esame.model.medicinali.Medicinale;
import unitn.esame.model.medicinali.con_ricetta.MedicinaleConRicetta;
import unitn.esame.model.medicinali.MedicinaleDaBanco;
import unitn.esame.model.medicinali.con_ricetta.MedicinaleConRicettaNonRipetibile;
import unitn.esame.model.medicinali.con_ricetta.MedicinaleConRicettaRipetibile;

import java.util.ArrayList;
import java.util.Date;
import java.util.Iterator;

public class Farmacia {
    private float soldiUtente;
    private Date dataOdierna;

    private ArrayList<Medicinale> medicinali;
    private ArrayList<Ricetta> ricette;

    public Farmacia(float soldiUtente) {
        this.soldiUtente = soldiUtente;
        this.dataOdierna = new Date();
        medicinali = new ArrayList<>();
        ricette = new ArrayList<>();

        Date ieri = new Date(dataOdierna.getTime() - 100000000);
        Date domani = new Date(dataOdierna.getTime() + 100000000);

        medicinali.add(new MedicinaleDaBanco("Benagol", 10, domani));
        medicinali.add(new MedicinaleDaBanco("Brufen200", 8, domani));
        medicinali.add(new MedicinaleConRicettaNonRipetibile("Brufen80", 20, domani));
        medicinali.add(new MedicinaleConRicettaRipetibile("Oki", 12, domani, 4));
        medicinali.add(new MedicinaleConRicettaRipetibile("Fluifort", 18, ieri, 2));
        medicinali.add(new MedicinaleConRicettaRipetibile("Tachipirina1000", 6, domani, 3));

        ricette.add(new Ricetta("Brufen800", ieri));
        ricette.add(new Ricetta("Tachipirina1000", domani));
        ricette.add(new Ricetta("Fluifort", domani));
    }

    public float getSoldiUtente() {
        return soldiUtente;
    }

    public Date getDataOdierna() {
        return dataOdierna;
    }

    public Iterator<Medicinale> getMedicinaliIterator() {
        return medicinali.iterator();
    }

    public Iterator<Ricetta> getRicetteIterator() {
        return ricette.iterator();
    }

    public ArrayList<Ricetta> getRicette() {
        return ricette;
    }

    public void compraMedicinale(Medicinale medicinale) {
        soldiUtente -= medicinale.getprezzoScontato();
    }
}
