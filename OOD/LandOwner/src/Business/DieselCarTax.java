package Business;

public class DieselCarTax implements Tax{
    private static final int firstIntervalTax = 100;
    private static final int secondIntervalTax = 300;
    private static final int thirdIntervalTax = 500;

    @Override
    public double computeTaxForTaxPayer(double engineSize) {
        if(engineSize < 1000)
            return firstIntervalTax;
        else if(engineSize < 2000)
            return secondIntervalTax;
        else return thirdIntervalTax;
    }
}
