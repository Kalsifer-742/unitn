package org.example.esame_2023_09_08.model.comparators;

import org.example.esame_2023_09_08.model.Titolo;

import java.util.Comparator;

public class OrderByNameComparator implements Comparator<Titolo> {
    @Override
    public int compare(Titolo t1, Titolo t2) {
        return t1.getNome().compareTo(t2.getNome());
    }
}
