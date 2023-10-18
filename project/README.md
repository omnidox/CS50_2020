Reference Standard Expiration Scanner.

By: Rafael Hidalgo

Hello, my name is Rafael Hidalgo. Before I explain my project, I would like to provide a bit of background. Currently my profession is that of an Analytical Chemist. 
As an Analytical Chemist, one of my roles is to test chemical samples against known chemical standards. We acquire standards from the United States Pharmacopeia (USP).
 
USP establishes written documented and physical reference standards for medicines, food ingredients, dietary supplement products, and ingredients. 
These standards are used by regulatory agencies and manufacturers to help to ensure that products are of the appropriate identity, as well as strength, quality, purity, and consistency.

Standards usually come in a container with a lot number and barcode pasted on the container surface. 
As a chemist it is my job to cross reference the lot number of standard containers with an excel database provided in the USP website. 
The URL of which I have pasted below. 

http://static.usp.org/doc/referenceStandards/usprefstd.xls

When I verify a standard, I ensure that the lot number of the standard is listed under Current Lot or Previous Lot. 
If it is listed under current lot, that means the standard has yet to have an expiration date and it is still good to use. 
If listed under previous lot, then this means that the standard will have an expiration date, 
and I would have to verify that my current standard has not exceeded that expiration date. Finally, if the standard is not listed in either column, 
then the standard is not good to use, as it most likely expired a long time ago.

With this in mind, I aimed to create an app that helps with verifying my Standards by either typing the lot number on the app, or even better, 
by scanning the barcode that is available on my standards. As you will see on the video, I have achieved this. 

In summary, I used a library called Jexcel API to extract all of my information from the excel file into my application. 
Similar to how the Pokemon class constructor was made for the pokedex app, 
I made a Java class constructor called Std_Data to help me parse the information I received my excel file.

I then took that data and applied it to a Recycler View. I then implemented a search function by making an EditText object and filtering my recycler view after my text input has changed.
Finally, I used the Zxing barcode scanner library to enable my camera to scan for barcodes, 
and I tied the code I made for my barcode scanner to my filtering method in order to enable filtering of my recycler view via barcode. 

Now I am able to verify my standards on my phone instead of a desktop computer. Please see the youtube video below for a Demo. 

https://youtu.be/PPxdT8T-sa8 




