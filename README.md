# WASM WebP Converter

Google has an image format called WebP, and a C library for converting
to and from WebP from different image formats.

This is a drag-and-drop WebP converter that uses the Emscripten compiler
to compile C code to Web Assembly, so the WebP C library can be used
in the browser.

This example does the file conversion in the browser, and then uploads
the result to a simple Python Flask backend.

# Instructions

## Install

For now, run this in a Linux environment.

Get the source code.

`git clone git@github.com:angstyloop/wasm-webp-converter.git`
`cd wasm-webp-converter`

Install pip.

`sudo apt install python3-pip`

Install Flask.

`pip install flask`

The WASM module has already been compiled, so you don't need to run the
compile script. You just need to start the Flask server, open a web browser
to the URL printed to console by the script, and drag an image onto the
screen. Try a PNG or a JPG.

## Start the Flask server.

### Brief
`git clone https://github.com/angstyloop/wasm-webp-converter.git`
`cd wasm-webp-converter`
`sudo apt install python3-pip`
`pip install flask`
`chmod u+x serve`
`./serve`


### Description

Run the Flask server with the following command.

`./serve`

Once you do that, the WebP image will appear in the `./uploads/` folder
of the repo root directory. You can open the image in a web browser and
view it. WebP has a variable amount of compression - it is controlled by
a quality factory (Q factor).

You should only need to edit `static/webp.html`, which contains the HTML and
the JavaScript for the simple web page.

# Keyframes

Aside from learning about Web Assembly (WASM), binary file transfer in
JavaScript, and WebP, you can also learn a bit about CSS keyframes from this
example. I used keyframes to create a "charging curve" for the color of
the WebP logo. It gives the logo a halogen lamp effect. There are lots of
examples of neat usages of keyframes like this one on the web if you google
around a bit.

# To Do

Write a .ps1 script for `serve`.

Exercise for the reader: can you extend this with a UI for the Q factor?
You shouldn't have to modify the WASM module at all - the WASM methods take
Q as an argument. You just need to write some JavaScript for modifying
Q, and then bind those JavaScript functions to HTML elements that you add.

