/*******************************************************
This program was created by the
CodeWizardAVR V2.60 Evaluation
Automatic Program Generator
� Copyright 1998-2012 Pavel Haiduc, HP InfoTech s.r.l.
http://www.hpinfotech.com

Project : Cronometer
Version :
Date    : 9/25/2024
Author  :
Company :
Comments:


Chip type               : ATmega8535
Program type            : Application
AVR Core Clock frequency: 1.000000 MHz
Memory model            : Small
External RAM size       : 0
Data Stack size         : 128
*******************************************************/

#include <mega8535.h>
#include <delay.h>

// Declare your global variables here
#define stopButton PINB .0
#define resetButton PINB .1
#define startButton PINB .2

// Signal Edge Detection Variable
bit botonp1 = 1;
bit botonp2 = 1;
bit botonp3 = 1;

bit botona1 = 1;
bit botona2 = 1;
bit botona3 = 1;

unsigned char counter[3] = {0x00, 0x00, 0x00};
bit isRunning = 0;

const char decoderArray[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 0x7f, 0x6f};

void main(void)
{
      // Declare your local variables here

      // Input/Output Ports initialization
      // Port A initialization
      // Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out
      DDRA = (1 << DDA7) | (1 << DDA6) | (1 << DDA5) | (1 << DDA4) | (1 << DDA3) | (1 << DDA2) | (1 << DDA1) | (1 << DDA0);
      // State: Bit7=1 Bit6=1 Bit5=1 Bit4=1 Bit3=1 Bit2=1 Bit1=1 Bit0=1
      PORTA = (1 << PORTA7) | (1 << PORTA6) | (1 << PORTA5) | (1 << PORTA4) | (1 << PORTA3) | (1 << PORTA2) | (1 << PORTA1) | (1 << PORTA0);

      // Port B initialization
      // Function: Bit7=In Bit6=In Bit5=In Bit4=In Bit3=In Bit2=In Bit1=In Bit0=In
      DDRB = (0 << DDB7) | (0 << DDB6) | (0 << DDB5) | (0 << DDB4) | (0 << DDB3) | (0 << DDB2) | (0 << DDB1) | (0 << DDB0);
      // State: Bit7=T Bit6=T Bit5=T Bit4=T Bit3=T Bit2=P Bit1=P Bit0=P
      PORTB = (0 << PORTB7) | (0 << PORTB6) | (0 << PORTB5) | (0 << PORTB4) | (0 << PORTB3) | (1 << PORTB2) | (1 << PORTB1) | (1 << PORTB0);

      // Port C initialization
      // Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out
      DDRC = (1 << DDC7) | (1 << DDC6) | (1 << DDC5) | (1 << DDC4) | (1 << DDC3) | (1 << DDC2) | (1 << DDC1) | (1 << DDC0);
      // State: Bit7=0 Bit6=0 Bit5=0 Bit4=0 Bit3=0 Bit2=0 Bit1=0 Bit0=0
      PORTC = (0 << PORTC7) | (0 << PORTC6) | (0 << PORTC5) | (0 << PORTC4) | (0 << PORTC3) | (0 << PORTC2) | (0 << PORTC1) | (0 << PORTC0);

      // Port D initialization
      // Function: Bit7=Out Bit6=Out Bit5=Out Bit4=Out Bit3=Out Bit2=Out Bit1=Out Bit0=Out
      DDRD = (1 << DDD7) | (1 << DDD6) | (1 << DDD5) | (1 << DDD4) | (1 << DDD3) | (1 << DDD2) | (1 << DDD1) | (1 << DDD0);
      // State: Bit7=1 Bit6=1 Bit5=1 Bit4=1 Bit3=1 Bit2=1 Bit1=1 Bit0=1
      PORTD = (1 << PORTD7) | (1 << PORTD6) | (1 << PORTD5) | (1 << PORTD4) | (1 << PORTD3) | (1 << PORTD2) | (1 << PORTD1) | (1 << PORTD0);

      // Timer/Counter 0 initialization
      // Clock source: System Clock
      // Clock value: Timer 0 Stopped
      // Mode: Normal top=0xFF
      // OC0 output: Disconnected
      TCCR0 = (0 << WGM00) | (0 << COM01) | (0 << COM00) | (0 << WGM01) | (0 << CS02) | (0 << CS01) | (0 << CS00);
      TCNT0 = 0x00;
      OCR0 = 0x00;

      // Timer/Counter 1 initialization
      // Clock source: System Clock
      // Clock value: Timer1 Stopped
      // Mode: Normal top=0xFFFF
      // OC1A output: Disconnected
      // OC1B output: Disconnected
      // Noise Canceler: Off
      // Input Capture on Falling Edge
      // Timer1 Overflow Interrupt: Off
      // Input Capture Interrupt: Off
      // Compare A Match Interrupt: Off
      // Compare B Match Interrupt: Off
      TCCR1A = (0 << COM1A1) | (0 << COM1A0) | (0 << COM1B1) | (0 << COM1B0) | (0 << WGM11) | (0 << WGM10);
      TCCR1B = (0 << ICNC1) | (0 << ICES1) | (0 << WGM13) | (0 << WGM12) | (0 << CS12) | (0 << CS11) | (0 << CS10);
      TCNT1H = 0x00;
      TCNT1L = 0x00;
      ICR1H = 0x00;
      ICR1L = 0x00;
      OCR1AH = 0x00;
      OCR1AL = 0x00;
      OCR1BH = 0x00;
      OCR1BL = 0x00;

      // Timer/Counter 2 initialization
      // Clock source: System Clock
      // Clock value: Timer2 Stopped
      // Mode: Normal top=0xFF
      // OC2 output: Disconnected
      ASSR = 0 << AS2;
      TCCR2 = (0 << WGM20) | (0 << COM21) | (0 << COM20) | (0 << WGM21) | (0 << CS22) | (0 << CS21) | (0 << CS20);
      TCNT2 = 0x00;
      OCR2 = 0x00;

      // Timer(s)/Counter(s) Interrupt(s) initialization
      TIMSK = (0 << OCIE2) | (0 << TOIE2) | (0 << TICIE1) | (0 << OCIE1A) | (0 << OCIE1B) | (0 << TOIE1) | (0 << OCIE0) | (0 << TOIE0);

      // External Interrupt(s) initialization
      // INT0: Off
      // INT1: Off
      // INT2: Off
      MCUCR = (0 << ISC11) | (0 << ISC10) | (0 << ISC01) | (0 << ISC00);
      MCUCSR = (0 << ISC2);

      // USART initialization
      // USART disabled
      UCSRB = (0 << RXCIE) | (0 << TXCIE) | (0 << UDRIE) | (0 << RXEN) | (0 << TXEN) | (0 << UCSZ2) | (0 << RXB8) | (0 << TXB8);

      // Analog Comparator initialization
      // Analog Comparator: Off
      ACSR = (1 << ACD) | (0 << ACBG) | (0 << ACO) | (0 << ACI) | (0 << ACIE) | (0 << ACIC) | (0 << ACIS1) | (0 << ACIS0);
      SFIOR = (0 << ACME);

      // ADC initialization
      // ADC disabled
      ADCSRA = (0 << ADEN) | (0 << ADSC) | (0 << ADATE) | (0 << ADIF) | (0 << ADIE) | (0 << ADPS2) | (0 << ADPS1) | (0 << ADPS0);

      // SPI initialization
      // SPI disabled
      SPCR = (0 << SPIE) | (0 << SPE) | (0 << DORD) | (0 << MSTR) | (0 << CPOL) | (0 << CPHA) | (0 << SPR1) | (0 << SPR0);

      // TWI initialization
      // TWI disabled
      TWCR = (0 << TWEA) | (0 << TWSTA) | (0 << TWSTO) | (0 << TWEN) | (0 << TWIE);

      while (1)
      {
            if (stopButton == 0)
                  botona1 = 0;
            else
                  botona1 = 1;
            if (resetButton == 0)
                  botona2 = 0;
            else
                  botona2 = 1;
            if (startButton == 0)
                  botona3 = 0;
            else
                  botona3 = 1;
            if ((0 == botona2) && (1 == botonp2)) // Flanco de bajada para reset
            {
                  counter[0] = 0x00;
                  counter[1] = 0x00;
                  counter[2] = 0x00;
                  isRunning = 0;
                  delay_ms(40);
            }
            if ((1 == botona2) && (0 == botonp2)) // Flanco de subida para reset
            {
                  delay_ms(40);
            }
            if ((0 == botona3) && (1 == botonp3)) // Flanco de subida para start
            {
                  isRunning = 1;
                  delay_ms(40); // Evita rebote
            }
            if ((1 == botona3) && (0 == botonp3))
            {                   // Flanco de bajada para start
                  delay_ms(40); // Evita rebote
            }
            if ((0 == botona1) && (1 == botonp1)) // Flanco de subida para stop
            {
                  isRunning = 0;
                  delay_ms(40); // Evita rebote
            }
            if ((1 == botona1) && (0 == botonp1))
            { // Flanco de bajada para stop

                  delay_ms(40); // Evita rebote
            }

            if (1 == isRunning)
            {
                  counter[2]++;
                  if (10 == counter[2])
                  {
                        counter[2] = 0;
                        counter[1]++;
                        if (10 == counter[1])
                        {
                              counter[1] = 0;
                              counter[0]++;
                              if (6 == counter[0])
                              {
                                    counter[0] = 0;
                              }
                        }
                  }
                  delay_ms(100);
            }
            PORTA = ~decoderArray[counter[0]];
            PORTC = decoderArray[counter[1]];
            PORTD = ~decoderArray[counter[2]];
            botonp1 = botona1;
            botonp2 = botona2;
            botonp3 = botona3;
      }
}
