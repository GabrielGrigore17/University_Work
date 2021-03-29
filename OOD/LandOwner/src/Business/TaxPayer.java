package Business;

public class TaxPayer {
    private final LandManager landManager = new LandManager();
    private final CarManager carManager = new CarManager();
    private final int SSN;
    private final ITax taxType;

    public TaxPayer(int SSN, ITax tax) {
        this.SSN = SSN;
        this.taxType = tax;
    }

    public int getSSN() {
        return SSN;
    }

    public void addLot(IShape shape){
        landManager.buyLand(shape);
    }

    public void removeLot(int id){
        landManager.sellLand(id);
    }

    public void addCar(ICar car){
        carManager.addCar(car);
    }

    public void removeCar(int id){
        carManager.removeCar(id);
    }

    public double computeCarsTax(){
        return carManager.computeTotalTax();
    }

    public double computeLandTax(){
        return taxType.computeTaxForTaxPayer(landManager.getTotalArea());
    }

    public double computeTotalTax(){
        return carManager.computeTotalTax() + taxType.computeTaxForTaxPayer(landManager.getTotalArea());
    }


}
