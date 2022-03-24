#include <IRremote.h>
int inpin=11;
int outpin1=5, outpin2=2, outpin3=3, outpin4=4;
IRrecv irrecv(inpin);
decode_results results;
void setup()
{
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(inpin, INPUT);
  pinMode(outpin1, OUTPUT);
  pinMode(outpin2, OUTPUT);
  pinMode(outpin3, OUTPUT);
  pinMode(outpin4, OUTPUT);
}

void loop()
{     
	if (irrecv.decode(&results)){
        if (results.value==16601263){
        digitalWrite(outpin1, HIGH);
        digitalWrite(outpin2, HIGH);
        digitalWrite(outpin3, HIGH);
        digitalWrite(outpin4, HIGH);
        }
        else if (results.value==16605343){
        digitalWrite(outpin1, HIGH);
        digitalWrite(outpin2, LOW);
        digitalWrite(outpin3, HIGH);
        digitalWrite(outpin4, LOW);
        }
        else if (results.value==16589023){
        digitalWrite(outpin1, LOW);
        digitalWrite(outpin2, HIGH);
        digitalWrite(outpin3, LOW);
        digitalWrite(outpin4, HIGH);
        }
        else{
        digitalWrite(outpin1, LOW);
        digitalWrite(outpin2, LOW);
        digitalWrite(outpin3, LOW);
        digitalWrite(outpin4, LOW);
        } 
       Serial.println(results.value);
     }
      irrecv.resume();
    }