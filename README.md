# Ledstairs

Staris light with any of 12v led strip controlled by Arduino Mini

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes. See deployment for notes on how to deploy the project on a live system.

### Prerequisites

You will need these things to build this project

- [Arduino Pro Mini or Micro 5V](https://www.aliexpress.com/item/Pro-Micro-ATmega32U4-5V-16MHz-Replace-ATmega328-Pro-Mini/32649703074.html?spm=2114.search0104.3.139.643e65d9cuwmkA&ws_ab_test=searchweb0_0,searchweb201602_3_10065_10068_319_317_10696_453_10084_454_10083_433_10618_431_10304_10307_10820_10821_537_10302_536_10902_10059_10884_10887_321_322_10103,searchweb201603_70,ppcSwitch_0&algo_expid=31fbeb1a-766d-4e84-a48f-54efbf7e215c-21&algo_pvid=31fbeb1a-766d-4e84-a48f-54efbf7e215c&transAbTest=ae803_5) or any other Arduino
- Shift registers [74HC595N](https://www.aliexpress.com/item/16-74HC595-74HC595N-SN74HC595N-DIP-16-10pcs-Free-postage/32819609046.html?spm=2114.search0104.3.146.2b4e5f68lIuVdt&ws_ab_test=searchweb0_0,searchweb201602_3_10065_10068_319_317_10696_453_10084_454_10083_433_10618_431_10304_10307_10820_10821_537_10302_536_10902_10059_10884_10887_321_322_10103,searchweb201603_70,ppcSwitch_0&algo_expid=011b071f-41d5-48f3-a437-db7986b805df-22&algo_pvid=011b071f-41d5-48f3-a437-db7986b805df&transAbTest=ae803_5)
- Logic circuits [ULN2803](https://www.aliexpress.com/item/10pcs-ULN2803A-ULN2803APG-ULN2803-DIP-18/32823940295.html?spm=2114.search0104.3.15.4c5b4f039GnUmZ&ws_ab_test=searchweb0_0,searchweb201602_3_10065_10068_319_317_10696_453_10084_454_10083_433_10618_431_10304_10307_10820_10821_537_10302_536_10902_10059_10884_10887_321_322_10103,searchweb201603_70,ppcSwitch_0&algo_expid=c10f3aa9-f3ec-4300-8407-b10b669f355f-2&algo_pvid=c10f3aa9-f3ec-4300-8407-b10b669f355f&transAbTest=ae803_5)
- [12v led strips](https://www.aliexpress.com/item/5M-Roll-3528-SMD-Waterproof-60-LEDs-M-300-LEDs-Warm-Cool-White-Red-Green-Blue/32261760142.html?spm=a2g0s.9042311.0.0.27424c4d3v950r)
- 100uF 16V polarized [capacitor](https://www.aliexpress.com/item/100-pcs-lot-25V-47uF-volume-in-5-11mm-47-uf-25-v-high-quality-aluminum/32812085542.html?spm=a2g0s.9042311.0.0.27424c4d3v950r)
- 100nF monolithic [capacitors](https://www.aliexpress.com/item/50PC-Monolithic-Capacitor-101-102-103-104-220-330-50V-100PF-1NF-10NF-0-1UF-22P/32865098104.html?spm=a2g0s.9042311.0.0.27424c4d3v950r)
- [DIP16 sockets](https://www.aliexpress.com/item/10PCS-IC-Sockets-DIP6-DIP8-DIP14-DIP16-DIP18-DIP20-DIP28-DIP40-pins-Connector-DIP-Socket-6/32946280676.html?spm=a2g0s.9042311.0.0.27424c4d3v950r)
- [DIP18 sockets](https://www.aliexpress.com/item/10PCS-IC-Sockets-DIP6-DIP8-DIP14-DIP16-DIP18-DIP20-DIP28-DIP40-pins-Connector-DIP-Socket-6/32946280676.html?spm=a2g0s.9042311.0.0.27424c4d3v950r)
- PCB factory where they made your PCB. I use service of [JLCPCB company](https://jlcpcb.com/)
- 3 pin terminal [KF301-3P](https://www.aliexpress.com/item/10PCS-LOT-KF301-3P-250A-160V-Screw-3Pin-5-08mm-Straight-Pin-PCB-Screw-Terminal-Block/32691503188.html?spm=2114.search0104.3.22.3f818a59LeIPvy&ws_ab_test=searchweb0_0,searchweb201602_3_10065_10068_319_317_10696_453_10084_454_10083_433_10618_431_10304_10307_10820_10821_537_10302_536_10902_10059_10884_10887_321_322_10103,searchweb201603_70,ppcSwitch_0&algo_expid=5bf8a851-3af4-4ada-bb6d-fa87ae9e59a2-3&algo_pvid=5bf8a851-3af4-4ada-bb6d-fa87ae9e59a2&transAbTest=ae803_5)
- 3 pin [JST 1.25mm](https://www.aliexpress.com/item/50pcs-MICRO-JST-Connector-1-25MM-Pitch-pin-header-2P-3P-4P-5P-6P-7P-8P/32961123150.html?spm=2114.search0104.3.23.640e7611EvbVeK&ws_ab_test=searchweb0_0,searchweb201602_3_10065_10068_319_317_10696_453_10084_454_10083_433_10618_431_10304_10307_10820_10821_537_10302_536_10902_10059_10884_10887_321_322_10103,searchweb201603_70,ppcSwitch_0&algo_expid=9013d55a-98b5-432a-9bcf-bb84c076dc6d-3&algo_pvid=9013d55a-98b5-432a-9bcf-bb84c076dc6d&transAbTest=ae803_5)
- PCB [spring terminal block](https://www.aliexpress.com/item/20PCS-Lot-141R-2-54-8P-8Pin-PCB-Spring-Terminal-Block-ROHS-connector-Pitch-2-54mm/32603594829.html?spm=a2g0s.9042311.0.0.27424c4d3v950r) with 8pin and pitch 2.54
- [FTDI FT232RL](https://www.aliexpress.com/item/FT232RL-FTDI-USB-3-3V-5-5V-to-TTL-Serial-Adapter-Module-for-Arduino-Mini-Port/32279080531.html?spm=2114.search0104.3.178.2ad813devOa2Ft&ws_ab_test=searchweb0_0,searchweb201602_3_10065_10068_319_317_10696_453_10084_454_10083_433_10618_431_10304_10307_10820_10821_537_10302_536_10902_10059_10884_10887_321_322_10103,searchweb201603_70,ppcSwitch_0&algo_expid=45da325f-cf9f-4fde-8745-46b2906db7b1-25&algo_pvid=45da325f-cf9f-4fde-8745-46b2906db7b1&transAbTest=ae803_5) programmer
- [Wires](https://www.aliexpress.com/item/Free-shipping-Dupont-line-120pcs-10cm-male-to-male-male-to-female-and-female-to-female/2041500641.html?spm=2114.search0104.3.3.208412505Yn61i&ws_ab_test=searchweb0_0,searchweb201602_3_10065_10068_319_317_10696_453_10084_454_10083_433_10618_431_10304_10307_10820_10821_537_10302_536_10902_10059_10884_10887_321_322_10103,searchweb201603_70,ppcSwitch_0&algo_expid=1c33c82a-5e96-4290-84a5-e9120151b2b5-0&algo_pvid=1c33c82a-5e96-4290-84a5-e9120151b2b5&transAbTest=ae803_5) with male or female pins

### Installing

Install one of these IDEs

- [Arduino IDE](https://www.arduino.cc/en/Main/Software) or any other IDE like [Platform IO](https://platformio.org/). You can use any online tools [Arduino web editor](https://create.arduino.cc/editor), [Tinkercat](https://www.tinkercad.com/circuits) or [Circuito.io](https://www.circuito.io/).

[Download](https://github.com/jhoralek/giom-weather-station/archive/master.zip) or clone project from github

```
git clone https://github.com/jhoralek/giom-weather-station.git
```

## Deployment

Add additional notes about how to deploy this on a live system

## Contributing

Please read [CONTRIBUTING.md](https://gist.github.com/PurpleBooth/b24679402957c63ec426) for details on our code of conduct, and the process for submitting pull requests to us.

## Versioning

We use [Git](https://git-scm.com/) for versioning. For the versions available, see the [tags on this repository](https://github.com/your/project/tags).

## Authors

- **Jiří Horálek** - _Initial work_ - [jhoralek](https://github.com/jhoralek)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
