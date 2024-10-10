package org.example.esame_20230718.model.ventilatori;

import org.example.esame_20230718.model.ventilatori.eccezioni.VentilatoreSoffittoNonPuoEssereMeccanico;

public class VentilatoreMeccanico extends Ventilatore {
    public VentilatoreMeccanico(String marca, Tipologia tipologia) throws VentilatoreSoffittoNonPuoEssereMeccanico {
        super(marca, tipologia, "Meccanica");

        if (tipologia == Tipologia.SOFFITTO) {
            throw new VentilatoreSoffittoNonPuoEssereMeccanico();
        }
    }
}
