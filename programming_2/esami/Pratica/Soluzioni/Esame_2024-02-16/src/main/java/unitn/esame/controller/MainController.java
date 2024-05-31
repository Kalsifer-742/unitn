package unitn.esame.controller;

import javafx.scene.control.Alert;
import unitn.esame.model.Farmacia;
import unitn.esame.model.Ricetta;
import unitn.esame.model.medicinali.Medicinale;
import unitn.esame.model.medicinali.MedicinaleDaBanco;
import unitn.esame.model.medicinali.con_ricetta.MedicinaleConRicettaRipetibile;
import unitn.esame.view.MainView;

import java.util.Date;
import java.util.Iterator;

public class MainController {
    private final MainView mainView;
    private final Farmacia farmacia;
    private Ricetta ricettaSelezionata;

    public MainController() {
        farmacia = new Farmacia(100);
        mainView = new MainView(this);
    }

    public MainView getMainView() {
        return mainView;
    }

    public float getSoldiUtente() {
        return farmacia.getSoldiUtente();
    }

    public Date getDataCorrente() {
        return farmacia.getDataOdierna();
    }

    public Iterator<Medicinale> getMedicinaliIterator() {
        return farmacia.getMedicinaliIterator();
    }

    public Iterator<Ricetta> getRicetteIterator() {
        return farmacia.getRicetteIterator();
    }

    public void setRicettaSelezionata(Ricetta ricetta) {
        ricettaSelezionata = ricetta;
    }

    public void setMedicinaleDaComprare(Medicinale medicinale) {
        mainView.setMedicinaleDaComprare(medicinale);
    }

    public void compraMedicinale(Medicinale medicinale) {
        if (farmacia.getSoldiUtente() - medicinale.getprezzoScontato() < 0) {
            new Alert(Alert.AlertType.ERROR, "soldi insufficienti").show();
            return;
        }

        if (medicinale.isScaduta()) {
            new Alert(Alert.AlertType.ERROR, "medicinale scaduto").show();
            return;
        }

        if (ricettaSelezionata == null) {
            new Alert(Alert.AlertType.ERROR, "nessuna ricetta selezionata").show();
            return;
        }

        if (farmacia.getRicette().contains(new Ricetta(medicinale.getNome(), medicinale.getDataDiScadenza()))) {
            new Alert(Alert.AlertType.ERROR, "ricetta non disponibile").show();
            return;
        }

        if (!medicinale.getNome().equals(ricettaSelezionata.getNomeMedicina())) {
            new Alert(Alert.AlertType.ERROR, "selezionare la ricetta corretta").show();
            return;
        }

        if (medicinale instanceof MedicinaleConRicettaRipetibile && ricettaSelezionata.getNumeroUsi() > ((MedicinaleConRicettaRipetibile) medicinale).getNumeroMaxRipetizioni()) {
            new Alert(Alert.AlertType.ERROR, "ricetta usata troppe volte").show();
            return;
        }

        farmacia.compraMedicinale(medicinale);
        mainView.clearCompra();
        mainView.clearRicette();
        mainView.updateFooter();
    }
}