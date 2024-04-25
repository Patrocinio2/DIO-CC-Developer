package br.dev.patrocinio.paradigmaAspectos;

import java.util.Scanner;

   public class Main {
       
       public static void main(String[] args){
           
           Scanner scanner = new Scanner(System.in);

           Conta c1 = new ContaPoupanca("Pessoa Física", "25/04/2024", 1000);
           Conta c2 = new ContaInvestimento("Pessoa Física", "25/04/2024", 2000);

           System.out.print("Digite o valor do saque para a Conta Poupança: ");
           double valor1 = scanner.nextDouble();
           c1.verificarSaldo(valor1);            

           System.out.print("Digite o valor do saque para a Conta Investimento: ");
           double valor2 = scanner.nextDouble();
           c2.verificarSaldo(valor2);    
       }
}