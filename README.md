# Xeus-cling & matplotlib-cpp in a jupyter notebook

This is a template for doing audio DSP visualizations with [xeus-cling](https://xeus-cling.readthedocs.io/en/latest/) and [matplotlib-cpp](https://github.com/lava/matplotlib-cpp) and rendering to wav from C++ in a jupyter notebook.

Thanks to @wolfv for the matplotlib-cpp code and @DannyHavenith for the original docker image, which has been slightly modified:

https://hub.docker.com/repository/docker/olilarkin/xeus-cling-mpl

also uses the [ICST DSP library](https://www.zhdk.ch/en/research/icst/software-downloads-5379/downloads-dsp-library-5384) AudioFile class for wav writing


## how to run it
* install [docker desktop](https://www.docker.com)
* `git clone --recursive https://github.com/olilarkin/XeusClingMatplotLibExample`
* `cd XeusClingMatplotLibExample`
* `docker run -it --rm --mount type=bind,source="$(pwd)",target=/work -p 8888:8888 olilarkin/xeus-cling-mpl`
