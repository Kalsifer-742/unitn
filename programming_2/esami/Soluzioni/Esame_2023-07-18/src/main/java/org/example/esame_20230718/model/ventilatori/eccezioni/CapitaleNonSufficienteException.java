package org.example.esame_20230718.model.ventilatori.eccezioni;

public class CapitaleNonSufficienteException extends Exception {
    public CapitaleNonSufficienteException() {
        super("Capitale non sufficiente a pagare gli abbonamenti");
    }
}
