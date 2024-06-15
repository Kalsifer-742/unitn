package org.example.esame_20230617.model;

public interface InterfacciaMutazione {
    void applica(Geraldo geraldo);
    void rimuovi(Geraldo geraldo);
    boolean isAttiva();
}
