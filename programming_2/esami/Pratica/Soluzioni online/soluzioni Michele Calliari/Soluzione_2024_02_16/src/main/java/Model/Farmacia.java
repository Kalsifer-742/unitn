package Model;

import Model.Medicine.Banco;
import Model.Medicine.NonRipetibile;
import Model.Medicine.Ripetibile;

import java.util.ArrayList;
import java.util.Date;

/**
 * La classe Farmacia rappresenta una farmacia con una lista di ricette e una lista di medicine.
 */
public class Farmacia {
    private ArrayList<Ricetta> ricette;
    private ArrayList<Medicina> medicine;

    /**
     * Costruttore della classe Farmacia.
     * Inizializza le liste di ricette e medicine con alcuni dati di esempio.
     */
    public Farmacia() {
        ricette = new ArrayList<>();
        medicine = new ArrayList<>();

        Date d = new Date();
        Date domani = new Date(d.getTime() + 100000000);
        Date ieri = new Date(d.getTime() - 100000000);

        // Creo medicine
        Medicina Benagol = new Banco("Benagol", 10, domani);
        Medicina Brufen200 = new Banco("Brufen200", 8, domani);
        Medicina Brufen800 = new NonRipetibile("Brufen800", 20, ieri);
        Medicina Oki = new Ripetibile("Oki", 12, domani, 4);
        Medicina Fluifort = new Ripetibile("Fluifort", 18, ieri, 3);
        Medicina Tachipirina1000 = new Ripetibile("Tachipirina1000", 6, domani, 2);

        // Creo ricette
        Ricetta ricBrufen800 = new Ricetta(Brufen800, ieri);
        Ricetta ricTachipirina1000 = new Ricetta(Tachipirina1000, domani);
        Ricetta ricFluifort = new Ricetta(Fluifort, domani);

        // Inserisco medicine
        medicine.add(Benagol);
        medicine.add(Brufen200);
        medicine.add(Brufen800);
        medicine.add(Oki);
        medicine.add(Fluifort);
        medicine.add(Tachipirina1000);

        // Inserisco ricette
        ricette.add(ricBrufen800);
        ricette.add(ricFluifort);
        ricette.add(ricTachipirina1000);
    }

    /**
     * Restituisce la lista di ricette della farmacia.
     *
     * @return la lista di ricette
     */
    public ArrayList<Ricetta> getRicette() {
        return ricette;
    }

    /**
     * Restituisce la lista di medicine della farmacia.
     *
     * @return la lista di medicine
     */
    public ArrayList<Medicina> getMedicine() {
        return medicine;
    }
}
