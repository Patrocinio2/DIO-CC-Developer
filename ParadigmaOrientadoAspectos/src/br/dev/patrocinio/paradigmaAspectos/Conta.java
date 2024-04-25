package br.dev.patrocinio.paradigmaAspectos;

public abstract class Conta implements ContaBancaria{

    String tipoCliente;
    String dataAbertura;
    double saldo;

    public Conta(String tipoCliente, String dataAbertura, double saldo){
        
        this.tipoCliente = tipoCliente;
        this.dataAbertura = dataAbertura;
        this.saldo = saldo;
    }

    public abstract void sacar(double valor);
    public abstract void depositar(double valor);
}