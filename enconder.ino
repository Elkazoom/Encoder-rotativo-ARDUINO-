int pin_ck = 2;
int pin_dt = 3;
int pin_sw = 4;

int flag = 0;
int last_signal = 0;
int signal_clock = 0;
int tooth_counter = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(pin_ck,INPUT);
  pinMode(pin_dt,INPUT);
  pinMode(pin_sw,INPUT_PULLUP);
  
  last_signal = digitalRead(pin_ck);
}

void loop() {
 
  signal_clock = digitalRead(pin_ck);

  if((signal_clock != last_signal) && (flag == 0))
  {
    if(digitalRead(pin_dt) == signal_clock)
    {
      Serial.println("sento horário (aumento)");
      flag = 1;
    }
    else
    {
      Serial.println("sento ant-horário (diminuição)");
      flag = 1;
    }
  }
  else
  {
    if(signal_clock != last_signal)
    {
      tooth_counter++;
      
      Serial.println(tooth_counter);
      if(tooth_counter == 2)
      {
        tooth_counter=0;
        flag = 0;
      }
    }
  }

  if(digitalRead(pin_sw) == LOW)
  {
      while(digitalRead(pin_sw) == LOW){}
      Serial.println("Botão apertado!");
  }

  last_signal = signal_clock;
}
