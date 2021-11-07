package com.company;

class Globals {
    public static int n = 0;
}

class Incrementer extends Thread{

    public void run(){
        for(int i = 0; i < 10; i++){
            int temp = Globals.n;
            Globals.n = temp + 1;
            System.out.println("Individual assignment " + Globals.n);
        }
    }

}

public class Main {

    public static void main(String[] args) {
        Incrementer myIncrementer1 = new Incrementer();
        Incrementer myIncrementer2 = new Incrementer();
        myIncrementer1.start();
        myIncrementer2.start();
        System.out.println("Final result " + Globals.n);
    }
}
