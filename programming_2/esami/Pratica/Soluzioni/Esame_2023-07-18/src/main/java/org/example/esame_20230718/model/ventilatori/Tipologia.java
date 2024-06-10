package org.example.esame_20230718.model.ventilatori;

public enum Tipologia {
    PIATANA(10),
    PARETE(20),
    SOFFITTO(2);

    private final int costo;

    Tipologia(int costo) {
        this.costo = costo;
    }

    public int getCosto() {
        return costo;
    }

    @Override
    public String toString() {
        return switch (this) {
            case PIATANA -> "Piantana";
            case PARETE -> "Parete";
            case SOFFITTO -> "Soffitto";
        };
    }
}
