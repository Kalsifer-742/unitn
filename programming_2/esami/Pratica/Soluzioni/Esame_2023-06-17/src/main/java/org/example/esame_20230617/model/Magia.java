package org.example.esame_20230617.model;

public class Magia {
    String nome;

    public Magia(String nome) {
        this.nome = nome;
    }

    public String getNome() {
        return nome;
    }

    @Override
    public String toString() {
        return nome;
    }
}
