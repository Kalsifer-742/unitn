package org.example.esame_2023_09_08.model;

import org.example.esame_2023_09_08.model.TitleListExceptions.TitleListEndReachedException;
import org.example.esame_2023_09_08.model.TitleListExceptions.TitleListStartReachedException;
import org.example.esame_2023_09_08.model.titoli.Anime;
import org.example.esame_2023_09_08.model.titoli.Film;
import org.example.esame_2023_09_08.model.titoli.SerieTV;

import java.util.Comparator;
import java.util.Date;
import java.util.LinkedList;

public class StreamingPlatform {
    LinkedList<Titolo> titoli;
    static int index;
    static int amount;

    public StreamingPlatform() {
        titoli = new LinkedList<>();
        index = 0;
        amount = 3;

        titoli.add(new SerieTV("Boris", 2010, "Italiano", 4, 10));
        titoli.add(new Anime("Attack on Titan", 2013, "Giapponese", "Inglese", 10));
        titoli.add(new Film("Parasite", 2019, "Inglese", 10));
        titoli.add(new Anime("Pokemon", 2010, "Inglese", 10));
        titoli.add(new Film("The Irishman", 2019, "Inglese", 5));
        titoli.add(new SerieTV("1994", 2019, "Italiano", 3, 10));
        titoli.add(new Film("Her", 2013, "Inglese", 20));
    }

    public void next() throws TitleListEndReachedException {
        if (amount < 3) {
            throw new TitleListEndReachedException();
        }

        if (titoli.size() - (index + 3) > 3) {
            amount = 3;
        } else {
            amount = titoli.size() - (index + 3);
        }

        index += 3;
    }

    public void prev() throws TitleListStartReachedException {
        if ((index - 3) < 0) {
            throw new TitleListStartReachedException();
        }
        amount = 3;
        index -= 3;
    }

    public LinkedList<Titolo> getTitlesToShow() {
        LinkedList<Titolo> titlesToShow = new LinkedList<>();

        if (titoli.isEmpty()) {
            return titlesToShow;
        }

        for (int i = 0; i < amount; i++) {
            Titolo titleToInsert;
            try {
                titleToInsert = titoli.get(index + i);
            } catch (IndexOutOfBoundsException e) {
               break;
            }

            titlesToShow.add(titleToInsert);
        }

        return titlesToShow;
    }

    public void sortTitles(Comparator<Titolo> comparator) {
        titoli.sort(comparator);
    }
}
