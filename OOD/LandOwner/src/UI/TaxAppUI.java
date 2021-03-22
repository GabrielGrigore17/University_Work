package UI;

import Business.*;

import java.util.Scanner;

public class TaxAppUI {
    static final String mainMenu = "Press 1 to add a tax payer\n" +
            "Press 2 to remove a tax payer\n" +
            "Press 3 to add a lot to a tax payer\n" +
            "Press 4 to remove a lot from a tax payer\n" +
            "Press 5 to get the total tax\n" +
            "Press 6 to change the tax per square meter";
    static final String ssnPrompt = "Please enter the Social Security Number:\n";
    static final String addLotPrompt = "Please press 1 for rectangle, 2 for square, 3 for triangle, 4 for circle";
    static final String removeLotPrompt = "Please enter the land ID";
    static final String getTotalPrompt = "This is the total amount ";
    static final String changeTaxPrompt = "Please insert the new tax per square meter";
    static final String rectanglePrompt = "Please enter the height, width, ID separated by a space";
    static final String squarePrompt = "Please enter the side and ID separated by a space";
    static final String trianglePrompt = "Please enter the side, height, ID separated by a space";
    static final String circlePrompt = "Please enter the radix and ID separated by a space";

    private final TaxCollector taxCollector = new TaxCollector();

    public void menu(){
        Scanner scanner = new Scanner(System.in);
        boolean isOn = true;
        while (isOn){
            System.out.println(mainMenu);
            int choice = scanner.nextInt();
            switch (choice){
                case 1: {
                    System.out.println(ssnPrompt);
                    int SSN = scanner.nextInt();
                    taxCollector.addTaxPayer(SSN);
                    break;
                }
                case 2:{
                    System.out.println(ssnPrompt);
                    int SSN = scanner.nextInt();
                    taxCollector.removeTaxPayer(SSN);
                    break;
                }
                case 3:{
                    System.out.println(ssnPrompt);
                    int SSN = scanner.nextInt();
                    System.out.println(addLotPrompt);
                    int secondChoice = scanner.nextInt();
                    switch (secondChoice){
                        case 1:{
                            System.out.println(rectanglePrompt);
                            double height = scanner.nextDouble();
                            double width = scanner.nextDouble();
                            int id = scanner.nextInt();
                            taxCollector.addLotToTaxPayer(SSN, new Rectangle(height, width, id));
                            break;
                        }
                        case 2:{
                            System.out.println(squarePrompt);
                            double side = scanner.nextDouble();
                            int id = scanner.nextInt();
                            taxCollector.addLotToTaxPayer(SSN, new Square(side, id));
                            break;
                        }
                        case 3:{
                            System.out.println(trianglePrompt);
                            double side = scanner.nextDouble();
                            double height = scanner.nextDouble();
                            int id = scanner.nextInt();
                            taxCollector.addLotToTaxPayer(SSN, new Triangle(side, height, id));
                            break;
                        }
                        case 4:{
                            System.out.println(circlePrompt);
                            double radix = scanner.nextDouble();
                            int id = scanner.nextInt();
                            taxCollector.addLotToTaxPayer(SSN, new Circle(radix, id));
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                case 4:{
                    System.out.println(ssnPrompt);
                    int SSN = scanner.nextInt();
                    System.out.println(removeLotPrompt);
                    int id = scanner.nextInt();
                    taxCollector.removeLotFromTaxPayer(SSN, id);
                    break;
                }
                case 5:{
                    System.out.println(getTotalPrompt);
                    System.out.println(taxCollector.getTotalTax());
                    break;
                }
                case 6:{
                    System.out.println(changeTaxPrompt);
                    double tax = scanner.nextDouble();
                    taxCollector.changeTaxPerSquareMeter(tax);
                    break;
                }
                default:{
                    isOn = false;
                    break;
                }
            }
        }
    }
}
