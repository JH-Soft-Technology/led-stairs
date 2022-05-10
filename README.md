# Ledstairs

Microcontroller operating stairway lighting via motion sensors and light intensity sensor. Has two [PIR motion sensors](https://en.wikipedia.org/wiki/Passive_infrared_sensor) to detect human or animal movement.
The board also has a light sensitivity sensor that prevents from triggering when there is still enough light.

It has been designed to be modularly applied to stairs of different sizes. Individual boards can be joined together and thus the possibility of lighting up the stairs with the number 8/16/24/32 steps.

If for some reason there are fewer steps than 8 or 16 or 24 or 32. It is possible to light up such a number of steps. The required number of slabs is connected and only the number of required steps is involved. In addition, the slots will be empty.

## Schematic

Board has one 12V input terminal. It's different to old version, because the old one has input for 12V and 5V independently. New design has only 12V input and it is redist for inner circuit to 5V voltage.

![Schematic](https://github.com/jhoralek/led-stairs/blob/master/images/led-stairs-schematic-smd.png)

## Design of the board

Board can be chained with up to 3 others. So maximal light management is 32 steps.

![PCBdesign](https://github.com/jhoralek/led-stairs/blob/master/images/led-stairs-smd-board.png)

## PCB board

It is double sided PCB board.

![PCB](https://github.com/jhoralek/led-stairs/blob/master/images/board_with_no_smds.jpg)

Master front side of the board with chips.

![PCBmasterFront](https://github.com/jhoralek/led-stairs/blob/master/images/master_front.jpg)

Master back side of the board with chips.

![PCBmasterBack](https://github.com/jhoralek/led-stairs/blob/master/images/master_back.jpg)

Master nad slave boards chained together.

![PCBmasterSlave](https://github.com/jhoralek/led-stairs/blob/master/images/master_slave_front.jpg)

## How does it work

This board is turning on each step by step depends from which side is someone goes. Each step is turn on with little delay so it has nice effect. You can put a 12V LED strips to each step or
small light into the wall next to the each step. It depends on witch stairs you have.

In the feature, I'll put some video or moving picture in GIF format, how does it work.

## What you need to accomplish the project

- 12V power supply with current depends on number of the steps and length of LED strip. You need to calculate total current drain of all LED strips plus 25% extra for safe power supply operation.

Example:

```
You have 16 steps and each step has 70 cm long LED strip.
1m of led strip need 4,2 watts.

16 x 0,7 = 11,2m LED strip.

11,2 x 4,2 = 47,02 watts to all LED strips.

You need add 25% from 47,02 which is 58,75 watts.

So you need to by powers supply with 12V voltage and at least 60 watts. 60 watts for 12V power supply is 5 amps.
```

- 2 PIR sensor like [HC-SR501](https://www.amazon.com/HC-SR501/s?k=HC-SR501)
- A cable with two wires init. A cable cross section of at least 0,25 mm to each.
- Some 12V LED strips or lights at 12V.
- Some case for microcontroller and power supply.

## Visual

![Up](https://github.com/jhoralek/led-stairs/blob/master/images/led-stairs-1.gif)
![Down](https://github.com/jhoralek/led-stairs/blob/master/images/led-stairs-2.gif)

## Authors

- **Jiří Horálek** - _Initial work_ - [jhoralek](https://github.com/jhoralek)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
