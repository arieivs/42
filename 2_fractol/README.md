# Fractol
Explore the magic of fractals and the graphics library MiniLibX

<br/>

## 📚 Compiling MiniLibX
In your Makefile, you must compile MiniLibX using its own Makefile and then copy the library libmlx.dylib to your current directory.
**WHY??**
dyld: Library not loaded: libmlx.dylib
  Referenced from: /Users/svieira/code/arieivs/42/2_fractol/./fractol
  Reason: image not found
Notice that MiniLibX is a dynamic library.

### 💡 Dynamic Library
A [Dynamic Library](https://www.techopedia.com/definition/27133/dynamic-library) is only loaded into your programme at run time, meaning it is not included in your executable.
Whereas a Static Library becomes part of your programme during its compilation, thus being part of the executable.
Learn more about the advantages and disadvantages of [static and dynamic libraries](https://www.learncpp.com/cpp-tutorial/a1-static-and-dynamic-libraries/).

<br/>

## 🖼 Getting familiar with MiniLibX
Follow the [MiniLibX documentation on 42Docs](https://harm-smits.github.io/42docs/libs/minilibx.html) and these [guides and tutorials on MiniLibX](https://gontjarow.github.io/MiniLibX/).

More Resources:

On MiniLibX and fractol: https://github.com/qst0/ft_libgfx

MLX Build (Docker container): https://github.com/Chr0nos/mlx-build

Get hypnotised by Julia set: https://julia.fractalnft.art/

Xlib Programming Manual: https://www.niksula.hut.fi/~jkirma/books/xlib.pdf#page=36

X11 Protocol: https://www.x.org/releases/X11R7.7/doc/xproto/x11protocol.html

<br/>

## 🐰 The beauty of mathematics
One of the most fascinating things is to realise that all these fractals are generated from iterating a very simple (yet complex) equation.
Dive into the maths with this [Numberphile video on Julia sets](https://www.youtube.com/watch?v=FFftmWSzgmk), this [Numberphile video on the Mandelbrot set](https://www.youtube.com/watch?v=NGMRB4O922I) and if you're still curious check this [video from Veritasium on the logistic map](https://www.youtube.com/watch?v=ovJcsL7vyrk).

<br/>

## 🎨 Let's render some fractals

Burnship fractal: http://www.paulbourke.net/fractals/burnship/

Colours:
https://www.codingame.com/playgrounds/2358/how-to-plot-the-mandelbrot-set/adding-some-colors
https://math.stackexchange.com/questions/90916/how-should-i-assign-rgb-colors-to-points-in-the-mandelbrot-set
https://stackoverflow.com/questions/16500656/which-color-gradient-is-used-to-color-mandelbrot-in-wikipedia
