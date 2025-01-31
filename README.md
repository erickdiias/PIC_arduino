# Controle de Motor com Sensor Ultrassônico e PID

## Descrição
Este projeto implementa um sistema de controle para um motor DC utilizando um sensor ultrassônico HC-SR04 para medir a distância. Um controlador PID (Proporcional, Integral e Derivativo) ajusta a velocidade do motor para manter a distância desejada (setpoint). O motor é acionado através de um driver L298N.

## Componentes Utilizados
- **Arduino Uno (ou compatível)**
- **Sensor ultrassônico HC-SR04**
- **Driver de motor L298N**
- **Motor DC**
- **Fonte de alimentação compatível**

## Conexões
| Componente  | Pino Arduino |
|------------|-------------|
| HC-SR04 TRIGGER | 9 |
| HC-SR04 ECHO | 10 |
| L298N ENA (PWM) | 5 |
| L298N IN1 | 6 |

## Funcionamento
1. O Arduino envia pulsos ao sensor HC-SR04 para medir a distância.
2. O valor lido é filtrado para reduzir ruídos.
3. O erro entre a distância medida e o setpoint é calculado.
4. O controlador PID ajusta o sinal PWM do motor com base nesse erro.
5. O motor é controlado para manter a distância desejada.

## Configuração do PID
Os parâmetros do controlador PID podem ser ajustados no código:
```cpp
Kp = 15.0;  // Ganho proporcional
Ki = 0.2;   // Ganho integral
Kd = 0.0;   // Ganho derivativo
```

## Serial Monitor
O código imprime os valores no monitor serial para análise e ajuste:
- **Setpoint** (distância desejada)
- **Distância mensurada** pelo sensor
- **Erro** (diferença entre setpoint e mensurado)
- **Saída PID** (sinal de controle aplicado ao motor)

## Como Usar
1. Faça as conexões conforme a tabela acima.
2. Carregue o código no Arduino.
3. Abra o Serial Plotter (9600 baud) para visualizar os dados.
4. Ajuste os ganhos PID para melhor desempenho.

## Melhorias Futuras
- Implementação de um sistema de autotune para o PID.
- Controle bidirecional do motor.
- Interface gráfica para ajuste em tempo real.

