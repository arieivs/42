# Fractol
Explore the magic of fractals and the graphics library MiniLibX.
Get hypnotised by the [Mandelbrot and Julia sets](https://julia.fractalnft.art/).

<br/>

## 📚 Compiling MiniLibX
In your Makefile, you must compile MiniLibX using its own Makefile and then copy the library libmlx.dylib to your current directory.
Else, you'll get an error saying the library libmlx.dylib was not loaded because the image could not be found.
Why?
And why such an inelegant solution?
To answer that we first need to understand dynamic libraries (MiniLibX is one).

### 💡 Dynamic Library
A [Dynamic Library](https://www.techopedia.com/definition/27133/dynamic-library) is only loaded into your programme at run time, meaning it is not included in your executable.
Whereas a Static Library becomes part of your programme during its compilation, thus being part of the executable.
Learn more about the advantages and disadvantages of [static and dynamic libraries](https://www.learncpp.com/cpp-tutorial/a1-static-and-dynamic-libraries/).

When running ```gcc <...> -l<..> -L<directory>``` the -L flag (and thus the given directory) is only used when linking, not on runtime.
At runtime, it looks for the needed libraries in specific paths, so the solution is to add our library's directory to one of them, the best option being ```rpath```.
Learn more on [dynamic loading and using rpath here](https://amir.rachum.com/blog/2016/09/17/shared-libraries/).
The equivalent to Linux's comand ```ldd``` on Mac is ```otool -L <executable>``` and by running ```otool -l <executable>``` you're able to check your rpath (under LC_RPATH).

Personally, I was able to change the ```rpath``` but it kept not being able to find libmlx.dylib, as it kept looking for it at the executable's directory instead of the given one. Which is why the very inelegant solution proposed above works.

<br/>

## 🖼 Getting familiar with MiniLibX
Follow the [MiniLibX documentation on 42Docs](https://harm-smits.github.io/42docs/libs/minilibx.html) and these [guides and tutorials on MiniLibX](https://gontjarow.github.io/MiniLibX/).

If you think MiniLibX is not enough and you want the whole package, here's some extra reading material: [Xlib Programming Manual](https://www.niksula.hut.fi/~jkirma/books/xlib.pdf#page=36) and [X11 Protocol](https://www.x.org/releases/X11R7.7/doc/xproto/x11protocol.html).

<br/>

## 🐰 The beauty of mathematics
One of the most fascinating things is to realise that all these fractals are generated from iterating a very simple (yet complex) equation.
Dive into the maths with this [Numberphile video on Julia sets](https://www.youtube.com/watch?v=FFftmWSzgmk), this [Numberphile video on the Mandelbrot set](https://www.youtube.com/watch?v=NGMRB4O922I) and if you're still curious check this [video from Veritasium on the logistic map](https://www.youtube.com/watch?v=ovJcsL7vyrk).

As you've noticed, it all goes around the following equation:
<p>z<sub>n + 1</sub> = z<sub>n</sub><sup>2</sup> + c</p>
Where both z and c are complex numbers (z is our variable, c a constant) and n is the iteration count.

For the Burning ships fractal (bonus) you simply need to use the absolute values of both the real and imaginary parts of z:
<p>z<sub>n + 1</sub> = ( |Re(z<sub>n</sub>)| + |Im(z<sub>n</sub>)| )<sup>2</sup> + c

<br/>
<br/>

## 🎨 Let's render some fractals
Follow [this tutorial on how to render the Mandelbrot set](http://warp.povusers.org/Mandelbrot/).
The Julia set and Burning ships fractal are almost the same!
Apply the same logic, just with minor changes in the mathematical equations.

To colour them, simply make the colours depend on n, the number of iterations.
Here are some additional suggestions:
* [Using HSV](https://www.codingame.com/playgrounds/2358/how-to-plot-the-mandelbrot-set/adding-some-colors) and how to convert HSV into RGB: the [logic](https://cs.stackexchange.com/questions/64549/convert-hsv-to-rgb-colors) and the [code](https://www.codespeedy.com/hsv-to-rgb-in-cpp/)
* [Psycadelic](https://math.stackexchange.com/questions/90916/how-should-i-assign-rgb-colors-to-points-in-the-mandelbrot-set)
* [Creating a cubic function with several points](https://stackoverflow.com/questions/16500656/which-color-gradient-is-used-to-color-mandelbrot-in-wikipedia), also [Wolframalpha](https://www.wolframalpha.com) will come in handy

<br/>

Happy rendering! 👨‍🎨
