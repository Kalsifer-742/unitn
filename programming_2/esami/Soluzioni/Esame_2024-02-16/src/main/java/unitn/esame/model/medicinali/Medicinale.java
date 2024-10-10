package unitn.esame.model.medicinali;

import java.util.Date;

public abstract class Medicinale implements Scadenza {
    protected String nome;
    protected float costo;
    protected float prezzoScontato;
    protected Date dataDiScadenza;

    public Medicinale(String nome, float costo, Date dataDiScadenza) {
        this.nome = nome;
        this.costo = costo;
        this.dataDiScadenza = dataDiScadenza;
    }

    public String getNome() {
        return nome;
    }

    public float getprezzoScontato() {
        return prezzoScontato;
    }

    public Date getDataDiScadenza() {
        return dataDiScadenza;
    }

    @Override
    public  String toString() {
        return nome + "\n" +
                "Costo base: " + costo + "$ Scontato a " + prezzoScontato + "$\n" +
                "scadenza: " + (isScaduta() ? "scaduta" : dataDiScadenza) + "\n";
    }

    @Override
    public boolean isScaduta() {
        return dataDiScadenza.before(new Date());
    }
}
