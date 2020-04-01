#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9,8);  // CS, CSN
const byte address[6] = "00017";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  radio.begin();
  radio.openWritingPipe(address);

  radio.stopListening(); // Transmitter mode
  
}

void loop() {
  // put your main code here, to run repeatedly:
  const char text[] = "Hello World!";
  radio.write(&text, sizeof(text));
  Serial.println("Hello");
  delay(1000);
}
