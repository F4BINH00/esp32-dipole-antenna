#include <Arduino.h>
#include <WiFi.h>

void setup()
{
  Serial.begin(115200);
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("\n--- Iniciando Scanner de Sinal (RSSI) ---");
}

void loop()
{
  Serial.println("Escaneando redes...");
  int n = WiFi.scanNetworks();

  if (n == 0)
  {
    Serial.println("Nenhuma rede encontrada.");
  }
  else
  {
    Serial.print(n);
    Serial.println(" redes encontradas:");
    for (int i = 0; i < n; ++i)
    {
      Serial.print(i + 1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print(" (");
      Serial.print(WiFi.RSSI(i)); // Este valor é o que você vai medir!
      Serial.println(" dBm)");
    }
  }
  Serial.println("-----------------------");
  delay(5000); // Aguarda 5 segundos para o próximo scan
}