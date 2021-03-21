package UI;

import Business.*;

import java.util.Scanner;

public class CommerceAppUI {
    private final LandManager owner = new LandManager();

    public void menu(){
        Scanner scanner = new Scanner(System.in);
        boolean isOn = true;
        while (isOn){
            String mainMenu = "Press 1 to buy land\nPress 2 to sell land\nPress 3 to display total area";
            System.out.println(mainMenu);
            int choice = scanner.nextInt();
            switch (choice) {
                case 1:{
                    String buyPrompt = "Please press 1 for rectangle, 2 for square, 3 for triangle, 4 for circle";
                    System.out.println(buyPrompt);
                    int secondChoice = scanner.nextInt();
                    switch (secondChoice){
                        case 1:{
                            String rectanglePrompt = "Please enter the height, width, ID separated by a space";
                            System.out.println(rectanglePrompt);
                            double height = scanner.nextDouble();
                            double width = scanner.nextDouble();
                            int id = scanner.nextInt();
                            owner.buyLand(new Rectangle(height, width, id));
                            break;
                        }
                        case 2:{
                            String squarePrompt = "Please enter the side and ID separated by a space";
                            System.out.println(squarePrompt);
                            double side = scanner.nextDouble();
                            int id = scanner.nextInt();
                            owner.buyLand(new Square(side, id));
                            break;
                        }
                        case 3:{
                            String trianglePrompt = "Please enter the side, height, ID separated by a space";
                            System.out.println(trianglePrompt);
                            double side = scanner.nextDouble();
                            double height = scanner.nextDouble();
                            int id = scanner.nextInt();
                            owner.buyLand(new Triangle(side, height, id));
                            break;
                        }
                        case 4:{
                            String circlePrompt = "Please enter the radix and ID separated by a space";
                            System.out.println(circlePrompt);
                            double radix = scanner.nextDouble();
                            int id = scanner.nextInt();
                            owner.buyLand(new Circle(radix, id));
                            break;
                        }
                        default:
                            break;
                    }
                    break;
                }
                case 2:{
                    String sellPrompt = "Please enter the land ID";
                    System.out.println(sellPrompt);
                    int id = scanner.nextInt();
                    owner.sellLand(id);
                    break;
                }
                case 3:{
                    System.out.println(owner.getTotalArea());
                    break;
                }
                default:{
                    isOn = false;
                    break;
                }
            }
            System.out.println();
        }
    }
}
