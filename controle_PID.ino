#define TRIGGER_PIN 9
#define ECHO_PIN 10
#define ENA 5   // PWM para velocidade do motor
#define IN1 6   // Ativa o motor (gira para um lado)

// Parâmetros PID
float Kp = 1.29, Ki = 0.0, Kd = 0.0;  
float setpoint = 200.0;  // Distância desejada em mm

// Variáveis PID
float erro, erro_anterior = 0;
float integral = 0;
float derivada;
float output_PID;
float output_PWM;

void setup() {
    Serial.begin(9600);
    pinMode(TRIGGER_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    pinMode(ENA, OUTPUT);
    pinMode(IN1, OUTPUT);

    digitalWrite(IN1, HIGH); // Gira apenas em um sentido
}

void loop() {
    // Medir a distância com o HC-SR04
    digitalWrite(TRIGGER_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(TRIGGER_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIGGER_PIN, LOW);
    
    long duration = pulseIn(ECHO_PIN, HIGH);
    float mensurado = duration * 0.034 / 2.0 * 10.0; // Conversão para mm

    // Cálculo do erro
    erro = setpoint - mensurado;
    
    // Cálculo PID
    integral += erro;
    derivada = erro - erro_anterior;
    output_PID = (Kp * erro) + (Ki * integral) + (Kd * derivada);

    // Limita o PWM entre 0 e 255
    output_PWM = constrain(output_PID, 0, 255);
    
    // Envia PWM para o motor
    analogWrite(ENA, (int)output_PWM);
    
    // Exibe os valores no Serial Plotter
    Serial.print("Setpoint: ");
    Serial.print(setpoint);
    Serial.print(", ");
    Serial.print("Mensurado: ");
    Serial.print(mensurado);
    Serial.print(", ");
    Serial.print("Erro: ");
    Serial.print(erro);
    Serial.print(", ");
    Serial.print("PWM: ");
    Serial.println(output_PWM);
    
    erro_anterior = erro;  // Atualiza o erro anterior
    delay(100);
}
