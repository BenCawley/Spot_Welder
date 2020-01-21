# Spot_Welder
A project to create a battery spot welder for basically no money / very cheaply using a modified microwave transformer and solid state relay with a digital controller. There are files for Python on the Raspberry Pi or C++ for an arduino. I had problems getting reliable timing with the Pi but you may have better success depending on your setup. See ReadMe for details.

The Code:
The RGB leds are to display what stage the relay is at whilst testing the firing sequence. To do this change pulse length to something you can observe, like 1000ms.

mainPulse is how long the relay will remain engaged for during the pulse that welds, whilst firstPulse is a fraction of mainPulse and is ment to clear the welding area of debris. Feel free to play around with these to get your desired result, but more on that later.

The rest of the code takes the relay through a cycle of these two pulses and includes a debounce to try and negate double triggering. The relayDelay value is there if your relay takes a significant amount of milliseconds to fire and accounts for that delay, e.g. most mechanical relays. It's for this reason that a solid state relay is the go-to for this kind of project.

The Process:

I'm assuming a fair level of electrical knowledge and the safety surrounding working with AC voltage here. Please don't attempt this if you're a novice or unsure about what you're doing. This is not a guide and not meant to safely hand hold you through the experience, it's just how I'm documenting my own.

The basic premise of this project surrounds a modified microwave transformer. Remove the secondary winding however you see fit (taking great care not to damage the primary) and replace it with one that will step your voltage down to around 5Vac. Mine turned out to develop 3V and that works perfectly fine. 

To calculate your voltages and windings use a site like this one https://mechatrofice.com/calculator/transformer and make an estimation of the number of windings in the primary. Some transformers may have this written on them or have a part number you can research,  but really we're just aiming for a ballpark figure.

Once you've found some suitably thick gauge cable for your secondary and calculated how many turns you need, give it a go and read the output with a multimeter. Do not try and read how many amps are being generated - It will be too many. You WILL destroy your meter. If your setup is anything like mine it's theoretical maximum load will be around 600 amps @ 3v, and my transformer isn't even that big to begin with. 

Suffice to say, at this point you should be conducting these tests very safely - be very aware and purposeful about what you are doing when you have the AC hooked up to the primary and make it a principle to think through every step and triple check that you have in fact unplugged it when you are finished. 

If your secondary voltage is too high you can always run two cables in parallel and hook them up at each end for the secondary, so that you have fewer turns but more cable present. I ended up doing this and soldered the ends together. This should provide you with the maximum current loading for your secondary winding, which is a good thing to have when dealing with hundreds of amps.

Next hook each end of your primary up to a welding pen or holder of some sort, I bought this one https://www.aliexpress.com/item/4000104109230.html?spm=a2g0s.9042311.0.0.67de4c4dx7IsP8 and it works pretty well, especially with an integrated switch. You can also hook up a footswitch to trigger the relay.

Once you have confirmed that your relay is firing (I just measured the voltage difference between the two output terminals and looked for a change) it's time to test it with a nickel strip and battery. I used a dead battery I'd recovered from another pack to test this as it doesn't matter if things go... sideways.

Now, because our setup isn't exactly refined or well controlled and a little bit janky, there is a high probability that the welder will just blow a hole in your nickel strip. This is quite spectacular and produces flying sparks so definitely WEAR EYE PROTECTION. 

Basically we are aiming for a weld that is incredibly difficult to separate with tools, if you've ever seperated a pre-made lithium ion pack you know the quality of weld that I mean. If you weld comes unstuck whilst manipulating the pack you need to increase the relay timing. If your nickel strip is being vaporized you need to reduce it. 

Finding that happy medium is something I am still trying to do with my setup, so don't be discouraged if you are having problems. Due to the nature of this setup we may need to limit the current to the primary. One possible solution to this is using a lighting dimmer or motor speed controller, but I need to do more research and experimentation. I'll update this readme as I get closer to a solution!

