#!/bin/bash

filename=$1

withTime="$(basename $filename)_$(date +%s)"

cp $filename $withTime
