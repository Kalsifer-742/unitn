package org.example.esame_20230718.model;

import org.example.esame_20230718.model.ventilatori.Tipologia;
import org.example.esame_20230718.model.ventilatori.Ventilatore;
import org.example.esame_20230718.model.ventilatori.VentilatoreMeccanico;
import org.example.esame_20230718.model.ventilatori.eccezioni.CapitaleNonSufficienteException;
import org.example.esame_20230718.model.ventilatori.eccezioni.VentilatoreSoffittoNonPuoEssereMeccanico;
import org.example.esame_20230718.model.ventilatori.elettrici.VentilatoreElettricoConBatteria;
import org.example.esame_20230718.model.ventilatori.elettrici.VentilatoreElettricoConPresa;

import java.util.Comparator;
import java.util.LinkedList;

public class SoloVentilatori {
    private double capitaleUtente;
    private double spesaMensile;
    private int mesiTrascorsi;
    LinkedList<Ventilatore> ventilatori;
    LinkedList<Ventilatore> ventilatoriAbbonati;

    public SoloVentilatori() {
        capitaleUtente = 100;
        spesaMensile = 0;
        mesiTrascorsi = 0;
        ventilatori = new LinkedList<>();
        ventilatoriAbbonati = new LinkedList<>();

        ventilatori.add(new VentilatoreElettricoConBatteria("Ariete", Tipologia.PIATANA));
        ventilatori.add(new VentilatoreElettricoConPresa("Bosch", Tipologia.PARETE));
        try {
            ventilatori.add(new VentilatoreMeccanico("Bosch", Tipologia.PARETE));
        } catch (VentilatoreSoffittoNonPuoEssereMeccanico e) {
            System.err.println(e.getMessage());
        }
        ventilatori.add(new VentilatoreElettricoConBatteria("Bosch", Tipologia.SOFFITTO));
        ventilatori.add(new VentilatoreElettricoConPresa("Parkside", Tipologia.SOFFITTO));
    }

    public LinkedList<Ventilatore> getVentilatori() {
        return ventilatori;
    }

    public String getUserInfo() {
        return "Capitale: " + capitaleUtente + " Spesa Mensile: " + spesaMensile + " Mesi Trascorsi: " + mesiTrascorsi;
    }

    public boolean isAbbonato(Ventilatore ventilatore) {
        return ventilatoriAbbonati.contains(ventilatore);
    }

    public boolean puoPagare(Ventilatore ventilatore) {
        return ventilatore.getCosto() < capitaleUtente;
    }

    public void aggiungiAbbonamento(Ventilatore ventilatore) {
        ventilatoriAbbonati.add(ventilatore);
        aggiornaSpesaMensile();
    }

    public void ordinaVentilatori(Comparator<Ventilatore> comparator) {
        ventilatori.sort(comparator);
    }

    public void aggiungiFondi(double fondi) {
        capitaleUtente += fondi;
    }

    public void avanzaMese() throws CapitaleNonSufficienteException {
        if (!ventilatoriAbbonati.isEmpty()) {
            double nuovoCapitaleSimulato = capitaleUtente;

            for (Ventilatore ventilatore : ventilatoriAbbonati) {
                nuovoCapitaleSimulato -= ventilatore.getCosto();
            }

            if (nuovoCapitaleSimulato < 0) {
                ventilatoriAbbonati.sort((Comparator.comparingDouble(Ventilatore::getCosto)));
                ventilatoriAbbonati.removeLast();
                aggiornaSpesaMensile();

                throw new CapitaleNonSufficienteException();
            } else {
                capitaleUtente = nuovoCapitaleSimulato;
            }
        }

        mesiTrascorsi += 1;
    }

    private void aggiornaSpesaMensile() {
        spesaMensile = 0;

        for (Ventilatore v: ventilatoriAbbonati) {
            spesaMensile += v.getCosto();
        }
    }
}
