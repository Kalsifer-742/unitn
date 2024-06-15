package org.example.esame_20230617.model;

import java.util.Objects;

public class Magia {
    final String nome;

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

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Magia magia = (Magia) o;
        return Objects.equals(getNome(), magia.getNome());
    }

    @Override
    public int hashCode() {
        return Objects.hashCode(getNome());
    }
}
