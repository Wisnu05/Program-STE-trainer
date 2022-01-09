/****Arduino MODBUS RTU***
 * 
 * dejan.rakijasic@gmail.com
 * 
 * MODBUS library written by Jason Vreeland [CodeRage]
 * Released 3/7/2010 under GNU license
 * 
 * Dimodifikasi Untuk Tugas Akhir Oleh
 * Wisnu Alamsyah (1802202), Wisnu1602@upi.edu
 * Pendidikan Teknik Elektro,FPTK,Universitas Pendidikan Indonesia
 * ****Trainer Emulator HMI Berbasis Mikrokontroller****
 */
#include <modbus.h>
#include <modbusDevice.h>
#include <modbusRegBank.h>
#include <modbusSlave.h>
modbusDevice regBank;
modbusSlave slave;

#define Pot A0              // Potensiometer terletak pada pin A0
#define LED 12               // LED terletak pada pin 12
#define Sn1 8               // Sensor1 terletak pada pin 8
#define Sn2 9               // Sensor2 terletak pada pin 9
#define B1 22               // Button1 terletak pada pin 30
#define B2 23               // Button2 terletak pada pin 31
#define B3 24               // Button3 terletak pada pin 32
#define B4 25               // Button4 terletak pada pin 33
#define S1 26               // Saklar1 terletak pada pin 34
#define S2 27               // Saklar2 terletak pada pin 35
#define S3 28               // Saklar3 terletak pada pin 36
#define S4 29               // Saklar4 terletak pada pin 37
#define RL1 30              // Relay1 terletak pada pin 22
#define RL2 31              // Relay2 terletak pada pin 23
#define RL3 32              // Relay3 terletak pada pin 24
#define RL4 33              // Relay4 terletak pada pin 25
#define RL5 34              // Relay5 terletak pada pin 26
#define RL6 35              // Relay6 terletak pada pin 27
#define RL7 36              // Relay7 terletak pada pin 28
#define RL8 37              // Relay8 terletak pada pin 29

void setup()
{   
  pinMode(B1, INPUT);       // Button1 sebagai Digital Input 1
  pinMode(B2, INPUT);       // Button2 sebagai Digital Input 2
  pinMode(B3, INPUT);       // Button3 sebagai Digital Input 3
  pinMode(B4, INPUT);       // Button4 sebagai Digital Input 4
  pinMode(S1, INPUT);       // Saklar1 sebagai Digital Input 5
  pinMode(S2, INPUT);       // Saklar2 sebagai Digital Input 6
  pinMode(S3, INPUT);       // Saklar3 sebagai Digital Input 7
  pinMode(S4, INPUT);       // Saklar4 sebagai Digital Input 8
  pinMode(Sn1, INPUT);      // Sensor1 sebagai Digital Input 9
  pinMode(Sn2, INPUT);      // Sensor2 sebagai Digital Input 10
  pinMode(RL1, OUTPUT);     // Relay1 Sebagai Digital Output 1
  pinMode(RL2, OUTPUT);     // Relay2 Sebagai Digital Output 2
  pinMode(RL3, OUTPUT);     // Relay3 Sebagai Digital Output 3
  pinMode(RL4, OUTPUT);     // Relay4 Sebagai Digital Output 4
  pinMode(RL5, OUTPUT);     // Relay5 Sebagai Digital Output 5
  pinMode(RL6, OUTPUT);     // Relay6 Sebagai Digital Output 6
  pinMode(RL7, OUTPUT);     // Relay7 Sebagai Digital Output 7
  pinMode(RL8, OUTPUT);     // Relay8 Sebagai Digital Output 8

  // Assign the Modbus Slave ID.
  regBank.setId(1);
  
  // Digital Output registers
  regBank.add(1);           // Digital Output 1
  regBank.add(2);           // Digital Output 2
  regBank.add(3);           // Digital Output 3
  regBank.add(4);           // Digital Output 4
  regBank.add(5);           // Digital Output 5
  regBank.add(6);           // Digital Output 6
  regBank.add(7);           // Digital Output 7
  regBank.add(8);           // Digital Output 8
  
  // Digital Input registers
  regBank.add(10001);       // Digital Input 1
  regBank.add(10002);       // Digital Input 2
  regBank.add(10003);       // Digital Input 3
  regBank.add(10004);       // Digital Input 4
  regBank.add(10005);       // Digital Input 5
  regBank.add(10006);       // Digital Input 6
  regBank.add(10007);       // Digital Input 7
  regBank.add(10008);       // Digital Input 8
  
  // Analog Output registers  
  regBank.add(40001);       // Analog Output 1
  
  //Analog input registers
  regBank.add(30001);       // Analog Input 1
  regBank.add(30002);       // Sensor 1
  regBank.add(30003);       // Sensor 2
  
  slave._device = &regBank; // Initialize the baudrate serial port 
  slave.setBaud(9600);      // Set in SCADA: Baud rate=9600,Data bits=8,Stop bits=1,Parity=None,Flow control=None
}

void loop()
{
  //Digital output
  int DO1 = regBank.get(1);
  if (DO1 <= 0 && digitalRead(RL1) == HIGH)digitalWrite(RL1,LOW);
  if (DO1 >= 1 && digitalRead(RL1) == LOW)digitalWrite(RL1,HIGH);
  int DO2 = regBank.get(2);
  if (DO2 <= 0 && digitalRead(RL2) == HIGH)digitalWrite(RL2,LOW);
  if (DO2 >= 1 && digitalRead(RL2) == LOW)digitalWrite(RL2,HIGH);
  int DO3 = regBank.get(3);
  if (DO3 <= 0 && digitalRead(RL3) == HIGH)digitalWrite(RL3,LOW);
  if (DO3 >= 1 && digitalRead(RL3) == LOW)digitalWrite(RL3,HIGH);
  int DO4 = regBank.get(4);
  if (DO4 <= 0 && digitalRead(RL4) == HIGH)digitalWrite(RL4,LOW);
  if (DO4 >= 1 && digitalRead(RL4) == LOW)digitalWrite(RL4,HIGH);
  int DO5 = regBank.get(5);
  if (DO5 <= 0 && digitalRead(RL5) == HIGH)digitalWrite(RL5,LOW);
  if (DO5 >= 1 && digitalRead(RL5) == LOW)digitalWrite(RL5,HIGH);
  int DO6 = regBank.get(6);
  if (DO6 <= 0 && digitalRead(RL6) == HIGH)digitalWrite(RL6,LOW);
  if (DO6 >= 1 && digitalRead(RL6) == LOW)digitalWrite(RL6,HIGH);
  int DO7 = regBank.get(7);
  if (DO7 <= 0 && digitalRead(RL7) == HIGH)digitalWrite(RL7,LOW);
  if (DO7 >= 1 && digitalRead(RL7) == LOW)digitalWrite(RL7,HIGH);
  int DO8 = regBank.get(8);
  if (DO8 <= 0 && digitalRead(RL8) == HIGH)digitalWrite(RL8,LOW);
  if (DO8 >= 1 && digitalRead(RL8) == LOW)digitalWrite(RL8,HIGH);
  
  //Digital Input
  byte DI1 = digitalRead(B1);
  if (DI1 >= 1)regBank.set(10001,1);
  if (DI1 <= 0)regBank.set(10001,0);
  byte DI2 = digitalRead(B2);
  if (DI2 >= 1)regBank.set(10002,1);
  if (DI2 <= 0)regBank.set(10002,0);
  byte DI3 = digitalRead(B3);
  if (DI3 >= 1)regBank.set(10003,1);
  if (DI3 <= 0)regBank.set(10003,0);
  byte DI4 = digitalRead(B4);
  if (DI4 >= 1)regBank.set(10004,1);
  if (DI4 <= 0)regBank.set(10004,0);
  byte DI5 = digitalRead(S1);
  if (DI5 >= 1)regBank.set(10005,1);
  if (DI5 <= 0)regBank.set(10005,0);
  byte DI6 = digitalRead(S2);
  if (DI6 >= 1)regBank.set(10006,1);
  if (DI6 <= 0)regBank.set(10006,0);
  byte DI7 = digitalRead(S3);
  if (DI7 >= 1)regBank.set(10007,1);
  if (DI7 <= 0)regBank.set(10007,0);
  byte DI8 = digitalRead(S4);
  if (DI8 >= 1)regBank.set(10008,1);
  if (DI8 <= 0)regBank.set(10008,0);
  
  // Sensor Input
  byte Sens1 = digitalRead(Sn1);
  if (Sens1 >= 1)regBank.set(30002,0);
  if (Sens1 <= 0)regBank.set(30002,1);
  byte Sens2 = digitalRead(Sn2);
  if (Sens2 >= 1)regBank.set(30003,0);
  if (Sens2 <= 0)regBank.set(30003,1);
  
  //Analog input
  regBank.set(30001, (word)analogRead(Pot));

  //Analog output 
  word AnOut = regBank.get(40001);
  analogWrite(LED,AnOut);
  
  slave.run();
  delay(100);
}
