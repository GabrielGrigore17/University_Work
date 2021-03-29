package Business;

import java.util.ArrayList;
import java.util.List;

public class TaxCollector {

    private final List<TaxPayer> taxPayers = new ArrayList<>();
    private double totalTax;

    public void removeTaxPayer(int SSN){
        taxPayers.removeIf(taxPayer -> taxPayer.getSSN() == SSN);
        totalTaxRefresh();
    }

    public void addTaxPayer(int SSN, ITax tax){
        taxPayers.add(new TaxPayer(SSN, tax));
    }

    public void addLotToTaxPayer(int SSN, IShape shape){
        for(TaxPayer taxPayer: taxPayers){
            if(taxPayer.getSSN() == SSN)
                taxPayer.addLot(shape);
        }
        totalTaxRefresh();
    }

    public void removeLotFromTaxPayer(int SSN, int id){
        for(TaxPayer taxPayer: taxPayers){
            if(taxPayer.getSSN() == SSN)
                taxPayer.removeLot(id);
        }
        totalTaxRefresh();
    }

    public void addCarToTaxPayer(int SSN, ICar car){
        for(TaxPayer taxPayer: taxPayers){
            if(taxPayer.getSSN() == SSN)
                taxPayer.addCar(car);
        }
        totalTaxRefresh();
    }

    public void removeCarFromTaxPayer(int SSN, int id){
        for(TaxPayer taxPayer: taxPayers){
            if(taxPayer.getSSN() == SSN)
                taxPayer.removeCar(id);
        }
        totalTaxRefresh();
    }

    public double getTaxOwedByATaxPayer(int SSN){
        for(TaxPayer taxPayer: taxPayers){
            if (taxPayer.getSSN() == SSN)
                return taxPayer.computeTotalTax();
        }
        return -1;
    }

    public double getLandTaxOwedByATaxPayer(int SSN){
        for(TaxPayer taxPayer: taxPayers){
            if (taxPayer.getSSN() == SSN)
                return taxPayer.computeLandTax();
        }
        return -1;
    }

    public double getCarsTaxOwedByATaxPayer(int SSN){
        for(TaxPayer taxPayer: taxPayers){
            if (taxPayer.getSSN() == SSN)
                return taxPayer.computeCarsTax();
        }
        return -1;
    }

    public double getTotalTax(){
        return totalTax;
    }

    private void totalTaxRefresh(){
        this.totalTax = 0;
        for(TaxPayer taxPayer: taxPayers)
            this.totalTax += taxPayer.computeLandTax();
    }

}
