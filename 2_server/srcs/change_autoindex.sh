#!/bin/bash

if [ "$1" = 'off' ]; then
	sed -i  '' 's/autoindex off/autoindex on/g' test
fi
if [ "$1" = 'on' ]; then
	sed -i  '' 's/autoindex on/autoindex off/g' test
fi
