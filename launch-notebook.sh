#! /bin/sh
alias docker="winpty docker"
docker run -it --rm --mount type=bind,source="$(pwd)",target=/work -p 8888:8888 olilarkin/xeus-cling-mpl