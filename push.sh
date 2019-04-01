#!/bin/bash

cd ./cpptest
make clean
cd -

git add *
git commit -m "modify files"
git push
