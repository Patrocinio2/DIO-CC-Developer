// Definindo os pinos para os LEDs
const int ledAzul = 2;
const int ledVerde = 3;
const int ledAmarelo = 4;
const int ledLaranja = 5;
const int ledVermelho = 6;

const int sensorTemp = A0; // Pino onde o sensor está conectado

void setup() 
{
  // Configura os pinos dos LEDs como saída
  pinMode(ledAzul, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledLaranja, OUTPUT);
  pinMode(ledVermelho, OUTPUT);

  Serial.begin(9600); // Inicia a comunicação serial para depuração
}

void loop() {
  int valorLido = analogRead(sensorTemp); // Lê o valor analógico do sensor
  float temperatura = (valorLido * 5.0 * 100.0) / 1024.0; // Converte o valor lido para temperatura em Celsius

  Serial.print("Temperatura: ");
  Serial.print(temperatura);
  Serial.println(" C");

  // Apaga todos os LEDs
  digitalWrite(ledAzul, LOW);
  digitalWrite(ledVerde, LOW);
  digitalWrite(ledAmarelo, LOW);
  digitalWrite(ledLaranja, LOW);
  digitalWrite(ledVermelho, LOW);

  // Acende o LED correspondente à faixa de temperatura
  if (temperatura < 10) 
  {
    digitalWrite(ledAzul, HIGH);
  } 
  else if (temperatura >= 10 && temperatura < 20)
  {
    digitalWrite(ledVerde, HIGH);
  } 
  else if (temperatura >= 20 && temperatura < 30) 
  {
    digitalWrite(ledAmarelo, HIGH);
  } 
  else if (temperatura >= 30 && temperatura < 35) 
  {
    digitalWrite(ledLaranja, HIGH);
  } 
  else if (temperatura >= 35) 
  {
    digitalWrite(ledVermelho, HIGH);
  }

  delay(1000); // Espera 1 segundo antes de ler novamente
}
