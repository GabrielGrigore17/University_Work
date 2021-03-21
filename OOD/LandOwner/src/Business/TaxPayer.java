package Business;

public class TaxPayer {
    private final LandManager landManager = new LandManager();
    private final int SSN;

    public TaxPayer(int SSN) {
        this.SSN = SSN;
    }

    public int getSSN() {
        return SSN;
    }

    public void addLot(Shape shape){
        landManager.buyLand(shape);
    }

    public void removeLot(int id){
        landManager.sellLand(id);
    }

    public double getTaxAmount(){
        return 0.01 * landManager.getTotalArea();
    }


}
