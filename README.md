# Jorjin Ameba Arduino Library
This library enables the usage of the uNabto framework on an Ameba board. The accompanying example [LightSwitch.ino](./examples/LightSwitch/LightSwitch.ino) controls an attached LED remotely using the framework. 

# What is needed to run the example
To run the example we need to install the Ameba board libraries and the Ameba specific uNabto files. 
We also need a device name and key, both of which can be created at [portal.nabto.com](https://portal.nabto.com/)

Furthermore a LED (and appropriate resistor) is needed.


## Step 1: Download General Ameba Libraries install<br/>
Follow the steps laid out [here](http://www.amebaiot.com/en/ameba-arduino-getting-started/) to install the general Ameba libraries into the Arduino IDE OR read it right here: 

Open up the Arduino IDE. 
Click `File` -> `Preferences` and then copy this
```shell
https://github.com/Ameba8195/Arduino/raw/master/release/package_realtek.com_ameba_index.json
```
into the `Additional Boards Manager URLs` input field. Click `OK`

Now click `Tools` --> `Board: ` -> `Boards Manager`

Here we search for `Ameba` and click `Install`

The Jorjin Ameba board Arduino libraries are now installed


## Step 2: uNabto libraries install<br/>
There are two ways of getting the uNabto libraries. 

Using git
```shell
git clone --recursive https://github.com/nabto/unabto-jorjin-sdk
```
then change directory to the `unabto-jorjin-sdk` folder and run
```shell
bash Make.sh
```

OR
download the release zip file [unabto-jorjin-sdk.zip](https://github.com/nabto/unabto-jorjin-sdk/releases)


No matter which way, we can now add the library to the Arduino IDE via `Sketch` -> `Include Library` -> `Add .ZIP Library...` and then browse to and add the `unabto-jorjin-sdk` folder that was just downloaded.

## Run the example
We can now open the [LightSwitch.ino](./examples/LightSwitch/LightSwitch.ino) example by going to `File` -> `Examples` -> `Nabto-Ameba` -> `LightSwitch`

Here we need to enter the SSID and password of the wireless network we want to attach to. Furthermore we need to input the device name and key we created at [portal.nabto.com](https://portal.nabto.com/)

Finally we need to remember to wire the LED and resistor up like so (try switching pins around if it does not work at first)
![alt tag](http://www.amebaiot.com/wp-content/uploads/2015/12/get-start-16.png)

When the example is compiled and uploaded to the device we simply need to press the `reset` button (see the above image). 
The board should now reset, connect to the specified wifi network and run uNabto. 

We can now control the LED by going to `devicename.demo.nab.to` in the browser of your choice. (`devicename` is the unique name created at [portal.nabto.com](https://portal.nabto.com/)).
The browser will present us with a login prompt, simply click `guest`. We can now control the LED by moving the slider.

## See it in action
Click the image to see the [LightSwitch.ino](./examples/LightSwitch/LightSwitch.ino) usage example in action.
[![Ameba blink](http://img.youtube.com/vi/TVG-g7WF7c8/0.jpg)](https://youtu.be/TVG-g7WF7c8 "Ameba blink")
