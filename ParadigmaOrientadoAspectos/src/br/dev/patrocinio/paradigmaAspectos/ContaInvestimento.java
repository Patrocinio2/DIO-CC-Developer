package br.dev.patrocinio.paradigmaAspectos;

public class ContaInvestimento extends Conta{

    public ContaInvestimento(String tipoCliente, String dataAbertura, double saldo){
        super(tipoCliente, dataAbertura, saldo);
    }

    @Override
    public void sacar(double valor){
        saldo = saldo - valor;
        System.out.println("Saque efetuado");
    }

    @Override
    public void depositar(double valor){
        saldo = saldo + valor;
        System.out.println("Depósito realizado");
    }

    @Override
    public void verificarSaldo(double valor){
        if(valor > saldo){
            System.out.println("Saldo insuficiente");
        }else{
            sacar(valor);
        }
    }
}