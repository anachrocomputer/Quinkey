# Quinkey #

Arduino sketch to read analog signal from Quinkey chord keyboard and
decode into chord keystrokes.

Quinkey connected to analog pin 0 (A0).

# Hardware #

![Quinkey](Quinkey.jpg "Quinkey")

# Wiring #

Inside the Quinkey is an R-2R resistor ladder DAC.
Six bits of the DAC are connected to the six microswitches under
the buttons.
The seventh (LSB) of the DAC is always 1.

The output of the DAC is sent to the host computer via a screened lead
terminated with a 3.5mm jack plug.

| Quinkey plug | Wire   | Function | Arduino |
|--------------|--------|----------|---------|
| Tip          | Red    | Analog   | A0      |
| Ring         | Blue   | +5V      | +5V     |
| Sleeve       | Screen | Ground   | Ground  |

Resistors inside Quinkey are 15k and 30k, 1%.
Two capacitors are also present,
one across the 5V power supply
and the other from the output to ground.

# Waveform #

![QuinkeyWaveform](QuinkeyWaveform.png "QuinkeyWaveform")

Pressing all four finger buttons and lower thumb button.
Time cursors are 20ms apart.
Voltage cursors are at 0V and 5V.


