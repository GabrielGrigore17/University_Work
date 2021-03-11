package UI;

import Business.Owner;
import Business.Rectangle;
import Business.Square;

import java.util.Scanner;

public class UserInterface {
    private final Owner owner = new Owner();

    public void menu(){
        Scanner scanner = new Scanner(System.in);
        boolean isOn = true;
        while (isOn){
            String mainMenu = "Press 1 to buy land\nPress 2 to sell land\nPress 3 to display total area";
            System.out.println(mainMenu);
            int choice = scanner.nextInt();
            switch (choice) {
                case 1:{
                    String buyPrompt = "Please press 1 for rectangle or 2 for square";
                    System.out.println(buyPrompt);
                    int secondChoice = scanner.nextInt();
                    if(secondChoice == 1){
                        String rectanglePrompt = "Please enter the height, width, ID separated by a space";
                        System.out.println(rectanglePrompt);
                        double height = scanner.nextDouble();
                        double width = scanner.nextDouble();
                        int id = scanner.nextInt();
                        owner.buyLand(new Rectangle(height, width, id));
                    }
                    else {
                        String squarePrompt = "Please enter the side and ID separated by a space";
                        System.out.println(squarePrompt);
                        double side = scanner.nextDouble();
                        int id = scanner.nextInt();
                        owner.buyLand(new Square(side, id));
                    }
                }
                case 2:{
                    String sellPrompt = "Please enter the land ID";
                    System.out.println(sellPrompt);
                    int id = scanner.nextInt();
                    owner.sellLand(id);
                }
                case 3:{
                    System.out.println(owner.getTotalArea());
                }
                default:{
                    isOn = false;
                }
            }
            System.out.println();
        }
    }
}
