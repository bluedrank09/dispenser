# dispenser
This code operates a dispenser machine to give you candy.

First, the code sets up the libraries, variables and signal pins. 

In the loop, the code checks for input(a coin you drop into the machine). If it doesn't sense anything, it won't do anything, but once it does, it turns a servo motor so the candy can drop. 

The rest of the loop lights up a neopixel ring around the coin slot in rainbow colours.
