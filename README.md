# mrubyc_for_ESP32_Arduino


An Arduino library of mruby/c for ESP32 Arduino


**This is my experimental work. There is no guarantee about this library.**

## Usage

### Condition

This library depends on ESP32 Arduino library. Please install it in advance.

### Import the library to Arduino IDE

Clone this repository.

    clone https://github.com/kishima/mrubyc_for_ESP32_Arduino.git

Copy "mrubyc_for_ESP32_Arduino" to your Arduino library directory.

    cp -r mrubyc_for_ESP32_Arduino [your document directory]/Arduino/libraries/mrubyc_for_ESP32_Arduino

Include a header file mrubyc_for_ESP32_Arduino.h.

### Implement mruby/c functions

Nothing changed in basic usage of mruby/c. You can use mruby/c APIs.
I added following function(s).

- mrbc_define_methods

You can refer example files about detailed usage.
Of course, you need compiled mruby byte code to run on it.

For example, a LED connected to GPIO 4 can be controled by following script.

```rb
puts "mruby/c example: control LED"
Arduino.pin_mode(4,:OUTPUT)
while true
	Arduino.digital_write(4,:HIGH)
	sleep(1)
	Arduino.digital_write(4,:LOW)
	sleep(1)
end
```

## Future work (if I'm good...)

- define mruby methods of Arduino library.
- define mruby methods of ESP32 library.
- implement an automatical executer and an uploader of mruby byte code.
- implement a function about downloading mruby byte code Over The Air.

## Copyright

Refer LICENSE file.


