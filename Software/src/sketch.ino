
#define ADC_PIN 0


// Function that printf and related will use to print
int serial_putchar(char c, FILE* f) {
    if (c == '\n') serial_putchar('\r', f);
    return Serial.write(c) == 1? 0 : 1;
}

FILE serial_stdout;
void setup()
{
    // Set up stdout
    fdev_setup_stream(&serial_stdout, serial_putchar, NULL, _FDEV_SETUP_WRITE);
    stdout = &serial_stdout;   Serial.begin(9600);
}

void loop()
{
    printf("analog: %d\n", analogRead(ADC_PIN));
}
