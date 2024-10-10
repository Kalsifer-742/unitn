package org.example.esame_20230718.model.ventilatori.eccezioni;

public class VentilatoreSoffittoNonPuoEssereMeccanico extends Exception{
    public VentilatoreSoffittoNonPuoEssereMeccanico() {
        super("I ventilatori a soffitto non possono essere meccanici");
    }
}
