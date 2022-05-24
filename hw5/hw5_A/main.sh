#!/bin/bash
filename=test
for par in $@;
do
mkdir output-$par && python ${filename}.py $par
done