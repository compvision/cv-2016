#!/bin/bash
cd /home/option16pi/
./cv-2015/build/src/cv_2015 -d 0 --headless &
cd NetworkTableClient
java NTable
