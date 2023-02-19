#!/bin/sh

sudo rm /usr/bin/cimg
sudo wget https://github.com/CheemsBread505/cimg-imageviewer/releases/download/v1.1/cimg-v1.1.zip
sudo unzip cimg.zip
sudo cp cimg /usr/bin/
sudo rm cimg && sudo rm cimg.zip