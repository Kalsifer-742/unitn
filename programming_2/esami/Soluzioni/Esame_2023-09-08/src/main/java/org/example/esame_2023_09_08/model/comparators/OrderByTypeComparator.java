package org.example.esame_2023_09_08.model.comparators;

import org.example.esame_2023_09_08.model.Titolo;
import org.example.esame_2023_09_08.model.titoli.Anime;
import org.example.esame_2023_09_08.model.titoli.Film;
import org.example.esame_2023_09_08.model.titoli.SerieTV;

import java.util.Comparator;

public class OrderByTypeComparator implements Comparator<Titolo> {
    private int getValue(Titolo t) {
        if (t instanceof Film) {
            return 0;
        } else if (t instanceof Anime) {
            return 1;
        } else {
            return 2;
        }
    }

    @Override
    public int compare(Titolo t1, Titolo t2) {
        if (getValue(t1) == getValue(t2)) {
            return t1.getNome().compareTo(t2.getNome());
        } else {
            if (getValue(t1) > getValue(t2)) {
                return 1;
            } else {
                return -1;
            }
        }
    }
}
