//----------------------------------
//
// Gestion de la fréquence du CPU
//
//----------------------------------
#include "rom/uart.h"
#include "esp_system.h"
#include "soc/rtc.h"



// affiche la fréquence du CPU
void afficheFrequence (){
  rtc_cpu_freq_t choixFreq; // type de fréquence
  String strFreq;  
  
  Serial.print ("\nFréquence  : ");
  choixFreq= rtc_clk_cpu_freq_get() ;

  switch (choixFreq){

    case RTC_CPU_FREQ_80M:
      strFreq ="RTC_CPU_FREQ_80M";
      break;

    case RTC_CPU_FREQ_160M:
      strFreq ="RTC_CPU_FREQ_160M";
      break;

    case RTC_CPU_FREQ_240M:
      strFreq ="RTC_CPU_FREQ_240M";
      break;

    case RTC_CPU_FREQ_2M:
      strFreq ="RTC_CPU_FREQ_2M";
      break;

    default:
      strFreq ="??? inconnu";
  }
  Serial.println(strFreq);
}

void setup() {
  rtc_cpu_freq_t choixFreq= RTC_CPU_FREQ_80M;  // fréquence choisie
  
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println(" *** ###  ---  ESP32 FREQUENCY  --- ### *** ");

  Serial.print("\n --- Avant modification --- ");
  afficheFrequence();
  uart_tx_wait_idle(0) ; // attente vide TX avant modification de la fréquence
  
  // Sélection  de la fréquence 
  rtc_clk_cpu_freq_set(choixFreq);
  
  Serial.print ("\n --- Après modification --- ");
  afficheFrequence();

}

void loop() {
  // put your main code here, to run repeatedly:
  delay(1);
}
