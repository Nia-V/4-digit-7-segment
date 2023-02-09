int latch = 9; 
int clock = 10; 
int data= 8 ; 
int pb = 2;
int counter= 0;
int counter1 = 0;
int counter2 = 0;
int counter3 = 0;
int D1 = 3;
int D2 = 4;
int D3 = 5;
int D4 = 6;
bool stopper = 0;

unsigned char table[]=
{
0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f, 0x77, 0x7c, 0x39, 0x5e, 0x79, 0x71, 0x00};

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    pinMode(latch, OUTPUT);
    pinMode(clock, OUTPUT);
    pinMode(data, OUTPUT);
    pinMode(pb, INPUT_PULLUP);
     pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
     pinMode(D4, OUTPUT);
}

void Display4(unsigned char num, unsigned char num1, unsigned char num2, unsigned char num3){   
 
    digitalWrite(D1, 0);
      digitalWrite(latch, 0);
    shiftOut(data, clock, MSBFIRST, table[num]);
           digitalWrite(latch, 1);
           digitalWrite(D1, 1);
 
    digitalWrite(D2, 0);
      digitalWrite(latch, 0);
    shiftOut(data, clock, MSBFIRST, table[num1]);
           digitalWrite(latch, 1);
           digitalWrite(D2, 1);

    digitalWrite(D3, 0);
      digitalWrite(latch, 0);
    shiftOut(data, clock, MSBFIRST, table[num2]);
           digitalWrite(latch, 1);
           digitalWrite(D3, 1);
  
    digitalWrite(D4, 0);
      digitalWrite(latch, 0);
    shiftOut(data, clock, MSBFIRST, table[num3]);
           digitalWrite(latch, 1);
           digitalWrite(D4, 1);

    digitalWrite(D4, 0);
      digitalWrite(D3, 0);
           digitalWrite(D2, 0);
           digitalWrite(D1, 0);
    
}

void loop() {


bool pbval = digitalRead(pb);
 if(pbval==0 && stopper == 0){// if button is pressed and stopper value is 0, is activated once when the button is pressed(aka not continuously)
    stopper = 1;//sets stopper true
    counter++;
    }
    if(pbval==1) { //if button is not pressed (activated continuously)
      stopper = 0; // sets stoper false
    }

if (counter ==10){
  counter1 ++;
  counter =0;
}
if (counter1 ==10){
  counter2 ++;
  counter1 =0;
}
if (counter2 ==10){
  counter3 ++;
  counter2 =0;
}
Display4(counter, counter1, counter2, counter3); 
Serial.print(counter3);
Serial.print(counter2);
Serial.print(counter1);
Serial.println(counter);

}
