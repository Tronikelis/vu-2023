#!/bin/bash

ps ax

echo "Kill pid?"

read id

kill $id
