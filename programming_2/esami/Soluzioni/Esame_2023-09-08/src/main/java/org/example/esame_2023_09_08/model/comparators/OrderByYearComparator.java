package org.example.esame_2023_09_08.model.comparators;

import org.example.esame_2023_09_08.model.Titolo;

import java.util.Comparator;

public class OrderByYearComparator implements Comparator<Titolo> {
    @Override
    public int compare(Titolo t1, Titolo t2) {
        if(t1.getAnnoDiPubblicazione() == t2.getAnnoDiPubblicazione()) {
            return new OrderByNameComparator().compare(t1, t2);
        } else {
            return Integer.compare(t1.getAnnoDiPubblicazione(), t2.getAnnoDiPubblicazione());
        }
    }
}
