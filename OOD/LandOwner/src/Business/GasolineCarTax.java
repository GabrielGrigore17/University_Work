package Business;

public class GasolineCarTax implements Tax{
    private static final int firstIntervalTax = 100;
    private static final int secondIntervalTax = 200;
    private static final int thirdIntervalTax = 300;

    @Override
    public double computeTaxForTaxPayer(double engineSize) {
        double tax = 0;
        if(engineSize < 1000)
            return firstIntervalTax;
        else if(engineSize < 2000)
            return secondIntervalTax;
        else return thirdIntervalTax;
    }
}
