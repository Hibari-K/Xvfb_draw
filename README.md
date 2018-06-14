# Xvfb_draw
drawing test for virtual framebuffer through Xvfb

## Dependency
* Xvfb
* x11vnc
* vncviewer

## Testing environment
Ubuntu 16.04

## Setup
If you've not install packages in *Dependency*, install them as follows:
```
$ sudo apt install xvfb x11vnc vncviewer
```

## test
First, `make run` to compile, run, and ready for drawing,
and then `make vnc` on another terminal.

Finally, please run `make kill` to quit Xvfb.
