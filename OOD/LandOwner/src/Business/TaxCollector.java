package Business;

import java.util.ArrayList;
import java.util.List;

public class TaxCollector {

    private final List<TaxPayer> taxPayers = new ArrayList<>();
    private double totalTax;
    private double taxPerSquareMeter = 0.01;

    public void removeTaxPayer(int SSN){
        taxPayers.removeIf(taxPayer -> taxPayer.getSSN() == SSN);
        totalTaxRefresh();
    }

    public void addTaxPayer(int SSN){
        taxPayers.add(new TaxPayer(SSN));
    }

    public void addLotToTaxPayer(int SSN, Shape shape){
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

    public void changeTaxPerSquareMeter(double tax){
        this.taxPerSquareMeter = tax;
        totalTaxRefresh();
    }

    public double getTotalTax(){
        return totalTax;
    }

    private void totalTaxRefresh(){
        this.totalTax = 0;
        for(TaxPayer taxPayer: taxPayers)
            this.totalTax += taxPayer.getLandArea() * taxPerSquareMeter;
    }

}
